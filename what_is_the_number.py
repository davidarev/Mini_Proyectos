"""
Hacer un programa donde la computadora genere un número aleatorio entre 1 y 100, y el usuario debe adivinarlo.
Si el usuario falla, la computadora le debe decir si el número que debe adivinar es mayor o menor que el que ingresó el usuario.
El programa debe terminar cuando el usuario adivine el número.
Hay que tener en cuenta que el usuario puede ingresar cualquier cosa, por lo que hay que verificar que lo que ingresó sea un número válido.
El programa debe mostrar un mensaje de error si el usuario ingresa algo que no sea un número en cada intento.
Hacer uso de funciones.
"""

import random

def is_valid_number(number): #Verifica que el número sea válido
    return number.isdigit() and 1 <= int(number) <= 100

def main(): #Función principal
    number = random.randint(1, 100) #Genera un número aleatorio entre 1 y 100
    user_number = input("Adivina el número: ")
    while not is_valid_number(user_number): #Verifica que el número sea válido
        print("Eso no es un número válido")
        user_number = input("Adivina el número: ")
    user_number = int(user_number)
    while user_number != number: #Se repite el juego hasta que el usuario adivine el número
        if user_number < number:
            print("El número es mayor")
        else:
            print("El número es menor")
        user_number = input("Adivina el número: ")
        while not is_valid_number(user_number): #Verifica que el número sea válido
            print("Eso no es un número válido")
            user_number = input("Adivina el número: ")
        user_number = int(user_number)
    print("Adivinaste el número")

if __name__ == '__main__':
    main()
