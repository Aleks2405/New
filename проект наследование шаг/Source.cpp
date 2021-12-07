#include <iostream>
#include <fstream>

using namespace std;
/*Çàäàíèå 2.
Ñîçäàéòå àáñòðàêòíûé êëàññ Shape äëÿ ðèñîâàíèÿ ïëîñêèõ 
ôèãóð. Îïðåäåëèòå âèðòóàëüíûå ìåòîäû:
•	 Show() — âûâîä íà ýêðàí èíôîðìàöèè î ôèãóðå,
•	 Save() — ñîõðàíåíèå ôèãóðû â ôàéë,
•	 Load() — ñ÷èòûâàíèå ôèãóðû èç ôàéëà.
Îïðåäåëèòå ïðîèçâîäíûå êëàññû: 
•	 Square — êâàäðàò, êîòîðûé õàðàêòåðèçóåòñÿ êîîðäèíàòàìè ëåâîãî âåðõíåãî óãëà è äëèíîé ñòîðîíû;
•	 Rectangle — ïðÿìîóãîëüíèê ñ çàäàííûìè êîîðäèíàòàìè âåðõíåãî ëåâîãî óãëà è ðàçìåðàìè;
•	 Circle — îêðóæíîñòü ñ çàäàííûìè êîîðäèíàòàìè öåíòðà è ðàäèóñîì;
•	 Ellipse — ýëëèïñ ñ çàäàííûìè êîîðäèíàòàìè âåðõíåãî óãëà îïèñàííîãî âîêðóã íåãî ïðÿìîóãîëüíèêà 
ñî ñòîðîíàìè, ïàðàëëåëüíûìè îñÿì êîîðäèíàò, è ðàçìåðàìè ýòîãî ïðÿìîóãîëüíèêà.
Ñîçäàéòå ìàññèâ ôèãóð, ñîõðàíèòå ôèãóðû â ôàéë, çàãðóçèòå â äðóãîé ìàññèâ è îòîáðàçèòå èíôîðìàöèþ î êàæäîé 
èç ôèãóð.*/

class Shape {
	
public:
	Shape(){}
	virtual void Show() = 0;
	virtual void Save() = 0;
	virtual void Load() = 0;
};
class Square : public Shape {   // êâàäðàò
	int dlina;
public:
	Square(){}
	Square(int a) : dlina(a){}
	virtual void Show() {
			for (int i = 0; i < dlina; i++) {
				for (int j = 0; j < dlina; j++) {
					cout <<"*" << " ";
				} cout << endl;
			}	
		}
	
	 virtual void Save()  {
		 ofstream fail;
		 fail.open("kv.txt", ios::app);
		 for (int i = 0; i < dlina; i++) {
			 for (int j = 0; j < dlina; j++) {
				 fail << "*" << " ";
			 } fail << endl;
		 }
		 fail.close();
	 }

     virtual void Load() {
		ifstream fail;
		char line[128];
		fail.open("kv.txt");
		int i = 0;
		fail.getline(line, 128);
		fail.close();
	}
};
class Rectangle : public Shape {
	int dlina;
	int vusota;
public:
	Rectangle(int a, int b) : dlina(a), vusota(b) {}
		virtual void Show() {
			for (int i = 0; i < dlina; i++) {
				for (int j = 0; j < vusota; j++) {
					cout << "*" << " ";
				} cout << endl;
			}
		}
		virtual void Save() {
			ofstream fail;
			fail.open("kv.txt", ios::app);
			for (int i = 0; i < dlina; i++) {
				for (int j = 0; j < vusota; j++) {
					fail << "*" << " ";
				} fail << endl;
			}
			fail.close();
		}
		virtual void Load(){}
		
};
class Circle : public Shape {
public:
};


int main() {
	

	Square one(5);
	one.Show();
	one.Save();
	one.Load();

	cout << endl;

	Rectangle two (5,10);
	two.Show();
	two.Save();
	two.Load();
	

	


}