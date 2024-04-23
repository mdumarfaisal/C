#include <iostream>
#include <string.h>
using namespace std;

class BloodBank
{
public:
    static int blood_group[8]; // using  Static Data Members
};

int BloodBank::blood_group[8] = {0, 0, 0, 0, 0, 0, 0, 0};//one dimensional array

class admin
{
public:
    int id;
    string name;
    int pass;

    void displayAll()
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
};

class donar
{
public:
    // donar();
    donar(int a1)
    {
        cout << "Total number of packet wants to donate : " << endl;
        int a;
        cin >> a;
        BloodBank::blood_group[a1] = BloodBank::blood_group[a1] + a;
    }
};

class patient
{
public:
    // patient();
    patient(int a1)
    {
        cout << "Total number of packet wants to recieve : " << endl;
        int a;
        cin >> a;
        BloodBank::blood_group[a1] = BloodBank::blood_group[a1] - a;
    }
};

int main()
{
    int n1 = 100;
    int i1 = 0;

    int n;
    do
    {
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
            admin z;
            z.displayAll();

            break;
        }

        

        case 2: // donar
        {
            cout << "Which blood do you want to donate" << endl;
            cout << "1.A 2.B 3.AB 4.O 5.A- 6.B- 7.AB- 8.O- : " << endl;

            int c1;
            cin >> c1;
            c1=c1-1;

            donar z(c1);

            break;
        }

        case 3: // patient
        {

            cout << "Which blood do you want to take" << endl;
            cout << "1.A 2.B 3.AB 4.O 5.A- 6.B- 7.AB- 8.O- : " << endl;

            int c2;
            cin >> c2;
            c2=c2-1;
            patient z1(c2);

            break;
        }

        case 4:
            cout << "Thank for Visiting !" << endl;
            break;
        }

    } while (n != 4);

    return 0;
}