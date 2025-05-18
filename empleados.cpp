#include <iostream>
#include "empleados.hpp"
using namespace std;

int main() {
    // Jefe ejemplo
    Jefe jefe("Juan", 5000, 758439);
    
    // agregar subordinados a jefe
    jefe.agregarSubordinados("Jose", 3000, 473200, jefe.getId());
    jefe.agregarSubordinados("Ana", 4200, 749302, jefe.getId());
    jefe.agregarSubordinados("Lisa", 5200, 794789, jefe.getId());
    jefe.agregarSubordinados("Daniel", 2800, 2283902, jefe.getId());
    
    // Buscar subordinados con mayór salario
    int n = 0;
    vector<string> subMayor;
    for (auto& i : jefe.getSubordinados()) {
        if (i.getSalario() > jefe.getSalario()) {
            subMayor.push_back(i.getNombre());
            n++;
        }
    }
    
    cout << "Subordinados con mayor salario que el jefe: " << endl;

    for (int i = 0; i < n; i++) {
        cout << subMayor[i] << endl;
    }

    return 0;
}
