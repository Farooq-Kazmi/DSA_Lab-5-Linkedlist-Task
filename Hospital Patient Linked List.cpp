#include <iostream>
using namespace std;
struct Patient{
	int ID;
	Patient *Next;
};
Patient *Head=0;
void end(int id){
	Patient *NewPatient=new Patient;
	NewPatient->ID=id;
	NewPatient->Next=0;
	
	if(Head==0)
	{
		Head= NewPatient;
	}
	else
	{
		Patient *temp=Head;
		while(temp->Next!=0)
	{
		temp=temp->Next;
	}
	temp->Next=NewPatient;
	}
}

void beg(int id){
	Patient *NewPatient=new Patient;
	NewPatient->ID=id;
	NewPatient->Next=Head;
	Head=NewPatient;
}

void display(){
	if(Head==0)
	{
		cout<<"No Patients in the list"<<endl;
	}
	else
	{
		Patient *temp=Head;
		while(temp!=0)
		{
			cout<<temp->ID<<endl;
			temp=temp->Next;
		}
	}
}


int main(){
	int ID,Choice;
	while(true)
	{
		cout << "\n--- Patient List ---\n";
        cout << "1. Emergency Patient\n";
        cout << "2. New Check-in\n";
        cout << "3. Display List\n";
        cout << "4. Exit\n";
        cout << "Enter Choice: ";
        cin >> Choice;
        
        if (Choice==1)
		{
            cout<<"Enter Patient ID: ";
            cin>>ID;
            beg(ID);
        }
        else if(Choice==2)
		{
            cout<<"Enter Patient ID: ";
            cin>>ID;
            end(ID);
        }
        else if(Choice==3)
		{
            display();
        }
        else if(Choice==4)
		{
            break;
        }
        else
		{
            cout << "Invalid choice!" << endl;
        }
    } 

    return 0;
}