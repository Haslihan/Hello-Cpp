#include <iostream>
#include <limits>
#include <string> 
#include <windows.h>
#include <fstream>
#define maxurun 100
using namespace std;
int bakiye = 0;
struct sepeturun {
    string isim;
    int fiyat;
};
struct urun {
    string isim;
    int fiyat;
};
int urunleriYukle(urun urunler[]) {
    ifstream dosya("urunler.txt");
    int sira = 0;
    if (dosya.is_open()) {
        while (dosya >> urunler[sira].isim >> urunler[sira].fiyat) {
            sira++;
        }
        dosya.close();
        cout << "Kay�tl� �r�nler Y�klendi" << endl;
    } else {
        cout << "Kay�tl� �r�n Bulunamad�" << endl;
    }
    return sira;
}
void urunleriKaydet(urun urunler[], int sira) {
    ofstream dosya("urunler.txt");
    if (dosya.is_open()) {
        for (int i = 0; i < sira; i++) {
            dosya << urunler[i].isim << " " << urunler[i].fiyat << endl;
        }
        dosya.close();
    	cout << "*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^\n";
		cout << "�r�nler dosyaya kaydedildi!" << endl;
    } else {
        cout << "*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^\n";
		cout << "Dosya a��lamad�!" << endl;
    }
}
void bakiyeekle() {
    cout << "Bakiyeniz: " << bakiye << endl;
    cout << "Eklemek istedi�iniz miktar� se�iniz: " << endl;
    int ekle;
    cin >> ekle;
    if (ekle < 0) {
        cout << "Negatif bakiye eklenemez" << endl;
    }
    else {
        bakiye += ekle;
    }
}

void menugoster() {   
    cout << "*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^\n";
	cout << "L�tfen bir se�im yap�n�z:" << endl;
    cout << "-------------------------------------\n";
    cout << "1. Bakiye Ekle" << endl;
    cout << "2. �r�n Ekle" << endl;
    cout << "3. �r�nleri Listele" << endl;
    cout << "4. Sepetim" << endl;
    cout << "5. �r�nleri Kaydet ve ��k" << endl;
    cout << "6. ��k��" <<endl;
    cout << "-------------------------------------\n";
}
int urunekle(urun ur[], int sirano) {
    cout << "�r�n�n�z�n fiyatini giriniz: \n";
    cout << "-------------------------------------\n";
    cin >> ur[sirano].fiyat;
    cout << "�r�n�n�z�n ismini giriniz: \n";
    cout << "-------------------------------------\n";
    cin.ignore();
    getline(cin, ur[sirano].isim);
    return sirano + 1;
}
int urunsatinal(urun ur[],sepeturun sepet[], int sirano,int sepetno) {
    if (sirano == 0) {
        cout << "�r�n listesi bo�" << endl;
        cout << "-------------------------------------\n";
    }
    else {
		for (int i = 0; i < sirano; i++) {
            cout << "[" << i << "]"<<"Urun " << i << ":" << ur[i].isim << ", Fiyat : " << ur[i].fiyat << endl;
            cout << "-------------------------------------\n";
        }
    }
	cout << "Hangi �r�n� sat�n almak istiyorsunuz? (Numaras�n� giriniz): \n";
	cout << "-------------------------------------\n";
    int secim;
    cin >> secim;
    if (secim < 0 || secim >= sirano) {
        cout << "Ge�ersiz �r�n se�imi" << endl;
        cout << "-------------------------------------\n";
        return sepetno;
    }
    if (bakiye < ur[secim].fiyat) {
  		cout << "Yeterli bakiyeniz yok" << endl;
		  cout << "-------------------------------------\n";
		  return sepetno;
	} 
	else {
		  bakiye -= ur[secim].fiyat;
		  cout << "�r�n sepete eklendi: " << ur[secim].isim << endl;
		  cout << "Kalan bakiye: " << bakiye << endl;
		  cout << "-------------------------------------\n";
		  sepet[sepetno].isim = ur[secim].isim;
		  sepet[sepetno].fiyat = ur[secim].fiyat;
		  return sepetno + 1;
}
}
void sepetgoster(sepeturun sepet[], int &sepetno) { 
    if (sepetno == 0) {
        cout << "Sepetiniz bo�" << endl;
        cout << "-------------------------------------\n";
        return;
    }
    cout << "Sepetinizdeki �r�nler:\n";
    cout << "-------------------------------------\n";
    for (int i = 0; i < sepetno; i++) {
        cout << "[" << i << "] " << sepet[i].isim << " | Fiyat: " << sepet[i].fiyat << endl;
        cout << "-------------------------------------\n";
    }
    cout << "\nBir i�lem yapmak istiyor musunuz?\n";
    cout << "-------------------------------------\n";
    cout << "[1] �r�n sil\n";
    cout << "[2] Geri d�n\n";
    cout << "-------------------------------------\n";
    int secim;
    cin >> secim;
    if (secim == 1) {
        int sil;
        cout << "Silmek istedi�iniz �r�n�n numaras�n� giriniz:\n";
        cin >> sil;
        if (sil <= 0 || sil > sepetno) {
            cout << "Ge�ersiz numara\n";
            return;
        }
        for (int i = sil - 1; i < sepetno - 1; i++) {
            sepet[i] = sepet[i + 1];
        }
        sepetno--;
        cout << "�r�n ba�ar�yla silindi.\n";
    } else {
        cout << "Geri d�n�l�yor...\n";
    }
}
int main() {
    setlocale(LC_ALL, "Turkish");
    SetConsoleOutputCP(1254);
    SetConsoleCP(1254);
    int secim, sira;
    urun urunler[maxurun];
    sira = urunleriYukle(urunler);
    sepeturun sepetim[maxurun];
	int sepet_sira = 0;
	cout << "*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^\n";
	cout << "Uygulamaya Ho�geldiniz"<<endl;
    while (true) {
        menugoster();
        cin >> secim;
        switch (secim) {
        case 1:
            bakiyeekle();
            break;
        case 2:
            if (sira < maxurun) {
                sira = urunekle(urunler, sira);
            }
            else {
                cout << "�r�n kapasitesi doldu" << endl;
            }
            break;
        case 3:
            sepet_sira = urunsatinal(urunler, sepetim, sira, sepet_sira);
            break;
        case 4:
			sepetgoster(sepetim, sepet_sira);
            break;
        case 5:
    		urunleriKaydet(urunler, sira);
    		cout << "��k�� yap�l�yor..." << endl;
    		return 0;
		case 6:
            cout << "��k�� yap�l�yor..." << endl;
            return 0;
        default:
            cout << "Ge�ersiz se�im, l�tfen tekrar deneyin..." << endl;
            break;
        }
		cout << "-------------------------------------\n";
		cout << "Devam etmek i�in bir tu�a bas�n�z..." << endl;
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');        
        cin.get();
        system("cls");
    }
    return 0;
}
