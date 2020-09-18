#ifndef VECTOR3_CPP_
#define VECTOR3_CPP_

#include "vector3.h"
#include <iostream>
#include <cmath>


namespace AltMath {
    long vector3::globId = 0;

    vector3::vector3 (double x, double y, double z)
        : x(x), y(y), z(z), id(globId) {
        globId++;
        std::cout << "Constructor    id_" << id << " " 
            << *this << std::endl;
    }

    vector3::vector3 (const vector3 &vec) 
        : x(vec.x), y(vec.y), z(vec.z), id(globId) {
        globId++;
        std::cout << "Copied id_" << vec.id << " to id_" << id << " " 
            << *this << std::endl;
    }

    vector3::~vector3 () {
        std::cout << "Destructor     id_" << id << std::endl; 
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

    vector3 &vector3::setx (double x) {
        this->x = x;
        return *this;
    }

    vector3 &vector3::sety (double y) {
        this->y = y;
        return *this;
    }

    vector3 &vector3::setz (double z) {
        this->z = z;
        return *this;
    }

    // Модуль вектора
    double vector3::abs () const {
        return sqrt (x * x + y * y + z * z);
    }

    // Нормализация вектора
    vector3 vector3::getnormalize () const {
        double len = this->abs ();
        return vector3 (x/len, y/len, z/len); 
    }

    vector3 &vector3::tonormalize () {
        double len = this->abs ();
        x = x/len;
        y = y/len;
        z = z/len;
        return *this;
    }


    // Присваивание 
    vector3 &vector3::operator= (const vector3 &vec) {
        x = vec.x;
        y = vec.y;
        z = vec.z;
        return *this;
    }

    vector3 &vector3::operator= (double scal) {
        x = scal;
        y = scal;
        z = scal;
        return *this;
    }


    // Унарный '+'
    vector3 &vector3::operator+ () {
        return *this;
    }


    // Унарный '-'
    vector3 &vector3::operator- () {
        x *= -1;
        y *= -1;
        z *= -1;
        return *this;
    }


    // Сумма векторов
    vector3 operator+ (const vector3 &vecA, const vector3 &vecB) {
        return vector3 (vecA.x + vecB.x,
                        vecA.y + vecB.y,
                        vecA.z + vecB.z);
    }

    vector3 &vector3::operator+= (const vector3 &vec) {
        x += vec.x;
        y += vec.y;
        z += vec.z;
        return *this;
    }


    // Разность векторов
    vector3 operator- (const vector3 &vecA, const vector3 &vecB) {
        return vector3 (vecA.x - vecB.x,
                        vecA.y - vecB.y,
                        vecA.z - vecB.z);
    }
    
    vector3 &vector3::operator-= (const vector3 &vec) {
        x -= vec.x;
        y -= vec.y;
        z -= vec.z;
        return *this;
    }


    // Произведение вектора со скаляром
    // vec - вектор
    // scal - скаляр
    vector3 operator* (const vector3 &vec, double scal) {
        return vector3 (vec.x * scal, 
                        vec.y * scal, 
                        vec.z * scal);
    }

    vector3 operator* (double scal, const vector3 &vec) {
        return vector3 (vec.x * scal,
                        vec.y * scal,
                        vec.z * scal);
    }

    vector3 &vector3::operator*= (double scal) {
        x *= scal;
        y *= scal;
        z *= scal;
        return *this;
    }


    // Векторное произведение двух векторов
    vector3 operator* (const vector3 &vecA, const vector3 &vecB) {
        return vector3 (vecA.y * vecB.z - vecA.z * vecB.y,
                        vecA.z * vecB.x - vecA.x * vecB.z,
                        vecA.x * vecB.y - vecA.y * vecB.x);
    }

    vector3 &vector3::operator*= (const vector3 &vec) {
        x = y * vec.z - z * vec.y;
        y = z * vec.x - x * vec.z;
        z = x * vec.y - y * vec.x;
        return *this;
    }


    // Скалярное произведение двух векторов
    double operator& (const vector3 &vecA, const vector3 &vecB) {
        return vecA.x * vecB.x + vecA.y * vecB.y + vecA.z * vecB.z;
    }


    // Перегрузка оператора стейтмента вывода
    std::ostream &operator<< (std::ostream &stream, const vector3 &vec) {
        stream << "(" << vec.x << ", " << vec.y << ", " << vec.z << ")";
        return stream;
    }



    // Косинус угла между двумя векторами
    double cos (const vector3 &vecA, const vector3 &vecB) {
        return (vecA & vecB) / (vecA.abs () * vecB.abs ());
    }

    // Синус угла между двумя векторами
    double sin (const vector3 &vecA, const vector3 &vecB) {
        return (vecA * vecB).abs () / (vecA.abs () * vecB.abs ());
    }

    // Величина угла в градусах между векторами в пределах [-180, 180]
    double angle (const vector3 &vecA, const vector3 &vecB) {
        return (atan2 ((vecA * vecB).abs (), vecA & vecB) * 180 / M_PI);
    }
}

#endif /* VECTOR3_CPP_ */
