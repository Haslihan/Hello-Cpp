#include <iostream>
using namespace std;
int a;
string b;
class araba{
	private:
		string marka;
		int hiz;
	public:
		araba(string m,int h){
			setmarka(m);
			sethiz(h);
		}
		araba(){
			setmarka("Girilmedi");
			sethiz(0);
		}
		void sethiz(int Yenihiz){
			if (Yenihiz<0){
				hiz=0;
			}
			else
			{
				hiz=Yenihiz;
			}
		}
		void setmarka(string yenimarka){
			marka=yenimarka;
		}
		int gethiz(){
			return hiz;
		}
		string getmarka(){
			return marka;
		}
		void goster(){
			cout << "Marka: " << marka <<endl<< "Hiz: " << hiz <<endl;
		}
};
int main(){
	cout << "Arabanizin markasi ne?\n";
	cin >> b;
	cout << "Arabanizin hizi ne?\n";
	cin >> a;
	araba arabam(b,a);
	arabam.goster();
	return 0;
}
