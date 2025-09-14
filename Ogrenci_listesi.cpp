#include <iostream>
#include <windows.h>
#define maxogrenci 100
using namespace std;
struct ogrenci{
	string ogrenci_adi;
	int ogrenci_no;
	double ort;
};
int ogrenciekle(ogrenci ogren[],int sirano){
	cout << "-----------------------------------------------------\n";
	cin.ignore();
	cout << "Öðrencinin ismini-soyismini giriniz\n";
	cout << "-----------------------------------------------------\n";
	getline(cin, ogren[sirano].ogrenci_adi);
	cout << "-----------------------------------------------------\n";
	cout << "Öðrencinin numarasýný giriniz\n";
	cout << "-----------------------------------------------------\n";
	cin >> ogren[sirano].ogrenci_no;
	cout << "-----------------------------------------------------\n";	
	cout << "Öðrencinin ortalamasýný giriniz\n";
	cout << "-----------------------------------------------------\n";
	cin >> ogren[sirano].ort;
	cout << "-----------------------------------------------------\n";
	return ++sirano;
}
void listele(ogrenci ogren[], int toplam){
	for(int i=0;i<toplam;i++){
		cout << "-----------------------------------------------------\n";
		cout << "Adý-Soyadý:"<< ogren[i].ogrenci_adi <<endl;
		cout << "Numarasý  :"<< ogren[i].ogrenci_no <<endl;
		cout << "Ortalamasý:"<< ogren[i].ort <<endl;
		cout << "-----------------------------------------------------\n";
 
	}
}
void bul(ogrenci ogren[], int toplam){
	int no;
	bool bulundu = false;
	cout << "-----------------------------------------------------\n";
	cout << "Aranacak öðrencinin numarasýný giriniz: \n";
	cout << "-----------------------------------------------------\n";
	cin >> no;
	for(int i=0;i<toplam;i++){
		if(ogren[i].ogrenci_no==no){
		cout << "-----------------------------------------------------\n";
		cout << "Adý-Soyadý:"<< ogren[i].ogrenci_adi <<endl;
		cout << "Numarasý  :"<< ogren[i].ogrenci_no <<endl;
		cout << "Ortalamasý:"<< ogren[i].ort <<endl; 
		cout << "-----------------------------------------------------\n";
		bulundu = true;
		break;
		}
		if(!bulundu){
		cout << "-----------------------------------------------------\n";
		cout << "Bu numaraya sahip bir öðrenci bulunamadý.\n";
		cout << "-----------------------------------------------------\n";
	}
	}
}
void menu(){
	cout << "-----------------------------------------------------\n";
	cout << "Eriþmek istediðiniz özelliðin numarasýný yazýp Enter'a basýn\n" << "1-Listeye Öðrenci Ekle\n" << "2-Listedeki tüm öðrencileri listele\n" << "3-Listeden öðrenci bul\n"<<"4-Çýkýþ\n";
	cout << "-----------------------------------------------------\n";
}
int main(){
		int secim, sira=0;
		setlocale(LC_ALL,"Turkish");
		SetConsoleOutputCP(1254);
		SetConsoleCP(1254);
		ogrenci ogr[maxogrenci];
		do{
		system("cls");
		cout << "Uygulamaya hoþgeldiniz" <<endl<<"<<<<<<<*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/>>>>>>>"<<endl;
		menu();
		cin >> secim;
		switch(secim){
			case 1:
				sira=ogrenciekle(ogr,sira);
				break;
			case 2:
				listele(ogr,sira);
				break;
			case 3:
				bul(ogr,sira);
				break;
			case 4:
				cout << "Çýkýþ yapýlýyor...\n";
				break;
			default:
				cout << "Lütfen uygun numarayý yazýnýnýz";
		}
		cout << "Devam etmek için bir tuþa basýnýz...";
		cin.ignore();
		cin.get();
	}while(secim!=4);
	return 0;
}
