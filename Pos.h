#include <iostream>
#include <ctime>
#include <iomanip>
#include <cstring>
#include <fstream>
using namespace std;
class SalesLineItem;
int strl(char *arr) //alternative for strlen to get length of a string
{
	int i = 0;
	for (i = 0; arr[i] != '\0'; i++)
	{
	}
	return i;
};
void strc(char *arr1, char *arr2) //alternative for strcpy to copy
{
	int l = 0;
	l = strl(arr2);
	l++;
	arr1 = new char[l];
	for (int i = 0; i < l; i++)
		arr1[i] = arr2[i];
}
void strca(char arr1[], char *arr2) //copy contents in array
{
	int l = 0;
	l = strl(arr2);
	l++;
	for (int i = 0; i < l; i++)
		arr1[i] = arr2[i];
}
int strcomp(char *arr1, char *arr2) //compares both strings
{
	int ch = 1;
	for (int i = 0; arr1[i] != '\0'; i++)
	{
		if (arr1[i] != arr2[i])
		{
			ch = 0;
		}
	}
	return ch;
}
int turnint(char *a)
{
	int i = 0;
	int r = 0;
	while (a[i] != '\0')
	{
		r = (a[i] - '0') + (r * 10);
		i++;
	}
	return r;
}
class Item
{
	char *Item_SKU;
	char *Description;
	int Price;
	int AvailableQuantity;
	char *CreationDate;

public:
	Item(char *sku, char *des, int pri, int qty)
	{
		int temp = strl(sku);
		temp++;
		Item_SKU = new char[temp];
		for (int i = 0; i < temp; i++)
		{
			Item_SKU[i] = sku[i];
		}
		temp = strl(des);
		temp++;
		Description = new char[temp];
		for (int i = 0; i < temp; i++)
		{
			Description[i] = des[i];
		}
		Price = pri;
		AvailableQuantity = qty;
		time_t rawtime;
		tm *timeinfo;
		CreationDate = new char[15];
		time(&rawtime);
		timeinfo = localtime(&rawtime);
		strftime(CreationDate, 15, "%d/%m/%y", timeinfo);
	}
	char *getdes() //returns description
	{
		return Description;
	}
	void setdes(char *des) //sets description
	{
		if (Description)
			delete[] Description;
		strc(Description, des);
	}
	int getpri() //returns price
	{
		return Price;
	}
	void setpri(int pri) //sets price
	{
		Price = pri;
	}
	int getqty() //returns quantity
	{
		return AvailableQuantity;
	}
	void setqty(int qty) //sets quatity
	{
		AvailableQuantity = qty;
	}
	void dqty(int n) //reduce quantity
	{
		AvailableQuantity -= n;
	}
	void negqty(int q) //reduce quantity
	{
		AvailableQuantity -= q;
	}
	char *getsku() //returns sku of item
	{
		return Item_SKU;
	}
	char *getdate() // returns date
	{
		return CreationDate;
	}
	void setdate(char *d) // sets date
	{
		delete[] CreationDate;
		strc(CreationDate, d);
	}

	friend ostream &operator<<(ostream &, Item &);
	~Item()
	{
		if (Item_SKU)
			delete[] Item_SKU;
		if (Description)
			delete[] Description;
		if (CreationDate)
			delete CreationDate;
	}
};
ostream &operator<<(ostream &out, Item &a)
{
	out << a.Item_SKU << "\t" << a.Description << "\t" << a.Price << "\t" << a.AvailableQuantity << "\t" << a.CreationDate << endl;
	return out;
}
class Customer
{
	char *CNIC;
	char *Name;
	char *Address;
	char *Phone;
	char *Email;
	int Type;
	int AmountPayable;
	int SalesLimit;

public:
	Customer(char *cnic, char *name, char *add, char *phone, char *mail, int type, int limit)
	{

		int l = 0;
		l = strl(cnic);
		l++;
		CNIC = new char[l];
		for (int i = 0; i < l; i++)
			CNIC[i] = cnic[i];
		l = 0;
		l = strl(name);
		l++;
		Name = new char[l];
		for (int i = 0; i < l; i++)
			Name[i] = name[i];
		l = 0;
		l = strl(add);
		l++;
		Address = new char[l];
		for (int i = 0; i < l; i++)
			Address[i] = add[i];
		l = 0;
		l = strl(phone);
		l++;
		Phone = new char[l];
		for (int i = 0; i < l; i++)
			Phone[i] = phone[i];
		l = 0;
		l = strl(mail);
		l++;
		Email = new char[l];
		for (int i = 0; i < l; i++)
			Email[i] = mail[i];
		Type = type;
		SalesLimit = limit;
		AmountPayable = 0;
	}
	char *getcnic()
	{
		return CNIC;
	}
	void setname(char *n)
	{
		delete[] Name;
		strc(Name, n);
	}
	int gettype()
	{
		return Type;
	}
	int getlim()
	{
		return SalesLimit;
	}
	char *getname() { return Name; }
	char *getadd() { return Address; }
	char *getphone()
	{
		return Phone;
	}
	char *getmail()
	{
		return Email;
	}
	void setmail(char *n)
	{
		delete[] Email;
		strc(Email, n);
	}
	void setphone(char *n)
	{
		delete[] Phone;
		strc(Phone, n);
	}
	void setadd(char *n)
	{
		delete[] Address;
		strc(Address, n);
	}
	void addbill(int n)
	{
		AmountPayable += n;
	}
	int getam()
	{
		return AmountPayable;
	}
	void pay(int n)
	{
		AmountPayable -= n;
	}
	friend ostream &operator<<(ostream &out, Customer &a);
	~Customer()
	{
		if (CNIC)
			delete[] CNIC;
		if (Name)
			delete[] Name;
		if (Address)
			delete[] Address;
		if (Phone)
			delete[] Phone;
		if (Email)
			delete[] Email;
	}
};
ostream &operator<<(ostream &out, Customer &a)
{
	out << a.CNIC << "\t" << a.Name << "\t" << a.Address << "\t" << a.Phone << "\t" << a.Email << "\t" << a.Type << "\t" << a.AmountPayable << endl;
	return out;
}
class Silver : public Customer
{
public:
	Silver(char *cnic, char *name, char *add, char *phone, char *mail) : Customer(cnic, name, add, phone, mail, 1, 40000)
	{
	}
};
class Gold : public Customer
{
	int dis;

public:
	Gold(char *cnic, char *name, char *add, char *phone, char *mail) : Customer(cnic, name, add, phone, mail, 2, 100000)
	{
		dis = 3;
	}
};
class Platinum : public Customer
{
	int dis;

public:
	Platinum(char *cnic, char *name, char *add, char *phone, char *mail) : Customer(cnic, name, add, phone, mail, 3, 250000)
	{
		dis = 5;
	}
};
class Sales;
class Receipt
{
	//<ReceiptNo><ReceiptDate><Sales><Amount>
	int no;
	int saleid;
	Sales *s;
	int Amount;
	char *date;

public:
	Receipt(int sid, int id, int Am)
	{
		no = id;
		s = NULL;
		saleid = sid;
		Amount = Am;
		time_t rawtime;
		tm *timeinfo;
		date = new char[15];
		time(&rawtime);
		timeinfo = localtime(&rawtime);
		strftime(date, 15, "%d/%m/%y", timeinfo);
	}
	void Setsale(Sales *sa);
	void setdate(char *da)
	{
		strc(date, da);
	}
	char *getdate()
	{
		return date;
	}
	int getid()
	{
		return no;
	}
	int getam()
	{
		return Amount;
	}
	int getsid()
	{
		return saleid;
	}
	~Receipt()
	{
		if (date)
			delete[] date;
	}
	friend ostream &operator<<(ostream &, Receipt &);
};
ostream &operator<<(ostream &out, Receipt &r)
{
	out << r.no << ";" << r.date << ";" << r.saleid << ";" << r.Amount;
	return out;
}
class Sales
{
	//(SaleID, Customer, SalesLineItem, Receipt, date, status
	int saleid;
	Customer *custom;
	char *cuscnic;
	SalesLineItem *s;
	Receipt **Rec;
	int nrec;
	char date[11];
	int status;

public:
	Sales(int id)
	{
		saleid = id;
		Rec = NULL;
		nrec = 0;
		cuscnic = NULL;
		status = 0;
		time_t rawtime;
		tm *timeinfo;
		time(&rawtime);
		timeinfo = localtime(&rawtime);
		strftime(date, 15, "%d/%m/%y", timeinfo);
	}
	char *getdate()
	{
		return date;
	}
	void setpointers(Customer *c, SalesLineItem *sli)
	{
		custom = c;
		if (cuscnic)
			delete[] cuscnic;
		cuscnic = NULL;
		int l = 0;
		l = strl(c->getcnic());
		l++;
		cuscnic = new char[l];
		for (int i = 0; i < l; i++)
			cuscnic[i] = c->getcnic()[i];
		s = sli;
	}
	void setdate(char *_date)
	{
		strc(date, _date);
		for (int i = 0; i < 11; i++)
			date[i] = _date[i];
	}
	int Recno() //return recordid
	{
		if (Rec)
			return Rec[nrec - 1]->getid();
		else
			return 0;
	}
	char *Recdate()
	{
		return Rec[nrec - 1]->getdate();
	}
	void stat() //satus will change to 1 when sale is complete
	{
		status = 1;
	}
	int getstat()
	{
		return status;
	}
	char *getcuscnic()
	{
		return custom->getcnic();
	}
	void setcus(Customer *c)
	{
		custom = c;
		int l = 0;
		l = strl(c->getcnic());
		l++;
		cuscnic = new char[l];
		for (int i = 0; i < l; i++)
			cuscnic[i] = c->getcnic()[i];
	}
	Customer *getcus()
	{
		return custom;
	}
	int getid()
	{
		return saleid;
	}
	void cnic(char *cnic)
	{
		int l = 0;
		l = strl(cnic);
		l++;
		cuscnic = new char[l];
		for (int i = 0; i < l; i++)
			cuscnic[i] = cnic[i];
	}
	int bill();
	void setsli(SalesLineItem *sli)
	{
		s = sli;
	}
	void addrec(Receipt *r)
	{
		Receipt **temp;
		temp = new Receipt *[nrec + 1];
		for (int i = 0; i < nrec; i++)
			temp[i] = Rec[i];
		temp[nrec] = r;
		if (Rec)
			delete[] Rec;
		Rec = temp;
		nrec++;
	}
	int paid()
	{
		int total = 0;
		for (int i = 0; i < nrec; i++)
		{
			total += Rec[i]->getam();
		}
		return total;
	}
	~Sales()
	{
		if (cuscnic)
			delete[] cuscnic;
	}
	friend ostream &operator<<(ostream &, const Sales &);
};
ostream &operator<<(ostream &out, const Sales &a)
{
	out << a.saleid << "\t";
	if (a.cuscnic)
		cout << a.cuscnic << "\t";
	cout << a.date << "\t" << a.status << "\t" << endl;
	return out;
}
void Receipt::Setsale(Sales *sa) //sets saleobj in receipt
{
	s = sa;
}
class SalesLineItem
{
	Item **items;
	int no;
	int *qty;
	Sales *s;
	int sid;

public:
	SalesLineItem(int sid)
	{
		items = NULL;
		qty = NULL;
		no = 0;
		s = NULL;
		this->sid = sid;
	}
	void print()
	{
		for (int i = 0; i < no; i++)
		{
			cout << sid << "\t" << items[i]->getsku() << "\t\t" << items[i]->getdes() << "\t" << qty[i] << "\t\t" << items[i]->getpri() * qty[i] << endl;
		}
	}

	void add(Item *it, int q) //adds a new item pointer in list by extension
	{
		Item **temp;
		int *tempqty;
		temp = new Item *[no + 1];
		tempqty = new int[no + 1];
		for (int i = 0; i < no; i++)
		{
			temp[i] = items[i];
			tempqty[i] = qty[i];
		}
		temp[no] = it;
		tempqty[no] = q;
		if (items)
			delete[] items;
		if (qty)
			delete[] qty;
		items = temp;
		qty = tempqty;
		no++;
	}
	int check(Item *i) //check if item is in list
	{
		int f = 0;
		for (int j = 0; j < no; j++)
		{
			if (i == items[j])
				f++;
		}
		return f;
	}
	void remove(char *sku) //removes item with same sku from list and shrinks the list
	{
		int i = 0;
		int j = 0;
		Item **temp;
		int *q;
		q = new int[no - 1];
		temp = new Item *[no - 1];
		for (i = 0; i < no; i++)
		{
			if (strcomp(sku, items[i]->getsku()))
			{
				cout << *items[i];
				delete items[i];
			}
			else
			{
				temp[j] = items[i];
				q[j] = qty[i];
				j++;
			}
			if (items)
			{
				delete[] items;
				delete[] qty;
			}
			items = temp;
			qty = q;
			no--;
		}
	}
	void dqty() //decrease quantity of item
	{
		for (int f = 0; f < no; f++)
			items[f]->dqty(qty[f]);
	}
	int getid()
	{
		return sid;
	}
	void fileload(ofstream &file, int &c) //use to store data
	{

		for (int i = 0; i < no; i++)
		{
			file << endl;
			file << c << ";" << sid << ";" << items[i]->getsku() << ";" << qty[i];
		}
	}
	void setid(int i)
	{
		sid = i;
	}
	void sale(Sales *sa)
	{
		s = sa;
	}
	void setsid(int i)
	{
		sid = i;
	}
	int getsid()
	{
		return sid;
	}
	int total()
	{
		int total = 0;
		for (int i = 0; i < no; i++)
		{
			total += (items[i]->getpri() * qty[i]);
		}
		return total;
	}
	~SalesLineItem()
	{
		if (qty)
			delete[] qty;
	}
	friend ostream &operator<<(ostream &, SalesLineItem &);
};
ostream &operator<<(ostream &out, SalesLineItem &sli)
{
	for (int i = 0; i < sli.no; i++)
	{
		out << sli.sid << ";" << sli.items[i]->getsku() << ";" << sli.qty[i] << endl;
	}
	return out;
}
int Sales::bill()
{

	return this->s->total();
}
class Pos
{
private:
	Item **items;
	int nitems;
	Customer **customers;
	int ncus;
	SalesLineItem **sli;
	Sales **sales;
	int nsale;
	int saleseed;
	Receipt **receipts;
	int nreceipts;
	int recseed;

public:
	Pos()
	{
		items = NULL;
		nitems = 0;
		customers = NULL;
		ncus = 0;
		sales = NULL;
		nsale = 0;
		saleseed = 0;
		receipts = NULL;
		sli = NULL;
		nreceipts = 0;
		recseed = 0;
	}
	void upload()
	{ //upload data into all files stored in variables
		ofstream out;
		out.open("Items.txt");
		out << "<SKU><Description><Price><AvailableQuantity><CreationDate>";
		for (int i = 0; i < nitems; i++)
			out << endl
				<< items[i]->getsku() << ";" << items[i]->getdes() << ";" << items[i]->getpri() << ";" << items[i]->getqty() << ";" << items[i]->getdate();
		out.close();
		out.open("Sales.txt");
		out << "<SaleID><Customer><Receipt><date><status>";
		for (int i = 0; i < nsale; i++)
		{
			out << endl
				<< sales[i]->getid() << ";";
			out << sales[i]->getcuscnic() << ";";
			out << sales[i]->Recno() << ";";
			out << sales[i]->getdate() << ";";
			if (sales[i]->getstat())
				out << "Completed";
			else
				out << "Incompleted";
		}
		out.close();
		out.open("Customers.txt");
		out << "<CNIC><Name><Address><Phone><Email><Type><AmountPayable><SalesLimit>";
		for (int i = 0; i < ncus; i++)
		{
			out << endl
				<< customers[i]->getcnic() << ";" << customers[i]->getname() << ";" << customers[i]->getadd() << ";" << customers[i]->getphone() << ";" << customers[i]->getmail() << ";" << customers[i]->gettype() << ";" << customers[i]->getam() << ";" << customers[i]->getlim();
		}
		out.close();
		out.open("SalesLineItem.txt");
		out << "<LineNo><Sales><Item><Quantity>";
		int count = 1;
		for (int i = 0; i < nsale; i++)
		{
			sli[i]->fileload(out, count);
			count++;
		}
		out.close();
		out.open("Receipt.txt");
		out << "<ReceiptNo><ReceiptDate><Sales><Amount>";
		for (int i = 0; i < nsale; i++)
		{
			if (sales[i]->Recno())
				out << endl
					<< sales[i]->Recno() << ";" << sales[i]->getdate() << ";" << sales[i]->getid() << ";" << sales[i]->paid();
		}
		out.close();
	}
	void additem()
	{
		char sku[10];
		char des[255];
		int pri, qty;
		cout << "SKU: ";
		cin >> sku;
		cin.ignore();
		cout << "Enter Description: ";
		cin.getline(des, 255);
		cout << "Enter Price: ";
		cin >> pri;
		cout << "Enter Quantity: ";
		cin >> qty;
		char in;
		cout << "All the input was correct and save item?\n[y/Y For Yes]\t[n/N For No]\n";
		cin >> in;
		cin.ignore();
		if (in == 89 || in == 121)
		{
			Item **temp;
			temp = new Item *[nitems + 1];
			for (int i = 0; i < nitems; i++)
				temp[i] = items[i];
			temp[nitems] = new Item(sku, des, pri, qty);
			nitems++;
			if (items)
				delete[] items;
			items = temp;
			//cout<<*items[nitems-1];
		}
	}
	void updateitem()
	{
		char sku[20];
		cout << "Enter SKU: ";
		cin >> sku;
		for (int i = 0; i < nitems; i++)
		{
			if (strcomp(sku, items[i]->getsku()))
			{
				char temp[255];
				cout << "Enter new description: ";
				cin.getline(temp, 255);
				if (temp[0])
					items[i]->setdes(temp);
				cout << "Enter new price: ";
				cin.getline(temp, 255);
				if (temp[0])
					items[i]->setpri(turnint(temp));
				cout << "Enter new quantity: ";
				cin.getline(temp, 255);
				if (temp[0])
					items[i]->setqty(turnint(temp));
				break;
			}
		}
	}
	void finditem()
	{
		char sku[20];
		char des[255];
		char pri[13];
		char qty[13];
		char date[20];
		cout << "Item_SKU: ";
		cin.getline(sku, 20);
		cout << "Description: ";
		cin.getline(des, 255);
		cout << "Price: ";
		cin.getline(pri, 13);
		cout << "Quantity: ";
		cin.getline(qty, 13);
		cout << "Creation Date[MM/DD/YY]: ";
		cin.getline(date, 20);
		for (int i = 0; i < nitems; i++)
		{
			if (strcomp(items[i]->getsku(), sku) || strcomp(items[i]->getdes(), des) || turnint(pri) == items[i]->getpri() || strcomp(items[i]->getdate(), date))
			{
				cout << "---------------------------------------------------------------------------------------------------------- \n";
				cout << *items[i] << endl;
				cout << "---------------------------------------------------------------------------------------------------------- \n";
			}
		}
	}
	void Removeitem()
	{
		char sku[20];
		cout << "Enter SKU: ";
		cin >> sku;
		cin.ignore();
		int i = 0;
		int j = 0;
		Item **temp;
		temp = new Item *[nitems - 1];
		for (i = 0; i < nitems; i++)
		{
			if (strcomp(sku, items[i]->getsku()))
			{
				int ko = 0;
				for (int k = 0; (k < nsale) && (ko == 0); k++)
				{
					if (sli[k]->check(items[i]))
					{
						ko++;
						break;
					}
				}
				if (ko != 0)
					goto C;
				cout << *items[i];
				delete items[i];
			}
			else
			{
				temp[j] = items[i];
				j++;
			}
		}
		if (items)
			delete[] items;
		items = temp;
		nitems--;
		if (0)
		{
		C:
			cout << "A record has been found of the sale of this product\n";
		}
	}
	void addcus()
	{
		char cnic[20];
		char name[20];
		char add[255];
		char phone[20];
		char mail[50];
		int type;
		cout << "Enter CNIC: ";
		cin >> cnic;
		cin.ignore();
		cout << "Enter Name: ";
		cin.getline(name, 20);
		cout << "Enter address: ";
		cin.getline(add, 255);
		cout << "Enter Phone no.: ";
		cin.getline(phone, 20);
		cout << "Enter e-mail: ";
		cin.getline(mail, 50);
		cout << "Enter type:\n1:Silver\n2:Gold\n3:Platinum\n";
		cin >> type;
		cin.ignore();
		if (type < 4 && type > 0)
		{
			Customer **temp = new Customer *[ncus + 1];
			for (int i = 0; i < ncus; i++)
				temp[i] = customers[i];
			if (type == 1)
				temp[ncus] = new Silver(cnic, name, add, phone, mail);
			if (type == 2)
				temp[ncus] = new Gold(cnic, name, add, phone, mail);
			if (type == 3)
				temp[ncus] = new Platinum(cnic, name, add, phone, mail);
			if (customers)
				delete[] customers;
			customers = temp;
			//cout<<*customers[ncus];
			ncus++;
		}
	}
	void updatecus() //update customer data
	{
		char cnic[20];
		char name[20];
		char add[255];
		char phone[20];
		char mail[50];
		char type[2];
		cout << "Enter CNIC: ";
		cin >> cnic;
		cin.ignore();
		int f = -1;
		for (int i = 0; i < ncus; i++)
			if (strcomp(cnic, customers[i]->getcnic()))
				f = i;
		if (f != -1)
		{
			cout << "---------------------------------------------------------------------------------------------------------- /n";
			cout << customers[f];
			cout << "---------------------------------------------------------------------------------------------------------- /n";
			cout << "Enter Name: ";
			cin.getline(name, 20);
			cout << "Enter address: ";
			cin.getline(add, 255);
			cout << "Enter Phone no.: ";
			cin.getline(phone, 20);
			cout << "Enter e-mail: ";
			cin.getline(mail, 50);
			cout << "Enter type:\n1:Silver\n2:Gold\n3:Platinum\n";
			cin.getline(type, 2);
			if (type[0] == '\0' || type[0] == '1' || type[0] == '2' || type[0] == '3')
				if (!type[0])
					type[0] = customers[f]->gettype();
			if (!name[0])
				strca(name, customers[f]->getname());
			if (!add[0])
				strca(add, customers[f]->getadd());
			if (!phone[0])
				strca(phone, customers[f]->getphone());
			if (!mail[0])
				strca(mail, customers[f]->getmail());
			delete customers[f];
			if (type[0] == '1')
				customers[f] = new Silver(cnic, name, add, phone, mail);
			if (type[0] == '2')
				customers[f] = new Gold(cnic, name, add, phone, mail);
			if (type[0] == '3')
				customers[f] = new Platinum(cnic, name, add, phone, mail);
		}
		else
		{
			cout << "Customer not found";
		}
	}
	void findcus() //finds customer in data
	{
		char cnic[20];
		char name[20];
		char add[255];
		char phone[20];
		char mail[50];
		char type[2];
		cout << "CNIC: ";
		cin.getline(cnic, 20);
		cout << "Enter Name: ";
		cin.getline(name, 20);
		cout << "Enter address: ";
		cin.getline(add, 255);
		cout << "Enter Phone no.: ";
		cin.getline(phone, 20);
		cout << "Enter e-mail: ";
		cin.getline(mail, 50);
		cout << "Enter type:\n1:Silver\n2:Gold\n3:Platinum\n";
		cin.getline(type, 2);
		for (int i = 0; i < ncus; i++)
		{
			if (strcomp(customers[i]->getcnic(), cnic) || strcomp(customers[i]->getname(), name) || strcomp(customers[i]->getadd(), add) || strcomp(customers[i]->getphone(), phone) || strcomp(customers[i]->getmail(), mail) || (type[0] == customers[i]->gettype() + '0'))
				cout << *customers[i] << endl;
		}
	}
	void removecus()
	{
		char cnic[50];
		cout << "Enter CNIC: ";
		cin >> cnic;
		cin.ignore();
		int i = 0;
		int j = 0;
		Customer **temp;
		temp = new Customer *[ncus - 1];
		for (i = 0; i < nitems; i++)
		{
			if (strcomp(cnic, customers[i]->getcnic()))
			{
				cout << *customers[i] << endl;
				delete customers[i];
			}
			else
			{
				temp[j] = customers[i];
				j++;
			}
			if (customers)
				delete[] customers;
			customers = temp;
			ncus--;
		}
	}
	void sale() //this will add a new sale member and extend memory
	{
		SalesLineItem **tempsli;
		tempsli = new SalesLineItem *[nsale + 1];
		int f = -1;
		int k = -1;
		int qty;
		int input;
		char sku[20];
		char cnic[30];
		while (k == -1)
		{
			cout << "Enter CNIC: ";
			cin >> cnic;
			for (int i = 0; i < ncus; i++)
			{
				if (strcomp(customers[i]->getcnic(), cnic))
					k = i;
			}
			if (k == -1)
				cout << "Not found\n";
		}
		tempsli[nsale] = new SalesLineItem(saleseed + 1);
	A:
		while (f == -1)
		{
			cout << "ItemSKU: ";
			cin >> sku;
			cin.ignore();
			for (int i = 0; i < nitems; i++)
			{
				if (strcomp(items[i]->getsku(), sku))
					f = i;
			}
			if (f == -1)
				cout << "Invalid SKU" << endl;
		}
		cout << "Description: " << items[f]->getdes() << endl;
		cout << "Price: " << items[f]->getpri() << endl;
		cout << "Enter Quantity: ";
		cin >> qty;
		if (items[f]->getqty() < qty)
			qty = items[f]->getqty();
		cout
			<< "Sub-Total: Rs." << items[f]->getpri() * qty;
		tempsli[nsale]->add(items[f], qty);
		f = -1;
	B:
		cout << "\nPress 1 to Enter New Item\nPress 2 to End Sale\nPress 3 to Remove an existing Item from the current sales\nPress 4 to Cancel Sale\n ";
		cin >> input;
		if (input == 1)
			goto A;
		else if (input == 3)
		{
			f = -1;
			cout << "ItemSKU: ";
			cin >> sku;
			tempsli[nsale]->remove(sku);
		}
		else if (input == 2)
		{
			if (customers[k]->getlim() < sli[nsale]->total() + customers[k]->getam())
			{
				cout << "Customer can not owe so much money.\nAskt the poor man to pay.\nAllready owe: " << customers[k]->getam() << endl;
				goto B;
			}
			for (int i = 0; i < nsale; i++)
				tempsli[i] = sli[i];
			if (sli)
				delete[] sli;
			sli = tempsli;
			Sales **temps;
			temps = new Sales *[nsale + 1];
			for (int i = 0; i < nsale; i++)
				temps[i] = sales[i];
			if (sales)
				delete[] sales;
			sales = temps;
			sales[nsale] = new Sales(saleseed + 1);
			sales[nsale]->setpointers(customers[k], sli[nsale]);
			customers[k]->addbill(sales[nsale]->bill());
			cout << "Sale ID is : " << sales[nsale]->getid();
			cout << "\t\tCNIC: " << customers[k]->getcnic() << "\nName: " << customers[k]->getname() << "\nType: ";
			if (customers[k]->gettype() == 1)
				cout << "Silver Customer\n";
			else if (customers[k]->gettype() == 2)
				cout << "Gold Customer\n";
			else
				cout << "Platinum Customer\n";
			cout << "----------------------------------------------------------------------------------------------------------------------- " << endl;
			cout << "Item_SKU\tDescription\tQuantity\tAmount\n----------------------------------------------------------------------------------------------------------------------- \n";
			sli[nsale]->print();
			cout << "----------------------------------------------------------------------------------------------------------------------- \n";
			cout << std::right << std::setw(256) << "Total Sales: " << sli[nsale]->total() << endl;
			sli[nsale]->dqty();
			nsale++;
		}
		else if (input == 4)
		{
			delete[] tempsli;
		}
		else
			goto B;
	}
	void payment() //pyment method to create reciept
	{
		int f = -1;
		int sid;
		while (f == -1)
		{
			cout << "Sale ID: ";
			cin >> sid;
			for (int i = 0; i < nsale; i++)
				if (sales[i]->getid() == sid)
					f = i;
			if (f == -1)
				cout << "Not Found;";
		}
		cout << "Customer Name: " << sales[f]->getcus()->getname() << endl;
		cout << "Total Sales Amount: " << sales[f]->bill() << endl;
		cout << "Amount Paid: " << sales[f]->paid() << endl;						 //17,550
		cout << "Remaining Amount: " << sales[f]->bill() - sales[f]->paid() << endl; //12,450
		if (!sales[f]->getstat())
		{
			cout << "Amount to be Paid: "; //10,00
			int amount;
			cin >> amount;
			cin.ignore();
			Receipt **tempp;
			tempp = new Receipt *[nreceipts + 1];
			for (int i = 0; i < nreceipts; i++)
			{
				tempp[i] = receipts[i];
			}
			tempp[nreceipts] = new Receipt(sales[f]->getid(), recseed + 1, amount);
			tempp[nreceipts]->Setsale(sales[f]);
			sales[f]->addrec(tempp[nreceipts]);
			sales[f]->getcus()->pay(amount);
			if (receipts)
				delete[] receipts;
			receipts = tempp;
			nreceipts++;
		}
	}
	void loaddata()
	{ //load data from all files
		int error = 0;
		ifstream file;
		file.open("Items.txt");
		if (!file)
		{
			cout << "Items.txt not found\n";
			error = 1;
		}
		else
		{
			char sku[10];
			char des[255];
			char pri[10], qty[5];
			char date[15];
			file.ignore(256, '\n');
			while (!file.eof())
			{
				file.getline(sku, 10, ';');
				//file.ignore(1);
				file.getline(des, 255, ';');
				//file.ignore(1);
				file.getline(pri, 10, ';');
				//file.ignore(1);
				file.getline(qty, 5, ';');
				file.getline(date, 15, '\n');
				Item **temp;
				temp = new Item *[nitems + 1];
				for (int i = 0; i < nitems; i++)
					temp[i] = items[i];
				temp[nitems] = new Item(sku, des, turnint(pri), turnint(qty));
				temp[nitems]->setdate(date);
				nitems++;
				if (items)
					delete[] items;
				items = temp;
				//file.ignore(256, '\n');
			}
			file.close();
		}
		file.open("Customers.txt");
		if (!file)
		{
			cout << "Customers.txt was not found\n";
			error = 1;
		}
		else
		{
			file.ignore(256, '\n');
			char cnic[20];
			char name[20];
			char add[255];
			char phone[20];
			char mail[50];
			char type[2];
			while (!file.eof())
			{
				file.getline(cnic, 20, ';');
				//cin.ignore();
				file.getline(name, 20, ';');
				file.getline(add, 255, ';');
				file.getline(phone, 20, ';');
				file.getline(mail, 50, ';');
				file.getline(type, 2, ';');
				file.ignore(256, '\n');
				//cin>>type;
				//cin.ignore();
				Customer **temp = new Customer *[ncus + 1];
				for (int i = 0; i < ncus; i++)
					temp[i] = customers[i];
				if (turnint(type) == 1)
					temp[ncus] = new Silver(cnic, name, add, phone, mail);
				if (turnint(type) == 2)
					temp[ncus] = new Gold(cnic, name, add, phone, mail);
				if (turnint(type) == 3)
					temp[ncus] = new Platinum(cnic, name, add, phone, mail);
				if (customers)
					delete[] customers;
				customers = temp;
				//cout<<*customers[ncus];
				ncus++;
			}
			file.close();
		}

		file.open("Sales.txt");

		if (!file)
		{
			cout << "Sales.txt was not found\n";
			error = 1;
		}
		else
		{
			char id[10];
			char cnic[20];
			char date[11];
			char status[12];
			char scrap[10];
			file.ignore(256, '\n');
			while (!file.eof())
			{
				file.getline(id, 10, ';');
				file.getline(cnic, 20, ';');
				file.getline(scrap, 10, ';');
				file.getline(date, 11, ';');
				file.getline(status, 12, '\n');
				//file.ignore(256, '\n');
				Sales **temps;
				temps = new Sales *[nsale + 1];
				for (int i = 0; i < nsale; i++)
					temps[i] = sales[i];
				if (sales)
					delete[] sales;
				sales = temps;
				sales[nsale] = new Sales(turnint(id));
				saleseed = turnint(id);
				int f = -1;
				for (int i = 0; i < ncus; i++)
				{
					if (strcomp(cnic, customers[i]->getcnic()))
						f = i;
				}
				if (f != -1)
				{
					sales[nsale]->setcus(customers[f]);
					sales[nsale]->setdate(date);
				}
				if (strcomp("Completed", status))
					sales[nsale]->stat();
				nsale++;
			}
			file.close();
		}
		file.open("SalesLineItem.txt");

		if (!file)
		{
			cout << "SalesLineItem.txt was not found\n";
			error = 1;
		}
		else
		{
			char sid[10];
			char sku[10];
			int qty;
			file.ignore(256, '\n');
			nsale = 0;
			while (!file.eof())
			{
				file.ignore(256, ';');
				file.getline(sid, 10, ';');
				file.getline(sku, 10, ';');
				file >> qty;
				//file.ignore();
				int f = -1;
				int k = -1;
				for (int i = 0; i < nitems; i++)
					if (strcomp(items[i]->getsku(), sku))
						f = i;
				for (int i = 0; i < nsale; i++)
					if (sli[i]->getsid() == turnint(sid))
					{
						k = i;
					}
				if (k == -1)
				{
					SalesLineItem **temp;
					temp = new SalesLineItem *[nsale + 1];
					for (int i = 0; i < nsale; i++)
					{
						temp[i] = sli[i];
					}
					temp[nsale] = new SalesLineItem(turnint(sid));
					temp[nsale]->add(items[f], qty);
					if (sli)
						delete[] sli;
					sli = temp;
					nsale++;
				}

				else
				{
					sli[k]->add(items[f], qty);
				}
			}
			for (int i = 0; i < nsale; i++)
			{
				for (int j = 0; j < nsale; j++)
				{
					if (sales)
						if (sales[j])
							if (sli[i]->getsid() == sales[j]->getid())
							{
								sli[i]->sale(sales[j]);
								sales[j]->setsli(sli[i]);
							}
				}
			}
			file.close();
		}
		file.open("Receipt.txt");
		if (!file)
		{

			cout << "Receipt.txt was not found\n";
			error = 1; //to indicate a file was not found
		}
		else
		{
			file.ignore(256, '\n');
			char sid[10];
			char id[10];
			char Am[10];
			char date[15];
			while (!file.eof())
			{
				file.getline(id, 10, ';');
				file.getline(date, 15, ';');
				file.getline(sid, 10, ';');
				file.getline(Am, 15, '\n');
				Receipt **temp;
				temp = new Receipt *[nreceipts + 1];
				for (int i = 0; i < nreceipts; i++) //copy previous reciept record to new record
				{
					temp[i] = receipts[i];
				}
				temp[nreceipts] = new Receipt(turnint(sid), turnint(id), turnint(Am));
				recseed = turnint(id);
				temp[nreceipts]->setdate(date);
				if (receipts)
					delete[] receipts;
				receipts = temp;

				int f = -1;
				for (int i = 0; i < nsale; i++) //fins sales is in sales data
					if (sales[i]->getid() == turnint(sid))
						f = i;
				if (f != -1)
				{
					receipts[nreceipts]->Setsale(sales[f]); //sets saleid in reciept
					sales[f]->addrec(receipts[nreceipts]);	//adds receiptid in sales
				}
				nreceipts++;
			}
			file.close();
		}
		if (error)
		{
			cout << endl;
			system("Pause");
		}
	}
	void showitems()
	{
		for (int i = 0; i < nitems; i++) //loop to print aal items
			cout << *items[i];
		for (int i = 0; i < ncus; i++) //loop to print all customers
			cout << *customers[i];
		for (int i = 0; i < nsale; i++) //loop to print all sales
			if (sales)
				cout << *sales[i];
	}

	~Pos()
	{ //delete items, customers, salelineitems,sales
		for (int i = 0; i < nitems; i++)
		{
			delete items[i];
		}
		for (int i = 0; i < ncus; i++)
		{
			delete customers[i];
		}
		for (int i = 0; i < nsale; i++)
		{
			delete sli[i];
		}
		for (int i = 0; i < nsale; i++)
		{
			delete sales[i];
		}
		for (int i = 0; i < nreceipts; i++)
		{
			delete receipts[i];
		}
		delete[] items;
		delete[] customers;
		delete[] sli;
		delete[] sales;
		delete[] receipts;
	}
};