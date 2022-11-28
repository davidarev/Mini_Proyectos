import random
import base64

def generate_password(): #Genera una contraseña aleatoria
    characters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890!@#$%^&*()_+-="
    password = ""
    for i in range(14):
        password += random.choice(characters) #Elige un carácter al azar
    return password

def is_strong_password(password): #Verifica que la contraseña sea segura
    has_uppercase = False
    has_lowercase = False
    has_number = False
    has_special_character = False
    for character in password: #Recorre cada carácter de la contraseña
        if character.isupper():
            has_uppercase = True
        elif character.islower():
            has_lowercase = True
        elif character.isdigit():
            has_number = True
        else: #Si el carácter no es una letra ni un número, es un carácter especial
            has_special_character = True
    return has_uppercase and has_lowercase and has_number and has_special_character

def main(): #Función principal
    password = generate_password() #Se llama a la función generate_password para generar una contraseña aleatoria
    while not is_strong_password(password): #Se verifica que la contraseña sea segura
        password = generate_password()
    print(" Tu nueva contraseña es:", password + "\n") #Se muestra la contraseña generada

if __name__ == '__main__':
    main()
