### Creador ***Alexei Hernandez***
***
# Explicación para la resolución del problema

Para este problema sobre los registros se decidió usar
```c++
map<string,map<string,long>>
```
siendo la presentacion abstracta de 
```c++
map<account,map<eventType,numEvent>>
```
se usó este contenedor ya que facilita la inserción ya que al ser claves unicas los valores no se van a repetir y solo hay que incrementar el valor para la combinación `[account][eventType]`,
adicional a esto la estructura siempre se mantiene ordenada.

Luego para el orden descendentes de 10 cuentas con mas numeros de eventos y tipos de eventos por numeros, se usó multimap con el criterio de orden descendente y se asigno la clave por el numero de cuentas o eventos y el valor el tipo de evento o cuenta, de esta forma la estructura se ordena, resolviendo el problema planteado.



# Contenedores en ***c++***

Los contenedores en c++ pertenecen a la libreria STL la cual es  es un conjunto de clases de plantillas de C ++ para proporcionar estructuras y funciones de datos de programación comunes como listas, pilas, matrices, etc. Es una biblioteca de clases de contenedores, algoritmos e iteradores. Es una biblioteca generalizada y, por lo tanto, sus componentes están parametrizados.
Pero en este caso vamos a hablar solo sobre los contenedores disponibles en c++.
Un contenedor es un objeto de soporte que almacena una colección de otros elementos. Se implementan como plantillas de clase, lo que permite una gran flexibilidad en los tipos admitidos como elementos. El contenedor gestiona el espacio de almacenamiento para sus elementos y proporciona funciones miembro para acceder a ellos, ya sea directamente o mediante iteradores. Los contenedores replican estructuras muy comúnmente utilizadas en la programación: matrices dinámicas, colas, pilas, montones, listas vinculadas, matrices asociativas etc. Muchos contenedores tienen varias funciones miembro en común y comparten funcionalidades. La decisión de qué tipo de contenedor usar para una necesidad específica generalmente no depende solo de la funcionalidad ofrecida por el contenedor, sino también de la eficiencia de algunos de sus miembros.

***

## Contenedores disponibles en c++

- Contenedores de secuencia

    - `array`
    - `vector`
    - `deque`
    - `forward_list`
    - `list`

- Adaptadores de contenedores

    - `stack`
    - `queue`
    - `priority_queue`

- Contenedores asociativos

    - `set`
    - `multiset`
    - `map`
    - `multimap`

- Contenedores asociativos desordenados

    - `unordered_set`
    - `unordered_multiset`
    - `unordered_map`
    - `unordered_multimap`

---

### ```array```
Los arrays son contenedores de secuencia de tamaño fijo: contienen un número específico de elementos ordenados en una secuencia lineal estricta.

Internamente, un array no guarda ningún dato que no sean los elementos que contiene (ni siquiera su tamaño, que es un parámetro de plantilla, fijado en tiempo de compilación). Es tan eficiente en términos de tamaño de almacenamiento como un array ordinario declarada. Esta clase simplemente agrega una capa de miembros y funciones globales, de modo que los arrays se pueden usar como contenedores estándar.

A diferencia de los otros contenedores estándar, los arrays tienen un tamaño fijo y no administran la asignación de sus elementos a través de un asignador: son un tipo agregado que encapsula una matriz de elementos de tamaño fijo. Por lo tanto, no se pueden expandir o contraer dinámicamente.

```c++
// C++ code to demonstrate working of array, 
// to() and get() 
#include<iostream> 
#include<array> // for array, at() 
#include<tuple> // for get() 
using namespace std; 
int main() 
{ 
    // Initializing the array elements 
    array<int,6> ar = {1, 2, 3, 4, 5, 6}; 
  
    // Printing array elements using at() 
    cout << "The array elements are (using at()) : "; 
    for ( int i=0; i<6; i++) 
    cout << ar.at(i) << " "; 
    cout << endl; 
  
    // Printing array elements using get() 
    cout << "The array elements are (using get()) : "; 
    cout << get<0>(ar) << " " << get<1>(ar) << " "; 
    cout << get<2>(ar) << " " << get<3>(ar) << " "; 
    cout << get<4>(ar) << " " << get<5>(ar) << " "; 
    cout << endl; 
  
    // Printing array elements using operator[] 
    cout << "The array elements are (using operator[]) : "; 
    for ( int i=0; i<6; i++) 
    cout << ar[i] << " "; 
    cout << endl; 
  
    return 0; 
  
} 
```

output

```
The array elemets are (using at()) : 1 2 3 4 5 6 
The array elemets are (using get()) : 1 2 3 4 5 6 
The array elements are (using operator[]) : 1 2 3 4 5 6 
```

---

### ```vector```

Los vectores son contenedores de secuencias que representan arrays que pueden cambiar de tamaño.

Al igual que los arrays, los vectores usan ubicaciones de almacenamiento contiguas para sus elementos, lo que significa que también se puede acceder a sus elementos utilizando compensaciones en punteros regulares a sus elementos, y tan eficientemente como en los arrays. Pero a diferencia de los arrays, su tamaño puede cambiar dinámicamente, y su almacenamiento es manejado automáticamente por el contenedor.

Internamente, los vectores usan un array asignada dinámicamente para almacenar sus elementos. Es posible que sea necesario reasignar esta matriz para aumentar su tamaño cuando se insertan nuevos elementos, lo que implica asignar una nueva matriz y mover todos los elementos a ella. Esta es una tarea relativamente costosa en términos de tiempo de procesamiento y, por lo tanto, los vectores no se reasignan cada vez que se agrega un elemento al contenedor.

Por lo tanto, en comparación con las arrays, los vectores consumen más memoria a cambio de la capacidad de administrar el almacenamiento y crecer dinámicamente de manera eficiente.

En comparación con los otros contenedores de secuencia dinámica ( etiquetas , listas y listas de reenvío ), los vectores son muy eficientes para acceder a sus elementos y agregar o quitar elementos relativamente eficientes de su extremo . Para las operaciones que implican insertar o eliminar elementos en posiciones distintas al final, funcionan peor que las demás y tienen iteradores y referencias menos consistentes que las listas y las listas de reenvío .

```c++
// C++ program to illustrate the
// iterators in vector
#include <iostream>
#include <vector>

using namespace std;

int main() 
{ 
    vector<int> g1; 
  
    for (int i = 1; i <= 5; i++) 
        g1.push_back(i); 
  
    cout << "Output of begin and end: "; 
    for (auto i = g1.begin(); i != g1.end(); ++i) 
        cout << *i << " "; 
  
    cout << "\nOutput of cbegin and cend: "; 
    for (auto i = g1.cbegin(); i != g1.cend(); ++i) 
        cout << *i << " "; 
  
    cout << "\nOutput of rbegin and rend: "; 
    for (auto ir = g1.rbegin(); ir != g1.rend(); ++ir) 
        cout << *ir << " "; 
  
    cout << "\nOutput of crbegin and crend : "; 
    for (auto ir = g1.crbegin(); ir != g1.crend(); ++ir) 
        cout << *ir << " "; 
  
    return 0; 
}
```

output

```
Output of begin and end: 1 2 3 4 5 
Output of cbegin and cend: 1 2 3 4 5 
Output of rbegin and rend: 5 4 3 2 1 
Output of crbegin and crend : 5 4 3 2 1
```

---

### `deque`

Las colas de doble extremo son contenedores de secuencia con tamaños dinámicos que se pueden expandir o contraer en ambos extremos.

Las bibliotecas específicas pueden implementar deques de diferentes maneras, generalmente como alguna forma de matriz dinámica. Pero, en cualquier caso, permiten acceder a los elementos individuales directamente a través de iteradores de acceso aleatorio, y el almacenamiento se maneja automáticamente al expandir y contraer el contenedor según sea necesario.

Por lo tanto, proporcionan una funcionalidad similar a los vectores, pero con una inserción y eliminación eficiente de elementos también al comienzo de la secuencia, y no solo al final. Pero, a diferencia de los vectores , no se garantiza que los deques almacenen todos sus elementos en ubicaciones de almacenamiento contiguas.

Ambos vectores y deques proporcionan una interfaz muy similar y se pueden usar para fines similares, pero internamente ambos funcionan de maneras muy diferentes: mientras que los vectores usan un solo array que necesita ser reasignada ocasionalmente para el crecimiento, los elementos de una deque pueden dispersarse en diferentes fragmentos de almacenamiento, con el contenedor manteniendo la información necesaria internamente para proporcionar acceso directo a cualquiera de sus elementos en tiempo constante y con una interfaz secuencial uniforme (a través de iteradores). Por lo tanto, los deques son un poco más complejos internamente que los vectores , pero esto les permite crecer más eficientemente bajo ciertas circunstancias, especialmente con secuencias muy largas, donde las reasignaciones se vuelven más caras.

Para las operaciones que implican la inserción o eliminación frecuente de elementos en posiciones distintas al principio o al final, los deques funcionan peor y tienen iteradores y referencias menos consistentes que las listas.

```c++
#include <iostream> 
#include <deque> 
  
using namespace std; 
  
void showdq(deque <int> g) 
{ 
    deque <int> :: iterator it; 
    for (it = g.begin(); it != g.end(); ++it) 
        cout << '\t' << *it; 
    cout << '\n'; 
} 
  
int main() 
{ 
    deque <int> gquiz; 
    gquiz.push_back(10); 
    gquiz.push_front(20); 
    gquiz.push_back(30); 
    gquiz.push_front(15); 
    cout << "The deque gquiz is : "; 
    showdq(gquiz); 
  
    cout << "\ngquiz.size() : " << gquiz.size(); 
    cout << "\ngquiz.max_size() : " << gquiz.max_size(); 
  
    cout << "\ngquiz.at(2) : " << gquiz.at(2); 
    cout << "\ngquiz.front() : " << gquiz.front(); 
    cout << "\ngquiz.back() : " << gquiz.back(); 
  
    cout << "\ngquiz.pop_front() : "; 
    gquiz.pop_front(); 
    showdq(gquiz); 
  
    cout << "\ngquiz.pop_back() : "; 
    gquiz.pop_back(); 
    showdq(gquiz); 
  
    return 0; 
} 

```

output 

```
The deque gquiz is :     15    20    10    30

gquiz.size() : 4
gquiz.max_size() : 4611686018427387903
gquiz.at(2) : 10
gquiz.front() : 15
gquiz.back() : 30
gquiz.pop_front() :     20    10    30

gquiz.pop_back() :     20    10
```

---

### `forward_list`

Las listas de reenvío son contenedores de secuencia que permiten operaciones de inserción y borrado de tiempo constante en cualquier lugar dentro de la secuencia.

Las listas de reenvío se implementan como listas enlazadas individualmente; Las listas enlazadas individualmente pueden almacenar cada uno de los elementos que contienen en ubicaciones de almacenamiento diferentes y no relacionadas. El orden se mantiene mediante la asociación a cada elemento de un enlace al siguiente elemento de la secuencia.

La principal diferencia de diseño entre un contenedor forward_list y una list es que el primero mantiene internamente solo un enlace al siguiente elemento, mientras que el segundo mantiene dos enlaces por elemento: uno apunta al siguiente elemento y el otro al anterior, lo que permite una iteración eficiente en ambas direcciones, pero consume almacenamiento adicional por elemento y con un tiempo ligeramente mayor por encima de la cabeza para insertar y quitar elementos. Los objetos forward_list son, por lo tanto, más eficientes que los objetos list , aunque solo pueden iterarse hacia adelante

El principal inconveniente de forward_list  y list en comparación con estos otros contenedores de secuencia es que carecen de acceso directo a los elementos por su posición; Por ejemplo, para acceder al sexto elemento en una lista de reenvío, uno tiene que iterar desde el principio hasta esa posición, lo que requiere un tiempo lineal en la distancia entre estos

```c++
// C++ code to demonstrate forward list 
// and assign() 
#include<iostream> 
#include<forward_list>  
using namespace std; 
  
int main() 
{ 
    // Declaring forward list 
    forward_list<int> flist1; 
  
    // Declaring another forward list 
    forward_list<int> flist2; 
  
    // Assigning values using assign() 
    flist1.assign({1, 2, 3}); 
  
    // Assigning repeating values using assign() 
    // 5 elements with value 10 
    flist2.assign(5, 10); 
  
    // Displaying forward lists 
    cout << "The elements of first forward list are : "; 
    for (int&a : flist1) 
        cout << a << " "; 
    cout << endl; 
      
    cout << "The elements of second forward list are : "; 
    for (int&b : flist2) 
        cout << b << " "; 
    cout << endl; 
  
    return 0; 
} 
```

output

```
The elements of first forward list are : 1 2 3 
The elements of second forward list are : 10 10 10 10 10 
```

---

### `List`

Las listas son contenedores de secuencia que permiten operaciones de inserción y borrado de tiempo constante en cualquier lugar dentro de la secuencia e iteración en ambas direcciones.

Los contenedores de listas se implementan como listas doblemente enlazadas. Las listas doblemente enlazdas pueden almacenar cada uno de los elementos que contienen en ubicaciones de almacenamiento diferentes y no relacionadas. El orden se mantiene internamente mediante la asociación a cada elemento de un enlace al elemento que lo precede y un enlace al elemento que lo sigue.

Son muy similares a forward_list : la principal diferencia es que los objetos forward_list son listas de enlace único y, por lo tanto, solo pueden iterarse hacia adelante, a cambio de ser algo más pequeños y más eficientes.

El principal inconveniente de las listas  forward_list  en comparación con estos otros contenedores de secuencia es que carecen de acceso directo a los elementos por su posición; Por ejemplo, para acceder al sexto elemento en una lista, uno tiene que iterar desde una posición conocida (como el principio o el final) a esa posición, lo que requiere un tiempo lineal en la distancia entre estos. También consumen un poco de memoria adicional para mantener la información de enlace asociada a cada elemento (que puede ser un factor importante para listas grandes de elementos de pequeño tamaño).

```c++
#include <list> 
#include <iterator> 
using namespace std; 
  
//function for printing the elements in a list 
void showlist(list <int> g) 
{ 
    list <int> :: iterator it; 
    for(it = g.begin(); it != g.end(); ++it) 
        cout << '\t' << *it; 
    cout << '\n'; 
} 
  
int main() 
{ 
  
    list <int> gqlist1, gqlist2; 
  
  
    for (int i = 0; i < 10; ++i) 
    { 
        gqlist1.push_back(i * 2); 
        gqlist2.push_front(i * 3); 
    } 
    cout << "\nList 1 (gqlist1) is : "; 
    showlist(gqlist1); 
  
    cout << "\nList 2 (gqlist2) is : "; 
    showlist(gqlist2); 
  
    cout << "\ngqlist1.front() : " << gqlist1.front(); 
    cout << "\ngqlist1.back() : " << gqlist1.back(); 
  
    cout << "\ngqlist1.pop_front() : "; 
    gqlist1.pop_front(); 
    showlist(gqlist1); 
  
    cout << "\ngqlist2.pop_back() : "; 
    gqlist2.pop_back(); 
    showlist(gqlist2); 
  
    cout << "\ngqlist1.reverse() : "; 
    gqlist1.reverse(); 
    showlist(gqlist1); 
  
    cout << "\ngqlist2.sort(): "; 
    gqlist2.sort(); 
    showlist(gqlist2); 
  
    return 0; 
  
}
```

output
```
List 1 (gqlist1) is :     0    2    4    6    
8    10    12    14    16    18

List 2 (gqlist2) is :     27    24    21    18    
15    12    9    6    3    0

gqlist1.front() : 0
gqlist1.back() : 18
gqlist1.pop_front() :     2    4    6    8    
10    12    14    16    18

gqlist2.pop_back() :     27    24    21    18    
15    12    9    6    3

gqlist1.reverse() :     18    16    14    12    
10    8    6    4    2

gqlist2.sort():     3    6    9    12    
15    18    21    24    27
```

---

### ```stack```

Las pilas son un tipo de adaptador de contenedor, específicamente diseñado para operar en un contexto LIFO (último en entrar, primero en salir), donde los elementos se insertan y extraen solo de un extremo del contenedor.

los stack se implementan como adaptadores de contenedores , que son clases que utilizan un objeto encapsulado de una clase de contenedor específica como contenedor subyacente , proporcionando un conjunto específico de funciones miembro para acceder a sus elementos. Los elementos son empujados y extraidos desde la "parte posterior" del contenedor específico, que se conoce como la parte superior de la pila.

El contenedor subyacente puede ser cualquiera de las plantillas de clase de contenedor estándar o alguna otra clase de contenedor específicamente diseñada. El contenedor deberá soportar las siguientes operaciones:

* empty
* size
* back
* push_back
* pop_back

```c++ 
// CPP program to demonstrate working of STL stack 
#include <bits/stdc++.h> 
using namespace std; 
  
void showstack(stack <int> s) 
{ 
    while (!s.empty()) 
    { 
        cout << '\t' << s.top(); 
        s.pop(); 
    } 
    cout << '\n'; 
} 
  
int main () 
{ 
    stack <int> s; 
    s.push(10); 
    s.push(30); 
    s.push(20); 
    s.push(5); 
    s.push(1); 
  
    cout << "The stack is : "; 
    showstack(s); 
  
    cout << "\ns.size() : " << s.size(); 
    cout << "\ns.top() : " << s.top(); 
  
  
    cout << "\ns.pop() : "; 
    s.pop(); 
    showstack(s); 
  
    return 0; 
} 
```

output
```
The stack is :     1    5    20    30    10

s.size() : 5
s.top() : 1
s.pop() :     5    20    30    10``

```

---

### `queue`

Las colas son un tipo de adaptador de contenedor, específicamente diseñado para operar en un contexto FIFO (primero en entrar, primero en salir), donde los elementos se insertan en un extremo del contenedor y se extraen del otro.

las colas se implementan como adaptadores de contenedores, que son clases que usan un objeto encapsulado de una clase de contenedor específica como su contenedor subyacente, proporcionando un conjunto específico de funciones miembro para acceder a sus elementos. Los elementos se insertan en la "parte posterior" del contenedor específico y se sacan de su "frente" .

El contenedor subyacente puede ser una de las plantillas de clase de contenedor estándar o alguna otra clase de contenedor diseñada específicamente. Este contenedor subyacente deberá soportar al menos las siguientes operaciones:

* empty
* size
* front
* back
* push_back
* pop_front

```c++
// CPP code to illustrate  
// Queue in Standard Template Library (STL) 
#include <iostream> 
#include <queue> 
  
using namespace std; 
  
void showq(queue <int> gq) 
{ 
    queue <int> g = gq; 
    while (!g.empty()) 
    { 
        cout << '\t' << g.front(); 
        g.pop(); 
    } 
    cout << '\n'; 
} 
  
int main() 
{ 
    queue <int> gquiz; 
    gquiz.push(10); 
    gquiz.push(20); 
    gquiz.push(30); 
  
    cout << "The queue gquiz is : "; 
    showq(gquiz); 
  
    cout << "\ngquiz.size() : " << gquiz.size(); 
    cout << "\ngquiz.front() : " << gquiz.front(); 
    cout << "\ngquiz.back() : " << gquiz.back(); 
  
    cout << "\ngquiz.pop() : "; 
    gquiz.pop(); 
    showq(gquiz); 
  
    return 0; 
} 
```

output

```
The queue gquiz is :     10    20    30

gquiz.size() : 3
gquiz.front() : 10
gquiz.back() : 30
gquiz.pop() :     20    30
```
---

### `priority_queue`
Las colas de prioridad son un tipo de adaptadores de contenedor, diseñados específicamente para que su primer elemento sea siempre el mayor de los elementos que contiene, de acuerdo con un criterio estricto de orden débil .

Este contexto es similar a un montón , donde los elementos se pueden insertar en cualquier momento, y solo se puede recuperar el elemento de montón máximo (el que está en la parte superior de la cola de prioridad ).

Las colas de prioridad se implementan como adaptadores de contenedor , que son clases que usan un objeto encapsulado de una clase de contenedor específica como contenedor subyacente , proporcionando un conjunto específico de funciones miembro para acceder a sus elementos. Los elementos se extraen de"parte posterior" del contenedor específico, que se conoce como la parte superior de la cola de prioridad.

El contenedor subyacente puede ser cualquiera de las plantillas de clase de contenedor estándar o alguna otra clase de contenedor específicamente diseñada. El contenedor será accesible a través de iteradores de acceso aleatorio y admitirá las siguientes operaciones:

* empty()
* size()
* front()
* push_back()
* pop_back()

```c++
// Note that by default C++ creates a max-heap 
// for priority queue 
#include <iostream> 
#include <queue> 
  
using namespace std; 
  
void showpq(priority_queue <int> gq) 
{ 
    priority_queue <int> g = gq; 
    while (!g.empty()) 
    { 
        cout << '\t' << g.top(); 
        g.pop(); 
    } 
    cout << '\n'; 
} 
  
int main () 
{ 
    priority_queue <int> gquiz; 
    gquiz.push(10); 
    gquiz.push(30); 
    gquiz.push(20); 
    gquiz.push(5); 
    gquiz.push(1); 
  
    cout << "The priority queue gquiz is : "; 
    showpq(gquiz); 
  
    cout << "\ngquiz.size() : " << gquiz.size(); 
    cout << "\ngquiz.top() : " << gquiz.top(); 
  
  
    cout << "\ngquiz.pop() : "; 
    gquiz.pop(); 
    showpq(gquiz); 
  
    return 0; 
} 
```

output

```
The priority queue gquiz is :     30    20    10    5    1

gquiz.size() : 5
gquiz.top() : 30
gquiz.pop() :     20    10    5    1
```

---

### `set`

Los conjuntos son contenedores que almacenan elementos únicos siguiendo un orden específico.

En un conjunto , el valor de un elemento también lo identifica (el valor es en sí mismo la clave , del tipo T ), y cada valor debe ser único. El valor de los elementos en un conjunto no se puede modificar una vez en el contenedor (los elementos siempre son constantes), pero se pueden insertar o eliminar del contenedor.

Internamente, los elementos en un conjunto siempre se ordenan siguiendo un criterio de ordenamiento débil estricto específico indicado por su objeto de comparación interno (de tipo Comparar ).

los contenedores de set son generalmente más lentos quecontenedores no ordenados para acceder a elementos individuales por su clave , pero permiten la iteración directa en subconjuntos según su orden.

Los conjuntos se implementan típicamente como árboles de búsqueda binarios .

```c++
#include <iostream> 
#include <set> 
#include <iterator> 
  
using namespace std; 
  
int main() 
{ 
    // empty set container 
    set <int, greater <int> > gquiz1;         
  
    // insert elements in random order 
    gquiz1.insert(40); 
    gquiz1.insert(30); 
    gquiz1.insert(60); 
    gquiz1.insert(20); 
    gquiz1.insert(50); 
    gquiz1.insert(50); // only one 50 will be added to the set 
    gquiz1.insert(10); 
  
    // printing set gquiz1 
    set <int, greater <int> > :: iterator itr; 
    cout << "\nThe set gquiz1 is : "; 
    for (itr = gquiz1.begin(); itr != gquiz1.end(); ++itr) 
    { 
        cout << '\t' << *itr; 
    } 
    cout << endl; 
  
    // assigning the elements from gquiz1 to gquiz2 
    set <int> gquiz2(gquiz1.begin(), gquiz1.end()); 
  
    // print all elements of the set gquiz2 
    cout << "\nThe set gquiz2 after assign from gquiz1 is : "; 
    for (itr = gquiz2.begin(); itr != gquiz2.end(); ++itr) 
    { 
        cout << '\t' << *itr; 
    } 
    cout << endl; 
  
    // remove all elements up to 30 in gquiz2 
    cout << "\ngquiz2 after removal of elements less than 30 : "; 
    gquiz2.erase(gquiz2.begin(), gquiz2.find(30)); 
    for (itr = gquiz2.begin(); itr != gquiz2.end(); ++itr) 
    { 
        cout << '\t' << *itr; 
    } 
  
    // remove element with value 50 in gquiz2 
    int num; 
    num = gquiz2.erase (50); 
    cout << "\ngquiz2.erase(50) : "; 
    cout << num << " removed \t" ; 
    for (itr = gquiz2.begin(); itr != gquiz2.end(); ++itr) 
    { 
        cout << '\t' << *itr; 
    } 
  
    cout << endl; 
  
    //lower bound and upper bound for set gquiz1 
    cout << "gquiz1.lower_bound(40) : "
         << *gquiz1.lower_bound(40) << endl; 
    cout << "gquiz1.upper_bound(40) : "
         << *gquiz1.upper_bound(40) << endl; 
  
    //lower bound and upper bound for set gquiz2 
    cout << "gquiz2.lower_bound(40) : "
         << *gquiz2.lower_bound(40) << endl; 
    cout << "gquiz2.upper_bound(40) : "
         << *gquiz2.upper_bound(40) << endl; 
  
    return 0; 
  
} 

```

output

```
The set gquiz1 is :      60    50    40    30    20    10

The set gquiz2 after assign from gquiz1 is : 10      20    30    40    50    60

gquiz2 after removal of elements less than 30 : 30    40    50    60
gquiz2.erase(50) : 1 removed     30    40    60
gquiz1.lower_bound(40) : 40
gquiz1.upper_bound(40) : 30
gquiz2.lower_bound(40) : 40
gquiz2.upper_bound(40) : 60
```

---

### `multiset`

Los conjuntos múltiples son contenedores que almacenan elementos siguiendo un orden específico y donde los elementos múltiples pueden tener valores iguales.

En un conjunto múltiple , el valor de un elemento también lo identifica (el valor es en sí mismo la clave , del tipo T ). El valor de los elementos en un conjunto múltiple no se puede modificar una vez en el contenedor (los elementos siempre son constantes), pero se pueden insertar o eliminar del contenedor.

Internamente, los elementos en un conjunto múltiple siempre se ordenan siguiendo un criterio de orden débil estricto específico indicado por su objeto de comparación interno (de tipo Comparar ).

multisetlos contenedores son generalmente más lentos que los contenedores unordered_multiset para acceder a elementos individuales por su clave , pero permiten la iteración directa en subconjuntos según su orden.

Los conjuntos múltiples generalmente se implementan como árboles de búsqueda binarios.

```c++
#include <iostream> 
#include <set> 
#include <iterator> 
  
using namespace std; 
  
int main() 
{ 
    // empty multiset container 
    multiset <int, greater <int> > gquiz1;         
  
    // insert elements in random order 
    gquiz1.insert(40); 
    gquiz1.insert(30); 
    gquiz1.insert(60); 
    gquiz1.insert(20); 
    gquiz1.insert(50); 
    gquiz1.insert(50); // 50 will be added again to the multiset unlike set 
    gquiz1.insert(10); 
  
    // printing multiset gquiz1 
    multiset <int, greater <int> > :: iterator itr; 
    cout << "\nThe multiset gquiz1 is : "; 
    for (itr = gquiz1.begin(); itr != gquiz1.end(); ++itr) 
    { 
        cout << '\t' << *itr; 
    } 
    cout << endl; 
  
    // assigning the elements from gquiz1 to gquiz2 
    multiset <int> gquiz2(gquiz1.begin(), gquiz1.end()); 
  
    // print all elements of the multiset gquiz2 
    cout << "\nThe multiset gquiz2 after assign from gquiz1 is : "; 
    for (itr = gquiz2.begin(); itr != gquiz2.end(); ++itr) 
    { 
        cout << '\t' << *itr; 
    } 
    cout << endl; 
  
    // remove all elements up to element with value 30 in gquiz2 
    cout << "\ngquiz2 after removal of elements less than 30 : "; 
    gquiz2.erase(gquiz2.begin(), gquiz2.find(30)); 
    for (itr = gquiz2.begin(); itr != gquiz2.end(); ++itr) 
    { 
        cout << '\t' << *itr; 
    } 
  
    // remove all elements with value 50 in gquiz2 
    int num; 
    num = gquiz2.erase(50); 
    cout << "\ngquiz2.erase(50) : "; 
    cout << num << " removed \t" ; 
    for (itr = gquiz2.begin(); itr != gquiz2.end(); ++itr) 
    { 
        cout << '\t' << *itr; 
    } 
  
    cout << endl; 
  
    //lower bound and upper bound for multiset gquiz1 
    cout << "gquiz1.lower_bound(40) : " 
         << *gquiz1.lower_bound(40) << endl; 
    cout << "gquiz1.upper_bound(40) : " 
         << *gquiz1.upper_bound(40) << endl; 
  
    //lower bound and upper bound for multiset gquiz2 
    cout << "gquiz2.lower_bound(40) : " 
         << *gquiz2.lower_bound(40) << endl; 
    cout << "gquiz2.upper_bound(40) : " 
         << *gquiz2.upper_bound(40) << endl; 
           
         return 0; 
  
} 
```

output

```
The multiset gquiz1 is :  60     50    50    40    30    20    10

The multiset gquiz2 after assign from gquiz1 is :  10     20    30    40    50    50    60

gquiz2 after removal of elements less than 30 :  30    40    50    50    60
gquiz2.erase(50) : 2 removed         30    40    60
gquiz1.lower_bound(40) : 40
gquiz1.upper_bound(40) : 30
gquiz2.lower_bound(40) : 40
gquiz2.upper_bound(40) : 60
```

### `map`

Los mapas son contenedores asociativos que almacenan elementos formados por una combinación de un valor clave y un valor mapeado, siguiendo un orden específico.

En un mapa, los valores clave se usan generalmente para ordenar e identificar de forma exclusiva los elementos, mientras que los valores mapeados almacenan el contenido asociado a esta clave . Los tipos de clave y valor mapeado pueden diferir y se agrupan en el tipo de miembro value_type , que es un tipo de par que combina ambos:


```c++
typedef pair<const Key, T> value_type;
```


Internamente, los elementos en un mapa siempre se ordenan por su clave siguiendo un criterio de orden débil estricto específico indicado por su objeto de comparación interno (de tipo Comparar ).

Los contenedores de mapas son generalmente más lentos que los contenedores de mapas desordenados para acceder a elementos individuales por su clave , pero permiten la iteración directa en subconjuntos según su orden.

Se puede acceder directamente a los valores mapeados en un mapa mediante su clave correspondiente utilizando el operador de soporte operador `[]`. Los

mapas se implementan típicamente comoÁrboles binarios de búsqueda .

```c++
#include <iostream> 
#include <iterator> 
#include <map> 
  
using namespace std; 
  
int main() 
{ 
  
    // empty map container 
    map<int, int> gquiz1; 
  
    // insert elements in random order 
    gquiz1.insert(pair<int, int>(1, 40)); 
    gquiz1.insert(pair<int, int>(2, 30)); 
    gquiz1.insert(pair<int, int>(3, 60)); 
    gquiz1.insert(pair<int, int>(4, 20)); 
    gquiz1.insert(pair<int, int>(5, 50)); 
    gquiz1.insert(pair<int, int>(6, 50)); 
    gquiz1.insert(pair<int, int>(7, 10)); 
  
    // printing map gquiz1 
    map<int, int>::iterator itr; 
    cout << "\nThe map gquiz1 is : \n"; 
    cout << "\tKEY\tELEMENT\n"; 
    for (itr = gquiz1.begin(); itr != gquiz1.end(); ++itr) { 
        cout << '\t' << itr->first 
             << '\t' << itr->second << '\n'; 
    } 
    cout << endl; 
  
    // assigning the elements from gquiz1 to gquiz2 
    map<int, int> gquiz2(gquiz1.begin(), gquiz1.end()); 
  
    // print all elements of the map gquiz2 
    cout << "\nThe map gquiz2 after"
         << " assign from gquiz1 is : \n"; 
    cout << "\tKEY\tELEMENT\n"; 
    for (itr = gquiz2.begin(); itr != gquiz2.end(); ++itr) { 
        cout << '\t' << itr->first 
             << '\t' << itr->second << '\n'; 
    } 
    cout << endl; 
  
    // remove all elements up to 
    // element with key=3 in gquiz2 
    cout << "\ngquiz2 after removal of"
            " elements less than key=3 : \n"; 
    cout << "\tKEY\tELEMENT\n"; 
    gquiz2.erase(gquiz2.begin(), gquiz2.find(3)); 
    for (itr = gquiz2.begin(); itr != gquiz2.end(); ++itr) { 
        cout << '\t' << itr->first 
             << '\t' << itr->second << '\n'; 
    } 
  
    // remove all elements with key = 4 
    int num; 
    num = gquiz2.erase(4); 
    cout << "\ngquiz2.erase(4) : "; 
    cout << num << " removed \n"; 
    cout << "\tKEY\tELEMENT\n"; 
    for (itr = gquiz2.begin(); itr != gquiz2.end(); ++itr) { 
        cout << '\t' << itr->first 
             << '\t' << itr->second << '\n'; 
    } 
  
    cout << endl; 
  
    // lower bound and upper bound for map gquiz1 key = 5 
    cout << "gquiz1.lower_bound(5) : "
         << "\tKEY = "; 
    cout << gquiz1.lower_bound(5)->first << '\t'; 
    cout << "\tELEMENT = "
         << gquiz1.lower_bound(5)->second << endl; 
    cout << "gquiz1.upper_bound(5) : "
         << "\tKEY = "; 
    cout << gquiz1.upper_bound(5)->first << '\t'; 
    cout << "\tELEMENT = "
         << gquiz1.upper_bound(5)->second << endl; 
  
    return 0; 
} 
```
output

```
The map gquiz1 is : 
    KEY    ELEMENT
    1    40
    2    30
    3    60
    4    20
    5    50
    6    50
    7    10


The map gquiz2 after assign from gquiz1 is : 
    KEY    ELEMENT
    1    40
    2    30
    3    60
    4    20
    5    50
    6    50
    7    10


gquiz2 after removal of elements less than key=3 : 
    KEY    ELEMENT
    3    60
    4    20
    5    50
    6    50
    7    10

gquiz2.erase(4) : 1 removed 
    KEY    ELEMENT
    3    60
    5    50
    6    50
    7    10

gquiz1.lower_bound(5) :     KEY = 5        ELEMENT = 50
gquiz1.upper_bound(5) :     KEY = 6        ELEMENT = 50
```

---

### `multimap`

Los multimapas son contenedores asociativos que almacenan elementos formados por una combinación de un valor clave y un valor mapeado , siguiendo un orden específico, y donde varios elementos pueden tener claves equivalentes.

En un mapa múltiple , los valores clave se usan generalmente para ordenar e identificar de forma única los elementos, mientras que los valores mapeados almacenan el contenido asociado a esta clave . Los tipos de clave y valor mapeado pueden diferir y se agrupan en el tipo de miembro `value_type` , que es un tipo de par que combina ambos:

 
```c++
typedef pair<const Key, T> value_type;
```

Internamente, los elementos en un mapa múltiple siempre se ordenan por su clave siguiendo un criterio específico estricto de ordenamiento débil indicado por su objeto de comparación interno (de tipo Comparar).

Los contenedores multimap son generalmente más lentos que los contenedores unordered_multimap para acceder a elementos individuales por su clave , pero permiten la iteración directa en subconjuntos según su orden.

Los mapas múltiples generalmente se implementan como árboles de búsqueda binarios .

```c++
#include <iostream> 
#include <map> 
#include <iterator> 
  
using namespace std; 
  
int main() 
{ 
    multimap <int, int> gquiz1;        // empty multimap container 
  
    // insert elements in random order 
    gquiz1.insert(pair <int, int> (1, 40)); 
    gquiz1.insert(pair <int, int> (2, 30)); 
    gquiz1.insert(pair <int, int> (3, 60)); 
    gquiz1.insert(pair <int, int> (4, 20)); 
    gquiz1.insert(pair <int, int> (5, 50)); 
    gquiz1.insert(pair <int, int> (6, 50)); 
    gquiz1.insert(pair <int, int> (6, 10)); 
  
    // printing multimap gquiz1 
    multimap <int, int> :: iterator itr; 
    cout << "\nThe multimap gquiz1 is : \n"; 
    cout << "\tKEY\tELEMENT\n"; 
    for (itr = gquiz1.begin(); itr != gquiz1.end(); ++itr) 
    { 
        cout  <<  '\t' << itr->first 
              <<  '\t' << itr->second << '\n'; 
    } 
    cout << endl; 
  
    // assigning the elements from gquiz1 to gquiz2 
    multimap <int, int> gquiz2(gquiz1.begin(),gquiz1.end()); 
  
    // print all elements of the multimap gquiz2 
    cout << "\nThe multimap gquiz2 after assign from gquiz1 is : \n"; 
    cout << "\tKEY\tELEMENT\n"; 
    for (itr = gquiz2.begin(); itr != gquiz2.end(); ++itr) 
    { 
        cout << '\t' << itr->first 
             << '\t' << itr->second << '\n'; 
    } 
    cout << endl; 
  
    // remove all elements up to element with value 30 in gquiz2 
    cout << "\ngquiz2 after removal of elements less than key=3 : \n"; 
    cout << "\tKEY\tELEMENT\n"; 
    gquiz2.erase(gquiz2.begin(), gquiz2.find(3)); 
    for (itr = gquiz2.begin(); itr != gquiz2.end(); ++itr) 
    { 
        cout << '\t' << itr->first 
             << '\t' << itr->second << '\n'; 
    } 
  
    // remove all elements with key = 4 
    int num; 
    num = gquiz2.erase(4); 
    cout << "\ngquiz2.erase(4) : "; 
    cout << num << " removed \n" ; 
    cout << "\tKEY\tELEMENT\n"; 
    for (itr = gquiz2.begin(); itr != gquiz2.end(); ++itr) 
    { 
        cout << '\t' << itr->first 
             << '\t' << itr->second << '\n'; 
    } 
  
    cout << endl; 
  
    //lower bound and upper bound for multimap gquiz1 key = 5 
    cout << "gquiz1.lower_bound(5) : " << "\tKEY = "; 
    cout << gquiz1.lower_bound(5)->first << '\t'; 
    cout << "\tELEMENT = " << gquiz1.lower_bound(5)->second << endl; 
    cout << "gquiz1.upper_bound(5) : " << "\tKEY = "; 
    cout << gquiz1.upper_bound(5)->first << '\t'; 
    cout << "\tELEMENT = " << gquiz1.upper_bound(5)->second << endl; 

    return 0; 

}
```
output
```
The multimap gquiz1 is : 
    KEY    ELEMENT
    1    40
    2    30
    3    60
    4    20
    5    50
    6    50
    6    10


The multimap gquiz2 after assign from gquiz1 is : 
    KEY    ELEMENT
    1    40
    2    30
    3    60
    4    20
    5    50
    6    50
    6    10


gquiz2 after removal of elements less than key=3 : 
    KEY    ELEMENT
    3    60
    4    20
    5    50
    6    50
    6    10

gquiz2.erase(4) : 1 removed 
    KEY    ELEMENT
    3    60
    5    50
    6    50
    6    10

gquiz1.lower_bound(5) :     KEY = 5        ELEMENT = 50
gquiz1.upper_bound(5) :     KEY = 6        ELEMENT = 50
```
---

Quedaria por mencionar los contenedores asociativos desordenados
pero debido a su similitud con sus equivalentes ordenados y simplificación en este trabajo se decidió no hablar tan detallado de cada uno, pero cabe destacar que hacen lo mismo que sus equivalentes ordenados pero no siguen un patrón de orden ademas estos contenedores son más rápidos que los contenedores asociativos ordenados para acceder a elementos individuales por su clave, aunque generalmente son menos eficientes para la iteración de rango a través de un subconjunto de sus elementos.