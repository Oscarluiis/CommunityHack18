// Para el manejo de la libreria

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

// Para manejar el archivo
#include <fstream>
#include <sstream>

// Para c++
using namespace std;
using namespace sf;

// Incluir Recursos (no necesariamente en la carpeta de proyecto, se puede con el path)

#include "ResourcePath.hpp"

// Crear la ventana (w=h, h=b)

const int W=800;
const int H=600;

//Velocidad a la que se va desplazar (nivel unico)

int speed = 4;

// Abrir ventana [h][b]

bool field [W][H];

// Hacer un Struct para los jugadores

struct player{
    
    // Movimiento en x, en y y en direcciones
   
    int x,y,dir;
    
    // Colorear (se le debe asignar un color a cada jugador)
    
    Color color;
    
    // Clase para el color
    player (Color c){
        
        // Movimiento en x
        
        x=rand() % W;
        
        // Movimiento en y
        
        y=rand()%H;
        
        // Ir dando el color
        
        color = c;
        
        // Ahora en direccion
        
        dir=rand()%4;
        
    }
    
    // Asi como cuando vas arriba y abajo, asi mismo derecha e izquierda
    // 4 direcciones posibles
    void tick(){
        
        if(dir==0)  y += 1;
        if(dir==1)  x -=  1;
        if(dir==2)  x += 1;
        if(dir==3)  y -=  1;
        
        // En caso de salir del screen duhhh duhhhh
        
        
    }
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
};
