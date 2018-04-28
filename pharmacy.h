#ifndef PHARMACY_H_INCLUDED
#define PHARMACY_H_INCLUDED

// ---- Library --- //
#include <iostream>
#include <time.h>


// Define Pointer
#define info(P) P->info
#define next(P) P->next
#define prev(P) P->prev
#define first(R) (R).first
#define last(R) (R).last

using namespace std;

// ---- Deklarasi Pointer addressAPK --- //
typedef int *addressMember;
typedef struct elmPharmacy *addressPharmacy;
typedef struct elmDrug *addressDrug;

// ----- Deklarasi Tipe Bentukan Infotype ----- //
struct infotypePharmacy
{
    string idPharmacy;
    string Pharmacyname;
    string location;
    string day;
};

struct infotypeDrug {
    string idDrug;
    string Drugname;
    string expired;
    string stock;
    string price;
    string kind;

};

// ------ Tipe Bentukan Element List ------ //

//Tipe bentukan Parent Apotek
struct elmPharmacy
{
    infotypePharmacy info;
    addressDrug Druglist;
    addressPharmacy next;
    addressPharmacy prev;
};

//Tipe bentukan Child Obat
struct elmDrug
{
    infotypeDrug info;
    addressDrug next;
};

// ------ Tipe Bentukan List ----- //
struct pharmacys
{
    addressPharmacy first;
    addressPharmacy last;
};

struct Drug
{
    addressDrug first;
};

//----------------- Fungsi dan Prosedur Default ----------------//
void createListDrug(Drug &R);
void createListPharmacy(pharmacys &Pharmacy);
void createDrug(infotypeDrug &DrugPharmacy);
addressPharmacy alokasiPharmacy(infotypePharmacy Pharmacy);
addressDrug alokasiDrug(infotypeDrug DrugPharmacy);

addressPharmacy findElmPharmacy(pharmacys R, string idPharmacy);
addressDrug findElmDrug(addressPharmacy PPharmacy, string idDrug);

void printInfoPharmacy(pharmacys Pharmacy);
void printInfoDrug(pharmacys Pharmacy);
void editInfoPharmacy(pharmacys &Pharmacy);
void editDrug(pharmacys &Pharmacy);
void searchPharmacy(pharmacys Pharmacy);
void searchDrug(pharmacys Pharmacy);

void insertDrugFirst(addressPharmacy PPharmacy, infotypeDrug addDrug);
void insertDrugLast(addressPharmacy PPharmacy, infotypeDrug addDrug);
void insertDrugAfter(addressPharmacy PPharmacy, infotypeDrug addDrug);
void addDrugPharmacy(pharmacys &Pharmacy);

addressPharmacy deleteFirstPharmacy(pharmacys &Pharmacy);
void deleteLastPharmacy(pharmacys &Pharmacy);
void deleteAfterPharmacy(pharmacys &Pharmacy);
void deletePharmacybyID(pharmacys &Pharmacy);
void deletePharmacyOption(pharmacys &Pharmacy);

void deleteDrugFirst(pharmacys &Pharmacy);
void deleteDrugAfter(pharmacys &Pharmacy);
void deleteDrugLast(pharmacys &Pharmacy);
void deleteDrugByID(pharmacys &Pharmacy);
void deleteDrugOption(pharmacys &Pharmacy);

void insertFirstPharmacy(pharmacys &R, addressPharmacy P);
void insertLastPharmacy(pharmacys &R, addressPharmacy P);
void insertAfterPharmacy(pharmacys &R, addressPharmacy P);
void addpharmacys(pharmacys &R);

void countTotalPharmacy(pharmacys Pharmacy);
void countTotalDrug(pharmacys Pharmacy);
void menucountDrug(pharmacys Pharmacy);


void sortpharmacys(pharmacys &Pharmacy);
void sortDrug(addressDrug &Pharmacy);

#endif // PHARMACY_H_INCLUDED
