#include <iostream>
#include "pharmacy.h"
#include <stdlib.h>
#include <conio.h>
#include <string>

using namespace std;

int main () {
    pharmacys mainPharmacy;
    createListPharmacy(mainPharmacy);
    addressPharmacy addPharmacy;
    infotypePharmacy dataPharmacy;
    addressDrug addDrug;
    infotypeDrug dataDrug;

//created by purnama sari//
    {   // Test Case Parent pharmacy

        dataPharmacy.idPharmacy = "Pharmacy-0010";
        dataPharmacy.Pharmacyname = "K-24 Pharmacy";
        dataPharmacy.location= "San Bojongsoang Street";
        dataPharmacy.day=" "    ;
        addPharmacy = alokasiPharmacy(dataPharmacy);
        insertLastPharmacy(mainPharmacy, addPharmacy);


        dataPharmacy.idPharmacy = "Pharmacy-0015";
        dataPharmacy.Pharmacyname = "Princeton Pharmacy";
        dataPharmacy.location= "Buah Batu Loop Street";
        dataPharmacy.day=" "    ;
        addPharmacy = alokasiPharmacy(dataPharmacy);
        insertLastPharmacy(mainPharmacy, addPharmacy);



        dataPharmacy.idPharmacy = "Pharmacy-0020";
        dataPharmacy.Pharmacyname = "Kimia Farma Pharmacy";
        dataPharmacy.location= "Seotta Street";
        dataPharmacy.day=" "    ;
        addPharmacy = alokasiPharmacy(dataPharmacy);
        insertLastPharmacy(mainPharmacy, addPharmacy);


        dataPharmacy.idPharmacy = "Pharmacy-0025";
        dataPharmacy.Pharmacyname = "Pooreun Pharmacy";
        dataPharmacy.location= "Gyeongsangnam Street";
        dataPharmacy.day=" "    ;
        addPharmacy = alokasiPharmacy(dataPharmacy);
        insertLastPharmacy(mainPharmacy, addPharmacy);



        dataPharmacy.idPharmacy = "Pharmacy-0030";
        dataPharmacy.Pharmacyname = "Suyaggug Pharmacy";
        dataPharmacy.location= "Seoul Street";
        dataPharmacy.day=" "    ;
        addPharmacy = alokasiPharmacy(dataPharmacy);
        insertLastPharmacy(mainPharmacy, addPharmacy);

        //created by hasna zakiyyah//
        //Test case drug

        dataDrug.idDrug="Drug-001";
        dataDrug.Drugname="Oskadon";
        dataDrug.kind="dizziness";
        dataDrug.price="10000";
        dataDrug.stock= "10";
        dataDrug.expired="22 August 2018";
        addPharmacy = findElmPharmacy(mainPharmacy, "Pharmacy-0030");
        insertDrugFirst(addPharmacy, dataDrug);

        dataDrug.idDrug="Drug-001";
        dataDrug.Drugname="Paracetamol";
        dataDrug.kind="fever";
        dataDrug.price="15000";
        dataDrug.stock= "20";
        dataDrug.expired="27 September 2018";
        addPharmacy = findElmPharmacy(mainPharmacy, "Pharmacy-0030");
        insertDrugFirst(addPharmacy, dataDrug);

        dataDrug.idDrug="Drug-002";
        dataDrug.Drugname="Betadine";
        dataDrug.kind="antiseptic";
        dataDrug.price="17000";
        dataDrug.stock= "25";
        dataDrug.expired="17 July 2019";
        addPharmacy = findElmPharmacy(mainPharmacy, "Pharmacy-0030");
        insertDrugFirst(addPharmacy, dataDrug);
    }
    Druglabel:
    system("cls");
    cout << "- - - ASD BIG PROJECT [1301164599 & 1301160541] - - -"<<endl;
    cout << "Pharmacy's and Drug's";
      cout   <<endl;
cout<< "1. Insert Pharmacy Store" << endl;
cout<< "2. Insert Drug Pharmacy" << endl;
cout<< "3. Edit Pharmacy Info" << endl; // By ID
cout<< "4. Edit Drug Pharmacy Info" << endl; // Based on Drug ID
cout<< "5. Delete Pharmacy" << endl; // Based on ID
cout<< "6. Delete Pharmacy Drugs" << endl; // Based on Drug ID
cout<< "7. Print Pharmacy Info" << endl;
cout<< "8. Print Pharmacy & Drug" << endl;
cout<< "9. Search Pharmacy" << endl; // Based on APK ID
cout<< "10. Search Pharmacy Drugs" << endl; // Based on Pharmacies
cout<< "11. Sorting Pharmacy by ID" << endl;
cout<< "12. Sorting Drug Pharmacy by ID" << endl;
cout<< "13. Calculate Total Pharmacy / Drug" << endl;
cout<< "0. EXIT" << endl;
    cout << endl;
    cout << "choose menu (number) "; int Drug;
    cin>>Drug; cin.ignore();
    switch (Drug) {
        case 1   :  system("cls"); addpharmacys(mainPharmacy);  getch(); goto Druglabel;
        case 2   :  system("cls"); addDrugPharmacy(mainPharmacy);         getch(); goto Druglabel;
        case 3   :  system("cls"); editInfoPharmacy(mainPharmacy);        getch(); goto Druglabel;
        case 4   :  system("cls"); editDrug(mainPharmacy);     getch(); goto Druglabel;
        case 5   :  system("cls"); deletePharmacyOption(mainPharmacy);    getch(); goto Druglabel;
        case 6   :  system("cls"); deleteDrugOption(mainPharmacy);  getch(); goto Druglabel;
        case 7   :  system("cls"); printInfoPharmacy(mainPharmacy);       getch(); goto Druglabel;
        case 8   :  system("cls"); printInfoDrug(mainPharmacy);     getch(); goto Druglabel;
        case 9   :  system("cls"); searchPharmacy(mainPharmacy);          getch(); goto Druglabel;
        case 10  :  system("cls"); searchDrug(mainPharmacy);        getch(); goto Druglabel;
        case 11  :  system("cls"); sortpharmacys(mainPharmacy);    getch(); goto Druglabel;
        // case 12  :  system("cls"); sortDrug(mainPharmacy);          getch(); goto druglabel;
        case 13  :  system("cls"); menucountDrug(mainPharmacy);          getch(); goto Druglabel;
        case 0   :  goto ExitLabel; // Case Exit
        default  : cin.ignore();  goto Druglabel; // Case Handling Inputan Lain
    }
    ExitLabel: ;

    return 0;
}

