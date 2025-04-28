// task_4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

/* The class DrawingAPI is an abstract class with a virtual function for drawing rectangles. */
class DrawingAPI {
public:
    virtual ~DrawingAPI() = default; 
    virtual void drawRectangle(int x, int y, int width, int height) = 0; 
};

/* The `API1Renderer` class in C++ provides a method to draw a rectangle and outputs information about
the drawn rectangle using API1. */
class API1Renderer {
public:
    void drawRectangle(int x, int y, int width, int height) {
        std::cout << "[API1Renderer] Drawing rectangle:\n"
            << "  Position: (" << x << ", " << y << ")\n"
            << "  Size: " << width << "x" << height << "\n"
            << "  Status: Successfully drawn using API1\n"
            << "----------------------------------------\n";
    }
};

/* The API2Graphics class in C++ provides a method to render a rectangle with specified position and
size using API2. */
class API2Graphics {
public:
    void renderRect(int left, int top, int w, int h) {
        std::cout << "[API2Graphics] Rendering rectangle:\n"
            << "  Position: (" << left << ", " << top << ")\n"
            << "  Size: " << w << "x" << h << "\n"
            << "  Status: Successfully rendered using API2\n"
            << "----------------------------------------\n";
    }
};

/* The class DrawingAPI1 adapts calls to API1Renderer for drawing rectangles. */
class DrawingAPI1 : public DrawingAPI {
private:
    API1Renderer renderer;
public:
    void drawRectangle(int x, int y, int width, int height) override {
        std::cout << "[DrawingAPI1] Adapting call to API1Renderer:\n";
        renderer.drawRectangle(x, y, width, height);
    }
};

/* The class DrawingAPI2 adapts calls to API2Graphics to draw rectangles. */
class DrawingAPI2 : public DrawingAPI {
private:
    API2Graphics graphics; 
public:
    void drawRectangle(int x, int y, int width, int height) override {
        std::cout << "[DrawingAPI2] Adapting call to API2Graphics:\n";
        graphics.renderRect(x, y, width, height);
    }
};

/* The Rectangle class represents a rectangle shape with position and size properties, and it can be
drawn using a specified DrawingAPI. */
class Rectangle {
private:
    int x, y, width, height;
    DrawingAPI* drawingAPI; 
public:
    Rectangle(int x, int y, int width, int height, DrawingAPI* api)
        : x(x), y(y), width(width), height(height), drawingAPI(api) {
        std::cout << "[Rectangle] Created with:\n"
            << "  Position: (" << x << ", " << y << ")\n"
            << "  Size: " << width << "x" << height << "\n"
            << "----------------------------------------\n";
    }

    void draw() {
        std::cout << "[Rectangle] Initiating draw operation:\n";
        drawingAPI->drawRectangle(x, y, width, height); 
    }
};

int main() {
    std::cout << "=== Vector Graphic Editor ===\n\n";

    std::cout << "[Main] Creating Rectangle with API1:\n";
    DrawingAPI1 api1;
    Rectangle rect1(10, 20, 30, 40, &api1);
    rect1.draw();

    std::cout << "\n";

    std::cout << "[Main] Creating Rectangle with API2:\n";
    DrawingAPI2 api2;
    Rectangle rect2(50, 60, 70, 80, &api2);
    rect2.draw();

    std::cout << "===  Completed ===\n";
    return 0;
}