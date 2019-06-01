#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string.h>
#include <stdlib.h>
using namespace std;
class hospital
{
public:
    void gethospital()
    {
        ofstream oh, hh;
        char group[3], name1[30];
        int quan1, m;
        char pass1[4];
        cout << "*******HOSPITAL ADMIN******" << endl
             << "----------------------------------"
             << endl
             << endl;
        cout << "Enter Password: ";
        cin >> pass1;
        if (!strcmp(pass1, "hospital"))
        {
            cout << "*******HOSPITAL ADMIN******" << endl
                 << "--------------------------------" << endl
                 << endl;
            cout << "Enter Hospital name :";
            cin >> name1;
            cout << endl
                 << "Enter hospital id:";
            cin >> m;
            cout << endl
                 << "Requested Blood group :";
            cin >> group;
            cout << endl
                 << "Requested Quantity (ml):";
            cin >> quan1;
            cout << endl
                 << endl
                 << endl
                 << "Thanks for the details, your request will shortly be approved by the Bank";

            oh.open("request.txt", ios::app);
            hh.open("list.txt", ios::app);
            oh << name1 << "\t" << endl
               << m << "\t" << endl
               << group << "\t" << endl
               << quan1 << "\t" << endl;
            hh << name1 << "\t" << endl
               << m << "\t" << endl
               << group << "\t" << endl
               << quan1 << "\t" << endl;
            oh.close();
            hh.close();
        }
        else
        {
            cout << "Incorrect Password ";
        }
    }
};

class admin
{
public:
    void getadmin()
    {
        cout << "*******BLOOD BANK ADMIN*******" << endl
             << "-------------------------------"
             << endl
             << endl;
        char pass[6];
        cout << "Enter Bank Password: ";
        cin >> pass;
        if (!strcmp(pass, "bank"))
        {

            while (1)
            {
                char name[30], ill[3], blood[3], name1[30], group[3];
                int s = 0, flag = 0, d = 0, dd = 0, mm = 0, yy = 0, age = 0, weight = 0, quan = 0, quan1 = 0, m = 0, k = 0;
                int ddd = 0, mmm = 0, yyy = 0, dd1 = 0, dd2 = 0, mm1 = 0, mm2 = 0, yy1 = 0, yy2 = 0;
                cout << "*******BLOOD BANK ADMIN*******" << endl
                     << "-------------------------------"
                     << endl
                     << endl;
                cout << "1.Donors applications." << endl
                     << "2.Database of Blood Samples ." << endl
                     << "3.List of Hospitals." << endl
                     << "4.Hospital Requests." << endl
                     << "5.Exit" << endl
                     << endl;
                cout << "Select an option to perform an operation :";
                cin >> s;

                if (s == 1)
                {

                    ifstream od;
                    od.open("donor.txt");
                    /*   cout << "******DONORS APPS********" << endl
                         << "-------------------------------"
                         << endl
                         << endl;*/
                    while (1)
                    {
                        cout << "******DONORS APPS********" << endl
                             << "-------------------------------"
                             << endl
                             << endl;
                        name[0] = '\0';
                        od >> name;
                        if (name[0] == '\0')
                        {
                            cout << endl
                                 << "----------------------";
                            break;
                        }

                        od >> age >> weight >> ill >> blood >> quan;
                        cout << "Name :" << name;
                        cout << endl
                             << "Age :" << age;
                        cout << endl
                             << "Any illness:" << ill;
                        cout << endl
                             << "Blood group:" << blood;
                        cout << endl
                             << "Quantity:" << quan;
                        cout << endl;
                        cout << "1.Accept" << endl
                             << "2.Reject" << endl
                             << endl
                             << "press the asigned number :";
                        cin >> d;
                        if (d == 1)
                        {

                            ofstream oa;
                            cout << "The seleceted form is accepted" << endl;
                            cout << "Enter todays date in the Format" << endl
                                 << "dd:";
                            cin >> dd;
                            cout << "mm:";
                            cin >> mm;
                            cout << "yyyy:";
                            cin >> yy;
                            oa.open("accept.txt", ios::app);
                            oa << name << "\t"
                               << endl
                               << age << "\t"
                               << endl
                               << weight << "\t"
                               << endl
                               << ill << "\t"
                               << endl
                               << blood << "\t"
                               << endl
                               << quan << "\t"
                               << endl
                               << dd << "\t"
                               << endl
                               << mm << "\t"
                               << endl
                               << yy << "\t"
                               << endl;
                            oa.close();
                        }
                        else if (d == 2)
                        {
                            cout << "Selected form is rejected" << endl;
                        }
                        else
                        {
                            cout << "Invalid Input" << endl;
                        }
                    }
                    od.close();
                    remove("donor.txt");
                }

                else if (s == 2)
                {
                    ifstream oa;
                    oa.open("accept.txt");
                    cout << "******DATABASE*********" << endl;
                    cout << "--------------------------";
                    while (1)
                    {
                        name[0] = '\0';
                        oa >> name;
                        if (name[0] == '\0')
                        {
                            cout << endl
                                 << "--------------------------" << endl;
                            break;
                        }
                        oa >> age >> weight >> ill >> blood >> quan >> dd >> mm >> yy;
                        cout << "Blood group:" << blood << endl
                             << "Donors name:" << name << endl
                             << "Quantity in ml:" << quan << endl
                             << "Date when blood is received: " << dd << "/" << mm << "/" << yy << endl
                             << endl;
                    }
                    oa.close();
                }

                else if (s == 3)
                {
                    cout << "**********HOSPITAL LIST***********" << endl
                         << "-------------------------------------"
                         << endl;
                    cout << "1. List of Hospitals" << endl
                         << "2. Update the List" << endl
                         << "3. Delete" << endl
                         << endl;
                    cout << "Select an option :";
                    cin >> d;
                    if (d == 1)
                    {
                        cout << "**********HOSPITAL LIST***********" << endl
                             << "-------------------------------------"
                             << endl;
                        ifstream hh;
                        hh.open("list.txt");
                        while (1)
                        {
                            name1[0] = '\0';
                            hh >> name1;
                            if (name1[0] == '\0')
                            {
                                cout << endl
                                     << "----------------------";
                                break;
                            }
                            hh >> m >> group >> quan1;
                            cout << "Name of the Hospital :" << name1;
                            cout << endl
                                 << "Hospital id :" << m;
                            cout << endl
                                 << endl;
                        }
                        hh.close();
                    }
                    else if (d == 2)
                    {
                        cout << "**********HOSPITAL LIST***********" << endl
                             << "-----------------------------------------"
                             << endl;
                        k = 0;
                        cout << endl
                             << "Enter the Hospital id you want to update :";
                        cin >> k;

                        ifstream hh;
                        hh.open("list.txt");
                        ofstream ht;
                        ht.open("t.txt");
                        while (1)
                        {
                            m = 0;
                            name1[0] = '\0';
                            hh >> name1;
                            if (name1[0] == '\0')
                            {
                                cout << endl
                                     << "--------------------------";
                                break;
                            }
                            hh >> m >> group >> quan1;
                            if (k != m)
                            {
                                ht << name1 << "\t" << endl
                                   << m << "\t" << endl
                                   << group << "\t" << endl
                                   << quan1 << "\t" << endl;
                                cout << "The given ID does not exist:";
                            }
                            else
                            {
                                cout << "Enter the new name for the hospital:";
                                cin >> name1;
                                ht << name1 << "\t" << endl
                                   << m << "\t" << endl
                                   << group << "\t" << endl
                                   << quan1 << "\t" << endl;
                                cout << "Your Update is successful";
                            }
                        }
                        hh.close();
                        ht.close();
                        remove("list.txt");
                        rename("t.txt", "list.txt");
                    }

                    else if (d == 3)
                    {

                        cout << "**********HOSPITAL LIST***********" << endl
                             << "--------------------------------------"
                             << endl;
                        k = 0;
                        cout << endl
                             << "Enter the hospital id you want to Delete :";
                        cin >> k;

                        ifstream hh;
                        hh.open("list.txt");
                        ofstream htt;
                        htt.open("tt.txt");

                        while (1)
                        {
                            m = 0;
                            name1[0] = '\0';
                            hh >> name1;
                            if (name1[0] == '\0')
                            {
                                cout << endl
                                     << "-------------------";
                                break;
                            }
                            hh >> m >> group >> quan1;
                            if (k != m)
                            {

                                htt << name1 << "\t" << endl
                                    << m << "\t" << endl
                                    << group << "\t" << endl
                                    << quan1 << "\t" << endl;
                            }
                            else
                            {
                                cout << endl
                                     << "Your given Record is Deleted";
                            }
                        }
                        hh.close();
                        htt.close();
                        remove("list.txt");
                        rename("tt.txt", "list.txt");
                    }
                    else
                    {
                        cout << "Invalid Choice";
                    }
                }

                else if (s == 4)
                {
                    cout << "********HOSPITAL REQUESTS*********" << endl
                         << "-----------------------------------------"
                         << endl
                         << endl;
                    ifstream oh;
                    oh.open("request.txt");
                    while (1)
                    {
                        cout << "*********HOSPITAL REQUESTS********" << endl
                             << "-----------------------------------------"
                             << endl
                             << endl;
                        name1[0] = '\0';
                        oh >> name1;
                        if (name1[0] == '\0')
                        {
                            cout << endl
                                 << "--------------------";
                            break;
                        }
                        oh >> m >> group >> quan1;
                        cout << "Name of the hospital :" << name1;
                        cout << endl
                             << "Hospital id :" << m;

                        cout << endl
                             << "Blood group needed:" << group;
                        cout << endl
                             << "Quantity needed:" << quan1;
                        cout << endl;
                        cout << "1.Accept" << endl
                             << "2.Reject" << endl
                             << endl
                             << "Select a choice :";
                        cin >> d;
                        if (d == 1)
                        {
                            ofstream hr;

                            cout << "Request Accepted" << endl;
                            cout << "Enters todays date in the fomat " << endl
                                 << "dd:";
                            cin >> ddd;
                            cout << "mm:";
                            cin >> mmm;
                            cout << "yyyy:";
                            cin >> yyy;
                            hr.open("acceptr.txt", ios::app);
                            hr << name1 << "\t" << endl
                               << m << "\t" << endl
                               << group << "\t" << endl
                               << quan1 << "\t" << endl
                               << ddd << "\t" << endl
                               << mmm << "\t" << endl
                               << yyy << "\t" << endl;
                            hr.close();
                        }
                        else if (d == 2)
                        {
                            cout << "Request rejected";
                        }
                        else
                        {
                            cout << "Invalid Input";
                        }
                    }
                    oh.close();
                    remove("request.txt");
                }

                else if (s == 5)
                {
                    flag = 1;
                }

                else
                {
                    cout << "Incorrect input";
                }

                if (flag == 1)
                {
                    break;
                }
            }
        }
        else
        {
            cout << "Incorrect Password";
        }
    }
};

class donor
{
public:
    void getdoner()
    {

        ofstream od;
        int age, weight, quan;
        char name[30], ill[3], blood[3];

        cout << "*******REGISTRATION FORM*******" << endl
             << "--------------------------------"
             << endl
             << endl;
        cout << "Enter Donors Name :";
        cin >> name;
        cout << endl
             << "Enter your Age :";
        cin >> age;
        if (age < 18)
        {
            cout << "Sorry you are not eligible to donate Blood" << endl;
            exit(0);
        }
        cout << endl
             << "Enter your Weight (KG):";
        cin >> weight;
        if (weight < 40)
        {
            cout << "Sorry you are not eligible to donate blood " << endl;
            exit(0);
        }
        cout << endl
             << "Have you ever been ill in your past life? " << endl
             << endl
             << "(Reply with either a yes or no)" << endl;
        cin >> ill;
        cout << endl
             << "Enter your Blood Group :";
        cin >> blood;
        cout << endl
             << "Enter the quantity of Blood you want to donate (ML) :";
        cin >> quan;
        cout << endl
             << endl
             << endl
             << "Thanks for the details, The form is sent to the Bank for approval." << endl;
        od.open("donor.txt", ios::app);
        od << name << "\t" << endl
           << age << "\t" << endl
           << weight << "\t" << endl
           << ill << "\t" << endl
           << blood << "\t" << endl
           << quan << "\t"
           << endl;
        od.close();
    }
};

class search
{
public:
    void getsearch()
    {
        ifstream bc;
        char bsample[10], name[30], ill[3], blood[3], quan[3], age[3], weight[4], dd[3], mm[4], yyyy[6];
        bc.open("accept.txt");
        cout << " Search Results" << endl
             << "-------------------------" << endl
             << endl;
        while (1)
        {
            name[0] = '\0';
            bc >> name;
            if (name[0] == '\0')
            {
                cout << endl
                     << "--------------------------" << endl;
                break;
            }
            bc >> age >> weight >> ill >> blood >> quan >> dd >> mm >> yyyy;
            cout << "Enter the Blood Sample you want to check for its availability:";
            cin >> bsample;
            if (strcmp(bsample, blood) == 0)
            {
                cout << "Blood Samples Available: " << endl;
                cout << "-------------------------------" << endl
                     << endl;
                cout << "Donors Name: " << name << endl
                     << "Donors age: " << age << endl
                     << "Donors Weight: " << weight << endl
                     << "Has Donor ever been sick?: " << ill << endl
                     << "Donors Blood Group: " << blood << endl
                     << "Blood Quantity Available: " << quan << " ml" << endl;
                cout << "-----------------------------" << endl;
            }
            else
            {
                cout << "----------------------------" << endl;
                cout << "No Blood Samples Available" << endl;
                cout << "----------------------------" << endl;
                break;
            }
        }
        bc.close();
    }
};
int main()
{
    int a, f = 0;

    while (1)
    {
        cout << "*********BLOOD BANK***********" << endl;
        cout << "--------------------------------" << endl
             << endl;

        cout << "1. Blood Donation Form" << endl
             << "2. Blood Bank Portal " << endl
             << "3. Hospital Portal " << endl
             << "4. Search for Blood Sample Availability: " << endl
             << "5. Exit " << endl
             << endl;

        cout << "Select an option to perform a Task :";
        cin >> a;
        if (a == 1)
        {
            donor d;
            d.getdoner();
        }

        else if (a == 2)
        {
            admin a;
            a.getadmin();
        }

        else if (a == 3)
        {
            hospital h;
            h.gethospital();
        }
        else if (a == 4)
        {
            search s;
            s.getsearch();
        }
        else if (a == 5)
        {
            f = 1;
        }
        else
        {
            cout << "Invalid Option Selection";
        }

        if (f == 1)
        {
            break;
        }
    }
    return 0;
}
