# Práctica 3: Calculadora

## Introducción

### Lenguaje de programación C++
C++ es un lenguaje de programación compilado, surgido inicialmente como una extensión del lenguaje de programación C, ofreciendo como una de sus mayores virtudes el trabajo con clases y por tanto implementar el paradigma de programación orientada a objetos. Una de sus grandes virtudes es el aprovechar la velocidad de procesamiento y manejo de memoria de C y añadir versatilidad y eficiencia, lo que le ha posicionado como un lenguaje muy utilizado en áreas como aplicaciones de escritorio, videojuegos y servidores web.

### Estructuras de datos
Para trabajar con un lenguaje de programación es necesario contar con variables, la cuales obtendrán valores y serán las que se actualizaran y modificaran dependiendo del código de forma que lleven a cabo una tarea.

Existe una gran variedad de estructuras de datos (también conocidas como _tipo de dato_) las cuales almacenan diferente información. Algunos de los más utilizados, y que existen de forma nativa en C++ son los siguientes:

|Nombre del tipo|Descripción del tipo|
|-|-|
|int|Representa un número entero, usualmente de 16bits o mayor|
|long|Representa un número entero, pero con el doble de precisión que un _int_|
|float|Representa un número con punto flotante (un número real)|
|double|Representa un número flotante, pero con el doble de precisión que un _float_|
|bool|Representa un número booleano (_verdadero_ o _falso_, o equivalentemente: _1_ o _0_)|
|char|Representa un número de un byte en memoria (generalmente 8 bits). Usualmente se utiliza para representar caracteres (letras, símbolos, etc.)|

### Operadores aritméticos
Dentro de los lenguajes de programación se pueden llevar a cabo operaciones aritméticas sobre los diferentes tipos de variables. Las operaciones básicas soportadas de forma nativa por C++ son:

|Símbolo|Operación|
|-|-|
|+|Suma|
|-|Resta|
|*|Multiplicación|
|/|División|
|%|Módulo (residuo de una división)|

Algunos ejemplos son:
```
x = 5 + 5; // x = 10
x = 3 * 4; // x = 12
x = 10 % 2; // x = 0
```

### Operadores relacionales y de comparación
De forma similar a los operadores aritméticos, existen operadores que permiten comparar variables. Dentro de los más comúnes en C++ se encuentran:

|Operador|Descripción breve|
|-|-|
|==|Exactamente igual a (una variable es equivalente a otra)|
|!=|Diferente a (una variable **NO** es equivalente a la otra)|
|<|Menor que|
|>|Mayor que|
|<=|Menor o igual que|
|>=|Mayor o igual que|

Algunos ejemplos son:
```
(3 > 6); //falso
(5 == 5.0); //verdadero
(8 <= 6); //falso
(15 != 3); //verdadero
```

### Operadores lógicos
También existen operadores binarios, dos de los más comúnes (_AND_ y _OR_) se representan de la siguiente forma:

|Operador|Descripción breve|
|-|-|
|\&\&|Operador lógico "AND"|
|\|\||Operador lógico "OR"|

Y los cuales tienen un comportamiento que puede representarse con las siguientes tablas de verdad:

##### Operador: AND
|a|b|a \&\& b|
|-|-|-|
|falso|falso|falso|
|verdadero|falso|falso|
|falso|verdadero|falso|
|verdadero|verdadero|verdadero|

##### Operador: OR
|a|b|a \|\| b|
|-|-|-|
|falso|falso|falso|
|verdadero|falso|verdadero|
|falso|verdadero|verdadero|
|verdadero|verdadero|verdadero|

### Instrucciones de control (condicionales)
En los lenguajes de programación existen las llamadas instrucciones de control, las cuales permiten llevar a cabo ciertos procesos que sirven para implementar los algoritmos en lenguaje humano (generalmente en inglés) y que a su vez puedan ser procesadas por la computadora. Dentro de ellas se encuentran los condicionales, los cuales sirven para hacer comparaciones y ejecutar instrucciones dependiendo de sus resultados. Un conjunto de condicionales en C++ podría lucir de la siguiente forma:

```
if (x < 2)
{
  std::cout << "x es menor que 2."
}
else if (x == 2)
{
  std::cout << "x es exactamente igual a 2."
}
else
{
  std::cout << "x es mayor que 2."
}
```

_**Nota:** recuerda que `std::cout` imprime texto en pantalla, permitiendo que el usuario pueda recibir información sobre el código que se está ejecutando._

En ese código se pueden identificar tres instrucciones de control: `if`, `else if` y `else`. En el caso de la instrucción `if` podemos notar que, dada la operación, dependiendo de la condición `x < 2` si se cumple, entonces podemos asumir que `x` es menor que 2, y por tanto se ejecutará el código que aparece entre llaves _{}_ inmediatamente debajo de la condición. De no cumplirse esa condición, se pasaría a evaluar la segunda condición, que sería el `else if`, en el ejemplo se cumpliría si el valor de `x` es exactamente igual a 2, y por tanto se ejecutaría la línea entre las llaves inmediatamente debajo de la condición. Por último, si ninguna de las dos condiciones se cumplieron, entonces se ejecuta aquello que se encuentre en la condición `else`, y que en nuestro ejemplo representaría que el valor de `x` es mayor a 2.

Es importante recalcar que después de una condición `if` puede haber tantos `else if` como sean necesarios, incluso puede no haber. Igualmente se puede omitir (si así se desea) la condición de `else` y por tanto, de no cumplirse las condiciones `if` y `else if` anteriores, simplemente no sucedería nada.

## Descripción

En esta práctica tendrás que implementar un código en C++ que emule el comportamiento de una calculadora básica. Esta calculadora tendrá la capacidad de realizar las siguientes operaciones entre dos números flotantes:

* Suma
* Resta
* Multiplicación
* División
* Módulo

Para ello tendrá tres variables de entrada: un primer número, el símbolo de la operación a realizar y finalmente el segundo número.

Tu programa tendrá que pedirle al usuario esta información en ese orden, primero indicará el primer número, luego la operación a llevar a cabo (para ello tendrá que escribir el caracters de la operación, por ejemplo el signo `+` para indicar una suma, `-` para la resta, `*` para la multiplicación, `/` para la división y finalmente `%` para el módulo) y posteriormente ingresará el segundo número.

### Ejemplo de funcionamiento
A continuación se muestra un ejemplo de cómo debería de lucir la ejecución de tu código considerando la operación de suma, un valor de 5 como el primer número y 8 como el segundo.

```
$ ./ Calculadora

Este programa hace operaciones basicas entre dos numeros.
Primer numero: 5
Operacion: +
Segundo numero: 8

Resultado:
5 + 8 = 13

```

**¡¡¡Recuerda no poner acentos en tus impresiones a consola!!!**
