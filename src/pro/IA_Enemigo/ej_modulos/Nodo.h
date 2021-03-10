#pragma once

class Nodo{
    private:
        Nodo *padre;
        int f;
        int g;
        int h;
        int x;
        int y;

    public:
        Nodo(Nodo *p, int coorX, int coorY);

        int getF();
        int getG();
        int getH();

        void setF(int fn);
        void setG(int gn);
        void setH(int hn);
};