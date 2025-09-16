#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int zorluk;
int menu(){
	cout << "Zorluk Modunuz Nasil Olsun (Elinizi Korkak Alistirmayin)\n1-Kolay\n2-Orta\n3-Zor\n4-Imkansiz\n";
	cin >> zorluk;
	return zorluk;
}
class SayiTahmin{
	private:
		int sayi;
	public:
		void SetSayiKolay(){
			sayi = rand() % 6;
		}
		void SetSayiOrta(){
			sayi = rand() % 11;
		}
		void SetSayiZor(){
			sayi = rand() % 36;
		}
		void SetSayiImkansiz(){
			sayi = rand() % 101;
		}
		int GetSayi(){
			return sayi;	
		}
};
int main(){
	int rastgele;
	int tahmin;
	srand(time(0));
	SayiTahmin ilk;
	cout << "Sayi Tahmin Oyununa Hosgeldiniz!\n";
	zorluk = menu();
	switch (zorluk){
		case 1:
			ilk.SetSayiKolay();
			rastgele = ilk.GetSayi();
			cout << "Peki, Sonraki Sefere Daha Zor Yap Ama. Neyse, Aklimdan 0 ile 5 arasinda bir sayi tuttum\nSence ne olabilir?\n";
			cin >> tahmin;
			while (tahmin > 5 || tahmin < 0){
				cout << "Yemezler. Olabilecek Bir Sayi Girer Misin?\n";
				cin >> tahmin;
			}
			if (tahmin == rastgele){
				cout << "Bildin. Bir De diger Zorluklarda Gorelim Seni\n";
			}
			else{
				cout << "Bunu Da Bilmen Lazimdi\n";
			}
			break;
		case 2:
			ilk.SetSayiOrta();
			rastgele = ilk.GetSayi();
			cout << "Hic Yoktan Iyidir. Neyse, Aklimdan 0 ile 10 arasinda bir sayi tuttum\nSence ne olabilir?\n";
			cin >> tahmin;
			while (tahmin > 10 || tahmin < 0){
				cout << "Yemezler. Olabilecek Bir Sayi Girer Misin?\n";
				cin >> tahmin;
			}
			if (tahmin == rastgele){
				cout << "Bildin. Bir De Diger Zorluklarda Gorelim Seni. Daha 2 Seviye Var!\n";
			}
			else{
				cout << "En Azindan Kolayda Takilmadin\n";
			}
			break;
		case 3:
			ilk.SetSayiZor();
			rastgele = ilk.GetSayi();
			cout << "Yurekliymissin. Neyse, Aklimdan 0 ile 35 arasinda bir sayi tuttum\nSence ne olabilir?\n";
			cin >> tahmin;
			while (tahmin > 35 || tahmin < 0){
				cout << "Yemezler. Olabilecek Bir Sayi Girer Misin?\n";
				cin >> tahmin;
			}
			if (tahmin == rastgele){
				cout << "Helal Olsun. Belki Imkansizi da basarirsin?\n Ama Unutma, Adi Ustunde\nIMKANSIZ\n";
			}
			else{
				cout << "Olsun, Bir Daha Dene\n";
			}
			break;
		case 4:
			ilk.SetSayiImkansiz();
			rastgele = ilk.GetSayi();
			cout << "Kendine Guveniyorsun Bakiyorum. Neyse, Aklimdan 0 ile 100 arasinda bir sayi tuttum (%1 Sansin Var)\nSence ne olabilir?\n";
			cin >> tahmin;
			while (tahmin > 100 || tahmin < 0){
				cout << "Yemezler. Olabilecek Bir Sayi Girer Misin?\n";
				cin >> tahmin;
			}
			if (tahmin == rastgele){
				cout << "Seni Ayakta Alkisliyorum\n";
			}
			else{
				cout << "Bir Sey Olmaz, En azindan korkak degilsin\n";
			}
			break;
	}
	return 0;
}
