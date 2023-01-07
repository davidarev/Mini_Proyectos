import os
import urllib.request

#Pido al usuario la URL de la imagen y la carpeta donde se guardará dicha imagen
image_url = input("Ingresa la URL de la imagen: ")
folder = input("Ingresa la carpeta de destino: ")

#Abro la URL de la imagen y leo el contenido en una variable
with urllib.request.urlopen(image_url) as url:
    image = url.read()

filename = os.path.basename(image_url) #Obtengo el nombre de archivo de la imagen a partir de la URL

destination = os.path.join(folder, filename) #Creo la ruta de destino

#Creo y escribo la imagen en el archivo
with open(destination, "wb") as f:
    f.write(image)

print("Imagen descargada en", destination)
