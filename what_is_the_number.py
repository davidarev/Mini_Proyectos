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
