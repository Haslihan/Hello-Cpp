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
        cout << "Kayýtlý Ürünler Yüklendi" << endl;
    } else {
        cout << "Kayýtlý Ürün Bulunamadý" << endl;
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
		cout << "Ürünler dosyaya kaydedildi!" << endl;
    } else {
        cout << "*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^*^\n";
		cout << "Dosya açýlamadý!" << endl;
    }
}
void bakiyeekle() {
    cout << "Bakiyeniz: " << bakiye << endl;
    cout << "Eklemek istediðiniz miktarý seçiniz: " << endl;
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
	cout << "Lütfen bir seçim yapýnýz:" << endl;
    cout << "-------------------------------------\n";
    cout << "1. Bakiye Ekle" << endl;
    cout << "2. Ürün Ekle" << endl;
    cout << "3. Ürünleri Listele" << endl;
    cout << "4. Sepetim" << endl;
    cout << "5. Ürünleri Kaydet ve Çýk" << endl;
    cout << "6. Çýkýþ" <<endl;
    cout << "-------------------------------------\n";
}
int urunekle(urun ur[], int sirano) {
    cout << "Ürününüzün fiyatini giriniz: \n";
    cout << "-------------------------------------\n";
    cin >> ur[sirano].fiyat;
    cout << "Ürününüzün ismini giriniz: \n";
    cout << "-------------------------------------\n";
    cin.ignore();
    getline(cin, ur[sirano].isim);
    return sirano + 1;
}
int urunsatinal(urun ur[],sepeturun sepet[], int sirano,int sepetno) {
    if (sirano == 0) {
        cout << "Ürün listesi boþ" << endl;
        cout << "-------------------------------------\n";
    }
    else {
		for (int i = 0; i < sirano; i++) {
            cout << "[" << i << "]"<<"Urun " << i << ":" << ur[i].isim << ", Fiyat : " << ur[i].fiyat << endl;
            cout << "-------------------------------------\n";
        }
    }
	cout << "Hangi ürünü satýn almak istiyorsunuz? (Numarasýný giriniz): \n";
	cout << "-------------------------------------\n";
    int secim;
    cin >> secim;
    if (secim < 0 || secim >= sirano) {
        cout << "Geçersiz ürün seçimi" << endl;
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
		  cout << "Ürün sepete eklendi: " << ur[secim].isim << endl;
		  cout << "Kalan bakiye: " << bakiye << endl;
		  cout << "-------------------------------------\n";
		  sepet[sepetno].isim = ur[secim].isim;
		  sepet[sepetno].fiyat = ur[secim].fiyat;
		  return sepetno + 1;
}
}
void sepetgoster(sepeturun sepet[], int &sepetno) { 
    if (sepetno == 0) {
        cout << "Sepetiniz boþ" << endl;
        cout << "-------------------------------------\n";
        return;
    }
    cout << "Sepetinizdeki ürünler:\n";
    cout << "-------------------------------------\n";
    for (int i = 0; i < sepetno; i++) {
        cout << "[" << i << "] " << sepet[i].isim << " | Fiyat: " << sepet[i].fiyat << endl;
        cout << "-------------------------------------\n";
    }
    cout << "\nBir iþlem yapmak istiyor musunuz?\n";
    cout << "-------------------------------------\n";
    cout << "[1] Ürün sil\n";
    cout << "[2] Geri dön\n";
    cout << "-------------------------------------\n";
    int secim;
    cin >> secim;
    if (secim == 1) {
        int sil;
        cout << "Silmek istediðiniz ürünün numarasýný giriniz:\n";
        cin >> sil;
        if (sil <= 0 || sil > sepetno) {
            cout << "Geçersiz numara\n";
            return;
        }
        for (int i = sil - 1; i < sepetno - 1; i++) {
            sepet[i] = sepet[i + 1];
        }
        sepetno--;
        cout << "Ürün baþarýyla silindi.\n";
    } else {
        cout << "Geri dönülüyor...\n";
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
	cout << "Uygulamaya Hoþgeldiniz"<<endl;
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
                cout << "Ürün kapasitesi doldu" << endl;
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
    		cout << "Çýkýþ yapýlýyor..." << endl;
    		return 0;
		case 6:
            cout << "Çýkýþ yapýlýyor..." << endl;
            return 0;
        default:
            cout << "Geçersiz seçim, lütfen tekrar deneyin..." << endl;
            break;
        }
		cout << "-------------------------------------\n";
		cout << "Devam etmek için bir tuþa basýnýz..." << endl;
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');        
        cin.get();
        system("cls");
    }
    return 0;
}
