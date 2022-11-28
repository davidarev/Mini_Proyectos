import random

def play(user_choice, computer_choice): #Compara las elecciones y devuelve el resultado
    if user_choice == computer_choice:
        return "Empate"
    elif user_choice == "piedra":
        if computer_choice == "papel":
            return "Perdiste"
        else:
            return "Ganaste"
    elif user_choice == "papel":
        if computer_choice == "tijera":
            return "Perdiste"
        else:
            return "Ganaste"
    elif user_choice == "tijera":
        if computer_choice == "piedra":
            return "Perdiste"
        else:
            return "Ganaste"

def is_valid_choice(choice): #Verifica que la elección sea válida
    return choice in ["piedra", "papel", "tijera"]

def main(): #Función principal
    user_choice = input("Ingrese su elección: ")
    if is_valid_choice(user_choice): #Verifica que la elección sea válida
        computer_choice = random.choice(["piedra", "papel", "tijera"]) #Elige una opción al azar
        print("La computadora eligió", computer_choice)
        print(play(user_choice, computer_choice)) #Se llama a la función play para comparar las elecciones y mostrar el resultado
    else:
        print("Esa no es una opción válida") #Si la elección no es válida, se muestra un mensaje de error

if __name__ == '__main__':
    while True: #Se repite el juego hasta que el usuario decida salir
        main()
        if input("¿Quieres jugar de nuevo? (s/n): ") == "n": #Pregunta si el usuario quiere jugar de nuevo
            break