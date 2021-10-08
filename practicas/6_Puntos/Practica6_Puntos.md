# Práctica 6: Puntos

## Descripción

Para esta práctica trabajaremos con transformaciones geométricas en un plano, de forma específica con traslaciones, rotaciones y escalamientos de un punto en un eje coordenado.

Puedes recordar los principios básicos de estas transformaciones [en la siguiente presentación](https://www.fing.edu.uy/inco/cursos/compgraf/Clases/2012/05-Transformaciones%20Geometricas.pdf) específicamente te va a ser de ayuda el principio (la sección _Transformaciones bidimensionales_), hasta antes de la sección _Coordenadas homogéneas y representación matricial de transformaciones bidimensionales_, pero nadie te limita a que revises el resto de la presentación.

Para desarrollar esta práctica hemos puesto a tu disposición [este código](Puntos.cpp) que contiene el esquema básico del funcionamiento de la práctica. En él, la función _main()_ realiza lo siguiente:
* Crea una instancia de la clase `Punto2D`.
* Pide al usuario que ingrese las coordenadas del punto en el plano.
* Solicita al usuario indicar la transformación a aplicar.
* Aplica la transformación solicitada sobre el punto.
* Imprime la posición final del punto.

El código cuenta con dos funciones, ambas ya implementadas:

`PedirValores` la cual solicita al usuario dos valores, uno para `x` y otro para `y` los cuales **son modificados por referencia**. El prototipo de la función luce como: `void PedirValores(float& x, float& y)`.

`PedirOperacion` es una función que solicita al usuario ingresar la transformación que desee aplicar. En concreto las opciones válidas son `t` para trasladar, `r` para rotar y `e` para escalar. si no ingresa alguna de las tres opciones anteriores, vuelve a solicitar al usuario que ingrese la operación hasta que ingrese una válida. La definición de la función tiene la forma `char PedirOperacion()` podrás notar que no recibe parámetros y regresa una variable del tipo`char` con la letra correspondiente a la transformación.

Este código cuenta también con la declaración de una variable `miPunto` del tipo `Punto2D`, este tipo corresponde a una clase con ese nombre, la cual hace referencia a un punto en el plano, y la cual debe de contar con sus correspondientes coordenadas `x` y `y`, así como un par de métodos que son llamados a lo largo del método _main()_.

En concreto requiere de los siguiente métodos:

* `SetPosicion`: Inicializa las coordenadas del punto, recibiendo como parámetros dos números flotantes.
* `Trasladar`: Traslada/desplaza el punto en el plano cierto valor en cada eje. Recibe como parámetros los valores a trasladar para cada eje, primero en el `x` y después el de las `y`.
* `RotarRespectoAlOrigen`: Rota el punto un cierto ángulo indicado con respecto al origen. Recibe como parámetro el ángulo a rotar **en grados**.
* `Escalar`: Escala la posición del punto en el plano, como parámetros recibe el factor de escala sobre cada eje, primero sobre `x` y luego sobre `y`.
* `GetX`: Regresa el valor de la coordenada `x` del punto en el plano.
* `GetY`: Regresa el valor de la coordenada `y` del punto en el plano.

## Implementación

Como podrás notar, no está definida la clase `Punto2D`, es ahí donde tú entras en acción.

Para lograr esta práctica tendrás que crear dos archivos: uno llamado `Punto.h` que contendrá la definición de la clase `Punto2D` así como sus atributos y las declaraciones de sus métodos, y otro llamado `Punto.cpp` que contendrá la implementación de los métodos de la mencionada clase.

Puedes agregar tantos atributos a la clase como creas necesario, siempre y cuando logre el objetivo de la práctica. Igualmente podrás agregar tantos métodos como consideres necesarios, considerando que **al menos deberán de estár implementados los indicados en la sección anterior** y que son los llamados a través de la función _main()_.

**IMPORTANTE**: No deberás modificar en absoluto el código en el archivo `Puntos.cpp` ya que éste está _totalmente implementado_ y por tanto no será descargado de tu repository, sino que se ocupará el [indicado en esta práctica](Puntos.cpp). Sin embargo es recomendable que lo descargues, para que puedas llevar a cabo las pruebas de forma local. Siéntete libre de agregarlo a la carpeta en tu repository, de estar presente simplemente se va a ignorar cuando se haga la revisión.

#### NOTA A CONSIDERAR
Para que tu práctica funcione de manera correcta vas a necesitar tener tres archivos, los ya mencionados `Punto.h` y `Punto.cpp` que es donde vas a implementar la declaración de la clase `Punto2D` y la implementación de sus métodos repectivamente. El tercer archivo será el que te brindamos `Puntos.cpp` en el cual se tiene toda la estructura del proyecto. De no tener estos tres archivos, tu proyecto no va a funcionar correctamente en tu computadora de forma local. **No es válido copiar y pegar el contenido de `Puntos.cpp` a `Punto.cpp` ya que esto creará conflictos al momento de compilar la práctica debido a que todo estará duplicado en el proyecto, comportamiento no deseado.**

En [este link puedes encontrar un pequeño ejemplo](http://www.math.uaa.alaska.edu/~afkjm/csce211/handouts/SeparateCompilation.pdf) del uso de archivo de encabezado (.h) y el trabajo con múltiples archivos fuente (.cpp) para la implementación de clases. En específico te puede resultar útil la información de la primera, segunda y principio de la tercera página del documento, donde se explican los conflictos de importar en varias ocasiones un mismo archivo de encabezado y cómo evitarlo. El documento está en inglés, pero es bastante ilustrativo el ejemplo, considerando que un comportamiento similar tendrá la prática que vas a realizar.

### Ejemplo de funcionamiento
A continuación se muestran ejemplos del funcionamiento esperado de tu práctica.

Para el caso de trasladar el punto, luciría como lo siguiente:

```
$ ./ Puntos

Ingresa la posicion inicial del punto.
x: 4
y: 5
Operacion ('t' para trasladar, 'r' para rotar, 'e' para escalar): t
Ingresa los valores a desplazar para cada eje
x: 3
y: -4
Posicion final:
[ 7 1 ]

```

La rotación  del punto tendría la siguiente implementación:

```
$ ./ Puntos

Ingresa la posicion inicial del punto.
x: 5
y: 2
Operacion ('t' para trasladar, 'r' para rotar, 'e' para escalar): r
Ingresa el valor del angulo a rotar (en grados): 45
Posicion final:
[ 2.12132 4.94975 ]

```

Y finalmente para un escalado la siguiente:

```
$ ./ Puntos

Ingresa la posicion inicial del punto.
x: 7
y: 5
Operacion ('t' para trasladar, 'r' para rotar, 'e' para escalar): e
Ingresa los factores a escalar para cada eje
x: .5
y: .25
Posicion final:
[ 3.5 1.25 ]

```
