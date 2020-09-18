#ifndef VECTOR3_H_
#define VECTOR3_H_

#include <iostream>

namespace AltMath {
    class vector3 {
        private:
            double x;
            double y;
            double z;
            static long globId;

        public:
            const long id;

            vector3 (double = .0, double = .0, double = .0);
            vector3 (const vector3 &vec);
            ~vector3 ();
            
            double getx () const;
            double gety () const;
            double getz () const;
            vector3 &setx (double x);
            vector3 &sety (double y);
            vector3 &setz (double z);

            // Модуль вектора
            double abs () const; 

            // Нормализация вектора
            vector3 getnormalize () const; 
            vector3 &tonormalize ();


            // Присваивание
            vector3 &operator= (const vector3 &vec);
            vector3 &operator= (double scal);

            // Унарный '+' (эквивалент 1 * vector3)
            vector3 &operator+ ();

            // Унарный '-' (эквивалент (-1) * vector3)
            vector3 &operator- ();

            // Сумма векторов
            friend vector3 operator+ (const vector3 &vecA, const vector3 &vecB);
            vector3 &operator+= (const vector3 &vec);

            // Разность векторов
            friend vector3 operator- (const vector3 &vecA, const vector3 &vecB);
            vector3 &operator-= (const vector3 &vec);

            // Произведение вектора со скаляром
            friend vector3 operator* (const vector3 &vec, double scal);
            friend vector3 operator* (double scal, const vector3 &vec);
            vector3 &operator*= (double scal);

            // Векторное произведение двух векторов
            friend vector3 operator* (const vector3 &vecA, const vector3 &vecB);
            vector3 &operator*= (const vector3 &vec);

            // Скалярное произведение двух векторов
            friend double operator& (const vector3 &vecA, const vector3 &vecB);

            
            // Перегрузка оператора стейтмента вывода
            friend std::ostream &operator<< (std::ostream &out, const vector3 &vec);   
    };

    // Косинус угла между двумя векторами
    double cos (const vector3 &vecA, const vector3 &vecB); 

    // Синус угла между двумя векторами
    double sin (const vector3 &vecA, const vector3 &vecB); 

    // Величина угла в градусах между векторами в пределах [-180, 180]
    double angle (const vector3 &vecA, const vector3 &vecB);
}


#endif /* VECTOR3_H_ */








