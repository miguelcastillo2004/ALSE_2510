#include <iostream>
#include "Circulo.h"
#include "Cuadrado.h"
#include "Triangulo.h"
#include <vector>

using namespace std;

int main() {
    vector<Geometrica*> vFig;

    // --- Prueba de Círculos e Intersección ---
    float r1, x1, y1, r2, x2, y2;

    // Pedir datos del primer círculo
    cout << "Ingrese el radio del primer círculo: ";
    cin >> r1;
    cout << "Ingrese la coordenada X del primer círculo: ";
    cin >> x1;
    cout << "Ingrese la coordenada Y del primer círculo: ";
    cin >> y1;

    // Pedir datos del segundo círculo
    cout << "Ingrese el radio del segundo círculo: ";
    cin >> r2;
    cout << "Ingrese la coordenada X del segundo círculo: ";
    cin >> x2;
    cout << "Ingrese la coordenada Y del segundo círculo: ";
    cin >> y2;

    // Crear los dos círculos con los datos ingresados
    Circulo c1(r1, x1, y1);
    Circulo c2(r2, x2, y2);

    // Verificar si se intersectan
    if (c1.seIntersectaCon(c2)) {
        cout << "Los círculos se intersectan." << endl;
    } else {
        cout << "Los círculos NO se intersectan." << endl;
    }

    // --- Prueba de Otras Figuras ---
    Circulo a = Circulo(5.);
    cout << "Perímetro del círculo: " << a.perimetro() << " y área: " << a.area() << endl;
    a.setRadio(7.);
    cout << "Perímetro del círculo actualizado: " << a.perimetro() << " y área: " << a.area() << endl;

    Cuadrado b = Cuadrado(10.);
    cout << "Perímetro del cuadrado: " << b.perimetro() << " y área: " << b.area() << endl;

    Geometrica* pG = nullptr;

    pG = &a;
    cout << "Perímetro: " << pG->perimetro() << " y área: " << pG->area() << endl;

    pG = &b;
    cout << "Perímetro: " << pG->perimetro() << " y área: " << pG->area() << endl;

    pG = new Triangulo(5., 6.);
    cout << "Perímetro del triángulo: " << pG->perimetro() << " y área: " << pG->area() << endl;

    cout << pG << endl;

    int tipo = 0;
    float radio, lado, base, altura;
    radio = lado = base = altura = 0.;

    for (int i = 0; i < 3; i++) {  // Solo 3 figuras para prueba rápida
        cout << "Figura para crear: Circulo(1), Cuadrado(2), Triangulo(3): ";
        cin >> tipo;
        switch (tipo) {
        case 1:
            cout << "Ingrese el radio: ";
            cin >> radio;
            pG = new Circulo(radio);
            break;
        case 2:
            cout << "Ingrese el lado: ";
            cin >> lado;
            pG = new Cuadrado(lado);
            break;
        case 3:
            cout << "Ingrese la base: ";
            cin >> base;
            cout << "Ahora la altura: ";
            cin >> altura;
            pG = new Triangulo(base, altura);
            break;
        default:
            cout << "Opción inválida." << endl;
            continue;
        }
        vFig.push_back(pG);
    }

    cout << "Total de figuras creadas: " << vFig.size() << endl;

    for (Geometrica* fig : vFig) {
        cout << "Perímetro: " << fig->perimetro() << " y área: " << fig->area() << endl;
    }

    for (Geometrica* fig : vFig) {
        delete fig;
    }

    return 0;
}
