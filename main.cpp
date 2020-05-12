#include <iostream>
#include <fstream>
#include <string.h>
#include <map>

using namespace std;
//prototipos

string comp_admin();        //ingresar al programa la contraseña del admin
void menu_admin();          //desplegar menu de administrador
void menu_usario();         //desplegar menu de usuario

int main()
{
    string contcorrecta, contraseña, usuario;

    int op=3;

    while(op!=0){
        cout << "Bienvenido al cinema: " << endl;
        cout<< "escriba 1 para ingresar como admin o 2 para ingresar como usuario, presione 0 para salir:"<<endl;
        cin>>op;

        switch(op){
            case 1:{
                contcorrecta = comp_admin();

                while(contcorrecta != contraseña){
                    cout<<"Ingrese la contraseña del administrador, ingrese x para volver: "<<endl;
                    cin >> contraseña;

                    if(contraseña == "x"){
                        break;
                    }
                }
            }
                while(op!=0){
                    menu_admin();
                    cin>>op;
                    switch(op){

                        case 1:{
                            //visualizar inventario
                        }
                        case 2:{
                            //ingresar articulos
                        }
                        case 3:{
                            //ingresar ombos
                        }
                        case 4:{
                            //generar reporte de ventas
                        }
                    }
                }

            case 2:{
                cout<<"ingrese su cedula: "<<endl;
                cin>>usuario;
                menu_admin();
                cin>>op;

            }
        }
    }
    return 0;
}

string comp_admin(){
    string data;

    ifstream archivo; // Abre el archivo en modo lectura

    // Se pone de manera explicita la ruta donde se encuentra el archivo
    archivo.open("../parcialV1/Base_de_datos/contraseña.txt");

    if (!archivo.is_open()) // Se comprueba si el archivo fue abierto exitosamente
    {
      std::cout << "Error opening file" << endl;
      exit(1);
    }

    //cout << "Leyendo el archivo" << endl;
    archivo >> data;

    archivo.close();

    return data;
}

//menu del administrador con sus respectivas opciones
void menu_admin(){
    cout<<"Bienvenido administrador, seleccione la opcion que desee, ingrese 0 para volver: "<<endl;
    cout<<"1) visualizar el inventario: "<<endl;
    cout<<"2) ingresar articulos al inventario: "<<endl;
    cout<<"3) ingresar un combo nuevo: "<<endl;
    cout<<"4) generar reporte de ventas de hoy: "<<endl;
}

void menu_usuario(){
    ifstream Leer;
    string Producto;
    int Valor, num=1;
    cout<<"Bienvenido usuario, seleccione la opcion que desee, ingrese 0 para volver: "<<endl;
    Leer.open("../parcialV1/Base_de_datos/Combos.txt");
    Leer>>Producto;
    cout<<"    Numero"<<"         Producto"<<"       Valor"<<endl;
    while (!Leer.eof()){
        Leer>>Producto>>Valor;
        cout<<num<<"  "<<Producto<<"  "<<Valor<<endl;
        cout<<endl;
        Leer>>Producto;
    }

    Leer.close();
}
