#pragma once
#include <iostream>

using namespace std;

class posInterpolada{
    private:
        float x, y;
        float lastX, lastY;
    
    public:
        float getX()        { return x;         }
        float getY()        { return y;         }
        float getLastX()    { return lastX;     }
        float getLastY()    { return lastY;     }

        void setPosition(float nx, float ny);
        void setLastPosition(float nx, float ny);
};