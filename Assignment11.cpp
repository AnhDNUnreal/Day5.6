#include "Assignment11.h"

using namespace std;

//**********************************************************
// Name:		CLine
// Description:	Constructor of CLine class
// Arguments:	input_length: length of the line
//              input_color: color of the line
// Return:		Object CLine.
//**********************************************************
CLine::CLine(int input_length, int input_color)
{

    length = input_length;
    color = input_color;
}

//**********************************************************
// Name:		draw
// Description:	Draw a line
// Arguments:	x: Console screen horizontal coordinates
//              y: Console screen vertical coordinates
//              device_context: Logical output device associated with physical output device 
// Return:		void
//**********************************************************
void CLine::draw(int x, int y, HDC device_context)
{

    HPEN pen = CreatePen(PS_SOLID, 2, (DWORD)color);
    SelectObject(device_context, pen);

    MoveToEx(device_context, x, y, (LPPOINT)NULL);
    LineTo(device_context, x + length, y);
}

//**********************************************************
// Name:		CCircle
// Description:	Constructor of CCircle class
// Arguments:	input_radium: Radium of the circle
//              input_color: color of the circle
// Return:		Object CCircle.
//**********************************************************
CCircle::CCircle(int input_radium, int input_color)
{
    radium = input_radium;
    color = input_color;
}

//**********************************************************
// Name:		draw
// Description:	Draw a circle
// Arguments:	x: Console screen horizontal coordinates
//              y: Console screen vertical coordinates
//              device_context: Logical output device associated with physical output device 
// Return:		void
//**********************************************************
void CCircle::draw(int x, int y, HDC device_context)
{
    HPEN pen = CreatePen(PS_SOLID, 2, (DWORD)color);
    SelectObject(device_context, pen);

    Ellipse(device_context, x, y, x + 2 * radium, y + 2 * radium);
}

//**********************************************************
// Name:		CRectangle
// Description:	Constructor of CRectangle class
// Arguments:	input_width: width of the rectangle
//              input_height: height of the rectangle
//              input_color: color of the rectangle
// Return:		Object CRectangle.
//**********************************************************
CRectangle::CRectangle(int input_width, int input_height, int input_color)
{
    width = input_width;
    height = input_height;
    color = input_color;
}

//**********************************************************
// Name:		draw
// Description:	Draw a Rectangle
// Arguments:	x: Console screen horizontal coordinates
//              y: Console screen vertical coordinates
//              device_context: Logical output device associated with physical output device 
// Return:		void
//**********************************************************
void CRectangle::draw(int x, int y, HDC device_context)
{
    HPEN pen = CreatePen(PS_SOLID, 2, (DWORD)color);
    SelectObject(device_context, pen);

    Rectangle(device_context, x, y, x + width, y + height);
}

//**********************************************************
// Name:		CSquare
// Description:	Constructor of CSquare class
// Arguments:	length_side: length of the line
//              input_color: color of the line
// Return:		Object CSquare.
//**********************************************************
CSquare::CSquare(int length_side, int input_color)
{
    width = length_side;
    height = length_side;
    color = input_color;
}

int main()
{
    //Use the pointer array of the CPicture class to initialize the shapes
    CPicture Picture;
    Picture.Arr_ptr[0] = new CLine(50, 3000);
    Picture.Arr_ptr[1] = new CCircle(50, 3000);
    Picture.Arr_ptr[2] = new CRectangle(50, 30, 1500);
    Picture.Arr_ptr[3] = new CSquare(50, 3000);

    //Enter the coordinates where the shapes will appear one after another
    int Array_CoordinateX[4];
    int Array_CoordinateY[4];

    for (int i = 0; i < 4; i++)
    {
        cout << "Input coordinate of Shape " << i + 1 << endl;
        cout << "X: ";
        cin >> Array_CoordinateX[i];
        cout << "Y: ";
        cin >> Array_CoordinateY[i];
    }

    cout << "Enter the order of the shapes: " << endl;
    cout << "1. Line " << endl;
    cout << "2. Circle " << endl;
    cout << "3. Rectangle " << endl;
    cout << "4. Square " << endl;
    cout << "0. Exit" << endl;
    cout << "Example: 1324" << endl << endl;
    string input;
    while (1)
    {
        //Choose the order in which shapes appear
        cout << " - Your input: ";
        cin >> input;
        system("CLS");

        //Get Console To Paint
        HWND console_handle = GetConsoleWindow();
        HDC device_context = GetDC(console_handle);
        int int_input;
        for (int i = 0; i < 4; i++)
        {
            int_input = input[i] - '0';
            if (int_input < 1 || int_input > 4)
                exit(0);
            //Draw shapes
            Picture.Arr_ptr[int_input - 1]->draw(Array_CoordinateX[i], Array_CoordinateY[i], device_context);
        }
        ReleaseDC(console_handle, device_context);
        Sleep(3000); // Delay to view picture
    }

}