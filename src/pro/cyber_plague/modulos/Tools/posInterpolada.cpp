#include "posInterpolada.h"

void posInterpolada::setPosition(float nx, float ny){
    lastX = x;
    lastY = y;
    x = nx;
    y = ny;
}