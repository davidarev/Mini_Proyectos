def sort_string(s):
  s_list = list(s) #Convierti el string en una lista de caracteres
  s_list = sorted(s_list) #Ordeno la lista de caracteres
  sorted_s = ''.join(s_list)   #Convierto la lista ordenada de caracteres de nuevo a un string
  return sorted_s

print(sort_string("supercalifragilisticoespiadiloso")) 
