#include "posInterpolada.h"

void posInterpolada::setPosition(float nx, float ny){
    lastX = x;
    lastY = y;
    x = nx;
    y = ny;
}
void posInterpolada::setLastPosition(float nx, float ny){
    lastX = nx;
    lastY = ny;
}