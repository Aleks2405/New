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
	virtual void Show() const = 0;
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
		 //char** arr = new char* [dlina];
		 for (int i = 0; i < dlina; i++) {
			// arr[i] = new char[dlina];
			 for (int j = 0; j < dlina; j++) {
				// arr[i][j] = '*';
				 fail << "*" << " ";
			 } fail << endl;
		 }
		 fail.close();
	 }

     virtual void Load() {
		ifstream fail;
		char line[128];
		fail.open("kv.txt");
		//fail >> *slov;
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
			char** arr = new char* [dlina];
			for (int i = 0; i < dlina; i++) {
				arr[i] = new char[vusota];
				for (int j = 0; j < vusota; j++) {
					arr[i][j] = '*';
					fail << arr[i][j] << " ";
				} fail << endl;
			}
			fail.close();
		}
	
};


int main() {
	//Square one(5);
	//one.Show();
	//one.Save("kv.txt");
	//one.Load("kv.txt");

	//cout << endl;
	Rectangle two(5,10);
	two.Show();
	//two.Save("kv.txt");
	//two.Load("kv.txt");

	


}