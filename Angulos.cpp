#include <iostream>
#include <cmath>
#define PI 3.14159265358979323846
using namespace std;

struct Point {
    float x, y;
};

float calcularAngulo(Point i1, Point f1, Point i2, Point f2) {
    float dx1 = f1.x - i1.x;
    float dy1 = f1.y - i1.y;
    float dx2 = f2.x - i2.x;
    float dy2 = f2.y - i2.y;
    float Ppunto = dx1 * dx2 + dy1 * dy2;
    float magnitud1 = sqrt(dx1 * dx1 + dy1 * dy1);
    float magnitud2 = sqrt(dx2 * dx2 + dy2 * dy2);
    float alpha = Ppunto / (magnitud1 * magnitud2);
    if (alpha > 1) {
        alpha = 1;
    }
    if (alpha < -1) {
        alpha = -1;
    }
    float angulo = acos(alpha);
    return angulo;
}

int main() {
    Point i1, f1, i2, f2;
    bool Grados;
    cout << "Ingrese el punto inicial del primer segmento (x y): ";
    cin >> i1.x >> i1.y;
    cout << "Ingrese el punto final del primer segmento (x y): ";
    cin >> f1.x >> f1.y;
    cout << "Ingrese el punto inicial del segundo segmento (x y): ";
    cin >> i2.x >> i2.y;
    cout << "Ingrese el punto final del segundo segmento (x y): ";
    cin >> f2.x >> f2.y;
    cout << "¿Desea el angulo en grados o radianes? (1 para grados, 0 para radianes): ";
    cin >> Grados;
    float angulo = calcularAngulo(i1, f1, i2, f2);
    if (Grados) {
        cout << "Angulo en grados: " << angulo * (180.0 / PI) << endl;
    } else {
        cout << "Angulo en radianes: " << angulo << endl;
    }

    return 0;
}
