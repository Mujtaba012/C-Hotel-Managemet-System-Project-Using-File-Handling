#include<iostream>
#include<stdlib.h>
#include<conio.h>
#include<fstream>
#include<string.h>

using namespace std;

// Prototypes Of HMS:  

// Header:
void header();
// Admin Menu Hotel Management System:
void menu();
// Manager Menu Options:
void menu1();
// Admin/Manager Selection:
int  admin();
// Adding Customer:
void add();
// Displaying Customer:
void display();
// Viewing Perticular Room Status:
void perticular_room();
// Viewing Perticular Customer Information:
void perticular_cus();
// Viewing Perticular Customer:
void edit_cus();
// Delete Customer Info:
void delete_cus();
// End All Program Execution: 
void finish();
// Main Driver Code: 
int  main();

// Globle Variables:
	string name, address,phone;
	string arr_date, dep_date;
	string payment;
	string room;
	string id;


// Header: 
void header()
{

	// Header of HMS:
	cout << "************************************************************" << endl;
	cout << "*                  Hotel Management System                 *" << endl;
	cout << "************************************************************" << endl;
}

// Menu HMS:
void menu()
{

	// Menu Options:
    cout<<"\n\t\tWELCOME TO HOTEL MANAGEMENT PROJECT\n  ";
    cout<<"\t\t_______________________________________  ";
    cout<<"\n\t\t1- Press 1 To reserve a room           ";
    cout<<"\n\t\t2- Press 2 to view all rooms status    ";
    cout<<"\n\t\t3- Press 3 to view room information    ";
    cout<<"\n\t\t4- Press 4 to view customer information";
    cout<<"\n\t\t5- Press 5 to edit the data            ";
    cout<<"\n\t\t6- Press 6 to leave the room           ";
    cout<<"\n\t\t7- Press 7 to exit                     ";
    cout<<"\n\t\t______________________________________ ";
}

// For Manager Option: 
void menu1()
{
	// Menu Options:
    cout<<"\n\t\tWELCOME TO HOTEL MANAGEMENT PROJECT\n  ";
    cout<<"\t\t_______________________________________  ";
    cout<<"\n\t\t1- Press 1 To reserve a room           ";
    cout<<"\n\t\t2- Press 2 to view all rooms status    ";
    cout<<"\n\t\t3- Press 3 to exit                     ";
    cout<<"\n\t\t______________________________________\n";	
}

// To Select the Login ID:
int admin()
{
	int r;
	cout<<"\n\t\tWELCOME TO HOTEL MANAGEMENT PROJECT\n    ";
    cout<<"\t\t_______________________________________    ";
    cout<<"\n\t\t1- Press 1 For Admin Login               ";
    cout<<"\n\t\t2- Press 2 For Manager Login		      ";
    cout<<"\n\t\t3- Press 3 For Others        		      ";
    cout<<"\n\t\t_______________________________________  ";

    cout << "\n\nPress Given Option : ";
    cin  >> r;
    
// If Condition for Admin:
    if(r== 1)
    {
    	return 1;
	}

// If Condition for Manager: 
	if (r==2)
	{
		return 2;
	}

// If Condition for Others:
	if (r==3)
	{
		cout << "\n-----SORRY YOU CANNOT USE SYSTEM-----"<<endl;
		return 3;
	}
    
}


// Add Customer:  
void add()
{
	char ch = 'y';

			while(ch == 'Y' || ch == 'y')
			{
	// Geting Information:
			cin.ignore();
			cout << "Main Manu  > Add Customer  \n\n";
			cout << "\nEnter Customer Name ......................... " ;
			getline(cin ,name) ;
			cout << "Enter Customer ID ........................... " ;
			getline(cin ,id) ;
			cout << "Enter Customer Address....................... " ;
			getline(cin ,address) ;
			cout << "Enter Customer Phone No...................... " ;
			getline(cin ,phone);
			cout <<  "Enter Room Number ........................... " ;
			getline(cin ,room);
			cout << "Enter Arrival Date........................... " ;
			getline(cin ,arr_date);
			cout << "Enter Departure Date......................... " ;
			getline(cin ,dep_date);
			cout << "Enter Customer Payment....................... " ;
			getline(cin ,payment) ;	

	// To Write in file:		
			ofstream wdata;
			wdata.open("test.txt", ios :: app);
			
			wdata << name      << endl;
			wdata << id        << endl;
			wdata << address   << endl;
			wdata << phone     << endl;
			wdata << room      << endl;
			wdata << arr_date  << endl;
			wdata << dep_date  << endl;
			wdata << payment   << endl;			
			wdata.close();	
	
	// To Take Record Again:		
			cout << "\nDo you want enter customer record again (Y/N): ";
			cin  >> ch;
	
	// System CLS:
			system("cls");		
			if(ch != 'y' && ch != 'Y')
			{
				break;
			}


		}

}

// Display All Customer Records: 
void display()
{
		char ch = 'y';
	
			while(ch == 'Y' || ch == 'y')
			{

		// Read from File:
				fstream rdata;
			rdata.open("test.txt");
								
				getline(rdata,name);
				getline(rdata,id);
				getline(rdata,address);
				getline(rdata,phone);
				getline(rdata,room);
				getline(rdata,arr_date);
				getline(rdata,dep_date);
				getline(rdata,payment);		
		
			while (!rdata.eof())
			{
	// Display Records:
			cout << "Customer Name ......................... " << name     <<endl;
			cout << "Customer ID ........................... " << id       <<endl;
			cout << "Customer Address....................... " << address  <<endl;
			cout << "Customer Phone No...................... " << phone    <<endl;
			cout << "Room Number ........................... " << room     <<endl;
			cout << "Arrival Date........................... " << arr_date <<endl;
			cout << "Departure Date......................... " << dep_date <<endl;
			cout << "Customer Payment....................... " << payment  <<endl;
			cout << endl ;

	// Read From File:
				getline(rdata,name);
				getline(rdata,id);
				getline(rdata,address);
				getline(rdata,phone);
				getline(rdata,room);
				getline(rdata,arr_date);
				getline(rdata,dep_date);
				getline(rdata,payment);

			}

			rdata.close();
			
	// To View All Customers Record again: 	
			cout << "\nDo you want to View All Customers record again (Y/N): ";
			cin  >> ch;
			system("cls");		
			
			if(ch != 'y' && ch != 'Y')
			{
				break;
			}
		}

}

// View Perticular Room Information : 
void perticular_room()
{
			char ch = 'y'; 
		
			while(ch == 'Y' || ch == 'y')
			{
			string r;
			
			cout <<"Enter Room ID to View record : ";
			cin  >> r;
			cout << endl;
			
	// ifstream to read form file:		
			ifstream rdata;
			rdata.open("test.txt");
	
	// ofstream to write in file:
			ofstream wdata;
			wdata.open("new.txt");
	
	// Read from file:
				getline(rdata,name);
				getline(rdata,id);
				getline(rdata,address);
				getline(rdata,phone);
				getline(rdata,room);
				getline(rdata,arr_date);
				getline(rdata,dep_date);
				getline(rdata,payment);
						
			
	// While Loop:	
			while (!rdata.eof())
			{
				if(room != r)
				{
					
					wdata << name      << endl;
					wdata << id        << endl;
					wdata << address   << endl;
					wdata << phone     << endl;
					wdata << room      << endl;
					wdata << arr_date  << endl;
					wdata << dep_date  << endl;
					wdata << payment   << endl;			
					
					
				}

				else if (room == r) 
				{
					
	// Customer Record:
					cout << "Customer Name ......................... " << name     <<endl;
					cout << "Customer ID ........................... " << id       <<endl;
					cout << "Customer Address....................... " << address  <<endl;
					cout << "Customer Phone No...................... " << phone    <<endl;
					cout << "Room Number ........................... " << room     <<endl;
					cout << "Arrival Date........................... " << arr_date <<endl;
					cout << "Departure Date......................... " << dep_date <<endl;
					cout << "Customer Payment....................... " << payment  <<endl;
	
	// Write to file
					wdata << name      << endl;
					wdata << id        << endl;
					wdata << address   << endl;
					wdata << phone     << endl;
					wdata << room      << endl;
					wdata << arr_date  << endl;
					wdata << dep_date  << endl;
					wdata << payment   << endl;			
					
				}
	// Read from File:
				getline(rdata,name);
				getline(rdata,id);
				getline(rdata,address);
				getline(rdata,phone);
				getline(rdata,room);
				getline(rdata,arr_date);
				getline(rdata,dep_date);
				getline(rdata,payment);
				
			}
				wdata.close();
				rdata.close();
			
	// Removing test.txt File 
			remove("test.txt") != 0;
			
	// Renaming new.txt file to test.txt file:
			rename("new.txt", "test.txt") != 0;
			cout << "\nDo you want to View Perticular Room record again (Y/N): ";
			cin  >> ch;
			system("cls");		
			
			if(ch != 'y' && ch != 'Y')
			{
				break;
			}

		}
	}
	
	
// View Perticular Customer Information : 
void perticular_cus()
{
		char ch = 'y';
		string b;
		while(ch == 'Y' || ch == 'y')
		{	
	// Enter Customer ID:
			cout <<"Enter Customer ID to View record : ";
			cin  >> b;
			cout << endl;
			
	// Read to File:
			ifstream rdata;
			rdata.open("test.txt");
	
	// Write to File:
			ofstream wdata;
			wdata.open("new.txt");
						
				getline(rdata,name);
				getline(rdata,id);
				getline(rdata,address);
				getline(rdata,phone);
				getline(rdata,room);
				getline(rdata,arr_date);
				getline(rdata,dep_date);
				getline(rdata,payment);

	// While Loop:				
			while (!rdata.eof())
			{
				
		// IF Condition:
				if(id != b)
				{
			
		// Write to File:	
			wdata << name      << endl;
			wdata << id        << endl;
			wdata << address   << endl;
			wdata << phone     << endl;
			wdata << room      << endl;
			wdata << arr_date  << endl;
			wdata << dep_date  << endl;
			wdata << payment   << endl;			
					
			}
	
		// Else Condition:
				else if (id == b) 
				{
					cout << "Customer Name ......................... " << name     <<endl;
					cout << "Customer ID ........................... " << id       <<endl;
					cout << "Customer Address....................... " << address  <<endl;
					cout << "Customer Phone No...................... " << phone    <<endl;
					cout << "Room Number ........................... " << room     <<endl;
					cout << "Arrival Date........................... " << arr_date <<endl;
					cout << "Departure Date......................... " << dep_date <<endl;
					cout << "Customer Payment....................... " << payment  <<endl;
		
		// Write to File:
				wdata << name      << endl;
				wdata << id        << endl;
				wdata << address   << endl;
				wdata << phone     << endl;
				wdata << room      << endl;
				wdata << arr_date  << endl;
				wdata << dep_date  << endl;
				wdata << payment   << endl;			
					
			}
			
		// Read to File:
				getline(rdata,name);
				getline(rdata,id);
				getline(rdata,address);
				getline(rdata,phone);
				getline(rdata,room);
				getline(rdata,arr_date);
				getline(rdata,dep_date);
				getline(rdata,payment);

			}
				wdata.close();
				rdata.close();
				
	// Remove test.txt File			
					remove("test.txt") != 0;
	
	// Rename new.txt to test.txt file:
					rename("new.txt", "test.txt") != 0;
	
	// To View Perticular Record Again:
			cout << "\nDo you want to View Perticular Customer record again (Y/N): ";
			cin  >> ch;
			system("cls");		
		
		// IF Condition:
			if(ch != 'y' && ch != 'Y')
			{
				break;
			}

		}
}


// Edit Customer Information: 
void edit_cus()
{
		char ch = 'y';
		string b; 
		while(ch == 'Y' || ch == 'y')
		{	
			string e_name, e_address,e_phone;
			string e_arr_date, e_dep_date, e_payment;
			string e_room;
			string e_id;
			
	// Enter Customer ID:	
			cout <<"Enter Customer ID to edit record : ";
			cin >> b;
			cout << endl;
			
	// ifstream :
			ifstream rdata;
			rdata.open("test.txt");
	
	// ofstream :
			ofstream wdata;
			wdata.open("new.txt");
	
	// Read to File:
				getline(rdata,name);
				getline(rdata,id);
				getline(rdata,address);
				getline(rdata,phone);
				getline(rdata,room);
				getline(rdata,arr_date);
				getline(rdata,dep_date);
				getline(rdata,payment);
						

	// While Loop: 
	
			while (!rdata.eof())
			{
	
	// IF Condition:
				if(id != b)
				{

		// Write to file:
					wdata << name      << endl;
					wdata << id        << endl;
					wdata << address   << endl;
					wdata << phone     << endl;
					wdata << room      << endl;
					wdata << arr_date  << endl;
					wdata << dep_date  << endl;
					wdata << payment   << endl;			
			
				}
		
		
		// Else If Condition:
				else if (id == b) 
				{
			
			// Edit Customer Record :
					cin.ignore();
					cout << "Main Manu  > Edit Customer Information: \n\n";
					cout << "Enter Customer Name ......................... " ;
					getline(cin ,e_name);
					cout << "Enter Customer ID ........................... " ;
					getline(cin ,e_id);
					cout << "Enter Customer Address....................... " ;
					getline(cin ,e_address);
					cout << "Enter Customer Phone No...................... " ;
					getline(cin ,e_phone);
					cout <<  "Enter Room Number ........................... " ;
					getline(cin ,e_room);
					cout << "Enter Arrival Date........................... " ;
					getline(cin ,e_arr_date);
					cout << "Enter Departure Date......................... " ;
					getline(cin ,e_dep_date);
					cout << "Enter Customer Payment....................... " ;
					getline(cin ,e_payment);

		// Write to File:
					wdata << e_name      << endl;
					wdata << e_id        << endl;
					wdata << e_address   << endl;
					wdata << e_phone     << endl;
					wdata << e_room      << endl;
					wdata << e_arr_date  << endl;
					wdata << e_dep_date  << endl;
					wdata << e_payment   << endl;			
				}
		
		// Read to File:
				getline(rdata,name);
				getline(rdata,id);
				getline(rdata,address);
				getline(rdata,phone);
				getline(rdata,room);
				getline(rdata,arr_date);
				getline(rdata,dep_date);
				getline(rdata,payment);				

			}
			wdata.close();
			rdata.close();

	// Remove test.txt file:			
			remove("test.txt") != 0;
	
	
			rename("new.txt", "test.txt") != 0;
			
			cout << "\nDo you want to edit Customer record again (Y/N): ";
			cin  >> ch;
			system("cls");		
	
	// If Condition to Break the loop:			
			if(ch != 'y' && ch != 'Y')
			{
				break;
			}

		}
}


// Delete Customer Record :
void delete_cus()
{
	// Default Set to Yes:
	char ch = 'y';
		string b; 
	
	// While Loop:
		while(ch == 'Y' || ch == 'y')
		{
	// Taking ID to Delete Record:
			cout <<"Enter Customer ID to delete record : ";
			cin  >> b;
		
		// ifstream :
			ifstream rdata;
			rdata.open("test.txt");
		
		// ofstream :
			ofstream wdata;
			wdata.open("new.txt");
			
				getline(rdata,name);
				getline(rdata,id);
				getline(rdata,address);
				getline(rdata,phone);
				getline(rdata,room);
				getline(rdata,arr_date);
				getline(rdata,dep_date);
				getline(rdata,payment);				

			
	// While Loop: 
	
			while (!rdata.eof())
			{
		
		// If Conditon:
				if(id != b)
				{
				
			// Write to file:
					wdata << name      << endl;
					wdata << id        << endl;
					wdata << address   << endl;
					wdata << phone     << endl;
					wdata << room      << endl;
					wdata << arr_date  << endl;
					wdata << dep_date  << endl;
					wdata << payment   << endl;			
			
				}
				
		// Else If Conditon:
				else if (id == b) 
				{
					cout << "\nRecord Deleted..\n";
				}
		
		// Read to File
				getline(rdata,name);
				getline(rdata,id);
				getline(rdata,address);
				getline(rdata,phone);
				getline(rdata,room);
				getline(rdata,arr_date);
				getline(rdata,dep_date);
				getline(rdata,payment);				

		}

			wdata.close();
			rdata.close();
			
	// Remove test.txt File:	
			remove("test.txt") != 0;
	
	// Rename new.txt to test.txt:
			rename("new.txt", "test.txt") != 0;
	
	// To Delete Customer Record:
			cout << "\nDo you want to Delete Customer record again (Y/N): ";
			cin  >> ch;
			system("cls");		
		
		// If Condition:
			if(ch != 'y' && ch != 'Y')
			{
				break;
			}

		}
}

// Finish Program Execution:
void finish()
{
		
	// To Finish All Program Execution:
	
				cout << "\n\n----------Program Ended SuccessfullY.----------\n";
				cout << "----------Have a Good Day.----------";
			
}


// Main Driver Code : 
int main()
{
	// Main Driver Code DataTypes:
	char op;
	int a ;
	char check='Y';
	string ad, pas;

	
// While Loop:
	while (check == 'Y' || check =='y')
	{

	// Header:
	header();

	// Check Admin Panel:
	a = admin();

// Conditon To Check For Admin:

	if (a == 1)
	{
		cout << "Enter Admin Name : ";
		cin  >> ad;
		cout << "Enter Admin Password : ";
		cin  >> pas;
		cout << endl<< endl;

// IF Condition For Admin:
	if (ad != "Mujtaba" && pas != "admin123") 
	{
		cout << "-----Sorry !! You enter wrong LogIn Information-----\n";
	}
	
// While Loop For Admin Panel:
	while(ad == "Mujtaba" && pas == "admin123")
	{
		system("cls");

// Main Loop:
	loop:
		
// Header:
	header();

//Menu :
	menu();

// DataType:
	int i,b;
	int r;

// Select Option:
	cout << "\nSelect Your Option : ";
	cin  >> op;

// While Loop:
	while (op == '1' || op == '2' || op == '3' || op == '4' || op == '5' || op == '6' || op == '7'  )
	{
	// Switch in Loop: 	

	switch(op)
	{

// Cases:

	
	//To Add Customer:
		case '1' :
			{
				add();
				goto loop;
				break;
				
			}
		
//		Display All Rooms Status:
		case '2':
		
		{
			display();	
			goto loop;
			break;
		
		}

//		To View Perticualr Room Information :
		case '3':
		
		{
			perticular_room();
			goto loop;
			break;

		}
		
//		To View Perticular Customer Record:
		case '4':
		
		{
			perticular_cus();
			goto loop;
			break;
	
		}
		

//		Edit Customer Information :
		case '5':
		
		{
			edit_cus();
			goto loop;
			break;
	
		}

//		Delete Perticular Record
		case '6':
		
		{
			delete_cus();
			goto loop;
			break;
		}
		
// To Finish Program Execution:
		case '7':
		{				
				finish();
				return 0;
			}
		
				break;
			}
		
		}	
	
	}

}
	

// Manager Panel:
	if (a == 2)
	{
	// Taking Manager Name and Password:
	
		cout << "Enter Manager Name : ";
		cin  >> ad;
	// Password:
		cout << "Enter Password     : ";
		cin  >> pas;
		cout << endl<< endl;

// If Condition to Check Manager:
	if (ad != "Hassan" && pas != "manager123") 
{
	cout << "-----Sorry !! You enter wrong LogIn Information-----\n";
}

// While Loop:
	while(ad == "Hassan" && pas == "manager123")
	{
	// System Cls:
		system("cls");

	// Loop1: 
		loop1 :

	// Header:
		header();

	// Menu:
		menu1();

	// Options:
		cout << "\nSelect Your Option : ";
		cin  >> op;
	
// While Loop:
	while (op == '1' || op == '2' || op == '3')
	{

	// Switch Option :	
	switch(op)
	{
// Cases: 
	
	// To Add Customer: 	
		case '1' :
			{
				add();
				goto loop1;
				break;
			}
			
	// To Display All Customers: 
		case '2' :
			{
				display();
				goto loop1;
				break;
			}
	
	// To Finish Program Execution:
		case '3' : 
				{
					finish();
					return 0;
				
				}
	
			}	
		}
	}
}

// IF Condition For Other Than Admin & Manager:
	if (a == 3)
	{
		cout << "\nSorry you are not autherized to use this System.\n";
	}

// To Select The Option Again After Wrong Entering Information:
	cout << "\nDo you want to press option again (Y/N) for Admin/Manager/Other : ";
	cin  >> check;
	cout << endl <<endl;

// System CLS:
	system("cls");
}
	
// IF Condtion to End Whole Program Execution:
	if(check != 'Y'|| check !='y')
	{
		cout << "\nProgram ended Successfully... ";
	}
	return 0;
}
