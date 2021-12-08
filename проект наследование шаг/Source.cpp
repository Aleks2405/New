#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <cstdlib>

using namespace std;
/*Задание 2.
Создайте абстрактный класс Shape для рисования плоских
фигур.Определите виртуальные методы :
•	 Show() — вывод на экран информации о фигуре,
•	 Save() — сохранение фигуры в файл,
•	 Load() — считывание фигуры из файла.
Определите производные классы :
•	 Square — квадрат, который характеризуется координатами левого верхнего угла и длиной стороны;
•	 Rectangle — прямоугольник с заданными координатами верхнего левого угла и размерами;
•	 Circle — окружность с заданными координатами центра и радиусом;
•	 Ellipse — эллипс с заданными координатами верхнего угла описанного вокруг него прямоугольника
со сторонами, параллельными осям координат, и размерами этого прямоугольника.
Создайте массив фигур, сохраните фигуры в файл, загрузите в другой массив и отобразите информацию о каждой
из фигур.*/

class Shape {
	
public:
	Shape(){}
	virtual void Show() = 0;
	virtual void Save(const char*part) = 0;
	virtual void Load(const char* part) = 0;
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
	
	 virtual void Save(const char* part)  {
		 ofstream fail;
		 fail.open(part, ios::app);
		 for (int i = 0; i < dlina; i++) {
			 for (int j = 0; j < dlina; j++) {
				 fail << "*" << " ";
			 } fail << endl;
		 }   fail << endl;
		 fail.close();
	 }

     virtual void Load(const char* part) {
		ifstream fail;
		string line;
		fail.open(part);
		getline(fail, line); //считывает пустую строку
		for (int i = 0; i < dlina; i++) {
			getline(fail, line);
		}
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
		virtual void Save(const char* part) {
			ofstream fail;
			fail.open(part, ios::app);
			for (int i = 0; i < dlina; i++) {
				for (int j = 0; j < vusota; j++) {
					fail << "*" << " ";
				} fail << endl;
			}  
			fail.close();
		}
		virtual void Load(const char* part){
			ifstream fail;
			string line;
			fail.open(part);
			getline(fail, line);
			for (int i = 0; i < vusota; i++) {	
				getline(fail, line); //считывает пустую строку
			}

			fail.close();
		}
		
};
class Circle : public Shape {
	size_t R;	
public:
	Circle(size_t a) : R(a){}

	virtual void Show(){
		unsigned n;
		size_t N;
		double di;
		N = 2 * R;
		di = 1.0 / R;
		for (int i = int(R); i >= -int(R); --i) {
			n = static_cast<int>(cos(asin(di * abs(int(i)))) * R);
			for (unsigned j = 0; j <= R - n; ++j) cout << " ";
			cout << "*";
			for (unsigned j = 0; j < 2 * n; ++j) cout << " ";
			cout << "*\n";
			
		}
	}
	virtual void Save(const char* part) {
		ofstream fail;
		fail.open(part, ios::app);
		unsigned n;
		size_t N;
		double di;
		N = 2 * R;
		di = 1.0 / R;
		for (int i = int(R); i >= -int(R); --i) {
			n = static_cast<int>(cos(asin(di * abs(int(i)))) * R);
			for (unsigned j = 0; j <= R - n; ++j);
		    fail << "*";
			for (unsigned j = 0; j < 2 * n; ++j);
			fail << "*\n";

		}
		fail.close();
	}
	virtual void Load(const char* part){
	}
	
};
class Ellipse :public Shape {
public:
	virtual void Show() {}
	virtual void Save(const char* part) {}
	virtual void Load(const char* part) {}
};


int main() {
	

	Square one(5);
	one.Show();
	one.Save("kv.txt");
	one.Load("kv.txt");

	//cout << endl;

	//Rectangle two (5,10);
	//two.Show();
	//two.Save("kv.txt");
	//two.Load("kv.txt");
	//Circle thee(3);
	//thee.Show();
	//thee.Save("kv.txt");

	//

	


}