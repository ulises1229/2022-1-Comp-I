# Práctica 4: Arreglos

## Descripción

Para esta práctica tendrás que implementar un código que haga dos operaciones básicas con arreglos:
- **Multiplicación** de un arreglo por un escalar (un número real).
- **Suma** entre dos arreglos elemento a elemento.

Para llevar a cabo esta implementación utilizarás [este código](Arreglos.cpp) que contiene una parte del proyecto ya implementado. En este código ya hemos implementado el funcionamiento del programa en la función _main()_, la cual hace lo siguiente:
* Pide al usuario que llene cada elemento del arreglo.
* Solicita al usuario indicar la operación a realizar (`+` para la suma, `*` para la multiplicación), si el usuario ingresa otro símbolo se repite la pregunta hasta que ingrese una opción válida.
* Dependiendo de la decisión realiza lo siguiente:
  - **Multiplicación**:
    - Pide al usuario ingresar el factor por el cual quiere multiplicar el arreglo.
    - Multiplica el arreglo y lo guarda.
  - **Suma**:
    - Pide al usuario llenar un nuevo arreglo del mismo tamaño que el primero.
    - Lleva a cabo la suma entre los dos arreglos elemento a elemento (i.e. *a<sub>i</sub>* + *b<sub>i</sub>* donde *a* y *b* son los dos arreglos ingresados por el usuario) y guarda el resultado.
* Finalmente imprime el resultado de la operación.

Este código contiene cuatro definiciones de funciones:

`ImprimirArreglo` tiene como objetivo recibir un arreglo e imprimirlo colocando un espacio entre cada uno de los elementos, esta función **ya está implementada para tí**, por lo que no deberás de modificarla. El prototipo de esta función luce como: `void ImprimirArreglo(array<float, LEN> arreglo)` donde el argumento `arreglo` es el arreglo a imprimir. Esta función no regresa ningún valor.

`LlenarArreglo` es una función que solicita al usuario llenar el arreglo elemento por elemento, comenzando por el primero, segundo y así sucesivamente; al final regresa el arreglo llenado por el usuario. La declaración de esta función luce así: `array<float, LEN> LlenarArreglo(void)` por lo que no recibe ningún argumento, y regresa un arreglo nuevo de longitud LEN, ya asignado con los valores ingresados por el usuario.

`MultiplicarArreglo` realiza la operación de multiplicación de cada elemento del arreglo por un valor escalar. El prototipo de la función luce como `array<float, LEN> MultiplicarArreglo(array<float, LEN> arreglo, float mult)` donde `arreglo` es el arreglo al que se le va a multiplicar cada elemento, y `multiplo` es el factor por el que se va a multiplicar. Esta función regresa el arreglo resultante de dicha operación.

`SumarArreglos` lleva a cabo la suma elemento a elemento entre dos arreglos. El prototipo de la función luce de la siguiente manera: `array<float, LEN> SumarArreglos(array<float, LEN> arr1, array<float, LEN> arr2)` donde 'arr1' y 'arr2' son los dos arreglos que se van a sumar. Esta función regresa un arreglo con los valores resultantes de la operación.

**Importante:** como habrás notado, en todas ocasiones se define el tamaño de los arreglos con la *constante global* `LEN`. Este valor está definido en la tercera línea del código que descargaste, y lo que permite es crear una constante (similar a `const`) pero con alcance global, esto quiere decir que todas las funciones de nuestro código tienen acceso a ella. Este valor **NO LO DEBES DE MODIFICAR EN EL CÓDIGO QUE ENTREGARÁS COMO PRÁCTICA**, pero puedes modificarlo cuanto quieras mientras pruebas tu código en tu computadora.

## Implementación

Tu proyecto consistirá en completar las funciones `LlenarArreglo`, `MultiplicarArreglo` y `SumarArreglos` de forma que lleven a cabo el funcionamiento indicado en la descripción de cada una. Estas funciones tienen una sección marcada con el comentario `// TODO`, misma en la que tendrás que escribir el código de tu implementación.

### Ejemplo de funcionamiento
A continuación se muestra un ejemplo de cómo debería de lucir la ejecución de tu código considerando la operación de suma.

```
$ ./ Arreglo

Valor elemento [0]: 1
Valor elemento [1]: 2
Valor elemento [2]: 3
Operación: +
Valor elemento [0]: 1
Valor elemento [1]: 2
Valor elemento [2]: 3
Resultado: 2 4 6

```

Y un ejemplo para el caso de la multiplicación:

```
$ ./ Arreglo

Valor elemento [0]: 2
Valor elemento [1]: 4
Valor elemento [2]: 6
Operación: /
Operación: *
Factor: 2
Resultado: 4 8 12
```

Nota que en este último caso se hizo el intento de ejecutar la operación `/` la cual no está permitida, por lo que se vuelve a hacer la misma pregunta al usuario hasta que ingresa un símbolo válido, en este caso `*` que corresponde a la multiplicación.
