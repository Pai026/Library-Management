//LIBRARY MANAGEMENT SYSTEM PROJECT
//PROJECT DONE BY ABHIRAM.R.PAI,JEFF CHANDY,VISHNU DHANAPAL
#include<iostream.h>
#include<fstream.h>
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<process.h>
#include<string.h>
#include<time.h>
class book
{ int bkno;
  char bname[20];
  char auth[20];
  char publ[20];
  int copies,issued;
  float cost;
 public:
  void read();
  void disp();
  void rep();
  void modify2();
  int b()
  {return bkno;
  }
  int issue()
  {return issued;
  }
  int checkissue()
  {if(issued<copies)
     return issued;
   else
      return -1;
  }
  void changeissue(int iss)
  { issued=iss+1;
  }
  void changei(int iss)
  { issued=iss-1;
  }
};
class customer
{ int custid;
  char name[20],address[40],s;
  long phone;
  float fee;
  int token;
  int bkid;
 public:
  void readit();
  void display();
  void report()
  {
   cout<<"\n\t|"<<custid<<"\t|"<<name<<"\t|"<<address<<"\t"<<"\t|"<<s
       <<"\t|"<<fee<<"\t|"<<phone<<"\t|"<<bkid;
  }
  void modify1();
  int cust()
  { return custid;
  }
  int r()
  {return token;
  }
 // void addtoken()
 // {token=1;}

//  void resettoken()
  //{token=0;}
  void changetoken()
  { if(token==1)
       token=0;
    else
      token=1;
  }
  void booktaken(int bt)
  { bkid = bt;}
  int retbt()
   { return bkid;}
};
class Transaction
{  int cutid;
   int booid;
   char trans[20];
  public:
   void re();
   void dis();
   int ct()
   { return cutid;}
   int bk()
   { return booid;}
   void t(char tr[])
   {  strcpy(trans,tr);}
   void tran(int c,int b)
   { cutid=c;
     booid = b;
   }
};
 int createcustid()
   {  int value;
	  customer c1;
		fstream file1;
		file1.open("cust1.dat",ios::in|ios::binary);
		if(file1)
		 {
		   file1.seekg(0,ios::beg);
		   while(file1.read((char*)&c1,sizeof(c1)));
		   value = c1.cust();
		   ++value;
		 }
		 else
		  value=1;


		file1.close();

	 return value;
  }
   int createbkno()
   {  int val;
	  book b1;
		fstream file1;
		file1.open("book1.dat",ios::in|ios::binary);
		if(file1)
		 {
		  file1.seekg(0,ios::beg);
		  while(file1.read((char*)&b1,sizeof(b1)));
		  val = b1.b();
		  ++val;
		 }
		 else
		   val=1;


		file1.close();

	 return val;
   }

void customer::readit()
{  int n,R;
     custid=createcustid();
     cout<<"\nEnter Customer's name:";
     gets(name);
     cout<<"_________________________";
     cout<<"\nEnter his/her Address:";
     gets(address);
	 cout<<"_________________________";
     cout<<"\nEnter Sex(M/F):";
     cin>>s;
      cout<<"_________________________";
     cout<<"\nEnter phone:";
     cin>>phone;
     cout<<"_________________________";
     cout<<"\nYour Customer id="<<custid;
     cout<<"_________________________";
     token=0;
     fee=100;
     bkid=0;

}
void book::rep()
{cout<<bkno<<"\t|"<<bname<<"\t|"<<auth<<"\t|"<<publ<<"\t|"<<copies<<"\t|"
 <<issued<<"\t|"<<cost;
}
void customer::display()
{
    cout<<"\t"<<"\n"<<"Customer Details:-";
    cout<<"\n|CustomerId"<<"\t|Name"<<"\t|Address"<<"\t|Sex"
	<<"\t|Fee"<<"\t|Phone"<<"\t|Book Taken";
    cout<<"\n|"<<custid<<"\t|"<<name<<"\t|"<<address
	<<"\t|"<<s<<"\t|"<<fee<<"\t|"<<phone<<"\t|"<<bkid;

}
void book::read()
{ bkno=createbkno();
  cout<<"\nEnter Book Name:-";
  gets(bname);
  cout<<"\nEnter author's Name:-";
  gets(auth);
  cout<<"\nEnter publisher's Name:-";
  gets(publ);
  cout<<"\nEnter the number of copies:-";
  cin>>copies;
  issued=0;
  cout<<"\nEnter the Cost of book:-";
  cin>>cost;
  cout<<"\nYour Book id:-"<<bkno;

}
void book::disp()
{
  cout<<"\t"<<"\n"<<"Book Details:-";
  cout<<"\n"<<"Bookno"<<"|"<<"Book"<<"|"<<"Author"
  <<"|"<<"Publisher"<<"|"<<"Copies"<<"|"<<"Issued"<<"\t|Cost";
  cout<<"\n|"<<bkno<<"\t|"<<bname<<"\t|"<<auth<<"\t|"<<publ<<"\t|"<<copies
  <<"\t|"<<issued<<"\t|"<<cost;

}
void read1()
{  customer C;
    C.readit();
   ofstream ofile1;
   ofile1.open("cust1.dat",ios::app|ios::binary);
   ofile1.write((char*)&C,sizeof(C));
     cout<<"\nCustomer record created....";
     ofile1.close();
     return;
}
void read2()
{ book B;
  B.read();
  ofstream ofile2;
  ofile2.open("book1.dat",ios::app|ios::binary);
   ofile2.write((char*)&B,sizeof(B));
   cout<<"\nBook record created....";
   ofile2.close();
   return;
}
void del()
{  customer C2;
   int cid,flag=0;
   ifstream ifile;
   ifile.open("cust1.dat",ios::binary);
   ofstream ofile;
   ofile.open("temp.dat",ios::binary);
   if(!ifile)
   { cout<<"Unable to open file....press any key to continue !";
     getch();
     exit(0);
   }
   cout<<"Enter The customer id to be deleted:";
   cin>>cid;
   while( ifile.read((char*)&C2,sizeof(C2)))
   {

     if(cid==C2.cust())
      { flag=1;
	cout<<"Record deleted.....";
      }
     else
	ofile.write((char*)&C2,sizeof(C2));
   }
   if(flag==0)
    cout<<"Such a record does not exist..!";
   ifile.close();
   ofile.close();
   remove("cust1.dat");
   rename("temp.dat","cust1.dat");
}
void customer::modify1()
{ cout<<"\nName="<<name;
   cout<<"_________________________";
  cout<<"\nAddress="<<address;
   cout<<"_________________________";
  cout<<"\nSex="<<s;
   cout<<"_________________________";
  cout<<"\nPhoneno="<<phone;
   cout<<"_________________________";
  cout<<"\nEnter new details:";
  char n[20],ad[40],se;
  int p;
  cout<<"\nEnter new name(Enter '.'to retain the old name):-";
  gets(n);
  cout<<"\nEnter new address(Enter '.'to retain the old address):-";
  gets(ad);
  cout<<"\nEnter new sex(M/F)(Enter '0'to retain the old sex):-";
  cin>>se;
  cout<<"Enter new phoneno(Enter '-1'to retain the old phoneno):-";
  cin>>p;
  if(strcmp(n,".")!=0)
    strcpy(name,n);
  if(strcmp(ad,".")!=0)
    strcpy(address,ad);
  if(se!=0)
    s=se;
  if(p!=-1)
     phone=p;
}
void modify()
{  int cuid;
   customer C3;
   char found='f';
   long pos;
  fstream ifile;
  ifile.open("cust1.dat",ios::in|ios::out|ios::binary);
   if(!ifile)
   { cout<<"Unable to open file...";
     getch();
     exit(0);
   }
  cout<<"Enter the customer id to be modified:";
  cin>>cuid;
  while(ifile)
  { pos=ifile.tellg();
    ifile.read((char*)&C3,sizeof(C3));
    if(C3.cust()==cuid)
    {  C3.modify1();
       ifile.seekg(pos);
       ifile.write((char*)&C3,sizeof(C3));
       found='t';
       break;
    }
  }
   if(found=='f')
     cout<<"Record not found...!";
     ifile.close();
}
void book::modify2()
{ cout<<"\nBookName="<<bname;
  cout<<"_________________________";
  cout<<"\nAuthors Name="<<auth;
  cout<<"_________________________";
  cout<<"\npublishers name="<<publ;
   cout<<"_________________________";
  cout<<"\nno of copies"<<copies;
   cout<<"_________________________";
  cout<<"\nno of books issued"<<issued;
   cout<<"_________________________";
  cout<<"\ncost="<<cost;
   cout<<"_________________________";
  cout<<"\nEnter new details:-";

  char n[20],ad[20],se[20];
  int p,i,c;
  cout<<"\nEnter new Book Name(Enter '.'to retain old Book Name)";
  gets(n);
  cout<<"\nEnter new Authors Name(Enter '.'to retain old Authors Name)";
  gets(ad);
  cout<<"\nEnter new Publishers Name(Enter '.'to retain old Publishers Name)";
  cin>>se;
  cout<<"\nEnter new no of copies(Enter '-1'to retain the old no of copies)";
  cin>>p;
  //cout<<"\nEnter new no of books issued(Enter '-1'to retain the old no of books issued)";
  //cin>>i;
  cout<<"\nEnter new cost(Enter '-1'to retain old cost)";
  cin>>c;
  if(strcmp(n,".")!=0)
    strcpy(bname,n);
  if(strcmp(ad,".")!=0)
    strcpy(auth,ad);
  if(strcmp(se,".")!=0)
    strcpy(publ,se);
  if(p!=-1)
     copies=p;
  //if(i!=-1)
    //issued=i;
  if(c!=-1)
    cost=c;
}
void modify3()
{  int bono;
   char found='f';
   long pos;
   book B1;
  fstream ifile;
  ifile.open("book1.dat",ios::in|ios::out|ios::binary);
   if(!ifile)
   { cout<<"Unable to open file....!";
     getch();
     exit(0);
   }
  cout<<"Enter the Book no to be modified:";
  cin>>bono;
  while(ifile)
  { pos=ifile.tellg();
    ifile.read((char*)&B1,sizeof(B1));
    if(B1.b()==bono)
    {  B1.modify2();
       ifile.seekg(pos);
       ifile.write((char*)&B1,sizeof(B1));
       found='t';
       break;
    }
  }
   if(found=='f')
    {cout<<"Record not found...!";
    }
     ifile.close();
}
void del1()
{  int bno,flag=0;
   ifstream ifile;
   book B;
   ifile.open("book1.dat",ios::binary);
   ofstream ofile;
   ofile.open("temp.dat",ios::binary);
   cout<<"Enter The book no to be deleted:";
   cin>>bno;
   while(ifile.read((char*)&B,sizeof(B)))
   {
     if(B.b()==bno)
      { flag=1;
	cout<<"Record deleted....!";
      }
     else
	ofile.write((char*)&B,sizeof(B));
   }
   if(flag==0)
    cout<<"Such a record does not exist....";
   ifile.close();
   ofile.close();
   remove("book1.dat");
   rename("temp.dat","book1.dat");
}
void Transaction::re()
{
  cout<<"\nEnter customer id:";
  cin>>cutid;
  cout<<"\nEnter Book Id:";
  cin>>booid;
}
void Transaction::dis()
{  //char date[9];
   //_strdate(date);
   cout<<"\n|"<<cutid<<"\t|"<<booid<<"\t|"<<"\t|"<<trans;
}
void issue()
{  Transaction T; int  flag=0,flag2=0,flag3=0;
   customer C;
   long pos,pos1;
   book B;
    int st,bn;
   T.re();
    int chk;
   fstream ifile1;
   ifile1.open("cust1.dat",ios::binary|ios::in|ios::out);
   fstream ifile2;
   ifile2.open("book1.dat",ios::binary|ios::in|ios::out);
   ofstream ifile3;
   ifile3.open("trans.dat",ios::binary|ios::app);
    while(ifile1.read((char*)&C,sizeof(C)))
    { if(C.cust()==T.ct())
       {  cout<<"\nCustomer Exists.";
	  flag=1;
	  st=C.r();
	  break;
       }
    }
    ifile1.close();
    if(flag==1)
    {   if(st==0)
	{
	  while(!ifile2.eof())
	  { pos=ifile2.tellg();
	    ifile2.read((char*)&B,sizeof(B));
		if(T.bk()==B.b())
		{ flag2=1;
		  chk=B.checkissue();
		  if(chk!=-1)
		    { B.changeissue(chk);
		      ifile2.seekg(pos);
		      ifile2.write((char*)&B,sizeof(B));
		      cout<<"\nBook is issued.";
		      T.t("issued");
		      ifile3.write((char*)&T,sizeof(T));
		      flag3=1;
		    }
		  else
		    cout<<"\nNo copies available";
		  break;
		}
	    }
	    if(flag2!=1)
	       cout<<"NO such book exist";
	  }
	   else
	     cout<<"Already issued a book";
   }
   else
    cout<<"no such customer";
    ifile3.close();
    ifile2.close();

    if(flag3==1)
     {
      ifile1.open("cust1.dat",ios::binary|ios::in|ios::out);
      while(!ifile1.eof())
      { pos1=ifile1.tellg();
	ifile1.read((char*)&C,sizeof(C));
	if(C.cust()==T.ct())
	{ bn = T.bk();
	  C.changetoken();
	  C.booktaken(bn);
	  //C.bid();
	  //C.addtoken();
	  ifile1.seekg(pos1);
	  ifile1.write((char*)&C,sizeof(C));
	}
      }
      ifile1.close();
      }
}
void ret()
{  Transaction T;
   customer C; long pos,pos1;
   book B;   int st,br,cn;
    cout<<"Enter the Customer No:";
    cin>>cn;
   //T.re();
    int chk,flag=0;
   fstream ifile1;
   ifile1.open("cust1.dat",ios::binary|ios::in|ios::out);
   fstream ifile2;
   ifile2.open("book1.dat",ios::binary|ios::in|ios::out);
   ofstream ifile3;
   ifile3.open("trans.dat",ios::binary|ios::app);
    while(ifile1.read((char*)&C,sizeof(C)))
    { if(C.cust()==cn)
       {  cout<<"\nCustomer Exists.";
	  flag=1;
	  br = C.retbt();
	  break;
       }
    }
    ifile1.close();
    if(flag==1)
    {
       while(!ifile2.eof())
       { pos=ifile2.tellg();
	 ifile2.read((char*)&B,sizeof(B));
	  if(B.b()==br)
	  {
	    chk=B.issue();
	    B.changei(chk);
	    ifile2.seekg(pos);
	    ifile2.write((char*)&B,sizeof(B));
	    cout<<"\nBook is returned.";
	    T.tran(cn,br);
	    T.t("return");
	    ifile3.write((char*)&T,sizeof(T));
	    break;
	   }
	 }
     }
     else

       cout<<"No such customer";
	ifile2.close();
	ifile3.close();

      if(flag==1)
      {
	ifile1.open("cust1.dat",ios::binary|ios::in|ios::out);
	while(!ifile1.eof())
	 { pos1=ifile1.tellg();
	   ifile1.read((char*)&C,sizeof(C));
	   if(C.cust()==cn)
	     { C.changetoken();
	       C.booktaken(0);
	       ifile1.seekg(pos1);
	       ifile1.write((char*)&C,sizeof(C));
	       break;
	     }
	 }
       }

}
void dispcus()
{int cu;
 customer C;int flag=0;
 ifstream ifile;
 ifile.open("cust1.dat",ios::binary);
 cout<<"Enter the customer i.d to be displayed";
 cin>>cu;
 while(ifile.read((char*)&C,sizeof(C)))
 {
  if(C.cust()==cu)
   { flag=1;
     cout<<"\t"<<"\n"<<"Customer Details=";
     cout<<"\nCustomerId"<<"\tName"<<"\tAddress"<<"\t\tSex"
     <<"\tFee"<<"\tPhone"<<"\t Book Taken";
     cout<<"\n";
     C.report();
     break;
   }
 }
  if(flag==0)
   cout<<"No Such Customer exist";

 ifile.close();
}
void dispbook()
{int bo,flag=0;
 book B;
 ifstream ifile;
 ifile.open("book1.dat",ios::binary);
 cout<<"Enter The Book i.d to be displayed";
 cin>>bo;
   while(ifile.read((char*)&B,sizeof(B)))
 {
  if(B.b()==bo)
  { flag=1;
    cout<<"BookNo"<<"\t"<<"Book"<<"\t"<<"Author"<<"\t"
	<<"Publisher"<<"\t"<<"copies"<<"\t"<<"Issue"<<"\t"<<"Cost";
    cout<<"\n";
    B.rep();
    break;
  }
 }
 if(flag==0)
  cout<<"No such Book exist";
 ifile.close();
}
void discall()
{ ifstream ifile;
  customer C;
  ifile.open("cust1.dat",ios::binary);
   cout<<"\t"<<"\n"<<"Customer Details=";
    cout<<"\nCustomerId"<<"\tName"<<"\tAddress"<<"\t\tSex"
    <<"\tFee"<<"\tPhone"<<"\tBook Taken";
  while(ifile.read((char*)&C,sizeof(C)))
  { cout<<"\n";
    C.report();
  }
  ifile.close();
}

void disball()
{ ifstream ifile;
  book B;
  ifile.open("book1.dat",ios::binary);
  cout<<"BookNo"<<"\t"<<"Book"<<"\t"<<"Author"<<"\t"<<"Publisher"
  <<"\t"<<"copies"<<"\t"<<"Issue"<<"\t"<<"Cost";
  while(ifile.read((char*)&B,sizeof(B)))
  {cout<<"\n";
   B.rep();
  }
  ifile.close();
}
void distall()
{ ifstream ifile;
  Transaction T;
  ifile.open("trans.dat",ios::binary);
  cout<<"\t"<<"\n"<<"Transaction=";
  cout<<"\n|"<<"CustomerId"<<"\t|BookID"<<"\t|Transaction Type";

  while(ifile.read((char*)&T,sizeof(T)))
  { cout<<"\n";
    T.dis();
  }
  ifile.close();
}
void intro()
{
	clrscr();
	cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
	cout<<"\t"<<"\n|LIBRARY MANAGEMENT SYSTEM                             |";
	cout<<"\n\n|MADE BY : ABHIRAM R PAI,JEFF CHANDY AND VISHNU DHANPAL|";
	cout<<"\n|Press any key to continue.....                        |";
	cout<<"\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
	getch();
}
void main()
{  intro();
   clrscr();
   customer C;
   book B;
   Transaction T;
   int ch,ch1,ch2,ch3,ch4,ch5,ch6;
 do
  { clrscr();
   cout<<"\n*******************************************";
   cout<<"\nLibrary Management";
   cout<<"\n1.Customer";
   cout<<"\n2.Book";
   cout<<"\n3.Transaction";
   cout<<"\n4.Report";
   cout<<"\n5.Exit";
   cout<<"\n******************************************";
   cout<<"\nEnter Choice";
   cin>>ch;
   switch(ch)
    { case 1:clrscr();
	      do
	      {cout<<"\n***********************";
	       cout<<"\nCustomer Menu";
	       cout<<"\n1.Create";
	       cout<<"\n2.Delete";
	       cout<<"\n3.Modify";
	       cout<<"\n4.Go back";
	       cout<<"\n***********************";
	       cout<<"\nEnter your choice";
	       cin>>ch1;
	       switch(ch1)
	       { case 1:read1();
			break;
		 case 2:del();
			break;
		 case 3:modify();
			break;
		 case 4:break;
		 default:cout<<"Wrong Case no";
			exit(0);
	       }
	      }while(ch1!=4);
		break;
      case 2:clrscr();
	     do
	     {cout<<"\n***********************";
	      cout<<"\nBook Details";
	      cout<<"\n1.Create";
	      cout<<"\n2.Delete";
	      cout<<"\n3.Modify";
	      cout<<"\n4.Go back";
	      cout<<"\n***********************";
	      cout<<"\nEnter your choice";
	      cin>>ch2;
	      switch(ch2)
	      { case 1:read2();
		       break;
		case 2:del1();
		       break;
		case 3:modify3();
		       break;
		case 4:break;
		default:cout<<"Wrong Case no";
			exit(0);
	      }
	     }while(ch2!=4);
	       break;
      case 3:clrscr();
	     do
	     {cout<<"\n***********************";
	      cout<<"\n"<<"\t"<<"Transation Menu=";
	      cout<<"\n1.Issue";
	      cout<<"\n2.Return";
	      cout<<"\n3.Back";
	      cout<<"\n***********************";
	      cout<<"\nEnter Your Choice";
	      cin>>ch3;
	      switch(ch3)
	      { case 1:issue();
		       break;
		case 2:ret();
			break;
		case 3:break;
		  default:cout<<"Wrong Case no";
		       exit(0);
	      }
	     }while(ch3!=3);
	      break;
      case 4: clrscr();
	     do
	     {cout<<"\n***********************";
	      cout<<"\n"<<"\t"<<"Report Menu";
	      cout<<"\n1.Customer";
	      cout<<"\n2.Book";
	      cout<<"\n3.Transaction";
	      cout<<"\n4.Back";
	      cout<<"\n***********************";
	      cout<<"\nEnter Your Choice";
	      cin>>ch4;
	      switch(ch4)
	      {case 1:clrscr();
		     do
		     {cout<<"\n***********************";
		      cout<<"\nCustomer Menu";
		      cout<<"\n1.Individual";
		      cout<<"\n2.All";
		      cout<<"\n3.Back";
		      cout<<"\n***********************";
		      cout<<"\nEnter your choice";
		      cin>>ch5;
		      switch(ch5)
		      {case 1:dispcus();
			      break;
		       case 2:discall();
			      break;
		       case 3:break;
		       default:cout<<"Wrong Case no";
			       exit(0);
			       break;
		      }
		     }while(ch5!=3);
		      break;
	       case 2:clrscr();
		     do
		     {cout<<"\n***********************";
		      cout<<"\nBook Menu";
		      cout<<"\n1.Individual";
		      cout<<"\n2.All";
		      cout<<"\n3.Back";
		      cout<<"\n***********************";
		      cout<<"\nEnter your choice";
		      cin>>ch6;
		      switch(ch6)
		      {case 1:dispbook();
			      break;
		       case 2:disball();
			      break;
		       case 3:break;

		       default:cout<<"Wrong Case no";
			       exit(0);
			       break;
		      }
		     }while(ch6!=3);
		      break;
	       case 3:clrscr();
		      distall();
		      break;
	       case 4:break;
	       default:cout<<"Wrong Case no";
		       exit(0);
		       break;
	      }
	     }while(ch4!=4);
	      break;
      case 5:exit(0);
      default:cout<<"Wrong Case no";
	      exit(0);
    }

  }while(ch!=5);
    getch();
}
