#ifndef VECTOR3_H_
#define VECTOR3_H_

#include <iostream>
#include <cmath>


class vector3 {
    private:
        double x;
        double y;
        double z;

    public:
        vector3 (double = .0, double = .0, double = .0);
        vector3 (const vector3 &vec);
        ~vector3 ();

        double getx () const;
        double gety () const;
        double getz () const;
        int setx (const double x);
        int sety (const double y);
        int setz (const double z);
        double abs () const;        // Модуль вектора
        vector3 normalize () const; // Нормализация вектора


        // Сумма векторов
        friend vector3 operator+ (const vector3 vecA, const vector3 vecB);

        // Разность векторов
        friend vector3 operator- (const vector3 vecA, const vector3 vecB);

        // Произведение вектора со скаляром
        friend vector3 operator* (const vector3 vec, const double scal);

        // Векторное произведение двух векторов
        friend vector3 operator* (const vector3 vecA, const vector3 vecB);

        // Скалярное произведение двух векторов
        friend double operator& (const vector3 vecA, const vector3 vecB);
};


// Косинус угла между двумя векторами
double cos (const vector3 vecA, const vector3 vecB); 

// Синус угла между двумя векторами
double sin (const vector3 vecA, const vector3 vecB); 

// Величина угла в градусах между векторами в пределах [-180, 180]
double angle (const vector3 vecA, const vector3 vecB);




#endif /* VECTOR3_H_ */








