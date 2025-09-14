#include <iostream>
#include <windows.h>
#include <cmath>
using namespace std;
int sayi;
int sayac;
int n;
int toplam=0;
int x;
int y;
int yedek;
int araliktoplami(int sayi1,int sayi2){
	n=abs(sayi1-sayi2);
	sayac=n-1;
	for(sayac;sayac != 0;sayac--){
		if (sayi1<sayi2){
			yedek=toplam;
			toplam = sayi1+1+sayi2-1;
			toplam =yedek+toplam;
		}
		if (sayi2<sayi1){
			yedek=toplam;
			toplam = sayi2+1+sayi2-1;
			toplam =yedek+toplam;
		}
		if (sayi2==sayi1){
			toplam=toplam+sayi1;
			break;
		}
		sayi1--;
		sayi2--;
	}	
	cout << "Bu iki sayi arasindaki sayilarin toplami: " << toplam <<endl;
	return toplam;
}
int main(){
	cout << "Birinci sayiyi giriniz" <<endl;
	cin >> x;
	cout << "Ikinci sayiyi giriniz" <<endl;
	cin >> y;
	araliktoplami(x,y);
	
	return 0;
}
