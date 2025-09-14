#include <iostream>
#include <cmath>
using namespace std;
int sayi1;
int sayi2;
int islem;
int cikis;
int mutlak_deger;
int krk;
int us_alma(int taban,int us){
	int sonuc=1;
	for (int i=0;i<us;i++){
		sonuc=sonuc*taban;
	}
	return sonuc;
}
int main(){
	while (true){
		cout << "Ilk sayiyi Giriniz: ";
		cin >> sayi1;
		cout << " " <<endl;
		cout << "Ikinci Sayiyi Giriniz: ";;
		cin >> sayi2;
		cout << "Istediginiz islemin basindaki numarayi yaziniz" <<endl;
		cout << "1 - Toplama		2 - Cikarma		3 - Carpma		4 - Bolme		  5 - Us alma		  6 - Karekok Alma		-1 - Cikis" << endl;
		cout << "Sectiginiz Numara: ";
		cin >> islem;
		if (islem == 1){
			cout << "Sonuc = " << sayi1 + sayi2;
			cout << " " <<endl;
		}
		if (islem == 2){
			cout << "Sonuc = " << sayi1 - sayi2 <<endl;
			cout << "Mutlak Degeri Alinsin mi(Istediginiz Secenegin Numarasini Girin)" <<endl;
			cout << "1-Evet		2-Hayir" <<endl;
			cout << "Sectiginiz Numara: ";
			cin >> mutlak_deger;
			if (mutlak_deger == 1){
				cout << abs(sayi1 - sayi2);
				cout << " " <<endl;
			}	
			if (mutlak_deger == 2){
				cout << " " <<endl;
			}	
		}
		if (islem == 3){
			cout << "Sonuc = " << sayi1 * sayi2 <<endl;;
			cout << " " <<endl;
			}	
		if (islem == 4){
			cout << "Sonuc = " << sayi1 / sayi2 <<endl;	
			cout << " " <<endl;
		}	
		if (islem == 5){
			cout << us_alma(sayi1,sayi2);
		}
		if (islem == 6){
			cout << "1-Ilk sayinin karekokunu al  "<< "  2-Ikinci sayinin karekokunu al";
			cin >> krk;	
			if (krk==1){
				cout << sqrt(sayi1);
			}
			if (krk==2){
				cout << sqrt(sayi2);
			}
		if (islem == -1){
			break;
			}
		}		
	}
}









