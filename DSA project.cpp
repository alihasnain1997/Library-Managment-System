#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<time.h>
#include <iomanip>
using namespace std;
class node{
	int serial;
	string name;
	int price;
	node *next;
	public:
	node(){
			serial=0;
			name=' ';
			price=0;
			next=NULL;
	}
	void setserial(int x){
		serial=x;
	}
	int getserial(){
		int d=serial;
		return d;
	}
	void setname(string x){
		name=x;
	}
	string getname(){
		string d=name;
		return d;
	}
	void setprice(int x){
		price=x;
	}
	int getprice(){
		int d=price;
		return d;
	}
	
	void setnext(node *n){
		next=n;
	}
	node *getnext(){
		node *n=next;
		return n;
	}
};
class foodsystem
{
	node *head;
	public:
		
		foodsystem(){
			head=NULL;
		}
		void addfoodlist()
		{
			fstream file;
		   	file.open("foodlist.txt",ios::app);
			int s,p;
			string n;
			cout<<"Enter food serial:";
			cin>>s;
			cout<<"Enter food Name:";
			cin>>n;
			cout<<"Enter food price:";
			cin>>p;
			node *f=food_search(s);
			if(f)
			{
				cout<<"Food Already Add.Plz Use Different serial for Add food."<<endl<<endl;
			}
			else
			{
			
			  file<<s<<"[serial]"<<endl;
			  file<<n<<"[Name]"<<endl;
			  file<<p<<"[Price]"<<endl;
			  file<<"---------------------------------------------------------------------------"<<endl;
			  cout<<endl;
			  file.close();
			  cout<<"Food Add Successfully."<<endl<<endl;
		    }
		}
		void readfoodlist()
		{
		    string w;
		    int x;
		    fstream file;
		    file.open("foodlist.txt",ios::in);
		    if(file.fail())
		    {
			   cout<<"fail"<<endl;
		    }
	    	while(!file.eof())
	    	{
	    	
	    		node *temp=new node();
		    	getline(file,w,'[');
		    	if(w=="\0")
		    	{
		    		break;
				}
				istringstream(w)>>x;
		    	temp->setserial(x);
		    	getline(file,w);
			    getline(file,w,'[');
			    temp->setname(w);
			    getline(file,w);
			    getline(file,w,'[');
			    istringstream(w)>>x;
			    temp->setprice(x);
			    getline(file,w);
			    getline(file,w);
			    if(head==NULL)
			    {
				     head=temp;
				     
			    }
			    else
			    {
			        node *temp2=head;
			        while(temp2->getnext()!=NULL)
					{
					  temp2=temp2->getnext();
			    	}
				    temp2->setnext(temp);
			    }
			   
	    	}
	    	file.close();
		}
		node *food_search(int s)
		{
			node *flag=0;
			readfoodlist();
			node *temp=head;
			while(temp!=NULL)
			{
				if(temp->getserial()==s)
				{
					flag=temp;
					break;
				}
				temp=temp->getnext();
			}
			return flag;
		}
		void fooditem_delete()
		{
			int s;
			cout<<"Enter Food Serial:";
			cin>>s;
		    node *f=food_search(s);
			fstream file;
		    file.open("deleteitem.txt",ios::app);
			if(f)
			{
				node *temp=head;
			    while(temp!=NULL)
			    {
				  if(temp->getserial()==s)
				  {
					temp=temp->getnext();
					if(temp==NULL)
				    {
				  	  break;
				    }
				  }
				  file<<temp->getserial()<<"[serial]"<<endl;
		    	  file<<temp->getname()<<"[Name]"<<endl;
		    	  file<<temp->getprice()<<"[Price]"<<endl;
		    	  file<<"------------------------------------------------------------"<<endl;
				  temp=temp->getnext();
			    }
			    file.close();
				remove("foodlist.txt");
			    rename("deleteitem.txt","foodlist.txt");
			    cout<<"food item Delete successfully"<<endl<<endl;
			}
			else
			{
				cout<<"food of this serial Not exist"<<endl<<endl;
			}	
		}
		void display()
		{
			readfoodlist();
			node *temp=head;
			cout<<endl<<endl;
			cout<<"	___________________________________________"<<endl;
			cout<<"	| Food No |        Food Name   |   Price  |"<<endl;
			while(temp!=NULL){
				cout<<"	-------------------------------------------"<<endl;
				cout<<"	|"<<setw(5)<<temp->getserial()<<"    |"<<setw(12)<<temp->getname()<<"     |"<<setw(7)<<temp->getprice()<<"   |"<<endl;
				temp=temp->getnext();
			}
			cout<<"	___________________________________________"<<endl<<endl<<endl;		
		}
	};
class node_order
{
	int order_id;
	int order_serial;
	string order_name;
	int order_price;
	int order_quantity;
	int order_totprice;
	int order_table;
	string time;
	node_order *next;
	public:
	node_order(){
		    order_id=0;
			order_serial=0;
			order_name=' ';
			order_price=0;
			order_quantity=0;
			order_totprice=0;
			order_table=0;
			time=' ';
			next=NULL;
	}
	void set_order_id(int x){
		order_id=x;
	}
	int get_order_id(){
		int d=order_id;
		return d;
	}
	void set_order_serial(int x){
		order_serial=x;
	}
	int get_order_serial(){
		int d=order_serial;
		return d;
	}
	void set_order_name(string x){
		order_name=x;
	}
	string get_order_name(){
		string d=order_name;
		return d;
	}
	void set_order_price(int x){
		order_price=x;
	}
	int get_order_price(){
		int d=order_price;
		return d;
	}
	void set_order_quantity(int x){
		order_quantity=x;
	}
	int get_order_quantity(){
		int d=order_quantity;
		return d;
	}
	void set_order_totprice(int x){
		order_totprice=x;
	}
	int get_order_totprice(){
		int d=order_totprice;
		return d;
	}
	void set_order_table(int x){
		order_table=x;
	}
	int get_order_table(){
		int d=order_table;
		return d;
	}
	void set_order_time(string x){
		time=x;
	}
	string get_order_time(){
		string d=time;
		return d;
	}
	void setordernext(node_order *n){
		next=n;
	}
	node_order *getordernext(){
		node_order *n=next;
		return n;
	}
};
class order:public foodsystem
{
	node_order *head;
	public:
		   order(){
			head=NULL;
		   }
		   void takeorder()
		   {
		   	 int t,q,s;
		   	 char time[9];
		   	 cout<<"Enter table NO:";
		   	 cin>>t;
		   	 cout<<"Place your order:";
		   	 cin>>s;
		   	 cout<<"Enter Quantity:";
		   	 cin>>q;
		   	 node *f=food_search(s);
		   	 if(f)
		   	 {
		   	 	int a,w,id=0;
		   	 	string d;
		   	 	a=f->getprice()*q;
		   	 	cout<<"choice food "<<f->getname()<<" its total price is:"<<a<<endl;
		   	 	cout<<"for confirm order press 1:";
		   	    cin>>w;
		   	    if(w==1)
		   	    {
					fstream file1;
                    file1.open("orderid.txt",ios::in);
                    file1>>id;
                    file1.close();
                    id=id+1;
                    fstream file;
                    file.open("orderlist.txt",ios::app);
		   	        file<<id<<"[order-id]"<<endl;
		   	        file<<s<<"[food-serial]"<<endl;
		   	        file<<f->getname()<<"[food-name]"<<endl;
		   	        file<<f->getprice()<<"[Price]"<<endl;
		   	        file<<q<<"[Quantity]"<<endl;
		   	        file<<a<<"[total-price]"<<endl;
		   	        file<<t<<"[table NO]"<<endl;
		   	        _strtime(time);
		   	        file<<time<<"[order-time]"<<endl;
		   	        file<<"---------------------------------------------------------------------------------------------------------------------------------"<<endl;
                    file1.open("orderid.txt",ios::out);
                    file1<<id;
                    cout<<"Order placed Successfully thanks."<<endl<<endl;
				}
				else
				{
					cout<<"order cancel"<<endl<<endl;
				}
		   	    
			 }
			 else
			 {
			 	cout<<"Food serial not exist in foodlist."<<endl<<endl;
			 }
		   }
		   node_order *orderread(string f)
		   {
		   	string w;
		   	int x;
		    fstream file;
		    file.open(f.c_str(),ios::in);
		    if(file.fail())
		    {
			   cout<<"fail"<<endl;
		    }
	    	while(!file.eof())
	    	{
	    	
	    		node_order *temp=new node_order();
		    	getline(file,w,'[');
		    	if(w=="\0")
		    	{
		    		break;
				}
				istringstream(w)>>x;
		    	temp->set_order_id(x);
		    	getline(file,w);
		    	getline(file,w,'[');
		    	istringstream(w)>>x;
		    	temp->set_order_serial(x);
		    	getline(file,w);
		    	getline(file,w,'[');
		    	temp->set_order_name(w);
		    	getline(file,w);
		    	getline(file,w,'[');
		    	istringstream(w)>>x;
		    	temp->set_order_price(x);
		    	getline(file,w);
		    	getline(file,w,'[');
		    	istringstream(w)>>x;
		    	temp->set_order_quantity(x);
		    	getline(file,w);
		    	getline(file,w,'[');
		    	istringstream(w)>>x;
		    	temp->set_order_totprice(x);
		        getline(file,w);
		    	getline(file,w,'[');
		    	istringstream(w)>>x;
		    	temp->set_order_table(x);
		    	getline(file,w);
		    	getline(file,w,'[');
		    	temp->set_order_time(w);
		    	getline(file,w);
		    	getline(file,w);
			    if(head==NULL)
			    {
				     head=temp;
			    }
			    else
			    {
			        node_order *temp2=head;
			        while(temp2->getordernext()!=NULL)
					{
					  temp2=temp2->getordernext();
			    	}
				    temp2->setordernext(temp);
			    }
			   
	    	}
	    	file.close();
	    	return head;
		   }
		   node_order *search_orderid(int id,string f)
		   {
		   	    node_order *flag=0;
			    node_order *temp=orderread(f);
			    while(temp!=NULL)
		    	{
				  if(temp->get_order_id()==id)
				  {
					flag=temp;
					break;
				  }
				temp=temp->getordernext();
			}
			return flag;
		   	
		   }
		   void deleteorder(int id,string f)
		   {
			    fstream file;
		        file.open("deleteorder.txt",ios::app);
				node_order *temp=head;
			    while(temp!=NULL)
			    {
				    if(temp->get_order_id()==id)
				    {
					   temp=temp->getordernext();
					   if(temp==NULL)
				       {
				  	     break;
				       }
				    }
				    file<<temp->get_order_id()<<"[order-id]"<<endl;
		   	        file<<temp->get_order_serial()<<"[food-serial]"<<endl;
		   	        file<<temp->get_order_name()<<"[food-name]"<<endl;
		   	        file<<temp->get_order_price()<<"[Price]"<<endl;
		   	        file<<temp->get_order_quantity()<<"[Quantity]"<<endl;
		   	        file<<temp->get_order_totprice()<<"[total-price]"<<endl;
		   	        file<<temp->get_order_table()<<"[table NO]"<<endl;
		   	        file<<temp->get_order_time()<<"[order-time]"<<endl;
		   	        file<<"---------------------------------------------------------------------------------------------------------------------------------"<<endl;
		   	  	    temp=temp->getordernext();
			    }
			    file.close();
				remove(f.c_str());
			    rename("deleteorder.txt",f.c_str());
			}
			
		  
		   void display(string f)
		   {
		   	    
			    node_order *temp=orderread(f);
			    cout<<endl<<endl;
			    cout<<"_____________________________________________________________________________"<<endl;
			    cout<<"|order id|Food Serial|  Food   Name |Price|Quantity|Total Bill|table|  Date  |"<<endl;
			    while(temp!=NULL){
			    cout<<"|----------------------------------------------------------------------------|"<<endl;
			    cout<<"|"<<setw(5)<<temp->get_order_id()<<"   |"<<setw(6)<<temp->get_order_serial()<<"     |"<<setw(12)<<temp->get_order_name()<<"  |"
				    <<setw(4)<<temp->get_order_price()<<" |"<<setw(5)<<temp->get_order_quantity()<<"   |"<<setw(7)<<temp->get_order_totprice()<<"   |"
					<<setw(3)<<temp->get_order_table()<<"  |"<<temp->get_order_time()<<"|"<<endl;
				    temp=temp->getordernext();
		    	}
		    	
		    	cout<<"|____________________________________________________________________________|"<<endl<<endl<<endl;
		   }
		  
	
};
class servedorder:public order
{
	public:
		   void addservedlist()
		   {
		   	  int id;
		   	  char time[9];
		   	  cout<<"Enter order id:";
		   	  cin>>id;
		   	  node_order *f=search_orderid(id,"orderlist.txt");
		   	  if(f)
		   	  {
		   	  	fstream file;
		        file.open("servedlist.txt",ios::app);
		        file<<f->get_order_id()<<"[order-id]"<<endl;
		   	    file<<f->get_order_serial()<<"[food-serial]"<<endl;
		   	    file<<f->get_order_name()<<"[food-name]"<<endl;
		   	    file<<f->get_order_price()<<"[Price]"<<endl;
		   	    file<<f->get_order_quantity()<<"[Quantity]"<<endl;
		   	    file<<f->get_order_totprice()<<"[total-price]"<<endl;
		   	    file<<f->get_order_table()<<"[table NO]"<<endl;
		   	    _strtime(time);
		   	    file<<time<<"[order-date]"<<endl;
		   	    file<<"---------------------------------------------------------------------------------------------------------------------------------"<<endl;
		   	  	deleteorder(id,"orderlist.txt");
		   	  	cout<<"Order served."<<endl<<endl;
			  }
			  else
			  {
			  	cout<<"Not Any Order of this Id."<<endl<<endl;
			  }
		   	  
		   }
};
class cash:public servedorder
{
	node_order *head;
	public:
		  void cashlist()
		  {
		  	int id;
		  	char time[9];
		  	cout<<"Enter Order id:";
		  	cin>>id;
		    node_order *f=search_orderid(id,"servedlist.txt");
		    if(f)
		    {
		    	fstream file;
		        file.open("cashlist.txt",ios::out);
		        file<<f->get_order_id()<<"[order-id]"<<endl;
		   	    file<<f->get_order_serial()<<"[food-serial]"<<endl;
		   	    file<<f->get_order_name()<<"[food-name]"<<endl;
		   	    file<<f->get_order_price()<<"[Price]"<<endl;
		   	    file<<f->get_order_quantity()<<"[Quantity]"<<endl;
		   	    file<<f->get_order_totprice()<<"[total-price]"<<endl;
		   	    file<<f->get_order_table()<<"[table NO]"<<endl;
		   	    _strtime(time);
		   	    file<<time<<"[order-time]"<<endl;
		   	    file<<"---------------------------------------------------------------------------------------------------------------------------------"<<endl;
		   	  	deleteorder(id,"servedlist.txt");
		   	  	cout<<"Bill Recived."<<endl<<endl;
			}
			else
			{
				cout<<"Order id not Exit in servedlist."<<endl<<endl;
			}
		  }
		  void totalcash()
		  {
		  	node_order *temp=orderread("cashlist.txt");
		  	int tot_cash=0;
		  	while(temp!=NULL){
		  		
			   tot_cash=tot_cash+temp->get_order_totprice();
			   temp=temp->getordernext();
				
			}
			cout<<"Total cash:"<<tot_cash<<endl<<endl;
		  	
		  }
};
int interface()
{
	int c;
	cout<<"=====>  1. Food List"<<endl;
	cout<<"=====>  2. Admin Panel"<<endl;
	cout<<"=====>  3. Exit"<<endl<<endl;
	cout<<"Press According your choice:";
	cin>>c;
	return c;
}
int Admin()
{
	int n;
	cout<<" 1. Add Food"<<endl;
	cout<<" 2. Delete Food"<<endl;
	cout<<" 3. Served order"<<endl;
	cout<<" 4. Recieve Bill"<<endl;
	cout<<" 5. Instant Foodlist"<<endl;
	cout<<" 6. Instant Order Preview"<<endl;
	cout<<" 7. Instant Served Orderlist"<<endl;
	cout<<" 8. Instant Recieved Bills"<<endl;
	cout<<" 9. Total Cash"<<endl;
	cout<<" 0. Main Menu"<<endl;
	cout<<"                       Press According Choice:";
	cin>>n;
	return n;
}
int main()
{
    mainpro:
    int c=interface();
    if(c==1)
    {
	    foodsystem f;
    	f.display();
    	order o;
    	o.takeorder();
    	goto mainpro;
    }
    else if(c==2)
    {
	     int p,n,s=-1;	
		 cout<<"Enter Password:";
		 cin>>p;
		 if(p==888)
		 {
			while(s!=0)
			{
			    n=Admin();
			   	if(n==1)
			    {
			   	    foodsystem f;
			   	  	f.addfoodlist();
				}
				else if(n==2)
				{
				    foodsystem f;
				    f.fooditem_delete();
				}
				else if(n==3)
				{
				    servedorder s;
				    s.addservedlist();
				}
				else if(n==4)
				{
					cash b;
					b.cashlist();
				}
				else if(n==5)
				{
					foodsystem f;
					f.display();
				}
				else if(n==6)
				{
					order o;
					o.display("orderlist.txt");
				}
				else if(n==7)
				{
					order o;
					o.display("servedlist.txt");
				}
				else if(n==8)
				{
					order o;
					o.display("cashlist.txt");
				}
				else if(n==9)
				{
					cash b;
					b.totalcash();
				}
				else if(n==0)
				{
					s=0;
				}
			}
		 }
		 else
		 {
			cout<<"Inncorrect Password."<<endl<<endl;
		 }
		goto mainpro;    
	}
	
}


