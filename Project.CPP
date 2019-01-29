#include<iostream>
#include<string.h>
#include<fstream>
#include<conio.h>
#include <iomanip>
using namespace std;

void logo();
int login();

//********************************************************************************************************************
//            Client Class
//
//********************************************************************************************************************

class Client
{
	friend class BST;
	private:
		
		int ID;
		char Name[20];			//Name of Person
		char CNIC[20];			//CNIC of that Person
		char Phone[20];			//Phone no of that person
		char Email[20];			//Email of that person
		char Address[50];			//Address of that person
		
		Client* left;
		Client* right;	
	public:
		bool add_client();
		void cin_client();
		void cout_client();
		int search_client();
		void display_client();
		void show_client();
		void modify_client();
		void cin_modify_client();
};


//********************************************************************************************************************
//            Room Class
//
//********************************************************************************************************************

class room
{
	friend class BST;
	private:
		
		int ID;
		int Room;				//Room of Person
		char Name[20];			//Name of Person
		char CNIC[20];			//CNIC of that Person
		char Phone[20];			//Phone no of that person
		char Email[20];			//Email of that person
		char Address[50];			//Address of that person
		
		room* left;
		room* right;	
	public:
		bool add_room();
		void cin_room();
		void cout_room();
		int search_room();
		void display_room();
		void show_room();
		void cin_modify_room();
		void modify_room();
};


//********************************************************************************************************************
//            BST Class
//
//********************************************************************************************************************

class BST
{
	private:
		Client* root;		//Pointer Object
		room* root1;
	public:
		BST()				//Constructor
		{
			root=0;
			root1=0;
		}
		~BST()				//Destructor
		{
			destroy(root);
			root1=0;
			root=0;
		}		
		void destroy(Client* t)
		{
			if(t)
			{
				destroy(t->left);
				destroy(t->right);
				delete t;
				t=0;
			}
		}
		int login();
		bool add();
		void search_client();
		void main_menu();
		void client_menu();
		void room_menu();
		void display();
		void complaint();
		bool add_room();
		void menu();
		void calculate();		
};

//********************************************************************************************************************
//            Login
//
//********************************************************************************************************************

int login()
{
	int i = 0,username_key,password_key,result;
	char temp_pass[20], password[20],username[20],fusername[20],fpassword[20];
	
	
	cout<<"please enter username : "<<endl;
	cin>>username;
	cout<<"please enter password : "<<endl;
	while ((temp_pass[i] = _getch())!='\0'){
		if (temp_pass[i] == 13){ // 13 is the ASCII of Enter
			break;
		}
		else if (temp_pass[i] == 8){ // 8 is the ASCII of BackSpace
		if (i != 0){
			cout<<"\b \b";
			i--;
		}
		else cout<<"\a";
		}
		else {
		cout<<"*";
		password[i] = temp_pass[i];
		i++;
		}
	}
	cout<<"\n";
	FILE *users=fopen("users.txt","r");
	fseek(users,0,0);
	while(!feof(users)){
	fscanf(users,"%s %s\n",&fusername,&fpassword);
	username_key=strcmp(username,fusername);
	password_key=strcmp(password,fpassword);
	if(username_key==0 && password_key==0){
		result=1;
		break;
	}
}
	if (username_key!=0 || password_key!=0){
	cout<<"\ninvalid username or password enterd \n";
	result=0;
	}
	fclose(users);	
	return result;
	
}


//********************************************************************************************************************
//            Main Menu
//
//********************************************************************************************************************

void BST::main_menu()
{
	int choice;
	while(choice!=5)
	{
		system("cls");
		cout<<"\n\n\n";
    	cout.put('\t').put(201).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(187);
		cout.put('\n').put('\t').put(186)<<"\t\t MAIN MENU \t      ";
		cout.put(186).put('\n').put('\t').put(186)<<"\t\t            \t      ";
		cout.put(186).put('\n').put('\t').put(186).put(196).put(196).put(196).put(196).put(196).put(196).put(196).put(196).put(196).put(196).put(196).put(196).put(196).put(196).put(196).put(196).put(196).put(196).put(196).put(196).put(196).put(196).put(196).put(196).put(196).put(196).put(196).put(196).put(196).put(196).put(196).put(196).put(196).put(196).put(196).put(196).put(196).put(186);
		cout.put('\n').put('\t').put(186)<<"\t  (1)   Client Menu \t      ";
		cout.put(186).put('\n').put('\t').put(186)<<"\t                      \t      ";
		cout.put(186).put('\n').put('\t').put(186)<<"\t  (2)   Room Menu \t      ";
		cout.put(186).put('\n').put('\t').put(186)<<"\t                   \t      ";
		cout.put(186).put('\n').put('\t').put(186)<<"\t  (3)   Food Menu  \t      ";
		cout.put(186).put('\n').put('\t').put(186)<<"\t                     \t      ";
		cout.put(186).put('\n').put('\t').put(186)<<"\t  (4)   Complaints  \t      ";
		cout.put(186).put('\n').put('\t').put(186)<<"\t\t\t\t      ";
		cout.put(186).put('\n').put('\t').put(186)<<"\t  (5)   EXIT  \t              ";
		cout.put(186).put('\n').put('\t').put(186)<<"\t\t\t\t      ";
		cout.put(186).put('\n').put('\t').put(200).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(188);
		cout<<"\n\n\t\tEnter Your Choice: ";
		cin>>choice;

		switch(choice)
		{
			case 1:	client_menu();
				break;
			case 2: room_menu();
				break;
			case 3:	menu();
				break;
			case 4: complaint();
				break;
			case 5: break;
			default:
				{
					cout<<"\n\n\t\t\tWrong choice.....!!!";
					cout<<"\n\t\t\tPress any key to continue....!!";
					getch();
				}
		}
		getch();
	}
}

//********************************************************************************************************************
//            Client Menu
//
//********************************************************************************************************************

void BST::client_menu()
{
	Client obj;
	int choice;
	while(choice!=5)
	{
		system("cls");
		cout<<"\n\n\n";
    	cout.put('\t').put(201).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(187);
		cout.put('\n').put('\t').put(186)<<"\t\t CLIENT MENU \t      ";
		cout.put(186).put('\n').put('\t').put(186)<<"\t\t            \t      ";
		cout.put(186).put('\n').put('\t').put(186).put(196).put(196).put(196).put(196).put(196).put(196).put(196).put(196).put(196).put(196).put(196).put(196).put(196).put(196).put(196).put(196).put(196).put(196).put(196).put(196).put(196).put(196).put(196).put(196).put(196).put(196).put(196).put(196).put(196).put(196).put(196).put(196).put(196).put(196).put(196).put(196).put(196).put(186);
		cout.put('\n').put('\t').put(186)<<"\t  (1)   Add Client    \t      ";
		cout.put(186).put('\n').put('\t').put(186)<<"\t                      \t      ";
		cout.put(186).put('\n').put('\t').put(186)<<"\t  (2)   Display Clients       ";
		cout.put(186).put('\n').put('\t').put(186)<<"\t                   \t      ";
		cout.put(186).put('\n').put('\t').put(186)<<"\t  (3)   Search Client         ";
		cout.put(186).put('\n').put('\t').put(186)<<"\t                     \t      ";
		cout.put(186).put('\n').put('\t').put(186)<<"\t  (4)   Modify Client Data    ";
		cout.put(186).put('\n').put('\t').put(186)<<"\t                     \t      ";
		cout.put(186).put('\n').put('\t').put(186)<<"\t  (5)   Exit to main menu     ";
		cout.put(186).put('\n').put('\t').put(186)<<"\t\t\t\t      ";
		cout.put(186).put('\n').put('\t').put(200).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(188);
		cout<<"\n\n\t\tEnter Your Choice: ";
		cin>>choice;

		switch(choice)
		{
			case 1:	add();
				break;
			case 2: obj.display_client();
				break;
			case 3: obj.search_client();
				break;
			case 4:	obj.modify_client();
				break;
			case 5:	break;
			default:
				{
					cout<<"\n\n\t\t\tWrong choice.....!!!";
					cout<<"\n\t\t\tPress any key to continue....!!";
					//getch();
				}
		}
	}
}

//********************************************************************************************************************
//            Room Menu
//
//********************************************************************************************************************
void BST::room_menu()
{
	room obj;
	int choice;
	while(choice!=5)
	{
		system("cls");
		cout<<"\n\n\n";
    	cout.put('\t').put(201).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(187);
		cout.put('\n').put('\t').put(186)<<"\t\t ROOM MENU \t      ";
		cout.put(186).put('\n').put('\t').put(186)<<"\t\t            \t      ";
		cout.put(186).put('\n').put('\t').put(186).put(196).put(196).put(196).put(196).put(196).put(196).put(196).put(196).put(196).put(196).put(196).put(196).put(196).put(196).put(196).put(196).put(196).put(196).put(196).put(196).put(196).put(196).put(196).put(196).put(196).put(196).put(196).put(196).put(196).put(196).put(196).put(196).put(196).put(196).put(196).put(196).put(196).put(186);
		cout.put('\n').put('\t').put(186)<<"\t  (1)   Add Room      \t      ";
		cout.put(186).put('\n').put('\t').put(186)<<"\t                      \t      ";
		cout.put(186).put('\n').put('\t').put(186)<<"\t  (2)   Display Rooms         ";
		cout.put(186).put('\n').put('\t').put(186)<<"\t                   \t      ";
		cout.put(186).put('\n').put('\t').put(186)<<"\t  (3)   Search Room           ";
		cout.put(186).put('\n').put('\t').put(186)<<"\t                     \t      ";
		cout.put(186).put('\n').put('\t').put(186)<<"\t  (4)   Modify Room Data      ";
		cout.put(186).put('\n').put('\t').put(186)<<"\t                     \t      ";
		cout.put(186).put('\n').put('\t').put(186)<<"\t  (5)   Exit to main menu     ";
		cout.put(186).put('\n').put('\t').put(186)<<"\t\t\t\t      ";
		cout.put(186).put('\n').put('\t').put(200).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(188);
		cout<<"\n\n\t\tEnter Your Choice: ";
		cin>>choice;

		switch(choice)
		{
			case 1:	add_room();
				break;
			case 2: obj.display_room();
				break;
			case 3: obj.search_room();
				break;
			case 4:	obj.modify_room();
				break;
			case 5:	break;
			default:
				{
					cout<<"\n\n\t\t\tWrong choice.....!!!";
					cout<<"\n\t\t\tPress any key to continue....!!";
					//getch();
				}
		}
	}
}

//********************************************************************************************************************
//            Enter Client Information
//
//********************************************************************************************************************

void Client::cin_client()
{
		cout<<"Enter ID ";
		cin>>ID;
		cout<<endl<<"Enter Name";
		cin.ignore();
		cin.getline(Name,20);
		cout<<endl<<"Enter CNIC";
		cin.getline(CNIC,20);
		cout<<endl<<"Enter Phone Number";
		cin.getline(Phone,20);
		cout<<endl<<"Enter Email Number";
		cin.getline(Email,20);
		cout<<endl<<"Enter Address Number";
		cin.getline(Address,50);
}


//********************************************************************************************************************
//            Display all Clients Information
//
//********************************************************************************************************************

void Client::show_client()
{
	cout<<"| "<<ID<<setw(8)<<"|"<<Name<<setw(15)<<"|"<<CNIC<<setw(6)<<"|"<<Phone<<setw(9)<<"|"<<Email<<setw(3)<<"|"<<Address<<"                  |"<<endl;
}


//********************************************************************************************************************
//            File Handling to display all client Information
//
//********************************************************************************************************************

void Client:: display_client()
{
	Client ob;
	bool flag=false;
	ifstream inFile;
	inFile.open("Data.dat",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	cout<<"\nBALANCE DETAILS\n";
	cout<<" __________________________________________________________________________________________________________________ \n";
	cout<<"|"<<"  ID"<<setw(8)<<"|"<<"Name"<<setw(15)<<"|"<<"CNIC"<<setw(15)<<"|"<<"Phone"<<setw(15)<<"|"<< "Email"<<setw(15)<<"|"<< "Address"<<"                 |"<<endl;
	cout<<"|___________|__________________|__________________|___________________|___________________|________________________|\n";
    	while(inFile.read(reinterpret_cast<char *> (&ob), sizeof(Client)))
	{
			ob.show_client();
			flag=true;
	}
	cout<<"|___________|__________________|__________________|___________________|___________________|________________________|\n";
	inFile.close();
	if(flag==false)
		cout<<"\n\nRoom number does not exist";
		
		getch();
}

//********************************************************************************************************************
//            ADD data usind BST
//
//********************************************************************************************************************

bool BST::add()
{	
	Client ob;
	ofstream outFile;
	outFile.open("Data.dat",ios::binary|ios::app);
	ob.cin_client();
	outFile.write(reinterpret_cast<char *> (&ob), sizeof(Client));
	outFile.close();
	
		Client* temp = new Client;
		temp->ID = ob.ID;
		temp->left = NULL;
		temp->right = NULL;

		Client* curr = root;
		Client* parent = 0;

		while(curr != NULL)
		{
			if(curr->ID == ob.ID)
			{
				delete temp;
				temp = NULL;
				return false;
			}
			else if(ob.ID < curr->ID)
			{
				parent = curr;
				curr = curr->left;
			}
			else
			{
				parent = curr;
				curr = curr->right;
			}
		}

		if(parent == NULL)
		{
			root = temp;
		}
		else
		{
			if(ob.ID < parent->ID)
			{
				parent->left = temp;
			}
			else
			{
				parent->right = temp;
			}
			return true;
		}
		
	}


//********************************************************************************************************************
//            Display Client
//
//********************************************************************************************************************

/*void BST::display()
{
	Client ob;
	
	Client* t = new Client;
	bool flag=false;
	ifstream inFile;
	inFile.open("Data.dat",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	cout<<"\n   ROOM DETAILS\n";
	cout<<" __________________________________________________________________________________________________________________ \n";
	cout<<"|"<<"  ID"<<setw(8)<<"|"<<"Name"<<setw(15)<<"|"<<"CNIC"<<setw(15)<<"|"<<"Phone"<<setw(15)<<"|"<< "Email"<<setw(15)<<"|"<< "Address"<<"                 |"<<endl;
	cout<<"|___________|__________________|__________________|___________________|___________________|________________________|\n";
    	while(inFile.read(reinterpret_cast<char *> (&ob), sizeof(Client)))
	{
			ob.show_client();
			flag=true;
	}
	cout<<"|___________|__________________|__________________|___________________|___________________|________________________|\n";
	inFile.close();
	if(flag==false)
		cout<<"\n\nRoom number does not exist";
	//system("cls");
	
	
	Client* root;
	while(t != 0)
	{
		if(ob.ID==t->ID)
		{
			cout<<"\nENTER CUSTOMER DETAIL";
			cout<<"\n_____________________";
			cout<<endl<<"Customer ID";
			cin>>t->ID;
			cout<<endl<<"Customer Name";
			cin>>t->Name;
			cout<<endl<<"Customer CNIC";
			cin>>t->CNIC;
			cout<<endl<<"Customer Phone Number";
			cin>>t->Phone;
		}
		else if(ob.ID<t->ID)
			t = t->left;
		else
			t = t->right;
	}
	cout<<"Name is present in the list";
	
}*/

//********************************************************************************************************************
//            Search specific client
//
//********************************************************************************************************************

int Client::search_client()
{
	int n;
	cout<<"Enter ID which you want to SEARCH";
	cin>>n;
	
	Client ob;
	bool flag=false;
	ifstream inFile;
	inFile.open("Data.dat",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		return 0;
	}
	cout<<"\nBALANCE DETAILS\n";

    	while(!inFile.eof())
	{
		inFile.read(reinterpret_cast<char *> (&ob), sizeof(Client));
		if(n==ob.ID)
		{
			ob.cout_client();
			flag=true;
		}
	}
	inFile.close();
	if(flag==false)
		cout<<"\n\nRoom number does not exist";
		
		getch();
}

//********************************************************************************************************************
//            Display Search Client Information
//
//********************************************************************************************************************

void Client::cout_client()
{
	cout<<"ID is="<<ID<<endl;
	cout<<"Name is="<<Name<<endl;
	cout<<"CNIC is="<<CNIC<<endl;
	cout<<"Phone number is="<<Phone<<endl;
	cout<<"Email is"<<Email<<endl;
	cout<<"Address is"<<Address<<endl;
	cout<<"\n\n___________________________________________________________________"<<endl;
}


//********************************************************************************************************************
//            Modify Function
//
//********************************************************************************************************************

void Client::modify_client()
{
	int n;
	cout<<"Enter ID which you want to SEARCH";
	cin>>n;
	
	bool found=false;
	Client ob;
	fstream File;
	File.open("Data.dat",ios::binary|ios::in|ios::out);
	if(!File)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	while(!File.eof() && found==false)
	{
		File.read(reinterpret_cast<char *> (&ob), sizeof(Client));
		if(ob.ID==n)
		{
			ob.cout_client();
			cout<<"\n\nEnter The New Details of account"<<endl;
			ob.cin_modify_client();
			int pos=(-1)*static_cast<int>(sizeof(Client));
			File.seekp(pos,ios::cur);
			File.write(reinterpret_cast<char *> (&ob), sizeof(Client));
			cout<<"\n\n\t Record Updated";
			found=true;
		  }
	}
	File.close();
	if(found==false)
		cout<<"\n\n Record Not Found ";
		
		getch();
}

//********************************************************************************************************************
//            Enter things which you want to modify
//
//********************************************************************************************************************

void Client::cin_modify_client()
{
	int choice;
		cout<<"\n\n\n";
    	cout.put('\t').put(201).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(187);
		cout.put('\n').put('\t').put(186)<<"\t Which thing you modify       ";
		cout.put(186).put('\n').put('\t').put(186)<<"\t\t            \t      ";
		cout.put(186).put('\n').put('\t').put(186).put(196).put(196).put(196).put(196).put(196).put(196).put(196).put(196).put(196).put(196).put(196).put(196).put(196).put(196).put(196).put(196).put(196).put(196).put(196).put(196).put(196).put(196).put(196).put(196).put(196).put(196).put(196).put(196).put(196).put(196).put(196).put(196).put(196).put(196).put(196).put(196).put(196).put(186);
		cout.put('\n').put('\t').put(186)<<"\t  (1)   ID            \t      ";
		cout.put(186).put('\n').put('\t').put(186)<<"\t                      \t      ";
		cout.put(186).put('\n').put('\t').put(186)<<"\t  (2)   Name                  ";
		cout.put(186).put('\n').put('\t').put(186)<<"\t                   \t      ";
		cout.put(186).put('\n').put('\t').put(186)<<"\t  (3)   CNIC                  ";
		cout.put(186).put('\n').put('\t').put(186)<<"\t                     \t      ";
		cout.put(186).put('\n').put('\t').put(186)<<"\t  (4)   Phone Number          ";
		cout.put(186).put('\n').put('\t').put(186)<<"\t                     \t      ";
		cout.put(186).put('\n').put('\t').put(186)<<"\t  (5)   Email                 ";
		cout.put(186).put('\n').put('\t').put(186)<<"\t                     \t      ";
		cout.put(186).put('\n').put('\t').put(186)<<"\t  (6)   Address               ";
		cout.put(186).put('\n').put('\t').put(186)<<"\t                     \t      ";
		cout.put(186).put('\n').put('\t').put(186)<<"\t  (7)   Exit                  ";
		cout.put(186).put('\n').put('\t').put(186)<<"\t\t\t\t      ";
		cout.put(186).put('\n').put('\t').put(200).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(188);
		cout<<"\n\n\t\tEnter Your Choice: ";
		cin>>choice;

		switch(choice)
		{
			case 1:	
			{
				cout<<"Enter ID ";
				cin>>ID;
			}
				break;
			case 2: 
			{
				cout<<endl<<"Enter Name";
				cin.ignore();
				cin.getline(Name,20);
			}
				break;
			case 3:	
			{
				cout<<endl<<"Enter CNIC";
				cin.ignore();
				cin.getline(CNIC,20);
			}
				break;
			case 4:	
			{
				cout<<endl<<"Enter Phone Number";
				cin.ignore();
				cin.getline(Phone,20);
			}
			case 5:	
			{
				cout<<endl<<"Enter Email Number";
				cin.ignore();
				cin.getline(Email,20);
			}
			case 6:
			{
				cout<<endl<<"Enter Address";
				cin.ignore();
				cin.getline(Address,20);
			}	
			case 7:break;
				
			default:
				{
					cout<<"\n\n\t\t\tWrong choice.....!!!";
					cout<<"\n\t\t\tPress any key to continue....!!";
					//getch();
				}
		}
		cout<<"New Record is";
		cout_client();
}

//********************************************************************************************************************
//            Enter Room Information
//
//********************************************************************************************************************

void room::cin_room()
{
		cout<<"Enter ID ";
		cin>>ID;
		cout<<"Enter Room Number";
		cin>>Room;
		cout<<endl<<"Enter Name";
		cin.ignore();
		cin.getline(Name,20);
		cout<<endl<<"Enter CNIC";
		cin.getline(CNIC,20);
		cout<<endl<<"Enter Phone Number";
		cin.getline(Phone,20);
		cout<<endl<<"Enter Email Number";
		cin.getline(Email,20);
		cout<<endl<<"Enter Address Number";
		cin.getline(Address,50);
}


//********************************************************************************************************************
//            Display all rooms Information
//
//********************************************************************************************************************

void room::show_room()
{
	cout<<"| "<<ID<<setw(8)<<"|"<<Room<<setw(8)<<"|"<<Name<<setw(15)<<"|"<<CNIC<<setw(15)<<"|"<<Phone<<setw(15)<<"|"<<Email<<setw(15)<<"|"<<Address<<"    |"<<endl;
}


//********************************************************************************************************************
//            File Handling to display all room Information
//
//********************************************************************************************************************

void room:: display_room()
{
	room ob;
	bool flag=false;
	ifstream inFile;
	inFile.open("Room.dat",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	cout<<"\nBALANCE DETAILS\n";
	cout<<" ______________________________________________________________________________________________________________________________ \n";
	cout<<"|"<<"  ID"<<setw(8)<<"|"<<"Room"<<setw(8)<<"|"<<"Name"<<setw(15)<<"|"<<"CNIC"<<setw(15)<<"|"<<"Phone"<<setw(15)<<"|"<< "Email"<<setw(15)<<"|"<< "Address"<<"                 |"<<endl;
	cout<<"|___________|___________|__________________|__________________|___________________|___________________|________________________|\n";
    	while(inFile.read(reinterpret_cast<char *> (&ob), sizeof(room)))
	{
			ob.show_room();
			flag=true;
	}
	cout<<"|___________|___________|__________________|__________________|___________________|___________________|________________________|\n";
	inFile.close();
	if(flag==false)
		cout<<"\n\nRoom number does not exist";
		
	getch();
}

//********************************************************************************************************************
//            ADD data usind BST
//
//********************************************************************************************************************

bool BST::add_room()
{	
	room ob;
	ofstream outFile;
	outFile.open("Room.dat",ios::binary|ios::app);
	ob.cin_room();
	outFile.write(reinterpret_cast<char *> (&ob), sizeof(room));
	outFile.close();
	
		room* temp = new room;
		temp->Room = ob.Room;
		temp->left = NULL;
		temp->right = NULL;

		room* curr = root1;
		room* parent = 0;

		while(curr != NULL)
		{
			if(curr->Room == ob.Room)
			{
				delete temp;
				temp = NULL;
				return false;
			}
			else if(ob.Room < curr->Room)
			{
				parent = curr;
				curr = curr->left;
			}
			else
			{
				parent = curr;
				curr = curr->right;
			}
		}

		if(parent == NULL)
		{
			root1 = temp;
		}
		else
		{
			if(ob.Room < parent->Room)
			{
				parent->left = temp;
			}
			else
			{
				parent->right = temp;
			}
			return true;
		}
		
	}

//********************************************************************************************************************
//            Search specific room
//
//********************************************************************************************************************

int room::search_room()
{
	int n;
	cout<<"Enter Room Number which you want to SEARCH";
	cin>>n;
	
	room ob;
	bool flag=false;
	ifstream inFile;
	inFile.open("Room.dat",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		return 0;
	}
	cout<<"\nBALANCE DETAILS\n";

    	while(!inFile.eof())
	{
		inFile.read(reinterpret_cast<char *> (&ob), sizeof(room));
		if(n==ob.Room)
		{
			ob.cout_room();
			flag=true;
		}
	}
	inFile.close();
	if(flag==false)
		cout<<"\n\nRoom number does not exist";
		
		getch();
}

//********************************************************************************************************************
//            Display Search room Information
//
//********************************************************************************************************************

void room::cout_room()
{
	cout<<"ID is="<<ID<<endl;
	cout<<"Room Number"<<Room<<endl;
	cout<<"Name is="<<Name<<endl;
	cout<<"CNIC is="<<CNIC<<endl;
	cout<<"Phone number is="<<Phone<<endl;
	cout<<"Email is"<<Email<<endl;
	cout<<"Address is"<<Address<<endl;
	cout<<"\n\n___________________________________________________________________"<<endl;
}


//********************************************************************************************************************
//            Modify Function
//
//********************************************************************************************************************

void room::modify_room()
{
	int n;
	cout<<"Enter Room Number which you want to SEARCH";
	cin>>n;
	
	bool found=false;
	room ob;
	fstream File;
	File.open("Room.dat",ios::binary|ios::in|ios::out);
	if(!File)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	while(!File.eof() && found==false)
	{
		File.read(reinterpret_cast<char *> (&ob), sizeof(room));
		if(ob.Room==n)
		{
			ob.cout_room();
			cout<<"\n\nEnter The New Details of account"<<endl;
			ob.cin_modify_room();
			int pos=(-1)*static_cast<int>(sizeof(room));
			File.seekp(pos,ios::cur);
			File.write(reinterpret_cast<char *> (&ob), sizeof(room));
			cout<<"\n\n\t Record Updated";
			found=true;
		  }
	}
	File.close();
	if(found==false)
		cout<<"\n\n Record Not Found ";
		
		getch();
}

//********************************************************************************************************************
//            Enter things which you want to modify
//
//********************************************************************************************************************

void room::cin_modify_room()
{
	int choice;
		cout<<"\n\n\n";
    	cout.put('\t').put(201).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(187);
		cout.put('\n').put('\t').put(186)<<"\t Which thing you modify       ";
		cout.put(186).put('\n').put('\t').put(186)<<"\t\t            \t      ";
		cout.put(186).put('\n').put('\t').put(186).put(196).put(196).put(196).put(196).put(196).put(196).put(196).put(196).put(196).put(196).put(196).put(196).put(196).put(196).put(196).put(196).put(196).put(196).put(196).put(196).put(196).put(196).put(196).put(196).put(196).put(196).put(196).put(196).put(196).put(196).put(196).put(196).put(196).put(196).put(196).put(196).put(196).put(186);
		cout.put('\n').put('\t').put(186)<<"\t  (1)   ID            \t      ";
		cout.put(186).put('\n').put('\t').put(186)<<"\t                      \t      ";
		cout.put(186).put('\n').put('\t').put(186)<<"\t  (2)   Room                  ";
		cout.put(186).put('\n').put('\t').put(186)<<"\t                   \t      ";
		cout.put(186).put('\n').put('\t').put(186)<<"\t  (3)   Name                  ";
		cout.put(186).put('\n').put('\t').put(186)<<"\t                     \t      ";
		cout.put(186).put('\n').put('\t').put(186)<<"\t  (4)   CNIC                  ";
		cout.put(186).put('\n').put('\t').put(186)<<"\t                     \t      ";
		cout.put(186).put('\n').put('\t').put(186)<<"\t  (5)   Phone Number          ";
		cout.put(186).put('\n').put('\t').put(186)<<"\t                     \t      ";
		cout.put(186).put('\n').put('\t').put(186)<<"\t  (6)   Email                 ";
		cout.put(186).put('\n').put('\t').put(186)<<"\t                     \t      ";
		cout.put(186).put('\n').put('\t').put(186)<<"\t  (7)   Address               ";
		cout.put(186).put('\n').put('\t').put(186)<<"\t                     \t      ";
		cout.put(186).put('\n').put('\t').put(186)<<"\t  (8)   Exit                  ";
		cout.put(186).put('\n').put('\t').put(186)<<"\t\t\t\t      ";
		cout.put(186).put('\n').put('\t').put(200).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(188);
		cout<<"\n\n\t\tEnter Your Choice: ";
		cin>>choice;

		switch(choice)
		{
			case 1:	
			{
				cout<<"Enter ID ";
				cin>>ID;
			}
				break;
			case 2: 
			{
				cout<<"Enter Room Number";
				cin>>Room;
			}
				break;
			case 3: 
			{
				cout<<endl<<"Enter Name";
				cin.ignore();
				cin.getline(Name,20);
			}
				break;
			case 4:	
			{
				cout<<endl<<"Enter CNIC";
				cin.getline(CNIC,20);
			}
				break;
			case 5:	
			{
				cout<<endl<<"Enter Phone Number";
				cin.getline(Phone,20);
			}
			case 6:	
			{
				cout<<endl<<"Enter Email";
				cin.getline(Email,20);
			}
			case 7:	
			{
				cout<<endl<<"Enter Address";
				cin.getline(Address,20);
			}
			case 8:break;
			default:
				{
					cout<<"\n\n\t\t\tWrong choice.....!!!";
					cout<<"\n\t\t\tPress any key to continue....!!";
					//getch();
				}
		}
		cout<<"New Record is";
		cout_room();
	
	/*cout<<"Enter ID ";
		cin>>ID;
		cout<<"Enter Room Number";
		cin>>Room;
		cout<<endl<<"Enter Name";
		cin.ignore();
		cin.getline(Name,20);
		cout<<endl<<"Enter CNIC";
		cin.getline(CNIC,20);
		cout<<endl<<"Enter Phone Number";
		cin.getline(Phone,20);
		cout<<endl<<"Enter Email Number";
		cin.getline(Email,20);
		cout<<endl<<"Enter Address Number";
		cin.ignore();
		cin.getline(Address,50);*/
}

//********************************************************************************************************************
//             FOOD MENU
//
//********************************************************************************************************************

void BST:: menu()
{
	//system("CLS");
	//fclose(fp);
    //system("COLOR FC");
    	cout<<"\n\n\n";
    	cout.put('\t').put(201).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(210).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(187);
		cout.put('\n').put('\t').put(186)<<"                                         Menu\t\t\t\t\t       ";
		cout.put(186).put('\n').put('\t').put(186)<<"Rice                                      ";
		cout.put(179)<<"  SHAWARMA                                 ";
		cout.put(186).put('\n').put('\t').put(186)<<"                                          ";
		cout.put(179)<<"                                           ";
		cout.put(186).put('\n').put('\t').put(186)<<" (1) Fine Special Rice         PKR :305   ";
		cout.put(179)<<" (11) Fine Special Roll       PKR :150     ";
		cout.put(186).put('\n').put('\t').put(186)<<"                                          ";
		cout.put(179)<<"                                           ";
		cout.put(186).put('\n').put('\t').put(186)<<" (2) Steamed Rice              PKR :330   ";
		cout.put(179)<<" (12) Chicken Shawarma        PKR :90      ";
		cout.put(186).put('\n').put('\t').put(186)<<"                                          ";
		cout.put(179)<<"                                           ";
		cout.put(186).put('\n').put('\t').put(186)<<" (3) Chicken Masala Rice       PKR :260   ";
		cout.put(179)<<" (13) Chicken Shawarma        PKR :110     ";
		cout.put(186).put('\n').put('\t').put(186)<<"                                          ";
		cout.put(179)<<"                                           ";
		cout.put(186).put('\n').put('\t').put(186)<<" (4) Chicken Fried Rice        PKR :260   ";
		cout.put(179)<<" (14) Beef Shawarma           PKR :80      ";
		cout.put(186).put('\n').put('\t').put(186)<<"                                          ";
		cout.put(179)<<"                                           ";
		cout.put(186).put('\n').put('\t').put(186)<<" (5) Mutton Fried Rice         PKR :305   ";
		cout.put(179)<<" SOUP                                      ";
		cout.put(186).put('\n').put('\t').put(186)<<"                                          ";
		cout.put(179)<<"                                           ";
		cout.put(186).put('\n').put('\t').put(186)<<" (6) Beef Chilli Fried Rice    PKR :250   ";
		cout.put(179)<<" (15) Fine Special Soup       PKR :420     ";
		cout.put(186).put('\n').put('\t').put(186)<<"                                          ";
		cout.put(179)<<"                                           ";
		cout.put(186).put('\n').put('\t').put(186)<<" (7) Egg Fried Rice            PKR :230   ";
		cout.put(179)<<" (16) Chicken Corn Soup       PKR :360     ";
		cout.put(186).put('\n').put('\t').put(186)<<"                                          ";
		cout.put(179)<<"                                           ";
		cout.put(186).put('\n').put('\t').put(186)<<" (8) Shrimp Fried Rice         PKR :280   ";
		cout.put(179)<<" (17) Sliced Chicken          PKR :370     ";
		cout.put(186).put('\n').put('\t').put(186)<<"                                          ";
		cout.put(179)<<"                                           ";
		cout.put(186).put('\n').put('\t').put(186)<<" (9) Plain Rice                PKR :190   ";
		cout.put(179)<<" (18) Fine Special Soup       PKR :420     ";
		cout.put(186).put('\n').put('\t').put(186)<<"                                          ";
		cout.put(179)<<"                                           ";
		cout.put(186).put('\n').put('\t').put(186)<<"DESSERT                                   ";
		cout.put(179)<<" FISH                                      ";
		cout.put(186).put('\n').put('\t').put(186)<<" (10) Chinese GreenTea (1cup)  PKR :35    ";
		cout.put(179)<<"  (19) Fried Pomfret          PKR :400     ";
		cout.put(186).put('\n').put('\t').put(200).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(207).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(205).put(188);
		cout << "\n\t\t\t Select Your Choice :=> ";
		calculate();

//0 = Black
//1 = Blue
//2 = Green
//3 = Aqua
//4 = Red
//5 = Purple
//6 = Yellow
//7 = White
//8 = Gray
//9 = Light Blue
//A = Light Green
//B = Light Aqua
//C = Light Red
//D = Light Purple
//E = Light Yellow
//F = Bright White
}

//********************************************************************************************************************
//            Calculate FOOD MENU
//
//********************************************************************************************************************

void BST:: calculate()
{	
	int AmountofSale[20];
	int order=1,num1=0,num2=0,num3=0,num4=0,num5=0,num6=0,num7=0,num8=0,num9=0,num10=0,num11=0,num12=0,num13=0,num14=0,num15=0,num16=0,num17=0,num18=0,num19=0;
	int rice1=305,rice2=330,rice3=360,rice4=360,rice5=305,rice6=250,rice7=230,rice8=280,rice9=190,Tea=400;
	int shawarma11=150,shawarma12=90,shawarma13=110,shawarma14=80,soup15=420,soup16=360,soup17=370,soup18=420,fish=400;
	int Bill=1430;
	
	cout<<"You have ordered:\n\n";
	
	while(order!=20)
	{
		cout<<"From the list of food, what would you like:\n";
		cin>>order;
		
		switch(order)
		{
			case 20:
	            break;
			case 1:
			{
				cout<<"How many plates of rice would you like to order:\n";
	            cin>>num1;
	            AmountofSale[1] = rice1;
	            Bill=+AmountofSale[1];
	            break;
			}
			case 2:
			{
				cout<<"How many plates of rice would you like to order:\n";
	            cin>>num1;
	            AmountofSale[2] = rice2 * num2;
	            Bill=+AmountofSale[2];
	            break;
			}
			case 3:
			{
				cout<<"How many plates of rice would you like to order:\n";
	            cin>>num1;
	            AmountofSale[3] = rice3 * num3;
	            Bill=+AmountofSale[3];
	            break;
			}
			case 4:
			{
				cout<<"How many plates of rice would you like to order:\n";
	            cin>>num1;
	            AmountofSale[4] = rice4 * num4;
	            Bill=+AmountofSale[4];
	            break;
			}
			case 5:
			{
				cout<<"How many plates of rice would you like to order:\n";
	            cin>>num1;
	            AmountofSale[5] = rice5 * num5;
	            Bill=+AmountofSale[5];
	            break;
			}
			case 6:
			{
				cout<<"How many plates of rice would you like to order:\n";
	            cin>>num1;
	            AmountofSale[6] = rice6 * num6;
	            Bill=+AmountofSale[6];
	            break;
			}
			case 7:
			{
				cout<<"How many plates of rice would you like to order:\n";
	            cin>>num1;
	            AmountofSale[7] = rice7 * num7;
	            Bill=+AmountofSale[7];
	            break;
			}
			case 8:
			{
				cout<<"How many plates of rice would you like to order:\n";
	            cin>>num1;
	            AmountofSale[8] = rice8 * num8;
	            Bill=+AmountofSale[8];
	            break;
			}
			case 9:
			{
				cout<<"How many plates of rice would you like to order:\n";
	            cin>>num1;
	            AmountofSale[9] = rice9 * num9;
	            Bill=+AmountofSale[9];
	            break;
			}
			case 10:
			{
				cout<<"How many cups of GreenTea would you like to order:\n";
	            cin>>num1;
	            AmountofSale[10] = Tea * num10;
	            Bill=+AmountofSale[10];
	            break;
			}
			case 11:
			{
				cout<<"How many Shawarma would you like to order:\n";
	            cin>>num1;
	            AmountofSale[11] = shawarma11 * num11;
	            Bill=+AmountofSale[11];
	            break;
			}
			case 12:
			{
				cout<<"How many Shawarma would you like to order:\n";
	            cin>>num1;
	            AmountofSale[12] = shawarma12 * num12;
	            Bill=+AmountofSale[12];
	            break;
			}
			case 13:
			{
				cout<<"How many Shawarma would you like to order:\n";
	            cin>>num1;
	            AmountofSale[13] = shawarma13 * num13;
	            Bill=+AmountofSale[13];
	            break;
			}
			case 14:
			{
				cout<<"How many Shawarma would you like to order:\n";
	            cin>>num1;
	            AmountofSale[14] = shawarma14 * num14;
	            Bill=+AmountofSale[14];
	            break;
			}
			case 15:
			{
				cout<<"How many Cups of Soup would you like to order:\n";
	            cin>>num1;
	            AmountofSale[15] = soup15 * num15;
	            Bill=+AmountofSale[15];
	            break;
			}
			case 16:
			{
				cout<<"How many Cups of Soup would you like to order:\n";
	            cin>>num1;
	            AmountofSale[16] = soup16 * num16;
	            Bill=+AmountofSale[16];
	            break;
			}
			case 17:
			{
				cout<<"How many Cups of Soup would you like to order:\n";
	            cin>>num1;
	            AmountofSale[17] = soup17 * num17;
	            Bill=+AmountofSale[17];
	            break;
			}
			case 18:
			{
				cout<<"How many Cups of Soup would you like to order:\n";
	            cin>>num1;
	            AmountofSale[18] = soup18 * num18;
	            Bill=+AmountofSale[18];
	            break;
			}
			case 19:
			{
				cout<<"How many Kg Pomfret would you like to order:\n";
	            cin>>num1;
	            AmountofSale[19] = fish * num19;
	            Bill=+AmountofSale[19];
	            break;
			}
		}
	}
	
	for(int i=1;i<20;i++)
	{
		Bill+=AmountofSale[i];
	}
		cout<<"Your Total Bill is=PKR "<<Bill;
}

//********************************************************************************************************************
//            Complaints
//
//********************************************************************************************************************

void BST:: complaint()
{
	char comp[50];
	cout<<"Enter your Complaints";
	cin.ignore();
	cin.getline(comp,50);
}

//********************************************************************************************************************
//            MAIN
//
//********************************************************************************************************************

int main()
{
	BST obj;
	system("color 5f");
	
	login();
	
	obj.main_menu();
	return 0;
}
