#include <iostream>
#include <unordered_map>

using namespace std;

class CargaDatos
{
private:
    unordered_map<string, int> sustantivos;
    unordered_map<string, int> excepciones;

public:
    CargaDatos() {}

    void inicializar()
    {
        cargarSustantivos();
        cargarExcepciones();
    }
    void cargarSustantivos()
    {
        string listaSustantivos[] = {
            "crema", "café", "estrella", "explosión", "guitarra", "plástico", "navaja", "martillo", "libros", "lápiz",
            "lapicera", "aluminio", "embarcación", "letra", "agujeta", "ventana", "librería", "sonido", "universidad", "rueda",
            "perro", "llaves", "camisa", "pelo", "papá", "sillón", "felicidad", "catre", "teclado", "servilleta", "escuela", "pantalla",
            "sol", "codo", "tenedor", "estadística", "mapa", "agua", "mensaje", "lima", "cohete", "rey", "edificio", "césped", "presidencia", "hojas", "parlante", "colegio", "granizo", "pestaña", "lámpara", "mano", "monitor", "flor", "música", "hombre", "tornillo", "habitación", "velero", "abuela", "abuelo", "palo", "satélite", "templo", "lentes", "bolígrafo", "plato", "nube", "gobierno", "botella", "castillo", "enano", "casa", "libro", "persona", "planeta", "televisor", "guantes", "metal", "teléfono", "proyector", "mono", "remera", "muela", "petróleo", "percha", "remate", "debate", "anillo", "cuaderno", "ruido", "pared", "taladro", "herramienta", "cartas", "chocolate", "anteojos", "impresora", "caramelos", "living", "luces", "angustia", "zapato", "bomba", "lluvia", "ojo", "corbata", "periódico", "diente", "planta", "chupetín", "buzo", "oficina", "persiana", "puerta", "tío", "silla", "ensalada", "pradera", "zoológico", "candidato", "deporte", "recipiente", "diarios", "fotografía", "ave", "hierro", "refugio", "pantalón", "barco", "carne", "nieve", "tecla", "humedad", "pistola", "departamento", "celular", "tristeza", "hipopótamo", "sofá", "cama", "árbol", "mesada", "campera", "discurso", "auto", "cinturón", "rúcula", "famoso", "madera", "lentejas", "piso", "maletín", "reloj", "diputado", "cuchillo", "desodorante", "candado", "luz", "montañas", "computadora", "radio", "moño", "cuadro", "calor", "partido", "teatro", "bife", "fiesta", "bala", "auriculares"};
        for (int i = 0; i <= 170; i++)
        {
            agregarSustantivo(listaSustantivos[i]);
        }
    }

    void cargarExcepciones()
    {
        string excepciones[] = {
            //Infitivos
            "ar", "er", "ir",
            //Gerundios
            "endo", "ando",
            "ado", "ido", "cho",
            "to", "so",
            //Articulos <=3 letras
            "las", "la", "el",
            "los", "lo", "a",
            "un", "una", "uno"};
        for (int i = 0; i < 10; i++)
        {
            agregarExcepciones(excepciones[i]);
        }
    }

    void agregarSustantivo(string sustantivo)
    {
        sustantivos.insert({sustantivo, 1});
    }

    void agregarExcepciones(string excepcion)
    {
        excepciones.insert({excepcion, 1});
    }

    bool esSustantivo(string palabra)
    {

        if (palabra.length() <= 3) // "las", "la", "el", "los", "lo", "a", "un", "una", "uno"
            return false;
        else if (buscarSustantivo(palabra))
            return true;

        int size = palabra.length();
        string gerundioLargo = palabra.substr(size - 4, size); // {endo, ando}
        string gerundioMedio = palabra.substr(size - 3, size); // {ado , ido , cho}
        string infinitivo = palabra.substr(size - 2, size);    // Gerundio Corto o infitivo {"ar", "er", "ir","to", "so"}
        if (!buscarExcepcion(gerundioLargo) && !buscarExcepcion(gerundioMedio) && !buscarExcepcion(infinitivo))
        {
            agregarSustantivo(palabra);
            return true;
        }
        return false;
    }

    bool buscarExcepcion(string key)
    {
        if (this->excepciones.find(key) == this->excepciones.end())
        {
            return false;
        }
        return true;
    }

    bool buscarSustantivo(string key)
    {
        if (this->sustantivos.find(key) == this->sustantivos.end())
        {
            return false;
        }
        return true;
    }

    void printExcepciones()
    {
        for (auto pair : excepciones)
        {
            cout << "{" << pair.first << "}" << endl;
        }
    }
    void printSustantitvos()
    {
        for (auto pair : sustantivos)
        {
            cout << "{" << pair.first << "}" << endl;
        }
    }
};
