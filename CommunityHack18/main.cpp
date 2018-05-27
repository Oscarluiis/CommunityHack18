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
        
        if(x>=W) x=0; if(x<0) x=W-1;
        if(y>=H) y=0; if (y<0) y=H-1;
    
    }
    
    //Para ir pintando
    
    Vector3f getColor(){
        return Vector3f(color.r,color.g,color.b);
    }
    
};

// La parte de archivos, donde va quedar registrado las victorias y apertura del juego

string toString (int n){
    stringstream s;
    s<<n;
    return s.str();
}

void registro(){
    
    RenderWindow app(VideoMode(800,600), "Community Hack 2018");
    //Crear la textura lol
    Texture t;
    
    // Cargar la imagen cualquiera
    if(!t.loadFromFile(resourcePath()+"NombreImagen.png")){
        return EXIT_FAILURE;
    }
   
    // Sprite es para utilizar la imagen cargada en la tarjeta grafica y fuente pues... la fuente
    
    Sprite ft(t);
    Font fuente;
    
    //Cargar la fuente cualquiera
    if(!fuente.loadFromFile(resourcePath() + "arial.ttf")){
        return EXIT_FAILURE;
    }
    
    Text texto;
    String cadena;
    cadena="=======================\n   MIS REGISTROS       \n=======================\n";
    texto.setFont(fuente);
    texto.setCharacterSize(12);
    texto.setPosition(10, 10);
    ifstream  archivo("Registro.txt");
    string line;
    
    if(archivo.is_open()){
        while(getline(archivo,line)){
            cadena=cadena+line+"\n";
        }
    }
    
    archivo.close();
    
    while(app.isOpen()){
        
    }
    
    
    
    
