// RETO 1 
#include <iostream> 

using namespace std; 
class Persona{ 

    // Atributos 
    public: 
    string tipoDoc; 
    string nombre; 
    string apellido;
    string sexo;  
    int documento; 
    int edad; 
    float peso; 
    float estatura; 

    //Crear constuctor vacio 
    Persona(){
    }
    
    // Métodos 
   /* Persona (string tipoDoc0, string nombre0, string apellido0, string sexo0, int documento0, int edad0, float peso0, float estatura0){
    }*/
    void pedirDatos(){
        cout << "Ingresa el tipo de documento";
        cin >> tipoDoc; 
        cout << "Ingresa el numero de documento";
        cin >> documento; 
        cout<< "Ingresa tu nombre";
        cin >> nombre; 
        cout << "Ingresa tu apellido"; 
        cin >> apellido; 
        cout << "Ingresa tu peso"; 
        cin >> peso; 
        cout << "Ingresa tu estatura"; 
        cin >> estatura; 
        cout << "Ingresa tu edad"; 
        cin >> edad; 
        cout << "Ingresa tu sexo"; 
        cin >> sexo; 
    };
int main(){
    //Creas la instancia de la clase 
    Persona persona0;
    persona0.pedirDatos(); 
}

    void mostrarPersona(){ 
        cout << "El tipo de documento es " << tipoDoc << " con el número " << documento << ". El nombre de la persona es " << nombre << " y el apellido. " << " Tiene un peso de " << peso << " kg y una estatura de " << estatura << " m. Tiene " << edad << " años. Y es " << sexo << "." << endl; 
};
void calcularImc() {
    float pesoActual;
    pesoActual = peso / (estatura * estatura);

    if (pesoActual < 20) {
        cout << "El peso está por debajo de lo ideal";
    } else if (pesoActual >= 20 && pesoActual <= 25) {
        cout << "El peso es ideal";
    } else {
        cout << "La persona está en sobrepeso";
    }
}
    void mayorEdad(){
        if (edad < 18){
            cout << "Eres menor de edad";
        } else ( edad >= 18);
            cout << "Eres mayo de edad";
}
};