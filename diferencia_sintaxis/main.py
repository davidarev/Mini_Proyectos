import random

#Funciones Paso 1
def moda(vec1, vec2):
    max = 0
    resultado = 0
    for i in range(len(vec2)):
        if vec2[i] > max:
            max = vec2[i]
            resultado = i
    return resultado

def print_array(arr):
    for elem in arr:
        print(elem, end = ", ")
    print()

#Funciones Paso 3
def mediana(vec, num):
    resultado = 0
    if num % 2 == 0:
        resultado = (vec[len(vec) // 2] + vec[len(vec) // 2 - 1]) / 2
    elif num % 2 == 1:
        resultado = vec[len(vec) // 2]
    return resultado

#Paso 1
arr = [0] * 40
random.seed(None)
for i in range(len(arr)):
    numero = 5 + random.randint(5, 20)
    arr[i] = numero

print("El array generado es: ", end="")
print_array(arr)

posiciones = [0] * 40
for elem in arr:
    posiciones[elem] += 1
moda = moda(arr, posiciones)
print("\nLa moda es el numero {}".format(moda))

#Paso 2
print("\nLos numeros ordenados y sin duplicar son: ", end="")
ordenados = set(arr)
for elem in ordenados:
    print(elem, end=", ")
print()

#Paso 3
ordenadosVec = list(ordenados)
mediana = mediana(ordenadosVec, len(ordenadosVec))
print("\nLa mediana es: ", mediana)
