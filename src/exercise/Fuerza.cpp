#include <filesystem>
#include "../../include/exercise/Fuerza.h"

Fuerza::Fuerza() {}
Fuerza::Fuerza(string nombre) {this -> nombre = nombre;}

Fuerza::~Fuerza() {cout<<"Ejercicio de Fuerza destruido"<<endl;}

void Fuerza:: ingresar_datos() {
    int repeticiones;
    int series;
    float peso;
    string frecuencia;

    do {
        cout << "Ingrese el número de repeticiones: ";
        cin >> repeticiones;
    } while (repeticiones<=0);

    do {
        cout << "Ingrese el número de series: ";
        cin >> series;
    } while (series<=0);

    do{
        cout << "Ingrese el peso que usa para el ejercicio (kg): ";
        cin >> peso;
    } while (peso<=0);

    do {
        cout << "Ingrese la frecuencia (diaria/interdiaria/semanal): ";
        cin >> frecuencia;
        if (frecuencia != "diaria" and frecuencia != "interdiaria" and frecuencia!= "semanal")
            cout << "La frecuencia tiene que ser diaria, interdiaria o semanal. Ingrésela nuevamente. "<<endl;
    } while(frecuencia != "diaria" and frecuencia != "interdiaria" and frecuencia!= "semanal");

    // Set the attributes with the validated user input
    this->repeticiones=repeticiones;
    this->series=series;
    this->peso=peso;
    this->frecuencia=frecuencia;
}

void Fuerza::mostrar_informacion() {
    cout << "Realiza " << repeticiones << " repeticiones de " << nombre << " en " << series << " series con un peso de "
         << peso << " Kg " << frecuencia << "mente" << endl;
    cout <<"Calorias quemadas : "<<CQE<<endl;
}

void Fuerza::exportacion_informacion() {
    std::string absolute_path = "C:\\Users\\PC\\OneDrive\\Escritorio\\UTEC\\CLionProjects\\docs\\ReporteGeneral.txt";
    std::cout << "Ruta absoluta: " << absolute_path << std::endl;

    // Verificar si el archivo está en modo de solo lectura
    std::filesystem::perms p = std::filesystem::status(absolute_path).permissions();
    if ((p & std::filesystem::perms::owner_write) == std::filesystem::perms::none) {
        std::cerr << "El archivo está en modo de solo lectura: " << absolute_path << std::endl;
        return;
    }

    // Probar con un archivo nuevo
    std::string test_path = "C:\\Users\\PC\\OneDrive\\Escritorio\\UTEC\\CLionProjects\\docs\\TestReporte.txt";
    std::ofstream test_file(test_path, std::ios::app);
    if (!test_file.is_open()) {
        std::cerr << "Error al abrir el archivo de prueba " << test_path << std::endl;
        return;
    }
    test_file << "Prueba de escritura en archivo nuevo." << std::endl;
    test_file.close();

    // Intentar abrir el archivo original
    std::ofstream archivo(absolute_path, std::ios::app);
    if (!archivo.is_open()) {
        std::cerr << "Error al abrir el archivo " << absolute_path << std::endl;
        return;
    }
    archivo << "Realiza " << repeticiones << " repeticiones de " << nombre << " en " << series << " series con un peso de " << peso << " Kg " << frecuencia << "mente" << std::endl;
    archivo << "Calorias quemadas : " << CQE << std::endl;
    archivo.close();
}

void Fuerza::hallar_CQ_FC(double TBM, int FCM) {

    if (nombre == "Press Banca") {
        FA = 0.9;
        CQE = 0.01 * peso * repeticiones * series * FA * TBM;
        FCE = 0.5 * FCM;
    }
    else if (nombre == "Peso Muerto"){
        FA = 1.1;
        CQE = 0.01 * peso * repeticiones * series * FA * TBM;
        FCE = 0.55 * FCM;
    }
    else if (nombre == "Sentadillas"){
        FA = 1.2;
        CQE = 0.03 * peso * repeticiones * series * FA * TBM;
        FCE = 0.45 * FCM;
    }
    else if (nombre == "Dominadas"){
        FA = 0.95;
        CQE = 0.05 * peso * repeticiones * series * FA * TBM;
        FCE = 0.6 * FCM;
    }
    else if (nombre == "Flexiones"){
        FA = 0.8;
        CQE = 0.04 * peso * repeticiones * series * FA * TBM;
        FCE = 0.55 * FCM;
    }
    CQE = -CQE;
    if (frecuencia == "diaria")
        CQE *= 7;
    else if (frecuencia == "interdiaria")
        CQE *= 3.5;
    else if (frecuencia == "semanal")
        CQE *= 1;
}


