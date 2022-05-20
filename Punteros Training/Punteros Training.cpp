#include <iostream>
#include <string>
#include<fstream>

using namespace std;

struct clientes {
    string nombre;
    string tratamiento;
    string hora;
    string precio;
    string numcita;
    clientes* anterior = nullptr;
    clientes* siguiente = nullptr;
};

int lugares = 1;
int calculo = 0;

clientes* primero = nullptr;
clientes* ultimo = nullptr;
clientes* auxiliar = nullptr;
clientes* auxiliar2 = nullptr;

void registros(string nombre, string tratamiento, string hora, string precio) {

    clientes* nuevocliente = new clientes;
    nuevocliente->nombre = nombre;
    nuevocliente->tratamiento = tratamiento;
    nuevocliente->hora = hora;
    nuevocliente->precio = precio;
   nuevocliente->numcita = to_string(lugares);

    if (lugares == 1) {
        primero = nuevocliente;
        ultimo = nuevocliente;
    }
    else {
        //Nuevo huesped
        //Sabe el anterior?
        nuevocliente->anterior = ultimo;
        //Sabe quien sera el nuevo? Respuesta: no
        ultimo->siguiente = nuevocliente;
        ultimo = nuevocliente;
    }
    //RESOLVER QUE PASA CUANDO LOS ELIMINEMOS 

    lugares++;

    //aqui
    ofstream data;
    string info;
  //  int num=0;

    data.open("DATA.txt", ios::app); //ABIR ARCHIVO

    if (data.fail()) {
        cout << endl << "ERROR 56" << endl;
        exit(1);
    }
   
    data << nombre<<endl;
    data << tratamiento << endl;
    data << hora << endl;
    data << precio << endl;
   data << nuevocliente->numcita << endl;
}

void impresiones() {
    auxiliar = primero;
    ifstream data;
   string texto;
   int cont = 1;

   /*  if (!auxiliar) {
         cout << "No hay citas registradas :(" << endl;
     }
     else {

         while (auxiliar) {


             cout << "================================================" << endl;
             cout << "Numero de cita: " << auxiliar->numcita << endl;
             cout << endl << "Nombre: " << auxiliar->nombre << endl;
             cout << "Tratamiento: " <<auxiliar->tratamiento<< endl;
             cout << "Hora asignada: " <<auxiliar->hora<< endl;
             cout << "Precio total: " << auxiliar->precio<<endl;
             auxiliar = auxiliar->siguiente;
         }
     }*/

    data.open("DATA.txt", ios::in);
    
    if (data.fail()) {
        cout << endl << "ERROR 94 NO SE PUDO ENCONTRAR EL ARCHIVO" << endl;
        exit(1);
    }

   // int num;
    string nom,trat,hora,precio,cita;
    
    while (getline(data, nom)) {
       
        cout << "=======================================================" << endl;
        /*data >> trat;
        data >> hora;
        data >> precio;*/
        
        getline(data, trat);
        getline(data, hora);
        getline(data, precio);
        getline(data, cita);

        cout <<"Numero de cita #" << cont << endl;
        cout << "Nombre: " << nom<<endl;
        cout << "Tratamiento: " << trat << endl;
        cout << "Hora: " << hora << " hrs."<<endl;
        cout << "Precio: $" << precio << endl;
        cout << "Numero de Folio =============== " << cita<<endl;
        cont++;
        
    }
    data.close();
    
}

void eliminar() {
   /* system("cls");
    string citaaux;
    string nom, trat, hora, precio, citap;
    ifstream data;

    if (data.fail()) {
        cout << endl << "ERROR 153 NO SE PUDO ENCONTRAR EL ARCHIVO" << endl;
        exit(1);
    }

    data.open("DATA.txt", ios::in);
    ofstream aux("Auxiliar.txt", ios::out);

    cout << "Ingrese el numero de cita a eliminar: ";
    getline(cin, citap);

   

    while (getline(data, nom)) {
        
        getline(data, trat);
        getline(data, hora);
        getline(data, precio);
        getline(data, citap);

        if (citap == citaaux) {
            cout << "Usuario Encontrado" << endl;
        }
        else {
            cout << "Usuario no encontrado" << endl;
        }

    }*/
    ofstream data;
    string citap;

    getline(cin, citap);

    data.open("DATA.txt", ios::out); //Abrir Archivo

    if (data.fail()) {
        cout << endl << "ERROR 165" << endl;
        exit(1);
    }

    while (auxiliar != nullptr) {
        if (citap == auxiliar->numcita) {
            if (auxiliar == primero) {
                if (auxiliar->siguiente != nullptr) {
                    primero = auxiliar = auxiliar->siguiente;
                    auxiliar->anterior = nullptr;
                }
                else {
                    free(auxiliar);
                    primero = nullptr;
                    break;
                }
            }
            else if (auxiliar->siguiente == nullptr) {
                if (auxiliar->anterior != nullptr) {
                    auxiliar->anterior->siguiente = nullptr;
                    ultimo = auxiliar->anterior;
                    free(auxiliar);
                }
                break;
            }
            else {
                if (auxiliar->anterior != nullptr)
                    auxiliar->anterior->siguiente = auxiliar->siguiente;
                if (auxiliar->siguiente != nullptr) {
                    auxiliar->siguiente->anterior = auxiliar->anterior;
                    auxiliar2 = auxiliar;
                    auxiliar = auxiliar->siguiente;
                    free(auxiliar2);
                }
            }
        }

        if(auxiliar != nullptr) {
            data << auxiliar->nombre << endl;
            data << auxiliar->tratamiento << endl;
            data << auxiliar->hora << endl;
            data << auxiliar->precio << endl;
            data << auxiliar->numcita << endl;
            auxiliar = auxiliar->siguiente;
        }
    }
    
}

void modificar() {
    system("cls");
    
    string folio;
    string nuevonombre;
    ofstream data;

    cout << endl << endl;
    cout << "===============================================================" << endl;
    cout << endl << "Ingrese el numero de FOLIO que quiere cambiar ";
    cin.ignore();
    getline(cin, folio);
    
    system("pause");
    while (auxiliar != nullptr) {
       
        if (folio == auxiliar->numcita) {
            cout << auxiliar->numcita << endl;
            cout << "Ingrese su nuevo nombre" << endl;
            getline(cin, nuevonombre);
            auxiliar->nombre = nuevonombre;
        }
        else {
            cout << endl << "Numero de Folio no encontrado, revice el numero de folio y no el numero de cita"<<endl;
            system("pause");
        }
        auxiliar = auxiliar->siguiente;
        data << nuevonombre<<endl;
    }

    
}

int main()
{
    system("color b");
    
    string name,tratamiento,descripcion,precio;
    int contador = 0, opcion = 0, dat = 0, op2 = 0, cantidad = 0;
    int cgeneral = 0;
    string cita;
    string hora;
    ifstream data;
    string nom, trat, horap, preciop;

    //CASOS

    int cant = 2;

    //casos

    if (data.fail()) {
        cout << endl << "ERROR 153 NO SE PUDO ENCONTRAR EL ARCHIVO" << endl;
        exit(1);
    }

    data.open("DATA.txt", ios::in);

    // Recorrer el archivo

    while (getline(data, nom)) {
        
        getline(data, trat);
        getline(data, horap);
        getline(data, preciop);
        //getline(data, cita);

        clientes* nuevocliente = new clientes;
        nuevocliente->nombre = nom;
        nuevocliente->tratamiento = trat;
        nuevocliente->hora = horap;
        nuevocliente->precio = preciop;
        nuevocliente->numcita = to_string(lugares);
        getline(data, nuevocliente->numcita);

        if (lugares++ == 1) {
            primero = nuevocliente;
            ultimo = nuevocliente;
        }
        else {
            //Nuevo huesped
            //Sabe el anterior?
            nuevocliente->anterior = ultimo;
            //Sabe quien sera el nuevo? Respuesta: no
            ultimo->siguiente = nuevocliente;
            ultimo = nuevocliente;
        }
       
    }

    inicio:
    
    opcion = 0;
    system("cls");
    cout << "                                                                                        =====";
    system("date /T");
    cout << "                         -----------Bienvenido a Dental Health International-----------" << endl << endl;
    cout << "  Estamos felices de que este aqui, por favor lea atentamente y seleccione una opcion del menu"<<endl;
    cout<<"usando solamente los numeros del panel numerico" << endl;
    cout << endl << endl;
    cout << "Ingrese una opcion:" << endl;
    
    cout << "---------------------------------------" << endl<<endl;
    cout << "1. Agendar Cita" << endl << "2. Lista de Citas Vigentes" << endl << "3. Modificar Cita" << endl;
    cout << "4. Eliminar Cita" << endl<<"5. Salir"<<endl;
    cout << endl << endl<<"Opcion seleccionada:  ";
    cin >> opcion;

    switch (opcion)
    {   
    case 1:
    reg:
        system("cls");
        cin.ignore();
        cout << endl << "Ingrese su nombre: ";
        getline(cin, name);
        cout << endl;
        cout << endl << "=============================================================================" << endl<<endl;
        cout << "Ingrese el tratamiento que desea usando los numero del panel numerico: " << endl<<endl;
        cout << "1)Consulta General - $100 ---------- 2)Resinas - $300"<<endl;
        cout << "3)Amalgamas - $150  ---------------- 4)Profilaxis - $350" << endl;
        cout << "5)Blanqueamiento - $400 ------------ 6)Endodoncia - $1,200" << endl;
        cout << "7)Extraccion Simple - $300 --------- 8)Extraccion del Cuarto Premolar - $500" << endl;
        cout << "9)Aplicacion de Selladores - $700 -- 10)Coronas de Zirconia - $1,800" << endl;
        cout << endl << endl;
        cout << "Opcion:  ";
        cin >> op2;
        switch (op2)
        {
        case 1:
            precio = "100";
            tratamiento = "Consulta General";
            break;
        case 2:
           cout << endl << "Cantidad: ";
           cin >> cant;
            calculo = 300 * cant; 
            precio = to_string(calculo);
            tratamiento = "Resinas";
            break;
        case 3:
            //Varios
            cout << endl << "Cantidad: ";
            cin >> cant;
            calculo = 150 * cant;
            precio = to_string(calculo);
            tratamiento = "Amalgamas";
            break;
        case 4:
            tratamiento = "Profilaxis";
            precio = "350";
            break;
        case 5:
            tratamiento = "Blanqueamiento";
            precio = "500";
            break;
        case 6:
            //Varios
            cout << endl << "Cantidad: ";
            cin >> cant;
            calculo = 1200 * cant;
            precio = to_string(calculo);
            tratamiento = "Endodoncia";
            break;
        case 7:
            //Varios
            cout << endl << "Cantidad: ";
            cin >> cant;
            calculo = 300 * cant;
            precio = to_string(calculo);
            tratamiento = "Extraccion Simple";
            break;
        case 8:
            //Varios MAX 4
            max:
            cout << endl << "Cantidad (Max 4):";
            cin >> cant;
            if (cant > 4) {
                cout << endl << "Cantidad Invalida"<<endl;
                //_sleep(1200);
                system("pause");
                goto max;
            }
            else {
                calculo = 500 * cant;
            }
            precio = to_string(calculo);
            tratamiento = "Extraccion de Muela del Juicio";
            break;
        case 9:
            //Varios
            cout << endl << "Cantidad: ";
            cin >> cant;
            calculo = 700 * cant;
            precio = to_string(calculo);
            tratamiento = "Aplicacion de Selladores";
            break;
        case 10:
            //Varios
            cout << endl << "Cantidad: ";
            cin >> cant;
            calculo = 1800 * cant;
            precio = to_string(calculo);
            tratamiento = "Coronas de Zirconia";
            break;

        default:
            break;
        }
       
        
        cout << endl << "Ingrese la hora (formato 24hrs. Ej. 17.30): ";
        cin.ignore();
        getline(cin, hora);
        
      
        cout << "=================================================" << endl;

        /*cout << endl << "El ultimo cliente es: " << ultimo->nombre << endl;
        cout << "El tratamiento seria: " << ultimo->tratamiento << endl;
        cout << "La hora asignada es: " << ultimo->hora << endl;
        cout << endl << "El ultimo precio es: " << ultimo->precio << endl;*/

        cout << endl << "Nombre: " << name<<endl;
        cout << "Tratamiento: " << tratamiento << endl;
        cout << "Hora: " << hora << endl;
        cout << "Precio total === " << precio << endl<<endl;
        
        cout << "Sus datos son correctos? (Presione 1 para SI, Presione 0 para NO)  ";
        cin >> dat;
        if (dat == 1) {

            registros(name, tratamiento, hora, precio);
            
            goto inicio;
        }
        else(dat == 0); {
            goto reg;
        }
        
        

        system("pause");
        goto inicio;
    
    case 2:
        system("cls");
        impresiones();
       
        cout << endl << endl;
        system("pause");
        goto inicio;
        break;

    case 3:
        
        modificar();
        goto inicio;
        
        break;

    case 4:
        
        cout << endl << "Ingrese el nombre del paciente que quiere eliminar de la lista: " << endl;
      getline (cin, cita);
        eliminar();
        goto inicio;
        break;
    case 5:
        system("exit");
        break;
    default:
        cout << "INVALIDO" << endl;
        system("pause");
        goto inicio;
        break;
    }
    

}
