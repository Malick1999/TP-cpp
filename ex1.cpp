#include <iostream>
using namespace std;

class Point {
private:
    float x;
    float y;

public:
    // Constructeur par défaut
    Point() : x(0.0f), y(0.0f) {}

    // Constructeur avec deux arguments
    Point(float xValue, float yValue) : x(xValue), y(yValue) {}

    // Constructeur par copie
    Point(const Point& other) : x(other.x), y(other.y) {}

    // Méthode pour obtenir la coordonnée x
    float getX() const { return x; }

    // Méthode pour obtenir la coordonnée y
    float getY() const { return y; }

    // Méthode pour afficher les coordonnées du point
    void print() const {
        cout << "Coordonnées du point : (" << x << ", " << y << ")" << endl;
    }

    // Méthode pour mettre à l'échelle les coordonnées du point
    void scale(float factor) {
        x *= factor;
        y *= factor;
    }
};

int main() {
    // Création d'un objet Point avec les coordonnées (4.5, 0.5)
    Point point(4.5f, 0.5f);
    point.print();

    // Création d'un nouvel objet Point avec le constructeur avec deux arguments
    Point newPoint(3.0f, 2.0f);
    newPoint.print();

    //13. Mise à l'échelle du point
    point.scale(2.0f);
    point.print();

    return 0;
}

