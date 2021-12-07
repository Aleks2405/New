#include <iostream>
#include <fstream>

using namespace std;
/*������� 2.
�������� ����������� ����� Shape ��� ��������� ������� 
�����. ���������� ����������� ������:
�	 Show() � ����� �� ����� ���������� � ������,
�	 Save() � ���������� ������ � ����,
�	 Load() � ���������� ������ �� �����.
���������� ����������� ������: 
�	 Square � �������, ������� ��������������� ������������ ������ �������� ���� � ������ �������;
�	 Rectangle � ������������� � ��������� ������������ �������� ������ ���� � ���������;
�	 Circle � ���������� � ��������� ������������ ������ � ��������;
�	 Ellipse � ������ � ��������� ������������ �������� ���� ���������� ������ ���� �������������� 
�� ���������, ������������� ���� ���������, � ��������� ����� ��������������.
�������� ������ �����, ��������� ������ � ����, ��������� � ������ ������ � ���������� ���������� � ������ 
�� �����.*/

class Shape {
	
public:
	Shape(){}
	virtual void Show() = 0;
	virtual void Save() = 0;
	virtual void Load() = 0;
};
class Square : public Shape {   // �������
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
class Rectangle : public Square {
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
	
};


int main() {
	ofstream fail;
	fail.open("kv.txt", ios::in);

	//Square one(5);
	//one.Show();
	//one.Save();
	//one.Load();

	//cout << endl;
	//Rectangle two (5,10);
	//two.Show();
	//two.Save();
	//two.Load("kv.txt");

	


}