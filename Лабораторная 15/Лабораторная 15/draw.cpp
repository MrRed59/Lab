﻿#include "draw.h"
#include "GL/glut.h"
#include <cmath>
#include <string>

void reshape(int w, int h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, w, 0, h);
    glMatrixMode(GL_MODELVIEW);
    glutPostRedisplay();
}

void display()
{
    glClearColor(0.19, 0.84, 0.76, 1.0);       //Фон
    glClear(GL_COLOR_BUFFER_BIT);

    constexpr int x[7]{ 0, 111, 350, 630, 430, 340, 650};    //x - координаты окружностей
    constexpr int y[7]{ 0, 370, 360, 440, 240, 490, 310};    //y - координаты окружностей

    glLineWidth(2.0);       //Толщина линии, связывающей окружности
    drawLine(x[1], y[1], x[2], y[2]);       //Координаты начала и конца линии. Берётся из массива.
    DrawString(GLUT_BITMAP_HELVETICA_18, (x[1] + x[2]) / 2, (y[1] + y[2]) / 2 + 15, 4);
    drawLine(x[1], y[1], x[5], y[5]);       //Координаты начала и конца линии. Берётся из массива.
    DrawString(GLUT_BITMAP_HELVETICA_18, (x[1] + x[5]) / 2, (y[1] + y[5]) / 2 + 15, 8);
    drawLine(x[2], y[2], x[3], y[3]);       //Координаты начала и конца линии. Берётся из массива.
    DrawString(GLUT_BITMAP_HELVETICA_18, (x[2] + x[3]) / 2, (y[2] + y[3]) / 2 + 15, 15);
    drawLine(x[2], y[2], x[4], y[4]);       //Координаты начала и конца линии. Берётся из массива.
    DrawString(GLUT_BITMAP_HELVETICA_18, (x[2] + x[4]) / 2 + 5, (y[2] + y[4]) / 2 + 15, 9);
    drawLine(x[4], y[4], x[6], y[6]);       //Координаты начала и конца линии. Берётся из массива.
    DrawString(GLUT_BITMAP_HELVETICA_18, (x[4] + x[6]) / 2, (y[4] + y[6]) / 2 + 20, 11);
    drawLine(x[6], y[6], x[3], y[3]);       //Координаты начала и конца линии. Берётся из массива.
    DrawString(GLUT_BITMAP_HELVETICA_18, (x[6] + x[3]) / 2 + 15, (y[6] + y[3]) / 2, 6);
    drawLine(x[5], y[5], x[2], y[2]);       //Координаты начала и конца линии. Берётся из массива.
    DrawString(GLUT_BITMAP_HELVETICA_18, (x[5] + x[2]) / 2 + 15, (y[5] + y[2]) / 2, 23);
    drawLine(x[5], y[5], x[3], y[3]);       //Координаты начала и конца линии. Берётся из массива.
    DrawString(GLUT_BITMAP_HELVETICA_18, (x[5] + x[3]) / 2 + 5, (y[5] + y[3]) / 2 + 15, 12);
   

    constexpr int vertexNum[7]{ 0, 1, 2, 3, 4, 5, 6};         //Номер вершины
    constexpr int R = 30;     //Радиус окружности
    constexpr int vertexCount = 6;
    for (int i = 1; i <= vertexCount; ++i)
    {
        drawFillCircle(x[i], y[i], R);                      //Отрисовываем круги по кол-ву вершин.
        DrawString(GLUT_BITMAP_TIMES_ROMAN_24, x[i], y[i], vertexNum[i]);   //Числа на вершинах
    }

    glEnd();
    glutSwapBuffers();
}

void drawLine(int x1, int y1, int x2, int y2)
{
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2i(x1, y1);
    glVertex2i(x2, y2);
    glEnd();
}

void drawFillCircle(int x, int y, int R)
{
    glColor3f(1.0, 1.0, 1.0);       //Цвет круга
    float x1{}, y1{};
    glBegin(GL_POLYGON);        //Посекторная отрисовка круга
    for (int i = 0; i <= R; i++)
    {
        for (int t = 0; t <= 360; t++)
        {
            x1 = static_cast<float> (i * std::sin(t) + x);
            y1 = static_cast<float> (i * std::cos(t) + y);
            glVertex2f(x1, y1);
        }
    }
    glEnd();
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_POINTS);     //Отрисовка контура круга
    for (int t = 0; t <= 360; t++)
    {
        x1 = static_cast<float> (R * std::sin(t) + x);
        y1 = static_cast<float> (R * std::cos(t) + y);
        glVertex2f(x1, y1);
    }
    glEnd();
}

void DrawString(void* p_font, int x, int y, int vertexNum)
{
    std::string s = std::to_string(vertexNum);
    glRasterPos2i(x - 6, y - 6);        //Выравнивание символа по центру окружности
    for (const char& i : s)
    {
        glutBitmapCharacter(p_font, i);     //Шрифт и отрисовываемый символ
    }
}
