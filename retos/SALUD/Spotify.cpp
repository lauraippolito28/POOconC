#include <iostream>
#include <string>

using namespace std;

class Cancion {
public:
    Cancion(string titulo, string artista) : titulo(titulo), artista(artista) {}

    string getTitulo() const { return titulo; }
    string getArtista() const { return artista; }

private:
    string titulo;
    string artista;
};
class Lista {
public:
    Lista(Cancion cancion) : cancion(cancion), siguiente(nullptr) {}

    Cancion getCancion() const { return cancion; }
    Lista* getSiguiente() const { return siguiente; }
    void setSiguiente(Lista* nodo) { siguiente = nodo; }

private:
    Cancion cancion;
    Lista* siguiente;
};

class ListaReproduccion {
public:
    ListaReproduccion() : cabeza(nullptr) {}

    void agregarCancion(Cancion cancion) {
        Lista* nuevoNodo = new Lista(cancion);
        if (cabeza) {
            cabeza = nuevoNodo;
        } else {
            Lista* temp = cabeza;
            while (temp->getSiguiente()) {
                temp = temp->getSiguiente();
            }
            temp->setSiguiente(nuevoNodo);
        }
    }

    void mostrarLista() const {
        Lista* temp = cabeza;
        while (temp) {
            cout << temp->getCancion().getTitulo() << " - " << temp->getCancion().getArtista() << endl;
            temp = temp->getSiguiente();
        }
    }

private:
    Lista* cabeza;
};
class Usuario {
public:
    Usuario(string nombre) : nombre(nombre), listaReproduccion(), listaMeGusta(nullptr), siguienteUsuario(nullptr) {}

    string getNombre() const { return nombre; }
    ListaReproduccion& getListaReproduccion() { return listaReproduccion; }

    void MeGusta(Cancion cancion) {
        Lista* nuevoNodo = new Lista(cancion);
        nuevoNodo->setSiguiente(listaMeGusta);
        listaMeGusta = nuevoNodo;
    }

    void mostrarMeGusta() const {
        Lista* temp = listaMeGusta;
        while (temp) {
            cout << temp->getCancion().getTitulo() << " - " << temp->getCancion().getArtista() << endl;
            temp = temp->getSiguiente();
        }
    }
    void setSiguienteUsuario(Usuario* usuario) { siguienteUsuario = usuario; }
    Usuario* getSiguienteUsuario() const { return siguienteUsuario; }

private:
    string nombre;
    ListaReproduccion listaReproduccion;
    Lista* listaMeGusta;
    Usuario* siguienteUsuario;
};

int main() {
    Cancion cancion1("Cancion 1", "Artista 1");
    Cancion cancion2("Cancion 2", "Artista 2");
    Cancion cancion3("Cancion 3", "Artista 3");
    Usuario usuario1("Usuario 1");
    Usuario usuario2("Usuario 2");
    usuario1.getListaReproduccion().agregarCancion(cancion1);
    usuario1.getListaReproduccion().agregarCancion(cancion2);
    usuario1.MeGusta(cancion1);
    usuario1.MeGusta(cancion3);
    usuario1.setSiguienteUsuario(&usuario2);
    cout << "Lista de reproducción de " << usuario1.getNombre() << ":" << endl;
    usuario1.getListaReproduccion().mostrarLista();

    cout << "\nLista de 'Me gusta' de " << usuario1.getNombre() << ":" << endl;
    usuario1.mostrarMeGusta();
    if (usuario1.getSiguienteUsuario() != nullptr) {
        cout << "\nEl siguiente usuario de " << usuario1.getNombre() << " es: " << usuario1.getSiguienteUsuario()->getNombre() << endl;
    } else {
        cout << "\nNo hay siguiente usuario para " << usuario1.getNombre() << endl;
    }

    return 0;
}
