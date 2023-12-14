//
//  main.cpp
//  hospital management system
//
//  Created by syeda manahil fatima on 04/02/2023.
//

#include <iostream>
#include<iomanip>
#include<fstream>
#include<string>
#include<ctime>
using namespace std;
void display()
{
    cout<<endl;
    cout<<"---------------------------------------------------------------------"<<endl;
    cout<<"*                                                                   *"<<endl;
    cout<<"*\t\t\t\t                                                    *"<<endl<<"*\t\t\t\t[1]. ADD new patient record                         *"<<endl<<"*\t\t\t\t                                                    *"<<endl <<"*\t\t\t\t[2]. DOCTORS PRESENT TODAY                          *"<<endl<<"*\t\t\t\t                                                    *"<<endl <<"*\t\t\t\t[3]. INFORMATION of  patient                        *"<<endl<<"*\t\t\t\t                                                    *"<<endl <<"*\t\t\t\t[4]. DETAIL about the hospital                      *"<<endl<<"*\t\t\t\t                                                    *"<<endl <<"*\t\t\t\t[5]. exit the program                               *"<<endl<<"*\t\t\t\t                                                    *"<<endl;
    cout<<"*                                                                   *"<<endl;
    cout<<"---------------------------------------------------------------------"<<endl;
}

void record()
{
    string name,address,bg,disease,sex,contact;
    int age,id;
    ofstream datafile("file.txt", ios::app);
    cout<<"enter name of the patient"<<endl;
    cin>>name;
    cout<<"enter address of the patient"<<endl;
    cin>>address;
    cout<<"enter blood group of the patient"<<endl;
    cin>>bg;
    cout<<"enter disease of the patient"<<endl;
    cin>>disease;
    cout<<"enter sex of the patient"<<endl;
    cin>>sex;
    cout<<"enter contact of the patient"<<endl;
    cin>>contact;
    cout<<"enter age of the patient"<<endl;
    cin>>age;
    cout<<"enter the patient id"<<endl;
    cin>>id;
   datafile<<name<<"\t"<<address<<"\t"<<bg<<"\t"<<disease<<"\t"<<sex<<"\t"<<contact<<"\t"<<age<<"\t"<<id<<"\t"<<endl;
    datafile.close();
    cout<<"INFORMATION SAVED SUCCESFULLY!!!"<<endl;
}

void doctors()
{
    int doc=0;
    string name;
    time_t now=time(0);
    char *dt = ctime(&now);
    ofstream datafile("file.txt", ios::app);
    cout<<"we have the following doctors"<<endl<<endl<<"Dr. Aroosh gynaecologist"<<endl<<"Dr. Jaffar for pediatrician"<<endl<<"Dr. Kainat oncologist"<<endl<<"Dr. Waqas general physician"<<endl<<"Dr. Tanjina ENT"<<endl<<"Dr. Ghania Gillani dentist"<<endl<<endl;
    cout<<"enter your name to mark present"<<endl<<endl<<"enter 'done' when you are done"<<endl<<endl;
    for( int i=0; i<5; i++)
    {
        cin>>name;
        if(name=="aroosh"){
            doc++;
        }
        if(name=="jaffar"){
            doc++;
        }
        if(name=="kainat"){
            doc++;
        }
        if(name=="waqas"){
            doc++;
        }
        if(name=="tanjina"){
            doc++;
        }
        if(name=="done"){
            break;
        }
    }
    cout<<"total present doctors on "<<dt<<"are: "<<doc<<endl;
    datafile<<name<<"\t"<<doc<<"\t"<<endl;
     datafile.close();
}

void search()
{
    string search,line;
    cout<<"press enter to proceed searching"<<endl;
    ifstream searchfile("file.txt", ios::in);
    cout<<"enter patient name to search"<<endl;
    cin>>search;
    while (!searchfile.eof())
    {
        searchfile>>line;
        if(search==line)
        {
            cout<<line<<" ";
            getline(searchfile, line);
            cout<<line<<endl;
        }
        else continue;
    }
    cout<<endl;
    searchfile.close();
}

void detail()
{
    ifstream datafileoutput("file.txt", ios::in);
    string line;
    cout<<"the whole record of hospital patients is: "<<endl;
    cout<<"name\t"<<"adress\t"<<"blood group\t"<<"disease\t"<<"sex\t"<<"contact\t"<<"age\t"<<"id\t"<<endl;
    while(!datafileoutput.eof())
    {
        getline(datafileoutput, line);
        cout<<line<<endl;
    }
}

int main() {
    int option;
    time_t now=time(0);
    char *dt = ctime(&now);
    cout<<endl;
    cout<<endl;
    cout<<"                           FAST HOSPITAL            "<<endl;
    cout<<"                           -------------"<<endl;
    cout<<endl;
    cout<<"                    W E L C O M E. GET WELL SOON"<<endl;
    cout<<endl;
    cout<<"Enter your corresponding action for today:  "<<dt<<endl;
    for(int i=0; option!=5;i++)
    {
        display();
        cout<<endl;
        cin>>option;
        if(option>0 && option<5){
    switch(option)
    {
        case 1:
            cout<<"___________________________________________________________________"<<endl;
            record();
            break;
        case 2:
            cout<<"___________________________________________________________________"<<endl;
           doctors();
            break;
        case 3:
            cout<<"___________________________________________________________________"<<endl;
            search();
            break;
        case 4:
            cout<<"___________________________________________________________________"<<endl;
            detail();
            break;
    }
        }
        else if(option==5)
            break;
        else
            cout<<"enter correct choice"<<endl;
    }
    return 0;
}

