#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
using namespace sf;

class caminar {
    public:
        

        void Update(float deltaTime);
        void Draw(RenderWindow window);
    private:
        RectangleShape body;
        unsigned int row;
        float speed;
        bool faceRithg;
}