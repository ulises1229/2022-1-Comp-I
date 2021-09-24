# Práctica 5: GaussJordan

## Descripción

En esta práctica implementarás un código que lleva a cabo el método de Gauss-Jordan para encontrar la solución de un sistema de ecuaciones lineales.

Recordarás el método de Gauss-Jordan de tus clases de álgebra lineal, específicamente en el primer parcial. Ahora es momento de dejar de resolverlo a mano y comenzar a sacar provecho de las computadoras y de las habilidades que estás desarrollando en programación.

Si crees que es buena idea un recordatorio del método de Gauss-Jordan puedes visitar el sitio de [Wikipedia](https://es.wikipedia.org/wiki/Eliminaci%C3%B3n_de_Gauss-Jordan#Forma_escalonada_y_escalonada_reducida) que contiene una idea general del método y su uso. Y si necesitas un poco más de ayuda con el método y su procedimiento, puedes revisar la descripción ejemplificada del [método de Gauss](https://www.uv.es/~diaz/mn/node29.html) y su respectivo complemento para el [método de Gauss-Jordan](https://www.uv.es/~diaz/mn/node30.html).

Para desarrollar esta práctica hemos puesto a tu disposición [este código](GaussJordan.cpp) que contiene el esquema básico del funcionamiento de tu programa. En este código, la función _main()_ realiza lo siguiente:
* Pide al usuario que llene la matriz con los valores del sistema de ecuaciones.
* Aplica el método de Gauss-Jordan sobre la matriz ingresada.
* Despliega en pantalla la solución de cada variable del sistema de ecuaciones.

A lo largo de todo el código vas a ver la definición del siguiente _template_ `template <typename matriz>`, el cual define un tipo de variable llamado `matriz` y que contendrá en nuestro caso la matriz sobre la que vamos a implementar el método de Gauss-Jordan. Este template hará referencia a la matriz de tamaño _variablesXcolumnas_ que contendrá la información del sistema de ecuaciones lineales que se busca resolver.

El código ya contiene cuatro definiciones de funciones:

`LLenarmatriz` la cual solicita al usuario llenar la matriz por filas, es decir, de arriba a abajo, y en cada iteración pide llenar las columnas elemento a elemento de izquierda a derecha. Esta función **ya está implementada para tí**, por lo que no deberás de modificarla. El prototipo de esta función luce como: `void LlenarMatriz(matriz & miMatriz)`, donde hay que prestar especial atención al paso del argumento `miMatriz` el cual se hace _por referencia_.

`ImprimirMatriz` es una función (**que ya implementamos para tí**) te permitirá imprimir la matriz en cualquier momento si lo consideras necesario. Esta función no se pretende llamar en el código final, pero es posible que te sea de ayuda mientras implementas tu código y haces pruebas. La definición de la función tiene la forma `void ImprimirMatriz(matriz & miMatriz)` donde el argumento pasado por referencia `miMatriz` es la matriz a imprimir.

`GaussJordan` esta función tiene como objetivo implementar el algoritmo de Gauss-Jordan sobre una matriz de tamaño _variablesXcolumnas_. Su prototipo de función es el siguiente `void GaussJordan(matriz & miMatriz)`, donde nuevamente se pasa una matriz por referencia, y será sobre la cual se implemente el algoritmo y que al final del proceso contenga la solución al sistema de ecuaciones.

`ImprimirSolucion` es la función que, tomando la matriz resultante de aplicar el método de Gauss-Jordan al sistema original, desplegará en pantalla la solución a cada una de las variables. Su protipo es de la forma `void ImprimirSolucion(matriz & miMatriz)` donde nuevamente `miMatriz` será la matriz que contenga el resultado final de la implementación del algoritmo, y de la cual se obtiene la solución al sistema de ecuaciones.

## Implementación

Tu proyecto consistirá en completar las funciones `GaussJordan` e `ImprimirSolucion` de forma que lleven a cabo el funcionamiento indicado en su respectiva descripción. Estas funciones tienen una sección marcada con el comentario `// TODO`, misma en la que tendrás que escribir el código de tu implementación.

Para lograrlo, puedes crear tantas variables o funciones como requieras, siempre y cuando no modifiques aquellas que ya hemos implementado para tí en el código original (prototipos de funciones, nombres de variables o templates, estructura de la función _main_, etc.)

### Ejemplo de funcionamiento
A continuación se muestra un ejemplo de cómo debería de lucir la ejecución de tu código sobre un sistema de ecuaciones que luce de la siguiente forma:

```
  2x + y - z = 8
  -3x - y + 2z = -11
  -2x + y + 2z = -3
```

donde `x`, `y` y `z` son las variables del sistema.

```
$ ./ GaussJordan

Valor elemento [0][0]: 2
Valor elemento [0][1]: 1
Valor elemento [0][2]: -1
Valor elemento [0][3]: 8
Valor elemento [1][0]: -3
Valor elemento [1][1]: -1
Valor elemento [1][2]: 2
Valor elemento [1][3]: -11
Valor elemento [2][0]: -2
Valor elemento [2][1]: 1
Valor elemento [2][2]: 2
Valor elemento [2][3]: -3

Solución:
x0 = 2
x1 = 3
x2 = -1

```

donde `x0` hace referencia a nuestra variable `x`, `x1` a `y` y `x2` a `z`.
