#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;
int tahmin;
int sayi=0;
int deneme;
int skor=0;
int main(){
	srand(time(0));
	sayi = rand()%10+1;
	cout << "Bilgisayar 1 ila 10 arasinda bir sayi tuttu\n" << "Sence bu sayi hangi sayi?\n";
	cin >> tahmin;
	skor ++;
	if (tahmin<1 || tahmin>10){
		cout << "Tahmin uygun aralikta degil";
	}
	if (tahmin == sayi){
		cout << "Dogru sayiyi tahmin ettiniz!\n";
		cout << "Puan: " << skor;
	}
	if (tahmin != sayi){
		cout << "Tahmin dogru degil\n"<<"Sansini bir daha denemek ister misin?\n"<<"[1]Bir daha deneyelim\n"<<"[2]Cikis\n";
		cin >> deneme;
		switch(deneme){
			case 1:
				while (tahmin != sayi){
		    		cout << "Bu seferki tahminin ne?\n";
		    		cin >> tahmin;
		    		skor ++;
		    		if (tahmin == sayi){
		        		cout << "Bu sefer dogru bildin, Tebrikler\n";
		        		cout << "Puan: " << skor;
		       		 break;
		   		 }
		    	cout << "Yanlis tahmin, Bir daha deneyelim\n";
				}
				break;
			case 2:
				cout << "Gorusuruz";
				break;
			default:
				cout << "Siklarda bu sayi yok";
		}
	}
	return 0;
}
