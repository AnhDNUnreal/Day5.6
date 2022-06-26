#pragma once
#include <Windows.h>
#include <iostream>
#include <cstdlib>
// ==================================================================.
// CShape : Abstract class for shapes
// ==================================================================.
class CShape
{
public:
    int color;
    virtual void draw(int x, int y, HDC device_context) = 0;
};
// ==================================================================.
// CLine : Class for draw line
// ==================================================================.
class CLine : public CShape
{
private:
    int length;
public:
    void draw(int x, int y, HDC device_context);

    CLine(int length, int color);
};
// ==================================================================.
// CCircle : Class for draw circle
// ==================================================================.
class CCircle : public CShape
{
private:
    int radium;
public:
    void draw(int x, int y, HDC device_context);

    CCircle(int radium, int color);
};
// ==================================================================.
// CRectangle : Class for draw rectangle
// ==================================================================.
class CRectangle : public CShape
{
protected:
    int width, height;
public:
    void draw(int x, int y, HDC device_context);

    CRectangle() {};
    CRectangle(int width, int height, int color);
};
// ==================================================================.
// CSquare : Class for draw square
// ==================================================================.
class CSquare : public CRectangle
{
public:
    CSquare(int side, int color);
};
// ==================================================================.
// CPicture : Management class
// ==================================================================.
class CPicture
{
public:
    CShape* Arr_ptr[4]; // Array of pointers to shapes

};  