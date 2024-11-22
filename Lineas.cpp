#include <iostream>
using namespace std;
struct Point {
    double x, y;
};

int orientacion(Point p, Point q, Point r) {
    double val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
    if (val == 0) return 0;         
    return (val > 0) ? 1 : 2;      
}

int linea(Point p1, Point q1, Point p2, Point q2) {
    int o1 = orientacion(p1, q1, p2);
    int o2 = orientacion(p1, q1, q2);
    int o3 = orientacion(p2, q2, p1);
    int o4 = orientacion(p2, q2, q1);

    if (o1 != o2 && o3 != o4) {
        return 1;
    } 
    if (o1 == 0 && o2 == 0 && o3 == 0 && o4 == 0) {
        return 0;
    } 
    else {
        return -1;
    }
}

int linea(Point p1, Point q1, Point p2, Point q2, bool checkPerpendicular) {
    if (checkPerpendicular) {
        double dx1 = q1.x - p1.x;
        double dy1 = q1.y - p1.y;
        double dx2 = q2.x - p2.x;
        double dy2 = q2.y - p2.y;

        if (dx1 * dy2 == dx2 * dy1) {
            return 0;
        }
        else if (dx1 * dx2 + dy1 * dy2 == 0) {
            return 1;
        }
        else {
        return -1; 
        }
    } else {
        return linea(p1, q1, p2, q2);
    }
}


int main() {
    Point p1, q1, p2, q2;
    cout << "Ingrese el punto inicial del primer segmento (x y):"<<endl;
    cout << "x: ";
    cin >> p1.x;
    cin.ignore();
    cout << "y: ";
    cin >> p1.y;
    cin.ignore();
    cout << "Ingrese el punto final del primer segmento (x y): "<<endl;
    cout << "x: ";
    cin >> q1.x;
    cin.ignore();
    cout << "y: ";
    cin >> q1.y;
    cin.ignore();
    cout << "Ingrese el punto inicial del segundo segmento (x y): "<<endl;
    cout << "x: ";
    cin >> p2.x;
    cin.ignore();
    cout << "y: ";
    cin >> p2.y;
    cin.ignore();
    cout << "Ingrese el punto final del segundo segmento (x y): "<<endl;
    cout << "x: ";
    cin >> q2.x;
    cin.ignore();
    cout << "y: ";
    cin >> q2.y;
    cin.ignore();

    bool checkPerpendicular; 
    cout << "Desea comprobar si las lineas son perpendiculares? (1 para si, 0 para no): "; 
    cin >> checkPerpendicular; int result; 
    if (checkPerpendicular) { 
        cout<<"1. Son perpendiculares"<<endl;
        cout<<"0. Son paralelas"<<endl;
        cout<<"-1. Se cruzan"<<endl;

        cout<< linea(p1, q1, p2, q2, true); 
    } 
    else {
        cout<<"1. Se cruzan"<<endl;
        cout<<"0. Son paralelas"<<endl;
        cout<<"-1. Ninguna de las anteriores"<<endl;
        cout<< linea(p1, q1, p2, q2); 
    }

    return 0;
}

