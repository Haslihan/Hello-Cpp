#include <iostream>
#define maxisim 10000
using namespace std;
string isim[maxisim];
int i = 0;
bool a;
int menusecimi;
int secim;
void menu(){
	do{
		a = false;
		cout << "-----------------------------------------------------\n";
		cout << "Yapacaginiz islemi seciniz\n";
		cout << "-----------------------------------------------------\n";
		cout << "1-Kisi Ekle	2-Kisi Listesi\n";
		cout << "-----------------------------------------------------\n";
		cin >> secim;
		if (secim != 1 && secim != 2){
			cout << "Yanlis rakami tusladiniz, tekrar deneyin\n";
			cout << "-----------------------------------------------------\n";
			cout << "Tekrar ana menuye donmek icin enter basiniz";
			int gecis;
			cin >> gecis;
			system ("cls");
			a = true;
		}
	}while (a == true);
}
void kisiekle(){
	cout << "-----------------------------------------------------\n";
	cout << "Isim-Soyisim Giriniz:\n";
	cout << "-----------------------------------------------------\n";
	cin.ignore();
	getline(cin,isim[i]);
	i++;
}
void listele(){
	for (int k=0;k<i;k++){
		cout << "-----------------------------------------------------\n";
		cout << isim[k] <<endl;
	}
	cout << "-----------------------------------------------------\n";
	cout << "Tekrar ana menuye donmek icin enter basiniz";
	int gecis2;
	cin >> gecis2;
}
int main(){
	cout << "Uygulamaya hosgeldiniz\n";
	while (true){
		menu ();
		if (secim == 1){
			kisiekle();
		}
		if (secim == 2){
			listele();
		}
		system ("cls");
	}
	return 0;
}
