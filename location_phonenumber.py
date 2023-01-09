import phonenumbers
from phonenumbers import geocoder

phone_number = phonenumbers.parse("Número de teléfono con código de país") #Parseo el número de teléfono
#Ejemplo: phone_number = phonenumbers.parse("+34123456789")

pais = geocoder.description_for_number(phone_number, "es") #Obtengo el país
print(pais)
