/*
    Лабораторная работа №1 - Вычисление площади треугольников по формулам Герона и Гаусса
*/

#include <stdio.h>
#include <math.h>

// Расстояние между двумя точками (модуль)
float distance(float x1, float y1, float x2, float y2);

// Формула Герона
float areaOfTriangleGeron(float x1, float y1, float x2, float y2, float x3, float y3);

// Формула Гаусса
float areaOfTriangleGauss(float x1, float y1, float x2, float y2, float x3, float y3);

int main() {
    float ax, ay, bx, by, cx, cy, px, py;

    printf("Введите координаты точки A (x, y): ");
    scanf("%f %f", &ax, &ay);

    printf("Введите координаты точки B (x, y): ");
    scanf("%f %f", &bx, &by);

    printf("Введите координаты точки C (x, y): ");
    scanf("%f %f", &cx, &cy);

    printf("Введите координаты точки P (x, y): ");
    scanf("%f %f", &px, &py);

    // по формуле Герона
    float areaABC = areaOfTriangleGeron(ax, ay, bx, by, cx, cy);
    float areaABP = areaOfTriangleGeron(ax, ay, bx, by, px, py);
    float areaBCP = areaOfTriangleGeron(bx, by, cx, cy, px, py);
    float areaCAP = areaOfTriangleGeron(cx, cy, ax, ay, px, py);

    printf("\nПлощадь треугольника ABC по формуле Герона: %.2f\n", areaABC);
    printf("Площадь треугольника ABP по формуле Герона: %.2f\n", areaABP);
    printf("Площадь треугольника BCP по формуле Герона: %.2f\n", areaBCP);
    printf("Площадь треугольника CAP по формуле Герона: %.2f\n\n", areaCAP);

    // по формуле Гаусса
    float gsareaABC = areaOfTriangleGauss(ax, ay, bx, by, cx, cy);
    float gsareaABP = areaOfTriangleGauss(ax, ay, bx, by, px, py);
    float gsareaBCP = areaOfTriangleGauss(bx, by, cx, cy, px, py);
    float gsareaCAP = areaOfTriangleGauss(cx, cy, ax, ay, px, py);

    printf("Площадь треугольника ABC по формуле Гаусса: %.2f\n", gsareaABC);
    printf("Площадь треугольника ABP по формуле Гаусса: %.2f\n", gsareaABP);
    printf("Площадь треугольника BCP по формуле Гаусса: %.2f\n", gsareaBCP);
    printf("Площадь треугольника CAP по формуле Гаусса: %.2f\n\n", gsareaCAP);

    float sumAreas = areaABP + areaBCP + areaCAP;
    float eps = 0.00001;

    if (fabs(sumAreas - areaABC) <= eps) {
        printf("Сумма площадей треугольников ABP, BCP, CAP равна площади треугольника ABC: %.2f\n", sumAreas);
        printf("Точка P принадлежит треугольнику ABC.\n");
    } else {
        printf("Сумма площадей треугольников ABP, BCP, CAP не равна площади треугольника ABC: %.2f\n", sumAreas);
        printf("Точка P не принадлежит треугольнику ABC.\n");
    }
    
    return 0;
}

float distance(float x1, float y1, float x2, float y2) {
    return fabs(sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2)));
}

float areaOfTriangleGeron(float x1, float y1, float x2, float y2, float x3, float y3) {
    float a = distance(x1, y1, x2, y2);
    float b = distance(x2, y2, x3, y3);
    float c = distance(x3, y3, x1, y1);
    float p = (a + b + c) / 2;
    return fabs(sqrt(p * (p - a) * (p - b) * (p - c)));
}

float areaOfTriangleGauss(float x1, float y1, float x2, float y2, float x3, float y3) {
    return fabs((x1 * y2 + x2 * y3 + x3 * y1 - x2 * y1 - x3 * y2 - x1*y3) / 2);
}