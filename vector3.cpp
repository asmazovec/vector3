#include "vector3.h"


vector3::vector3 (double x, double y, double z)
    : x(x), y(y), z(z) {
    std::cout << this << " Constructor " << std::endl;
}

vector3::vector3 (const vector3 &vec) 
    : x(vec.x), y(vec.y), z(vec.z) {
    std::cout << this << " Copied      " << std::endl;
}

vector3::~vector3 () {
    std::cout << this << " Destructor  " << std::endl; 
}

double vector3::getx () const {
    return x;
}

double vector3::gety () const {
    return y;
}

double vector3::getz () const {
    return z;
}

int vector3::setx (const double x) {
    this->x = x;
    return 0;
}

int vector3::sety (const double y) {
    this->y = y;
    return 0;
}

int vector3::setz (const double z) {
    this->z = z;
    return 0;
}

// Модуль вектора
double vector3::abs () const {
    return sqrt (x * x + y * y + z * z);
}

// Нормализация вектора
vector3 vector3::normalize () const {
    double len = (*this).abs ();
    return vector3 (x/len, y/len, z/len); 
}



// Сумма векторов
vector3 operator+ (const vector3 vecA, const vector3 vecB) {
    return vector3 (vecA.x + vecB.x,
                    vecA.y + vecB.y,
                    vecA.z + vecB.z);
}

// Разность векторов
vector3 operator- (const vector3 vecA, const vector3 vecB) {
    return vector3 (vecA.x - vecB.x,
                    vecA.y - vecB.y,
                    vecA.z - vecB.z);
}

// Произведение вектора со скаляром
vector3 operator* (const vector3 vec, const double scal) {
    return vector3 (vec.x * scal, 
                    vec.y * scal, 
                    vec.z * scal);
}

// Векторное произведение двух векторов
vector3 operator* (const vector3 vecA, const vector3 vecB) {
    return vector3 (vecA.y * vecB.z - vecA.z * vecB.y,
                    vecA.z * vecB.x - vecA.x * vecB.z,
                    vecA.x * vecB.y - vecA.y * vecB.x);
}

// Скалярное произведение двух векторов
double operator& (const vector3 vecA, const vector3 vecB) {
    return vecA.x * vecB.x + vecA.y * vecB.y + vecA.z * vecB.z;
}



// Косинус угла между двумя векторами
double cos (vector3 vecA, const vector3 vecB) {
    return (vecA & vecB) / (vecA.abs () * vecB.abs ());
}

// Синус угла между двумя векторами
double sin (const vector3 vecA, const vector3 vecB) {
    return (vecA * vecB).abs () / (vecA.abs () * vecB.abs ());
}

// Величина угла в градусах между векторами в пределах [-180, 180]
double angle (const vector3 vecA, const vector3 vecB) {
    return (atan2 ((vecA * vecB).abs (), vecA & vecB) * 180 / acos (-1));
}



