/**************PresentaciÛn***********
Nombre: Barba RamÌrez Kevin JosuÈ y MartÌnez MuÒoz Alejandra EstefanÌa
Fecha: jueves 18-mayo-2023
Programa: ProyectoFinal.cpp
Centro Universitario de los Altos / Universidad de Guadalajara
INGENIER√çA EN COMPUTACI”N / 2DO SEMESTRE
Profesor: Cruz Franco Carlos Javier
DescripciÛn: Programa que almacena datos especÌficos sobre alumnos (nombre, materias, maestros, carrera y calificaciones) para mostrar un promedio de calificaciones,
adem·s que permite modificar/borrar cualquiera de los datos
***************************************/
#include <iostream> //Se incluye la librerÌa principal
#include <string>  //LibrerÌa para poder usar datos del tipo string
#include <vector> //Estructura de vector utilizada para ordenar los datos y permitir guardar m·s de una cosa en cada estructura
#include <limits> // Incluir la biblioteca <limits> para usar numeric_limits
using namespace std; //Marca el uso del cout sin la funcion del std

//Declara la estructura de los alumnos
struct Alumno{
	string nombre;
	string carrera;
	//Los siguientes 3 datos se declaran con vector para poder almacenar m·s de un dato diferente en Èl
	vector<string> materias;
	vector<string> maestros;
	vector<float> calificaciones;
};

//Declara las funciones void
void agregar();
void editar();
void vaciar();
void ver();

// Variables para almacenar los datos de los alumnos que se quieran registrar
    vector<Alumno> alumnos;
    
int main(){
	//Le pone un color bonito al programa :)
	system ("color 06");
	//Llama a la estructura
	struct Alumno;
	//Muestra la bienvenida al usuario
	cout << "------------BIENVENIDO------------" << endl;
	//Declara la variable para la seleccion del men˙
	char sel;
	//Inicia un ciclo hasta que se quiera cerrar el programa
	do{
		//Muestra el men˙
		cout << "----------------------------------" << endl;
		cout << "|Que quieres hacer?              |" << endl;
		cout << "|1.Agregar alumno                |" << endl;
		cout << "|2.Editar alumno                 |" << endl;
		cout << "|3.Vaciar alumno                 |" << endl;
		cout << "|4.Ver alumno (datos y promedio) |" << endl;
		cout << "|5.Salir                         |" << endl;
		cout << "----------------------------------" << endl;
		cout << "Seleccion: ";
		cin >> sel;
		
		//Inicia un switch seg˙n la selecciÛn del usuario
		switch(sel){
			//Indicaciones de como agregar un alumno
			case '1':
				agregar();
			break;
			//Indicaciones de como editar un alumno
			case '2':
				editar();
			break;
			//Indicaciones de como vaciar un alumno
			case '3':
				vaciar();
			break;
			//Indicaciones de como ver los datos y promedio de un alumno
			case '4':
				ver();
			break;
			//Indicaciones para finalizar el programa
			case '5':
				cout << "----------------------------------------------------" << endl;
				cout << "Eso era todo, muchas gracias por usar el programa :)" << endl;
				cout << "----------------------------------------------------" << endl;
			break;
			//Indicaciones para cuando no se cumple ning˙n caso anterior
			default:
				cout << "Noup, definitivamente esa no es una opcion, intenta otra vez" << endl;
				cout << "----------------------------------" << endl;
			break;
			}
	//Le da la condiciÛn de finalizar al while
	}while(sel!='5');
	
}

//Apartado de voids
void agregar() { //Para la opciÛn agregar alumno
    Alumno alumno;
    //Pide los datos del alumno
    cin.ignore();
    cout << "Ingrese el nombre del alumno: ";
    getline(cin, alumno.nombre);
    cout << "Ingrese la carrera del alumno: ";
    getline(cin, alumno.carrera);
    cout << "Ingrese el numero de materias: ";
    int cuantas;
    cin >> cuantas;
    while (cin.fail()) {  // Verifica si la entrada fue incorrecta
    	cin.clear();  // Limpia el estado de error
        cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Ignora el resto de la lÌnea
        cout << "Me parece que ese no es un numero, sabes cuantas materias tiene el alumno? escribe el numero: ";
        cin >> cuantas;
    }
    cin.ignore();
    //Hace un for para preguntar por materias diferentes seg˙n el n˙mero de materias que dijo el usuario
    for(int i = 0; i < cuantas; i++) {
        cout << "Ingrese el nombre de la materia " << i+1 << ": ";
        string materia;
        getline(cin, materia);
        alumno.materias.push_back(materia); //Indica que ha aumentado una materia
        cout << "Ingrese el nombre del maestro de la materia " << i+1 << ": ";
        string maestro;
        getline(cin, maestro);
        alumno.maestros.push_back(maestro); //Indica que ha aumentado un maestro
        cout << "Ingrese la calificacion de la materia " << i+1 << ": ";
        float calificacion;
        cin >> calificacion;
        while (cin.fail()) {  // Verifica si la entrada fue incorrecta
	    	cin.clear();  // Limpia el estado de error
	        cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Ignora el resto de la lÌnea
	        cout << "Noup, esa no es una calificacion numerica, intenta otra vez: ";
	        cin >> calificacion;
    	}
        alumno.calificaciones.push_back(calificacion); //Indica que se ha registrado una nueva calificaciÛn
        cin.ignore();
    }
    alumnos.push_back(alumno); //Indica que ya hay un alumno m·s guardado
    cout << "Alumno registrado exitosamente" << endl;
    cout << "----------------------------------" << endl;
system("pause"); //Lo pusimos para que el men˙ no se muestre de golpe al terminar el proceso
system("cls"); //Limpia la pantalla
main(); //Regresa al main
}

//Indicaciones de lo que hace el main para editar alg˙n dato de alg˙n alumno
void editar() { //Para editar a los alumnos
    if (alumnos.empty()) { //Si a˙n no se han agregado
        cout << "No hay alumnos registrados" << endl;
        cout << "----------------------------------" << endl;
        return;
    }
    cout << "----------------------------------" << endl;
    cout << "Alumnos registrados:" << endl; 
    for (int i = 0; i < alumnos.size(); i++) { //Se hace un for para mostrar la lista de alumnos ya registrados
        cout << i << ". " << alumnos[i].nombre << endl;
    }
    cout << "----------------------------------" << endl;
    cout << "Seleccione un alumno: ";
    int seleccion;
    cin >> seleccion;
    while (cin.fail()) {  // Verifica si la entrada fue incorrecta
    	cin.clear();  // Limpia el estado de error
        cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Ignora el resto de la lÌnea
        cout << "No hay ningun alumno con ese registro, intenta otra vez: ";
        cin >> seleccion;
    }
    if (seleccion < 0 || seleccion >= alumnos.size()) { //Valida que el n˙mero de alumno realmente existe
        cout << "Seleccion invalida" << endl;
        cout << "----------------------------------" << endl;
        return;
    }
    Alumno& alumno = alumnos[seleccion]; //Establece cu·l va a ser el alumno que se va a modificar
    cout << "----------------------------------" << endl;
    cout << "Datos del alumno seleccionado:" << endl;
    cout << "Nombre: " << alumno.nombre << endl;
    cout << "Carrera: " << alumno.carrera << endl;
    cout << "Materias: " << endl;
    for (int i = 0; i < alumno.materias.size(); i++) { //Seg˙n el n˙mero de materias que se registraron, muestra los datos guardados
        cout << "- " << alumno.materias[i] << endl;
        cout << "  Maestro: " << alumno.maestros[i] << endl;
        cout << "  Calificacion: " << alumno.calificaciones[i] << endl;
    }
    cout << "----------------------------------" << endl;
    cout << "Que dato quieres editar?" << endl;
    cout << "1. Nombre" << endl;
    cout << "2. Carrera" << endl;
    cout << "3. Materias" << endl;
    int opcion;
    cin >> opcion;
    while (cin.fail()) {  // Verifica si la entrada fue incorrecta
    	cin.clear();  // Limpia el estado de error
        cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Ignora el resto de la lÌnea
        cout << "Me parece que ese no es una opcion valida, intenta de nuevo: ";
        cin >> opcion;
    }
    cin.ignore();
    cout << "----------------------------------" << endl;
    switch (opcion) { //Seg˙n la opciÛn que seleccione
        case 1: //Editar nombre
            cout << "Ingrese el nuevo nombre: ";
            getline(cin, alumno.nombre);
            cout << "Alumno modificado correctamente :)" << endl;
			cout << "----------------------------------" << endl;
        break;
        case 2: //Editar carrera
            cout << "Ingrese la nueva carrera: ";
            getline(cin, alumno.carrera);
            cout << "Alumno modificado correctamente :)" << endl;
			cout << "----------------------------------" << endl;
        break;
        case 3: //Editar materia
            if (alumno.materias.empty()) { //Si no existe ninguna materia guardada
                cout << "El alumno no tiene materias registradas" << endl;
                cout << "----------------------------------" << endl;
                return;
            }
            cout << "Materias:" << endl;
            for (int i = 0; i < alumno.materias.size(); i++) {
                cout << i+1 << ". " << alumno.materias[i] << endl;
            }
            cout << "Seleccione una materia: ";
            int cual;
            cin >> cual;
            while (cin.fail()) {  // Verifica si la entrada fue incorrecta
		    	cin.clear();  // Limpia el estado de error
		        cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Ignora el resto de la lÌnea
		        cout << "No hay ninguna materia con ese registro, intenta otra vez: ";
		        cin >> cual;
		    }
            if (cual < 1 || cual > alumno.materias.size()) { //Valida que el numero de materia realmente existe
                cout << "Seleccion invalida" << endl;
                cout << "----------------------------------" << endl;
                return;
            }
            cout << "----------------------------------" << endl;
            cout << "Que dato de la materia " << alumno.materias[cual-1] << " quieres editar?" << endl;
            cout << "1. Nombre" << endl;
            cout << "2. Maestro" << endl;
            cout << "3. Calificacion" << endl;
            int que;
            cin >> que;
            while (cin.fail()) {  // Verifica si la entrada fue incorrecta
		    	cin.clear();  // Limpia el estado de error
		        cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Ignora el resto de la lÌnea
		        cout << "Me parece que ese no es una opcion valida, intenta de nuevo: ";
		        cin >> que;
		    }
            cout << "----------------------------------" << endl;
            switch (que) { //Seg˙n la opciÛn que seleccione
		        case 1: //Editar nombre de materia
		            cout << "Ingrese el nuevo nombre de la materia: ";
		            cin.ignore();
		            getline(cin, alumno.materias[cual-1]);
		            cout << "Alumno modificado correctamente :)" << endl;
					cout << "----------------------------------" << endl;
		        break;
		        case 2: //Editar nombre de maestro de imparte la materia
		            cout << "Ingrese el nuevo maestro de la materia: ";
		            cin.ignore();
		            getline(cin, alumno.maestros[cual-1]);
		            cout << "Alumno modificado correctamente :)" << endl;
		            cout << "----------------------------------" << endl;
		        break;
		        case 3: //Editar la calificaciÛn de la materia
		            cout << "Ingrese la nueva calificacion de la materia: ";
		            cin >> alumno.calificaciones[cual-1];
		            while (cin.fail()) {  // Verifica si la entrada fue incorrecta
				    	cin.clear();  // Limpia el estado de error
				        cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Ignora el resto de la lÌnea
				        cout << "Noup, esa no es una calificacion numerica, intenta otra vez: ";
				        cin >> alumno.calificaciones[cual-1];
				    }
				    cout << "Alumno modificado correctamente :)" << endl;
		            cout << "----------------------------------" << endl;
		        break;
		    }
		break;
	}
system("pause"); //Lo pusimos para que el men˙ no se muestre de golpe al terminar el proceso
system("cls"); //Limpia la pantalla
main(); //Regresa al main
}

//Indicaciones de lo que hace el void para eliminar a un alumno
void vaciar(){ //Para eliminar los alumnos ya registrados
    if (alumnos.empty()) { //Si a˙n no se guardan alumnos
        cout << "No hay alumnos registrados" << endl;
        cout << "----------------------------------" << endl;
        return;
    }
    cout << "----------------------------------" << endl;
    cout << "Alumnos registrados:" << endl;
    for (int i = 0; i < alumnos.size(); i++) {
        cout << i << ". " << alumnos[i].nombre << endl; //Se hace un for para mostrar la lista de alumnos ya registrados
    }
    cout << "----------------------------------" << endl;
    cout << "Seleccione un alumno para eliminar: ";
    int seleccion;
    cin >> seleccion;
    while (cin.fail()) {  // Verifica si la entrada fue incorrecta
    	cin.clear();  // Limpia el estado de error
        cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Ignora el resto de la lÌnea
        cout << "No hay ningun alumno con ese registro, intenta otra vez: ";
        cin >> seleccion;
    }
    if (seleccion < 0 || seleccion >= alumnos.size()) { //Valida que el numero del alumno realmente existe
        cout << "Seleccion invalida" << endl;
        cout << "----------------------------------" << endl;
        return;
    }
    // Eliminar al alumno seleccionado
    alumnos.erase(alumnos.begin() + seleccion);
    cout << "Alumno eliminado exitosamente" << endl;
    cout << "----------------------------------" << endl;
system("pause"); //Lo pusimos para que el men˙ no se muestre de golpe al terminar el proceso
system("cls"); //Limpia la pantalla
main(); //Regresa al main
}

//Indicaciones de lo que hace el void para ver los datos de los alumnos
void ver(){ //Para ver la lista de alumnos guardados
	if (alumnos.empty()) { //Si ·un no hay alumnos registrados y el txt est· vacÌo
        cout << "No hay alumnos registrados" << endl;
        cout << "----------------------------------" << endl;
        return;
    }
    cout << "----------------------------------" << endl;
    cout << "Alumnos registrados:" << endl;
    for (int i = 0; i < alumnos.size(); i++) { //Se hace un for para mostrar la lista de alumnos ya registrados
        cout << i << ". " << alumnos[i].nombre << endl;
    }
    cout << "----------------------------------" << endl;
    cout << "Seleccione un alumno: ";
    int seleccion;
    cin >> seleccion;
    while (cin.fail()) {  // Verifica si la entrada fue incorrecta
    	cin.clear();  // Limpia el estado de error
        cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Ignora el resto de la lÌnea
        cout << "No hay ningun alumno con ese registro, intenta otra vez: ";
        cin >> seleccion;
    }
    if (seleccion < 0 || seleccion >= alumnos.size()) { //Valida que el alumno seleccionado realmente existe
        cout << "Seleccion invalida." << endl;
        cout << "----------------------------------" << endl;
        return;
    }
    cout << "----------------------------------" << endl;
    Alumno alumno = alumnos[seleccion]; //Muestra todos los datos del alumno seleccionado
    cout << "Nombre: " << alumno.nombre << endl;
    cout << "Carrera: " << alumno.carrera << endl;
    cout << "Materias:" << endl;
    for (int i = 0; i < alumno.materias.size(); i++) {
        cout << "- " << alumno.materias[i] << endl;
        cout << "  Maestro: " << alumno.maestros[i] << endl;
        cout << "  Calificacion: " << alumno.calificaciones[i] << endl;
    }
    // Obtener las calificaciones del alumno seleccionado y calcular el promedio
    float sum = 0.0, prom;
    vector<float> calificaciones = alumnos[seleccion].calificaciones;
    for(int i = 0; i < calificaciones.size(); i++) {
        sum += calificaciones[i];
    }
    prom = sum / calificaciones.size();
    // Mostrar el promedio al usuario con el mensaje que corresponde
    cout << "El promedio del alumno " << alumnos[seleccion].nombre << " es: " << prom << endl;
    if(prom <= 59){
    	cout << "Reprobado :(" << endl;
    	cout << "----------------------------------" << endl;
	}else if(prom > 60 && prom < 79){
		cout << "Regular O.o" << endl;
		cout << "----------------------------------" << endl;
	}else if(prom > 80 && prom < 89){
		cout << "Muy bien :)" << endl;
		cout << "----------------------------------" << endl;
	}else if(prom > 90){
		cout << "Excelente! :D" << endl;
		cout << "----------------------------------" << endl;
	}
system("pause"); //Lo pusimos para que el men˙ no se muestre de golpe al terminar el proceso
system("cls"); //Limpia la pantalla
main(); //Regresa al main
}
