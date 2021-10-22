#include <iostream>
#include<math.h>
#include <vector>
#include <sstream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using std::cout;
using std::cin;
using std::string;
using std::endl;
using std::stringstream;
using std::vector;

int menu();
int ejercicio1();
double ejercicio2(int limite, int n);
int ejercicio3A();
int ejercicio3B();
int submenu();

int main(int argc, char** argv) {
	int opcion = menu();
	while (opcion != 4) {
		switch (opcion) {
			case 1: {
				ejercicio1();
				cout << endl;
				break;
			}
			case 2: {
				int limite = 0;
				cout << "Ingrese el limite: ";
				cin >> limite;

				if (limite <= 0) {
					cout << "Numero ingresado es menor o igual a 0";
				} else {
					double resp = 4*ejercicio2(limite, 0);
					cout << resp;
				}

				cout << endl;
				break;
			}
			case 3: {
				int subopcion = submenu();

				if (subopcion == 1) {
					ejercicio3A();
				} else {
					ejercicio3B();
				}
				cout << endl;
				break;
			}
			default:
				cout << "Opcion invalida";
		}
		opcion = menu();
	}
	return 0;
}

int menu() {
	int opcion = 0;
	cout << "===========Menu===========" << endl
	     << "1) Ejercicio1" << endl
	     << "2) Ejercicio2" << endl
	     << "3) Ejercicio3" << endl
	     << "4) Salir" << endl;
	cout << "Ingrese su opcion: ";
	cin >> opcion;
	return opcion;
}

int submenu() {
	int opcion = 0;
	cout << "===========Sub-Menu===========" << endl
	     << "1) Rombo" << endl
	     << "2) Contorno Rombo" << endl;
	cout << "Ingrese su opcion: ";
	cin >> opcion;
	return opcion;
}

int ejercicio1() {
	string horaA;
	string horaB;
	cout << "Ingrese la primera hora: ";
	cin >> horaA;
	cout << "Ingrese la segunda hora: ";
	cin >> horaB;
	//PRIMERA HORA
	stringstream ss(horaA);
	vector<string> tokens;
	string temp_str;
	while(std::getline(ss, temp_str, ':')) {
		tokens.push_back(temp_str);
	}
	int hora1 = 0;
	int hora2 = 0;
	stringstream intValue(tokens[0]);
	intValue >> hora1;
	stringstream intValue2(tokens[1]);
	intValue2 >> hora2;
	//SEGUNDA HORA
	stringstream ssB(horaB);
	while(std::getline(ssB, temp_str, ':')) {
		tokens.push_back(temp_str);
	}
	int hora1B = 0;
	int hora2B = 0;
	stringstream intValueB(tokens[2]);
	intValueB >> hora1B;
	stringstream intValue2B(tokens[3]);
	intValue2B >> hora2B;

	if (hora1 > hora1B) {
	} 
	else if (hora1 == hora1B && hora2 >= hora2B) {
	}
	else {
		int num1 = hora1B - hora1;
		int num2 = 0;
		if (hora2 > hora2B) {
			num1--;
			num2 = 60-hora2 + hora2B;
		}
		else {
			num2 = hora2B - hora2;
		}
		cout << "Tiempo Total: " << num1 << " Horas " << "y " << num2 << " minutos";
	}
	return 0;
}

double ejercicio2(int limite, int n) {

	if (limite == n) {
		return 0;
	} else {
		return (pow(-1, n)/((2*n) +1)) + ejercicio2(limite, n+1);
	}

}

int ejercicio3A() {
	int size = 0;
	cout << "Ingrese un numero impar: ";
	cin >> size;

	if (size % 2 == 0) {
		cout << "Numero ingresado no es impar";
	} else {

		int piramide = 1;
		int espacios = (size/2) ;

		for (int i = 0; i < size; i++) {
			if (i < size/2) {

				for (int j = 0; j < espacios; j++) {
					cout << " ";
				}
				for (int k = 0; k < piramide; k++) {
					cout << "*";
				}
				cout << endl;

				piramide += 2;
				espacios--;
			} else {
				for (int l = 0; l < espacios; l++) {
					cout << " ";
				}
				for (int f = 0; f < piramide; f++) {
					cout << "*";
				}
				cout << endl;

				piramide -= 2;
				espacios++;
			}
		}
	}
	return 0;
}

int ejercicio3B() {
	int size = 0;
	cout << "Ingrese un numero impar: ";
	cin >> size;

	if (size % 2 == 0) {
		cout << "Numero ingresado no es impar";
	} else {

		int piramide = 1;
		int espacios = (size/2) ;

		for (int i = 0; i < size; i++) {
			cout << "*";
		}
		cout << endl;

		for (int i = 0; i < size; i++) {
			if (i < size/2) {

				for (int j = 0; j < espacios; j++) {
					cout << "*";
				}
				for (int k = 0; k < piramide; k++) {
					cout << " ";
				}
				for (int j = 0; j < espacios; j++) {
					cout << "*";
				}
				cout << endl;

				piramide += 2;
				espacios--;
			} else if (size/2 == i) {
				piramide -= 2;
				espacios++;
				piramide -= 2;
				espacios++;
			} else if (size-1 == i) {
				for (int i = 0; i < size; i++) {
					cout << "*";
				}
				cout << endl;
			} else {
				for (int l = 0; l < espacios; l++) {
					cout << "*";
				}
				for (int f = 0; f < piramide; f++) {
					cout << " ";
				}
				for (int l = 0; l < espacios; l++) {
					cout << "*";
				}
				cout << endl;

				piramide -= 2;
				espacios++;
			}
		}
	}
	return 0;
}