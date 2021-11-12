# Práctica 8: GaussJordan en Python

## Descripción

Uff, nuevo lenguaje. `print("Hola Python!")`.

En esta ocasión vas a reforzar los conocimientos básicos de este nuevo lenguaje llevando a cabo una práctica que ya realizamos anteriormente en C++, pero ahora con la sintáxis de Python. Esa práctica es el método de Gauss Jordan para resolver sistemas de ecuaciones, que llevaste a cabo en la [práctica 5](../5_GaussJordan), con la ligera variante de que en esta ocasión **vamos a pedirle al usuario que indique el número de ecuaciones en el sistema**.

## Implementación
En esta práctica tendrás que implementar el método de Gauss Jordan en Python en un archivo `GaussJordanP.py`.

#### NOTA A CONSIDERAR
Puedes desarrollar tu práctica en un Notebook de Python (i.e. archivo con extensión `.ipynb`), sin embargo, para poder calificarla será necesario que en tu repository en GitHub la subas como un archivo de código fuente `.py`, de forma contraria podría haber problemas al momento de calificar. Aún así, no te limites a subir a tu repository tu Notebook si así lo deseas.

### Ejemplo de funcionamiento
Retomando el ejemplo en la [práctica 5](../5_GaussJordan/Practica5_GaussJordan.md#ejemplo-de-funcionamiento), tenemos lo siguiente:

A continuación se muestra un ejemplo de cómo debería de lucir la ejecución de tu código sobre un sistema de ecuaciones que luce de la siguiente forma:

```
  2x + y - z = 8
  -3x - y + 2z = -11
  -2x + y + 2z = -3
```

donde `x`, `y` y `z` son las variables del sistema.

```
$ python GaussJordanP.py

Número de ecuaciones: 3

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
