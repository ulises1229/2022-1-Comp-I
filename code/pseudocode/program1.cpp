
// Algoritmo 1: Este pseudocódigo realiza la sumatoria de los elementos de un vector
procedure sumElements(A,n)
    // Inputs: A: Vector de entrada 
            // n: Número de elementos de A
    // Output: Suma de todos los elementos del vector add
    suma = 0
    for(i = 0; i<n; i++)
        suma = suma + A[i]
    return suma
    
// Algoritmo 2: Este pseudocódigo realiza la suma del producto de dos series
procedure sumProduct()
    #inputs: m, n
    #output: total
    total = 0
    for (i = 1; i<n; i++) #n operaciones
        for (j= 0; j<m; j++) #m operaciones
            total = total + (i * j)
    return total
    