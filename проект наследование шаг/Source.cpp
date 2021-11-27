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
�� ���������, ������������� ���� ���������, � ��������� ����� ��������������.
�������� ������ �����, ��������� ������ � ����, ��������� � ������ ������ � ���������� ���������� � ������ 
�� �����.*/

class Shape {
protected:
	string slov;
public:
	virtual void Show() = 0;
	virtual void Save(const char* part) = 0;
	virtual void Load(const char* part) = 0;
};
class Square : public Shape {   // �������
	//char** arr;
	int dlina;
public:
	Square(int a) : dlina(a){}
	virtual void Show() {
			char** arr = new char* [dlina];
			for (int i = 0; i < dlina; i++) {
				arr[i] = new char[dlina];
				for (int j = 0; j < dlina; j++) {
					arr[i][j] = '*';
					cout << arr[i][j] << " ";
				} cout << endl;
			}	
		}
	
	 virtual void Save(const char* part) {
		 ofstream fail;
		 fail.open(part, ios::app);
		 char** arr = new char* [dlina];
		 for (int i = 0; i < dlina; i++) {
			 arr[i] = new char[dlina];
			 for (int j = 0; j < dlina; j++) {
				 arr[i][j] = '*';
				 fail << arr[i][j] << " ";
			 } fail << endl;
		 }
		 fail.close();
	 }

     virtual void Load(const char* part) {
		ifstream fail;
		
		fail.open(part);
		//fail >> *slov;
		int i = 0;
		while (getline (fail, slov)) {
			i++;
			cout << slov << endl;
		}
		
		fail.close();
		
	}
};
class Rectangle : public Shape {

};


int main() {
	Square one(5);
	one.Show();
	one.Save("kv.txt");
	one.Load("kv.txt");


}