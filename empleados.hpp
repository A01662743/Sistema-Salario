#include <iostream>
#include <vector>
using namespace std;

#ifndef EMPLEADO
#define EMPLEADO

class Empleado {
    protected:
    string nombre;
    int salario;
    int id;

    public:
    Empleado();
    Empleado (string _nombre, int _salario, int _id);
    void setSalario (int _salario);
    int getSalario ();
    string getNombre ();
    void setNombre (string _nombre);
    int getId ();
    void setId(int _id);
};

Empleado::Empleado(){
    nombre = "Sin nombre";
    salario = 0;
    id = 0;
};

Empleado::Empleado (string _nombre, int _salario, int _id){
    nombre = _nombre;
    salario = _salario;
    id = _id;
};

void Empleado:: setSalario (int _salario){
    salario = _salario;
};

int Empleado:: getSalario (){
    return salario;
};

string Empleado:: getNombre (){
    return nombre;
};

void Empleado:: setNombre (string _nombre) {
    nombre = _nombre;
};

int Empleado:: getId (){
    return id;
};

void Empleado:: setId(int _id){
    id = _id;
};

#endif EMPLEADO

#ifndef SUBORDINADO
#define SUBORDINADO

class Subordinado : public Empleado {
    private:
    int idJefe;

    public:
    Subordinado();
    Subordinado (string _nombre, int _salario, int _id, int _idJefe);
    int getIdJefe();
    void setIdJefe(int _idJefe);
};

Subordinado::Subordinado():Empleado(){
    idJefe = 0;
};

Subordinado::Subordinado (string _nombre, int _salario, int _id, int _idJefe) : Empleado (_nombre, _salario, _id) {
    idJefe = _idJefe;
};

int Subordinado:: getIdJefe(){
    return idJefe;
};

void Subordinado:: setIdJefe(int _idJefe){
    idJefe = _idJefe;
};

#endif SUBORDINADO

#ifndef JEFE
#define JEFE

class Jefe : public Empleado {
    private:
    vector<Subordinado> subordinados;

    public:
    Jefe();
    Jefe(string _nombre, int _salario, int _id);
    vector<Subordinado> getSubordinados();
    void agregarSubordinados(string _nombre, int _salario, int _id, int _idJefe);
};

Jefe::Jefe():Empleado(){
    subordinados = vector<Subordinado>();
};

Jefe::Jefe(string _nombre, int _salario, int _id):Empleado(_nombre, _salario, _id){
    subordinados = vector<Subordinado>();
};

vector<Subordinado> Jefe:: getSubordinados(){
    return subordinados;
};

void Jefe:: agregarSubordinados(string _nombre, int _salario, int _id, int _idJefe){
    Subordinado subordinado = Subordinado(_nombre, _salario, _id, _idJefe);
    subordinados.push_back(subordinado);
};

#endif JEFE
