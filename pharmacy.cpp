#include "pharmacy.h"
#include <iostream>


using namespace std;

//----------------- Create ----------------//

void createListPharmacy(pharmacys &R)
{
    first(R)= NULL;
    last(R)= NULL;
}
void createListDrug(Drug &R)
{
    first(R)= NULL;
}

void createPharmacy(infotypePharmacy &Pharmacy)
{

    cout<<"** Input New Apotek **"<<endl;
    cout<<"Input Pharmacy's ID      : ";
    getline(cin, Pharmacy.idPharmacy);
    cout<<"Pharmacy's name   : ";
    getline(cin, Pharmacy.Pharmacyname);
    cout<<"Location of Pharmacy : ";
    getline(cin, Pharmacy.location);
    time_t now = time(0);
    string dt = ctime(&now);
    cout<<"Input date : "<<dt;
    Pharmacy.day=dt;
}

void createDrug(infotypeDrug &DrugPharmacy)
{
    cout<<"== Input New Drug =="<<endl;
    cout<<"Input Drug's ID : ";
    getline(cin, DrugPharmacy.idDrug);
    cout<<"Drug's name    : ";
    getline(cin, DrugPharmacy.Drugname);
    cout<<"Kind of Drug   : ";
    getline(cin, DrugPharmacy.kind);
    cout<<"Stock of Drug    : ";
    getline (cin, DrugPharmacy.stock);
    cout<<"Expired   : ";
    getline(cin, DrugPharmacy.expired);
    cout<<"Price (Rp.)   : ";
    cin>>DrugPharmacy.price;
    cin.ignore();

    cout<<endl;
}

//----------------- Address ----------------//

addressPharmacy alokasiPharmacy(infotypePharmacy Pharmacy)
{
    addressPharmacy P;
    P = new elmPharmacy;
    info(P) = Pharmacy;
    next(P) = NULL;
    prev(P) = NULL;
    P->Druglist = NULL;
    return P;
}

addressDrug alokasiDrug(infotypeDrug DrugPharmacy)
{
    addressDrug Q = new elmDrug;
    Q->info = DrugPharmacy;
    Q->next = NULL;
    return Q;
}

addressPharmacy findElmPharmacy(pharmacys R, string idPharmacy)
{
    addressPharmacy P;
    if(first(R) == NULL)
    {
        return NULL;
    }
    else
    {
        bool found = false;
        P = first(R);
        while ((info(P).idPharmacy != idPharmacy) && (found == false))
        {
            if (next(P) == NULL)
            {
                found = true;
            }
            else
            {
                P = next(P);
            }
        }
        if (found)
            return NULL;
        else
            return P;
    }
}

addressDrug findElmDrug(addressPharmacy PPharmacy, string idDrug)
{
    addressDrug M;
    M = PPharmacy->Druglist;
    if (M==NULL)
        return NULL;
    else
    {
        while (M != NULL)
        {
            if (M->info.idDrug == idDrug)
            {
                return M;
            }
            M = M -> next;
        }
        return M;
    }
}

//----------------- View ----------------//

void printInfoPharmacy(pharmacys Pharmacy)
{
    addressPharmacy P;
    P = Pharmacy.first;
    if(Pharmacy.first == NULL)
        cout<<"There is no pharmacy that you want"<<endl;
    else
    {
        cout<<"========== Pharmacy's list that found =========="<<endl;
        int i = 1;
        while(P != NULL)
        {

            cout<<"Data Pharmacy Ke-"<<i<<endl;
            i++;
            cout<<"Pharmacy's ID                : "<<P->info.idPharmacy<<endl;
            cout<<"Pharmacy's name              : "<<P->info.Pharmacyname<<endl;
            cout<<"Location Of Pharmacy         : "<<P->info.location<<endl;
            cout<<"Date of pharmacy inventory   : "<<P->info.day<<endl;
            cout<<endl;
            P = P->next;
        }
    }
}

void printInfoDrug(pharmacys Pharmacy)
{
    addressPharmacy P;
    addressDrug Q;
    P = Pharmacy.first;
    if(Pharmacy.first == NULL)
        cout<<"There is no pharmacy that you want"<<endl;
    else
    {
        cout<<"==== List of Pharmacy with the Drug ===="<<endl;
        cout<<endl;
        int i = 1;
        while(P != NULL)
        {
            cout<<"--- Data Pharmacy ke-"<<i<< " ---"<<endl;
            i++;
            cout<<"Pharmacy's ID    : "<<P->info.idPharmacy<<endl;
            cout<<"Pharmacy's name  : "<<P->info.Pharmacyname<<endl;
            Q = P->Druglist;
            if(Q==NULL)
            {
                cout<<"\n====== Drug is empty ======"<<endl;
            }
            else
            {
                cout<<"\n====== Drug's list ======"<<endl;
            }
            while(Q != NULL)
            {
                cout<<"Drug's ID        : "<<Q->info.idDrug<<endl;
                cout<<"Drug's name      : "<<Q->info.Drugname<<endl;
                cout<<"Kind Of Drug     : "<<Q->info.kind<<endl;
                cout<<"Price            : "<<Q->info.price<<endl;
                cout<<"Drug's stock     : "<<Q->info.stock<<endl;
                cout<<"Expired          : "<<Q->info.expired<<endl;
                cout<<endl;
                Q = Q->next;
            }
            cout<<endl;
            P = P->next;
        }
    }
}


//----------------- Editing ----------------//

void editInfoPharmacy(pharmacys &Pharmacy)
{
    if(Pharmacy.first != NULL)  //Cek Apotek Apakah Kosong atau Tidak
    {
        printInfoPharmacy(Pharmacy);
        string strSearchPharmacy;
        cout << "Input ID Pharmacy that you want to edit: ";
        cin>>strSearchPharmacy;
        cin.ignore();
        addressPharmacy PPharmacy = findElmPharmacy(Pharmacy, strSearchPharmacy); //Mencari Elemen Apotek
        if(PPharmacy == NULL)
        {
            cout<<"Pharmacy's ID is not found"<<endl;
            cout<<endl;
        }
        else
        {
            cout<<"Pharmacy's ID is found"<<endl;
            cout<<"Edit Pharmacy's name : ";
            getline(cin, PPharmacy->info.Pharmacyname);
            cout<<"Edit Pharmacy's location: ";
            getline(cin, PPharmacy->info.location);
            cout<<"Edit Successfull"<<endl;
            cout<<endl;
        }
    }
    else
    {
        cout<<"There is no Pharmacy that can be edit"<<endl;
    }
}

void editDrug(pharmacys &Pharmacy)
{
    if(Pharmacy.first == NULL)
        cout<<"There is no Pharmacy that you want"<<endl;
    else
    {
        printInfoPharmacy(Pharmacy);
        string strSearchID;
        string strSearchIDDrug;
        cout << "Input Drug's ID that you want to edit the price of it : ";
        getline(cin, strSearchID);
        addressPharmacy PPharmacy = findElmPharmacy(Pharmacy, strSearchID);
        if (PPharmacy == NULL)
        {
            cout << "Pharmacy is not found";
        }
        else
        {
            addressDrug M = PPharmacy->Druglist;
            cout << "List Drug Pharmacy - "<<PPharmacy->info.Pharmacyname<<endl;
            while (M != NULL)  // Looping Untuk Menampilkan Obat Apotek
            {
                cout<<"Drug's ID        : "<<M->info.idDrug<<endl;
                cout<<"Drug's name      : "<<M->info.Drugname<<endl;
                cout <<"Kind of Drug    : "<<M->info.kind<<endl;
                cout <<"Price           : "<<M->info.price<<endl;
                cout <<"Drug's stock    : "<<M->info.stock<<endl;
                cout<<endl;
                M = M->next;
            }
            cout << endl;
            cout << "Input Drug's ID that you want to edit the price of it  : ";
            getline(cin, strSearchIDDrug);
            M = PPharmacy->Druglist;
            while (M != NULL)
            {
                if (M->info.idDrug == strSearchIDDrug)
                {
                    break;
                }
                else
                {
                    M = M->next;
                }
            }
            if (M == NULL)
            {
                cout << "There is no Drug that suitable"<<endl;
            }
            else
            {
                cout << "Drug is found"<<endl;
                cout << "New Drug's name     : "<<M->info.Drugname<<endl;
                cout << "Kind of New Drug    : ";
                cin>>M->info.kind;
                cout << "Price of new drug     : ";
                cin>>M->info.price;
                cout << "Stock of new drug     : ";
                cin>>M->info.stock;
                cout << "Input new price: ";
                cin>>M->info.price;
                cout << "Edit is successfull"<<endl;
            }
        }
    }
}


//----------------- Seacrhing ----------------//

void searchPharmacy(pharmacys Pharmacy)
{
    if (Pharmacy.first == NULL)
        cout <<"Pharmacy is not found"<<endl;
    else
    {
        string strSearch;
        cout <<"Input ID / Pharmacy's name that you want to search : ";
        getline(cin, strSearch);
        addressPharmacy P = Pharmacy.first;
        while (P != NULL)
        {
            if((P->info.idPharmacy == strSearch) || (P->info.Pharmacyname == strSearch))
                break;
            else
                P = P->next;
        }
        if (P==NULL)
        {
            cout <<"There is no data that stable"<<endl;
            cout <<endl;
        }
        else
        {
            cout <<"Data is found"<<endl;
            cout <<"Pharmacy's ID             : "<<P->info.idPharmacy<<endl;
            cout <<"Pharmacy's name           : "<<P->info.Pharmacyname<<endl;
            cout <<"Location Of Pharmacy      : "<<P->info.location<<endl;
            cout<<"Date of pharmacy inventory : "<<P->info.day<<endl;
        }
    }
}

void searchDrug(pharmacys Pharmacy)
{
    if (Pharmacy.first == NULL)
        cout << "Data is not found" << endl;
    else
    {
        string strSearch;
        cout << "Input ID / Name of Drug that you want to search : ";
        getline(cin, strSearch);
        addressPharmacy P = Pharmacy.first;
        addressDrug Q;
        bool checkFound = false;
        while (P != NULL)
        {
            Q = P->Druglist;
            while (Q != NULL)
            {
                if ((Q->info.idDrug == strSearch) || (Q->info.Drugname == strSearch))
                {
                    checkFound = true;
                    break;
                }
                Q = Q->next;
            }
            if (checkFound)
                break;
            P = P->next;
        }
        if (Q == NULL)
        {
            cout << "There is no data that suitable" << endl;
            cout << endl;
        }
        else
        {
            cout << "Data is found" << endl;
            cout << "Drug's ID    : " << Q->info.idDrug << endl;
            cout << "Drug's name  : " << Q->info.Drugname << endl;
            cout << "Kind of Drug : " << Q->info.kind << endl;
            cout << "Price        : " << Q->info.price << endl;
            cout << "Drug's stock : " << Q->info.stock << endl;
            cout << "Expired      : " << Q->info.expired << endl;
            cout << "Availabe at  : " << P->info.Pharmacyname << endl;
            cout << endl;
        }
    }
}

//----------------- Insert Obat ----------------//
void insertDrugFirst(addressPharmacy PPharmacy, infotypeDrug addDrug)
{
    if (PPharmacy == NULL){
        cout <<"Pharmacy is not found";
    }else{
        addressDrug M = alokasiDrug(addDrug);
        if (PPharmacy->Druglist == NULL)  //PAPK itu Elemet parennya kalau daftar obat list childnya //daftar obat milik element parent
        {
            PPharmacy->Druglist = M;
        }
        else
        {
            M->next = PPharmacy->Druglist;
            PPharmacy->Druglist = M;
        }
    }
}


void insertDrugLast(addressPharmacy PPharmacy, infotypeDrug addDrug)
{
    if (PPharmacy == NULL)
    {
        cout <<"Pharmacy is not found";
    }
    else
    {
        addressDrug P;
        P = PPharmacy->Druglist;
        addressDrug M = alokasiDrug(addDrug);
        if (P == NULL)
        {
            insertDrugFirst(PPharmacy, addDrug);

        }
        else
        {
            while (P->next != NULL)
            {
                P = P->next;
            }
            P->next = M;
        }
    }
}


void insertDrugAfter(addressPharmacy PPharmacy, infotypeDrug addDrug)
{

    string searchIDDrug;
    addressDrug M = PPharmacy->Druglist;
    if (M == NULL)
    {
        cout << "because nothing drugs available, so direct input to first list" <<endl;
        insertDrugFirst(PPharmacy,addDrug);
    }
    else
    {
        cout << "list of pharmacy - "<<PPharmacy->info.Pharmacyname<<endl;
        while (M != NULL)
        {
            //looping untuk menampilkan obat apotek
            cout << "Data is found" << endl;
            cout << "Drug's ID      : " << M->info.idDrug << endl;
            cout << "Drug's name    : " << M->info.Drugname << endl;
            cout << "Kind of Drug   : " << M->info.kind << endl;
            cout << "Price          : " << M->info.price << endl;
            cout << "Drug's stock   : " << M->info.stock << endl;
            cout << "Expired        : " << M->info.expired << endl;
            cout << endl;
            M = M->next;
        }
        cout <<endl;
        cout << "input drug id that you want for insert after: ";
        getline(cin, searchIDDrug);
        M = findElmDrug(PPharmacy,searchIDDrug);
        if (M == NULL)
        {
            cout<<"insert after element not available"<<endl;
        }
        else
        {
            addressDrug addPharmacySisip;
            addPharmacySisip = alokasiDrug(addDrug);
            if (M->next == NULL)
            {
                //Jika Elemen di Ujung
                insertDrugLast(PPharmacy, addDrug);
            }
            else
            {
                addPharmacySisip->next = M->next;
                M->next = addPharmacySisip;
            }
        }
    }
}


void addDrugPharmacy(pharmacys &Pharmacy)
{
    if (Pharmacy.first == NULL)
    {
        cout<<"Nothing registered pharmacy"<<endl;
    }
    else
    {
        string seacrhPharmacy;
        printInfoPharmacy(Pharmacy);
        cout<<"Add pharmacy ID to add drug: ";
        cin>>seacrhPharmacy;
        cin.ignore();
        addressPharmacy PPharmacy = findElmPharmacy(Pharmacy, seacrhPharmacy);
        if (PPharmacy == NULL)
        {
            cout<<"Pharmacy not found";
        }
        else
        {
            infotypeDrug addDrug;
            createDrug(addDrug);
            char menu;
            cout<<endl;
            cout<<"choose type of insert that you want: "<<endl
                <<"1. Insert First"<<endl
                <<"2. Insert Last"<<endl
                <<"3. Insert After"<<endl;
DrugLabel :
            cout<<"Pilihan: ";
            cin>>menu;
            cin.ignore();
            switch (menu)
            {
            case '1' :
                insertDrugFirst(PPharmacy, addDrug);
                break;
            case '2' :
                insertDrugLast(PPharmacy,addDrug);
                break;
            case '3' :
                insertDrugAfter(PPharmacy,addDrug);
                break;
            default  :
                cin.ignore();
                goto DrugLabel;
            }
            cout<<"Data Succesfully inserted"<<endl;
        }
    }
}

//----------------- Delete Apotek ----------------//

addressPharmacy deleteFirstPharmacy(pharmacys &Pharmacy)
{
    addressPharmacy P;
    if (first(Pharmacy) == NULL)
    {
        return NULL;
    }
    else
    {
        P = first(Pharmacy);
        if (next(first(Pharmacy))==NULL)
        {
            first(Pharmacy) = NULL;
            last(Pharmacy) = NULL;
            return P;
        }
        else
        {
            prev(next(P)) = NULL;
            first(Pharmacy) = next(P);
            next(P) = NULL;
            return  P;
        }
    }
}

void deleteLastPharmacy(pharmacys &Pharmacy)
{
    addressPharmacy P;
    if (first(Pharmacy) == NULL)
    {
        cout<<"Pharmacy's data is not found"<<endl;
    }
    else
    {
        P = last(Pharmacy);
        if (prev(P) == NULL)
        {
            first(Pharmacy) = NULL;
            last(Pharmacy) = NULL;
        }
        else
        {
            next(prev(P)) = NULL;
            last(Pharmacy) = prev(P);
            prev(P) = NULL;

        }
    }
}

void deleteAfterPharmacy(pharmacys &Pharmacy)
{
    addressPharmacy P;
    if (first(Pharmacy) = NULL)
    {
        cout<<"Pharmacy's data not found"<<endl;
    }
    else
    {
        string Del;
        cout<<endl;
        printInfoPharmacy(Pharmacy);
        cout<<"Input pharmacy ID : ";
        getline(cin, Del);
        addressPharmacy R = findElmPharmacy(Pharmacy,Del);
        if (R ->next == NULL)
        {
            cout<<"this is last element"<<endl;
        }
        else
        {
            addressPharmacy P = R->next;
            if (P->next == NULL)  //elemen yang dihapus berada diujung
            {
                R->next = NULL;
                P->prev = NULL;
                delete P;
            }
            else
            {
                //elemen yang dihapus di tenggah-tenggah
                R->next = P->next;
                P->prev->prev = R;
                P->next = NULL;
                P->prev = NULL;
                delete P;
            }
            cout<<"Pharmacy delete succesfully"<<endl;
        }
    }
}

void deletePharmacybyID(pharmacys &Pharmacy)
{
    string searchPharmacy;
    printInfoPharmacy(Pharmacy);
    cout<<"input ID will be delete : ";
    getline(cin, searchPharmacy);
    addressPharmacy PPharmacy = findElmPharmacy(Pharmacy, searchPharmacy);
    if (PPharmacy == NULL)
    {
        //ksus elemen tidak ditemukan
        cout<<"pharmacy id not found"<<endl;
    }
    else
    {
        if (Pharmacy.first->next == NULL)
        {
            Pharmacy.first = NULL;
            Pharmacy.last = NULL;
            delete PPharmacy;
        }
        else if ((PPharmacy == Pharmacy.first) && (PPharmacy->next != NULL))
        {
            //Kasus elemen Yang di delete di elemen yang pertama
            deleteFirstPharmacy(Pharmacy);
        }
        else if ((PPharmacy == Pharmacy.last) && (PPharmacy->prev != NULL))
        {
            //Kasus Elemen yang di delete elemen terakhir
            deleteLastPharmacy(Pharmacy);
        }
        else if ((PPharmacy != Pharmacy.first) && (PPharmacy != Pharmacy.last) && (PPharmacy->next != NULL))
        {
            //kasus element di tenggah delete after
            addressPharmacy P =PPharmacy->prev;
            PPharmacy->next = PPharmacy->next;
            PPharmacy->next->prev = P;
            PPharmacy->next = NULL;
            PPharmacy->prev = NULL;
            delete PPharmacy;
        }
        else
            cout<<"can't be deleted"<<endl;

    }
}


void deletePharmacyOption(pharmacys &Pharmacy)
{
    if(Pharmacy.first == NULL)
        cout<<"nothing pharmacy's data"<<endl;
    else
    {
        char menu;
DrugLabel :
        cout << "choose delete method"<<endl
             << "1.  Delete First"<<endl
             << "2.  Delete Last"<<endl
             << "3.  Delete After"<<endl
             << "4.  Delete By ID"<<endl
             << "5. Exit"<<endl;

        cout <<"Masukkan Pilihan : ";
        cin>>menu;
        cin.ignore();
        switch (menu)
        {
        case '1' :
            deleteFirstPharmacy(Pharmacy);
            cout<<"pharmacy's data deleted successfully"<<endl;
            break;
        case '2' :
            deleteLastPharmacy(Pharmacy);
            cout<<"pharmacy's data deleted successfully"<<endl;
            break;
        case '3' :
            deleteAfterPharmacy(Pharmacy);
            cout<<"pharmacy's data deleted successfully"<<endl;
            break;
        case '4' :
            deletePharmacybyID(Pharmacy);
            cout<<"pharmacy's data deleted successfully"<<endl;
            break;
        default  :
            cin.ignore();
            goto DrugLabel;
        }
        //obatAkhir;
    }
}

//----------------- Delete Obat ----------------//

void deleteDrugFirst(pharmacys &Pharmacy)
{
    cout<<endl;
    printInfoPharmacy(Pharmacy);
    cout<<endl;
    string SearchByID;
    cout<<"Enter the Pharmacy ID to Removed: ";
    getline(cin,SearchByID);
    addressPharmacy PPharmacy = findElmPharmacy(Pharmacy, SearchByID);
    if (PPharmacy == NULL)
    {
        cout<<"Pharmacy Not Found";
    }
    else
    {
        addressDrug P = PPharmacy->Druglist;
        if (P == NULL)
        {
            cout<<"Drug Not Found"<<endl;
        }
        else
        {
            if (P->next == NULL)
            {
                PPharmacy->Druglist = NULL;
                P = NULL;
                delete P;
            }
            else
            {
                PPharmacy->Druglist = P->next;
                P->next = NULL;
                delete P;
            }
            cout<<"Drug Successfully removed"<<endl;
        }
    }
}


void deleteDrugLast(pharmacys&Pharmacy)
{
    cout<<endl;
    printInfoPharmacy(Pharmacy);
    cout<<endl;
    string SearchID;
    cout << "Enter the Pharmacy Id to delete: ";
    getline(cin, SearchID);
    addressPharmacy PPharmacy = findElmPharmacy(Pharmacy, SearchID);
    if (PPharmacy == NULL)
    {
        cout <<"Pharmacy Not Found"<<endl;
    }
    else
    {
        addressDrug M = PPharmacy->Druglist;
        if (M == NULL)
        {
            cout << "Empty Drugs At The Pharmacy"<<endl;
        }
        else
        {
            while (M->next != NULL)
            {
                M = M->next;
            }
            addressDrug N = PPharmacy->Druglist;
            while (N->next->info.idDrug != M->info.idDrug)
            {
                N = N->next;
            }
            N->next = NULL;
            delete M;
            cout <<"Drug Successfully Deleted"<<endl;
        }
    }
}


void deleteDrugAfter(pharmacys &Pharmacy)
{
    cout<<endl;
    printInfoPharmacy(Pharmacy);
    cout<<endl;
    string searchByIDPharmacy;
    string SearchIDDrug;
    cout << "Enter Pharmacy ID to remove Drug: ";
    getline(cin, searchByIDPharmacy);
    addressPharmacy PPharmacy= findElmPharmacy(Pharmacy, searchByIDPharmacy);
    if (PPharmacy == NULL)
    {
        cout<<"Pharmacy not found"<<endl;
    }
    else
    {
        addressDrug  M = PPharmacy->Druglist;
        if (M == NULL)
        {
            cout<<"Drug not found"<<endl;
        }
        else
        {
            cout << "List of Pharmacy Drugs - "<<PPharmacy->info.Pharmacyname<<endl;
            while (M != NULL)
            {
                //Loping untuk menapilkan Obat Apotek
                cout << "Data Found" << endl;
                cout << "Drug ID          : " << M->info.idDrug<< endl;
                cout << "Drug Name        : " << M->info.Drugname<< endl;
                cout << "Type of Drug     : " << M->info.kind << endl;
                cout << "Drug prices      : " << M->info.price<< endl;
                cout << "Stock of Drugs   : " << M->info.stock << endl;
                cout << "Expired           : " << M->info.expired << endl;
                cout << endl;
                M = M->next;
            }
            cout <<endl;
            cout<< "Enter the ID of the Drug before the ID will be Deleted : ";
            cin>> SearchIDDrug;
            cin.ignore();
            M = findElmDrug(PPharmacy, SearchIDDrug);
            if ((M != PPharmacy->Druglist) && (M->next == NULL))
            {
                //elemen yang di ujung ya
                cout<<"No More Drugs After This Drug"<<endl;
            }
            else if ((M == PPharmacy->Druglist) && (M->next == NULL))
            {
                // Jika Obat Tunggal
                cout<<"the only one drugs available in this pharmacy"<<endl;
            }
            else
            {
                addressDrug N = M->next;
                if (N->next == NULL )
                {
                    M->next = NULL;
                    delete N;
                }
                else
                {
                    M->next = N->next;
                    N->next = NULL;
                    delete  N;
                }
                cout << "drug successfully deleted"<<endl;
            }
        }
    }
}

void deleteDrugByID(pharmacys &Pharmacy)
{
    string SearchIDPharmacy;
    string SearchIDDrug;
    printInfoPharmacy(Pharmacy);
    cout <<"input pharmacy ID that the drug want to delete: ";
    getline(cin, SearchIDPharmacy);
    addressPharmacy  PPharmacy = findElmPharmacy(Pharmacy, SearchIDPharmacy); //mengambil keberadaan APK dimana
    if (PPharmacy == NULL)
    {
        cout << "pharmacy not found";
    }
    else
    {
        addressDrug M = PPharmacy->Druglist;
        if (M == NULL)
        {
            cout << "There is no Available drug in this pharmacy"<<endl;
        }
        else
        {
            cout << "List of Pharmacy Drugs - "<<PPharmacy->info.Pharmacyname<<endl;
            while (M != NULL)  //Looping untuk menamoikan Obat Apotek
            {
                cout << "Data Found" << endl;
                cout << "Drug ID          : " << M->info.idDrug<< endl;
                cout << "Drug Name        : " << M->info.Drugname<< endl;
                cout << "Type of Drug     : " << M->info.kind << endl;
                cout << "Drug prices      : " << M->info.price<< endl;
                cout << "Stock of Drugs   : " << M->info.stock << endl;
                cout << "Expired          : " << M->info.expired << endl;
                cout << endl;
                M = M->next;
            }
            cout<<endl;
            cout<< "Enter the Drug ID to be Deleted : ";
            getline(cin, SearchIDDrug);
            //mencari ID Obat
            M = PPharmacy->Druglist;
            while (M != NULL)
            {
                //looping untuk posisi elemnt yang dihapus
                if (M->info.idDrug == SearchIDDrug)
                {
                    break;
                }
                else
                {
                    M = M->next;
                }
            }
            if (M == NULL)
            {
                cout <<"There is no corresponding Drug ID"<<endl;
            }
            else
            {
                if (PPharmacy->Druglist->next == NULL)
                {
                    //jika terdapat satu obat
                    PPharmacy->Druglist = NULL;
                    delete M;
                    cout << "Drug Successfully Deleted"<<endl;
                }

                else  // Jika Terdapat Banyak Obat
                {
                    if (M == PPharmacy->Druglist)
                    {
                        //jika ada di awal list
                        addressDrug  Q = PPharmacy->Druglist;
                        while (Q->next != M)
                        {
                            Q = Q->next;
                        }
                        Q->next = NULL;
                        delete M;
                        cout<<"Drug Successfully Deleted"<<endl;
                    }
                    else if (M->next == NULL)
                    {
                        addressDrug Q = PPharmacy->Druglist;
                        //jika berada di tenggah
                        while (Q->next != M)
                        {
                            Q = Q->next;
                        }
                        Q->next = M->next;
                        M->next = NULL;
                        delete M;
                        cout <<"Drug Successfully Deleted"<<endl;
                    }
                    else
                    {
                        addressDrug  Q = PPharmacy->Druglist;
                        //Jika Berada di akhir
                        while (Q->next != M)
                        {
                            Q = Q->next;
                        }
                        Q->next = NULL;
                        delete M;
                        cout << "Drug Successfully Deleted"<<endl;

                    }
                }
            }
        }
    }
}

//Address P;
//void deleteID(apotek,12,P);

void deleteDrugOption(pharmacys &Pharmacy)
{
    if (Pharmacy.first == NULL)
    {
        cout<<"Tidak Terdapat Apotek"<<endl;
    }
    else
    {
        char menu;
firstDrug:
        cout << "choose delete method" << endl
             << "1.  Delete First" << endl
             << "2.  Delete Last" << endl
             << "3.  Delete After" << endl
             << "4.  Delete By ID" << endl
             << "5. Exit" << endl;

        cout << "choose  : ";
        cin >> menu;
        cin.ignore();
        switch (menu)
        {
        case '1' :
            deleteDrugFirst(Pharmacy);
            cout << "Pharmacy successfully deleted" << endl;
            break;
            goto firstDrug;
        case '2' :
            deleteDrugLast(Pharmacy);
            cout << "Pharmacy successfully deleted" << endl;
            break;
            goto firstDrug;
        case '3' :
            deleteAfterPharmacy(Pharmacy);
            cout << "Pharmacy successfully deleted" << endl;
            break;
            goto firstDrug;
        case '4' :
            deleteDrugByID(Pharmacy);
            cout << "Pharmacy successfully deleted" << endl;
            break;
            goto firstDrug;
        case '5' :
            goto lastDrug;
        default  :
            cin.ignore();
            goto firstDrug;
lastDrug :
        ;
    }
}

}
void insertFirstPharmacy(pharmacys &R, addressPharmacy P)
{
    if (first(R)== NULL) //kondisi ketika list kosong
    {
        first(R) = P;
        last(R) = P;
    }
    else
    {
        P->next = R.first;
        R.first->prev =P;
        R.first = P;
    }
}


void insertLastPharmacy(pharmacys &R, addressPharmacy P)
{
    if(first(R) == NULL)
    {
        //kondisi ketika list ksosong
        first(R) = P;
        last(R) = P;
    }
    else
    {
        prev(P) = last(R);
        next(prev(P)) = P;
        last(R) = P;
        next(P) = NULL;
    }
}

void insertAfterPharmacy(pharmacys &R, addressPharmacy P)
{
    if (R.first == NULL)
    {
        cout<<"because Element Empty then Element directly in insert at the beginning of list"<<endl;
        insertFirstPharmacy(R, P);
    }
    else
    {
        string SearchByID;
        printInfoPharmacy(R);
        cout<<endl;
        cout<<"input pharmacy id for insert after: ";
        getline(cin, SearchByID);
        addressPharmacy PPharmacy;
        PPharmacy = findElmPharmacy(R, SearchByID);
        if (PPharmacy == NULL)
        {
            cout<<"insert after element is not availabe"<<endl;
        }
        else
        {
            if (PPharmacy->next == NULL)
            {
                insertLastPharmacy(R, P);
            }
            else
            {
                P->next = PPharmacy->next;
                P->prev = PPharmacy;
                PPharmacy->next->prev = P;
                PPharmacy->next = P;
            }
        }
    }
}


//----------------- Penambahan Insert Parent Apotek  ----------------//

void addpharmacys(pharmacys &R)
{
    infotypePharmacy addPharmacy;
    createPharmacy(addPharmacy);
    addressPharmacy  PPharmacy;
    PPharmacy = alokasiPharmacy(addPharmacy);
    char menu;
    cout<<endl;
    cout<<"choose insert method : "<<endl
        <<"1. Insert First" <<endl
        <<"2. Insert Last" <<endl
        <<"3. Insert After" <<endl;
Druglabel :
    cout<<"Pilihan : "<<endl;
    cin>>menu;
    cin.ignore();
    switch (menu)
    {
    case '1' :
        insertFirstPharmacy(R, PPharmacy);
        break;
    case '2' :
        insertLastPharmacy(R, PPharmacy);
        break;
    case '3' :
        insertAfterPharmacy(R, PPharmacy);
        break;
    default :
        cin.ignore();
        goto Druglabel;
    }
    cout <<"Data Successfully Inserted"<<endl;
}


//----------------- Penambahan Counter  ----------------//

void countTotalPharmacy(pharmacys Pharmacy)
{
    addressPharmacy PPharmacy;
    PPharmacy = Pharmacy.first;
    if (PPharmacy == NULL)
    {
        cout<<"Total Unpublished Pharmacy Not Available"<<endl;
    }
    else
    {
        int countNum = 0;
        while (PPharmacy != NULL)
        {
            countNum++;
            PPharmacy = PPharmacy->next;
        }
        cout << "Total Available Pharmacies Now Is : " << countNum << "Pharmacy" << endl;
    }
}


void countTotalDrug(pharmacys Pharmacy)
{
    if (Pharmacy.first == NULL)
        cout<<"drug empty"<<endl;
    else
    {
        string SearchByIDPharmacy;
        string SearchByIDDrug;
        printInfoPharmacy(Pharmacy);
        cout<<endl;
        cout<<"input pharmacy id that will count type of drug: ";
        getline(cin, SearchByIDPharmacy);
        addressPharmacy PPharmacy = findElmPharmacy(Pharmacy, SearchByIDPharmacy);
        if (PPharmacy != NULL)
        {
            int countNum = 0; //counter hitung
            addressDrug M = PPharmacy->Druglist;
            //looping hitung element
            while (M != NULL)
            {
                countNum++;
                M = M->next;
            }
            cout<<endl;
            cout<<"Pharmacy : "<<PPharmacy->info.Pharmacyname<<" - Have "<<countNum<<" Drug"<<endl;
        }
        else
        {
            cout<<endl;
            cout<<"There is no Pharmacy ID"<<endl;
        }
    }
}

void menucountDrug(pharmacys Pharmacy)
{
    char menu;
    cout<<"====== Choose a list that you want to count ======"<<endl
        <<"1. Pharmacy"<<endl
        <<"2. Drug on the pharmacy"<<endl
        <<"3. Back to Main Menu"<<endl;
Druglabel :
    cout<<"Pilihan : ";
    cin>>menu;
    cin.ignore();
    switch (menu)
    {
    case '1' :
        countTotalPharmacy(Pharmacy);
        break;
    case '2' :
        countTotalDrug(Pharmacy);
        break;
    case '3' :
        break;
    default  :
        goto Druglabel;
    }
}


//----------------- Sorting Metode Merger Sort----------------//
addressPharmacy cekmin (pharmacys Pharmacy)
{
    addressPharmacy P;
    string minimum;
    P=first(Pharmacy);
    if (first(Pharmacy)==NULL)
    {
        return  0;
    }
    else
    {
        minimum = first(Pharmacy)->info.idPharmacy;
        addressPharmacy Q;
        while (P != NULL )
        {
            if (info(P).idPharmacy >= minimum)
            {
                minimum = info(P).idPharmacy;
                Q = P;
            }
            P = next(P);

        }
            return Q;
    }
}
void sortpharmacys(pharmacys &Pharmacy)
{

    pharmacys A2;
    createListPharmacy(A2);
    while(Pharmacy.first != NULL)
    {
        addressPharmacy P;
        P = cekmin(Pharmacy);

//        if (P !=NULL)sortobat(P->daftarObat);
        if (next(P) == NULL)
        {
            deleteLastPharmacy(Pharmacy);
        }
        else
        {
            if (P == first(Pharmacy))
            {
                deleteFirstPharmacy(Pharmacy);
            }
            else
            {
                P->prev->next = next(P);
                P->next->prev = prev(P);
            }
        }
        prev(P) = NULL;
        next(P) = NULL;
        if (P != NULL)
        {
//            cout << P<< endl;
            insertLastPharmacy(A2,P);
        }
    }
    Pharmacy = A2;
    printInfoPharmacy(Pharmacy);
}

addressDrug cekmin (addressDrug Pharmacy)
{
    addressDrug P;
    string minimum;
    P = Pharmacy;
    if (P ==NULL)
    {
        return NULL;
    }
    else
    {
        minimum = P->info.idDrug;
        while (P != NULL )
        {
            if (info(P).idDrug < minimum)
            {
                minimum = info(P).idDrug;

            }
            P = next(P);
        }

        P = Pharmacy;

        bool founded = false;
        while(P != NULL && !founded)
        {
            if (info(P).idDrug == minimum)
                founded = true;
            else
                P = next(P);
        }
        if (founded)
            return P;
        else
            return NULL;
    }
}
void sortDrug(addressDrug &Pharmacy)
{

    addressDrug A2 = NULL;
    while(Pharmacy != NULL)
    {
        cout << Pharmacy;
        addressDrug P;
        P = cekmin(Pharmacy);
       //NGELUARIN MIN DARI APK
        if (P != NULL)
        {
            if (next(P) != NULL){
            addressDrug Q;
            Q = Pharmacy;
            while(next(Q) != P){
                Q = next(Q);
            }
            next(Q) = NULL;
            }
        }
        else
        {
            if (P == Pharmacy)
            {
                Pharmacy = next(Pharmacy);
            }
            else
            {
                addressDrug Q = Pharmacy;
                while(next(Q) != P)
                    Q = next(Q);
                next(Q) = next(P);
            }
        }
        //NGELUARIN MIN DARI APK

        next(P) = NULL;
        if (P != NULL)
        {
            addressDrug Q;
            Q = A2;
            if (A2 == NULL){
                A2 = P;
                next(A2) = NULL;
            }
            else
            {
            Q = A2;
            while(next(Q) != NULL){
                Q = next(Q);
            }
            next(Q) = P;
            next(P) = NULL;
            cout << "X";
            }
        }
    }
    Pharmacy = A2;
}
//
//void sortobat(addressObat &APK)
//{
//
//    addressObat A2;
//    while(APK != NULL)
//    {
//        addressObat P;
//        P = cekmin(APK);
//        if (next(P) == NULL)
//        {
//            addressObat Q;
//            Q = APK;
//            while(next(Q) != P){
//                Q = next(Q);
//            }
//            next(Q) = NULL;
//        }
//        else
//        {
//            if (P == APK)
//            {
//                APK = next(APK);
//            }
//            else
//            {
//                addressObat Q = APK;
//                while(next(Q) != P)
//                    Q = next(Q);
//                next(Q) = next(P);
//            }
//        }
//        next(P) = NULL;
//        if (P != NULL)
//        {
//            addressObat Q;
//            Q = APK;
//            while(next(Q) != NULL){
//                Q = next(Q);
//            }
//            next(Q) = P;
//            next(P) = NULL;
//        }
//    }
//    APK = A2;
//}
