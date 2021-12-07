#include <iostream>
#include <fstream>

using namespace std;
/*«адание 2.
—оздайте абстрактный класс Shape дл€ рисовани€ плоских 
фигур. ќпределите виртуальные методы:
Х	 Show() Ч вывод на экран информации о фигуре,
Х	 Save() Ч сохранение фигуры в файл,
Х	 Load() Ч считывание фигуры из файла.
ќпределите производные классы: 
Х	 Square Ч квадрат, который характеризуетс€ координатами левого верхнего угла и длиной стороны;
Х	 Rectangle Ч пр€моугольник с заданными координатами верхнего левого угла и размерами;
Х	 Circle Ч окружность с заданными координатами центра и радиусом;
Х	 Ellipse Ч эллипс с заданными координатами верхнего угла описанного вокруг него пр€моугольника 
со сторонами, параллельными ос€м координат, и размерами этого пр€моугольника.
—оздайте массив фигур, сохраните фигуры в файл, загрузите в другой массив и отобразите информацию о каждой 
из фигур.*/

class Shape {
	
public:
	Shape(){}
	virtual void Show() = 0;
	virtual void Save() = 0;
	virtual void Load() = 0;
};
class Square : public Shape {   // квадрат
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