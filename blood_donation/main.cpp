#include <iostream>
#include <string.h>
using namespace std;



class BloodBank
{
public:
    static int blood_group[8]; // using  Static Data Members
};

int BloodBank::blood_group[8] = {0, 0, 0, 0, 0, 0, 0, 0}; // one dimensional array

class admin
{
public:
    int id;
    string name;
    int pass;

    int admincheck()
    {
        cout << "Enter Id: ";
        cin >> id;
        cout << "Enter Name: ";
        cin >> name;
        cout << "Enter Pass: ";
        cin >> pass;
        if ((id == 1001) && (name == "Faisal") && (pass == 2023))
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    virtual void displayAll()
    {
        if (admincheck() == 1)
        {
            cout << "A+   " << BloodBank::blood_group[0] << " packet." << endl;
            cout << "B+   " << BloodBank::blood_group[1] << " packet." << endl;
            cout << "AB+  " << BloodBank::blood_group[2] << " packet." << endl;
            cout << "O+   " << BloodBank::blood_group[3] << " packet." << endl;
            cout << "A-   " << BloodBank::blood_group[4] << " packet." << endl;
            cout << "B-   " << BloodBank::blood_group[5] << " packet." << endl;
            cout << "AB-  " << BloodBank::blood_group[6] << " packet." << endl;
            cout << "O-   " << BloodBank::blood_group[7] << " packet." << endl;
        }

        else
        {
            cout << endl;
            cout << "WRONG CREDENTENTIAL !!!";
            cout << endl;
            cout << "Enter a Valid credentials";
        }
    }
};

class securitycheck : public admin
{

    void displayAll()
    {
        if (admincheck() == 1)
        {
            cout << "A+   " << BloodBank::blood_group[0] << " packet." << endl;
            cout << "B+   " << BloodBank::blood_group[1] << " packet." << endl;
            cout << "AB+  " << BloodBank::blood_group[2] << " packet." << endl;
            cout << "O+   " << BloodBank::blood_group[3] << " packet." << endl;
            cout << "A-   " << BloodBank::blood_group[4] << " packet." << endl;
            cout << "B-   " << BloodBank::blood_group[5] << " packet." << endl;
            cout << "AB-  " << BloodBank::blood_group[6] << " packet." << endl;
            cout << "O-   " << BloodBank::blood_group[7] << " packet." << endl;
        }

        else
        {
            cout << endl;
            cout << "WRONG CREDENTENTIAL !!!";
            cout << endl;
            cout << "Enter a Valid credentials";
        }
    }
};

class donar
{
public:
    int testrequired;
    int blooddonor;

    // donar();

    friend int testoutput(donar &); // Friend Function

    donar()
    {
    }

    donar(int a1) // CONSTRUCTOR
    {

        cout << "Total number of packet wants to donate : " << endl;
        int a;
        cin >> a;
        blooddonor = a;
        BloodBank::blood_group[a1] = BloodBank::blood_group[a1] + a;
    }

    int blooddonar1()
    {

        return blooddonor;
    }

    bool testoutput(int test1)
    {

        if (blooddonor >= 1)
        {
            if (testrequired == 1)
            {

                cout << "SUCCESSFULLY DONATED!" << endl;
            }
            else
            {
                cout << "YOUR TEST REPORT ARE NOT HEALTHY SO BETTER LUCK NEXT TIME" << endl;
            }
        }

        else
        {
            cout << "Enter a valid Number of packets" << endl;
        }
    }
    ~donar() // DESTRUCTOR
    {
        cout << endl;
        cout << "1.Enter blood donation portal again." << endl;
        cout << "2.EXIT" << endl;
        int a;
        cout << "CHOOOSE ANY FROM ABOVE!  ";
        cin >> a;
        if (a == 1)
        {
        }
        else
        {
            exit(0);
        }
    }
};

// friend function definition
int testoutput(donar &d)
{
    int BloodPressureupper, BloodPressurelower, Pulse, Hemoglobin, anyinfectiousdisease; // DATA FOR TESTREQUIRED

    // BloodPressure -- 180/100 mmHg
    //  pulse   --  50-100 beats per minute
    //  Hemoglobin -- MALE  13 mg/dL   FEMALE - 12.5 mg/dl
    //   anyinfectiousdisease  0 -NO  ,1-YES
    cout << endl;
    cout << "Enter your Health details" << endl;
    cout << " BloodPressure upper limit:  ";
    cin >> BloodPressureupper;

    cout << " BloodPressure lower limit:  ";
    cin >> BloodPressurelower;

    cout << " Pulse : ";
    cin >> Pulse;
    cout << " Hemoglobin:  ";
    cin >> Hemoglobin;
    cout << " anyinfectiousdisease (1 for yes   or 0 for  no): ";
    cin >> anyinfectiousdisease;

    if ((BloodPressureupper >= 180) && (BloodPressurelower >= 100) && (Pulse > 50) && (Pulse < 100) && (Hemoglobin > 13) && (anyinfectiousdisease == 0))
    {
        d.testrequired = 1;
    }

    else
    {
        d.testrequired = 0;
    }
}

class patient
{
public:
    // data
    int bloodtakeaway;

    // patient();
    patient(int a1) // CONSTRUCTOR
    {
    }

    void takeaway(int a1, int pack)
    {
        // cout << "Total number of packet wants to recieve : " << endl;
        int a;
        a = pack;
        bloodtakeaway = a;

        int checkquantityavailable;
        checkquantityavailable = BloodBank::blood_group[a1] - a;

        if (checkquantityavailable > 0)
        {
            if (bloodtakeaway > 0)
            {
                BloodBank::blood_group[a1] = BloodBank::blood_group[a1] - a;
                cout << endl;
                cout << "SUCCESSFULLY BLOOD RECIEVED" << endl;
            }

            else
            {
                cout << "PLEASE ENTER A VALID PACKETS";
            }
        }

        else
        {
            cout << "SORRY WE DONT HAVE REQUIRED BLOOD PACKETS";
        }
    }

    void takeaway(int a1, float pack)
    {
        cout << "SORRY WE HAVE NOT ANY FEATURE LIKE THIS";
    }

    ~patient() // DESTRUCTOR
    {
    }
};

int main()
{
    int n1 = 100;
    int i1 = 0;

    int n;
    do
    {
        cout << "\n"
             << "\n";
        cout << "\tWELCOME TO BLOOD MANAGEMENT SYSTEM! \t" << endl
             << endl;
        cout << "1.ADMIN" << endl;
        cout << "2.DONAR" << endl;
        cout << "3.PATIENT" << endl;
        cout << "4.EXIT" << endl;

        cin >> n;

        switch (n)
        {
        case 1:
        {

            admin *z;
            securitycheck z1;

            z = &z1;

            z->displayAll();

            break;
        }

        case 2: // donar
        {

            cout << "Which blood do you want to donate" << endl;
            cout << "1.A 2.B 3.AB 4.O 5.A- 6.B- 7.AB- 8.O- : " << endl;

            int c1;
            cin >> c1;
            c1 = c1 - 1;
            donar z(c1);
            testoutput(z);
            if (z.testoutput(1))
            {
                BloodBank::blood_group[c1] = BloodBank::blood_group[c1] - z.blooddonar1();
            }

            break;
        }

        case 3: // patient
        {

            cout << "Which blood do you want to take" << endl;
            cout << "1.A 2.B 3.AB 4.O 5.A- 6.B- 7.AB- 8.O- : " << endl;

            int c2;
            int pac;
            float ml;
            int amount;

            cin >> c2;
            c2 = c2 - 1;
            patient z1(c2);

            cout << "Want Blood in Packet(1) or Ml(2) : ";
            cin >> amount;
            if (amount == 1)
            {
                cout << "Total number of packet wants to recieve : ";
                cin >> pac;
                z1.takeaway(c2, pac);
            }
            else if (amount == 2)
            {
                cout << "Total amount of blood wants to recieve in ml : ";
                cin >> ml;
                z1.takeaway(c2, ml);
            }

            break;
        }

        case 4:
            cout << "Thank for Visiting !" << endl;
            break;
        }

    } while (n != 4);

    return 0;
}

/*--------------------- CONCEPT USED  IN  THIS PROJECT----------------------------------------*/
/*

 1. Single inheritance
 2. Hierarchical Inheritance
 3. Classes and Objects
 4. Static Data Members
 5. Constructors and Destructors
 6. Friend Functions
 7.Functions with default Arguments.
 8. Function Overloading
 9.Virtual Functions
 10.

 */
