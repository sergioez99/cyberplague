// #define MAX_NUMBER_OF_ITEMS 6
// #define MAX_NUMBER_OF_ITEMS_L 5
// #define MAX_NUMBER_OF_ITEMS_N 5
// #define MAX_NUMBER_OF_ITEMS_T 3
// #define MAX_NUMBER_OF_ITEMS_P 4



// class Menu : public State{


//       public:
//         ~Menu();

//         void Render();
//         int run(M_Window &window);
//         void MoveUp();
//         void MoveDown();
//         void Update();
//         void Handle();
//         void Init();
//         CyberPlague* getContexto();
//         int GetPressedItem();
//         int Eventos(vector<bool> key);
//         static Menu* Instance(CyberPlague* contexto, M_Window *w);

//     protected:
//         Menu(CyberPlague* contexto, M_Window *w);
//         Menu(const Menu &);
//         Menu &operator = (const Menu &);

//     private:

//         int menustate;
//         int selectedItemIndex;
//         int selectedItemIndexL;
//         int selectedItemIndexN;
//         int selectedItemIndexT;
//         int selectedItemIndexP;
//         int width;
//         int height;
//         M_Window* window;
//      //   vector<bool> key;

//         static Menu* pinstance;
//         CyberPlague *_contexto;
//       //  sf::Font font;
//         sf::Text menu[MAX_NUMBER_OF_ITEMS];
//         sf::Text menuL[MAX_NUMBER_OF_ITEMS_L];
//         sf::Text menuN[MAX_NUMBER_OF_ITEMS_N];
//         sf::Text menuT[MAX_NUMBER_OF_ITEMS_T];
//         sf::Text menuP[MAX_NUMBER_OF_ITEMS_P];


// };