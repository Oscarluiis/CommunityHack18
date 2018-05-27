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
        Event e;
        while(app.pollEvent(e)){
            if(e.type == Event::Closed)
                app.close();
        }
        
        texto.setString(cadena);
        app.clear();
        app.draw(texto);
        app.display();
    }
}

// Ahora la funcion para que escriba (hora actual : 20:56)

void escribir (string pal){
    
    ofstream fichero;
    fichero.open("Registro.txt",std::ios_base::app);
    fichero<<pal;
    fichero.close();
}

// Abrir el juego o al menos la ventana lol (hora actual : 21:06)

void game (){
    
    
    srand(time(0));
    // Ventana
    RenderWindow window (VideoMode (W,H), "Community Hack 2018");
    window.setFramerateLimit(60);
    
    Texture texture;
    
    if(!texture.loadFromFile(resourcePath()+"NombreImagen2")){
        
        return EXIT_FAILURE;
    }
    
    Sprite sBackground(texture);
    
    //Definiendo el color por cada jugador (hora actual : 21:16)
    
    player p1(Color::Red), p2(Color::White);
    
    Sprite sprite;
    
    // Procesar textura (hora actual : 21:27)
    
    RenderTexture text;
    
    // Se crea (Es al contorno de la ventana)
    
    text.create(W, H);
    text.setSmooth(true);
    sprite.setTexture(text.getTexture());
    text.clear();
    text.draw(sBackground);
    
    // Declara la variable fuente (hora actual : 21:33)
    
    Font font;
    
    if(!font.loadFromFile(resourcePath()+"NombreImagen3")){
        
        return EXIT_FAILURE;
    }
    
    Text tex ("¡Ganaste!", font, 35);
    tex.setPosition(W/2-80, 20);
    
    // Probando efectos visuales (shader como neon) ------ Proceso de decision (si se pone o no)
    // However trato de implementar (hora actual : 21:41)
    // pdt: voy a tomar un receso lol xD
    
    Shader* shader = new Shader;
    
    shader  -> loadFromFile(resourcePath()+"shader.frag", Shader :: Fragment);
    shader -> setUniform("frag_ScreenResolution",  100);
    shader -> setUniform ("frag_LightAttenuation", 100);
    RenderStates states; states.shader = shader;
    
    // Variable random para que vayan 0-0 xD (hora actual : 23:38)
    
    bool Game = -1;
    
    while (window.isOpen()){
    
        Event eve;
        
        while (window.pollEvent(eve)){
            if (eve.type == Event::Closed)
                window.close();
        }
    
        // Movimientos para el jugador 1
        
        if (Keyboard :: isKeyPressed(Keyboard :: Left)) if (p1.dir != 2) p1.dir = 1;
        if (Keyboard :: isKeyPressed(Keyboard :: Right)) if(p1.dir != 1) p1.dir = 2;
        if (Keyboard :: isKeyPressed(Keyboard :: Up)) if (p1.dir != 3) p1.dir = 0;
        if (Keyboard :: isKeyPressed(Keyboard :: Down)) if(p1.dir != 0) p1.dir = 3;
        
        // Movimientos para el jugador 2
        
        if (Keyboard :: isKeyPressed(Keyboard :: A)) if (p2.dir != 2) p2.dir = 1;
        if (Keyboard :: isKeyPressed(Keyboard :: D)) if (p2.dir != 1) p2.dir = 2;
        if (Keyboard :: isKeyPressed(Keyboard::W)) if (p2.dir != 3) p2.dir =0;
        if (Keyboard :: isKeyPressed(Keyboard :: S)) if (p2.dir != 0) p2.dir=3;
        
     // pdt: hora actual : 00:07
        
        // Validar el empate
        
        if (!Game){
            window.draw(tex);
            window.display();
            continue;
            
        }
        
        // Velocidad (hora actual : 00:12 )
        
        for ( int i=0; i< speed ; i++ ){
            
            p1.tick(); p2.tick();
            
            if (field [p1.x] [p1.y] == 1){
                Game = 0;
                tex.setFillColor(p2.color);
                escribir("\n\n GANADOR: Jugador 1\t Puntos: 10 ");
            }
            
            if (field[p2.x][p2.y]==1){
                Game = 0;
                tex.setFillColor(p1.color);
                escribir("\n\n GANADOR: Jugador 2\t Puntos: 10 ");
            }
            
            field [p1.x][p1.y] = 1;
            field [p2.x][p2.y] = 1;
            
            // Forma que ira dibujando (hora actual : 02:25)
            
            CircleShape cir(3);
            cir.setPosition(p1.x, p1.y); cir.setFillColor(p1.color); text.draw(cir);
            cir.setPosition(p2.x, p2.y); cir.setFillColor(p1.color); text.draw(cir);
            
            text.display();
            
            shader -> setUniform("frag_LightOrigin", Vector2f(p1.x, p1.y));
            shader -> setUniform("frag_LightColor", p1.getColor());
            
            text.draw(sprite, states);
            
            shader ->  setUniform("frag_LightOrigin", Vector2f(p2.x, p2.y));
            shader -> setUniform("frag_LightColor", p2.getColor());
            text.draw(sprite, states);
        }
        // Mostrar
        window.clear();
        window.draw(sprite);
        window.display();
    }
}

// Funcion de instrucciones (hora actual 02:51)

void instruccion(){
    
    RenderWindow app (VideoMode(800,600),"Como Jugar");
    app.setFramerateLimit(60);
    
    Texture t1;
    
    if(!t1.loadFromFile(resourcePath()+"NombreImagen4")){
        return EXIT_FAILURE;
        
    }
    
    Sprite sback(t1);
    while(app.isOpen()){
        
        Event e;
        
        while(app.pollEvent(e)){
            if(e.type==Event::Closed){
                app.close();
            }
        }
        
        app.clear();
        app.draw(sback);
        app.display();
    }
    
}



    
    
    
    
    
    
    
    
    
