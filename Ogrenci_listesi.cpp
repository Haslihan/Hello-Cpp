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
	cout << "��rencinin ismini-soyismini giriniz\n";
	cout << "-----------------------------------------------------\n";
	getline(cin, ogren[sirano].ogrenci_adi);
	cout << "-----------------------------------------------------\n";
	cout << "��rencinin numaras�n� giriniz\n";
	cout << "-----------------------------------------------------\n";
	cin >> ogren[sirano].ogrenci_no;
	cout << "-----------------------------------------------------\n";	
	cout << "��rencinin ortalamas�n� giriniz\n";
	cout << "-----------------------------------------------------\n";
	cin >> ogren[sirano].ort;
	cout << "-----------------------------------------------------\n";
	return ++sirano;
}
void listele(ogrenci ogren[], int toplam){
	for(int i=0;i<toplam;i++){
		cout << "-----------------------------------------------------\n";
		cout << "Ad�-Soyad�:"<< ogren[i].ogrenci_adi <<endl;
		cout << "Numaras�  :"<< ogren[i].ogrenci_no <<endl;
		cout << "Ortalamas�:"<< ogren[i].ort <<endl;
		cout << "-----------------------------------------------------\n";
 
	}
}
void bul(ogrenci ogren[], int toplam){
	int no;
	bool bulundu = false;
	cout << "-----------------------------------------------------\n";
	cout << "Aranacak ��rencinin numaras�n� giriniz: \n";
	cout << "-----------------------------------------------------\n";
	cin >> no;
	for(int i=0;i<toplam;i++){
		if(ogren[i].ogrenci_no==no){
		cout << "-----------------------------------------------------\n";
		cout << "Ad�-Soyad�:"<< ogren[i].ogrenci_adi <<endl;
		cout << "Numaras�  :"<< ogren[i].ogrenci_no <<endl;
		cout << "Ortalamas�:"<< ogren[i].ort <<endl; 
		cout << "-----------------------------------------------------\n";
		bulundu = true;
		break;
		}
		if(!bulundu){
		cout << "-----------------------------------------------------\n";
		cout << "Bu numaraya sahip bir ��renci bulunamad�.\n";
		cout << "-----------------------------------------------------\n";
	}
	}
}
void menu(){
	cout << "-----------------------------------------------------\n";
	cout << "Eri�mek istedi�iniz �zelli�in numaras�n� yaz�p Enter'a bas�n\n" << "1-Listeye ��renci Ekle\n" << "2-Listedeki t�m ��rencileri listele\n" << "3-Listeden ��renci bul\n"<<"4-��k��\n";
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
		cout << "Uygulamaya ho�geldiniz" <<endl<<"<<<<<<<*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/>>>>>>>"<<endl;
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
				cout << "��k�� yap�l�yor...\n";
				break;
			default:
				cout << "L�tfen uygun numaray� yaz�n�n�z";
		}
		cout << "Devam etmek i�in bir tu�a bas�n�z...";
		cin.ignore();
		cin.get();
	}while(secim!=4);
	return 0;
}
