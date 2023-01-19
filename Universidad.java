import java.util.ArrayList;
import java.util.Scanner;

//File Estudiante.java
class Estudiante {
	private String nombre;
	private int edad;
	private String ID;

	//Constructor
	public Estudiante(String nombre, int edad, String ID) {
		this.nombre = nombre;
		this.edad = edad;
		this.ID = ID;
	}

	//Metodos Getters
	public String getNombre() {
		return nombre;
	}

	public int getEdad() {
		return edad;
	}

	public String getID() {
		return ID;
	}
}

//File Grupo.java
class Grupo {
	private ArrayList<Estudiante> estudiantes; //Array que contiene objetos de tipo Estudiante

	//Constructor
	public Grupo() {
		estudiantes = new ArrayList<Estudiante>();
	}

	//Funcion para añadir un Estudiante al array
	public void agregarEstudiante(Estudiante estudiante) {
		estudiantes.add(estudiante);
	}

	//Funcion para borrar un Estudiante del array
	public void borrarEstudiante(String ID) {
		for (Estudiante elem : estudiantes) { //Recorro todos los elementos del array -de tipo Estudiante-
			if (elem.getID().equals(ID)) { //Si el DNI del elemento es igual al DNI que paso por parametro, borro dicho elemento
				estudiantes.remove(elem); //Borro el elemento
				System.out.println("Estudiante eliminado con éxito. \n");
				return;
			}
		}
		System.out.println("No se ha encontrado un estudiante con ese ID. \n");
	}

	public ArrayList<Estudiante> getEstudiantes() {
		return estudiantes;
	}

	//Funcion para mostrar por pantalla los estudiantes de un grupo
	public void imprimirGrupo() {
		if (estudiantes.size() == 0) { //Si esta vacio
			System.out.println("No hay estudiantes en este grupo. \n");
		} 
		else {
			for (Estudiante elem : estudiantes) { //Recorro cada elemento del array e imprimimos sus valores
				System.out.println("Nombre: " + elem.getNombre());
				System.out.println("Edad: " + elem.getEdad());
				System.out.println("ID: " + elem.getID() + "\n");
			}
		}
	}
}

//File Main.java
public class Universidad {
	public static void main(String[] args) {
		//Creo las dos clases
		Grupo claseA = new Grupo();
		Grupo claseB = new Grupo();
		Scanner sc = new Scanner(System.in);
		int opcion = 0;
		//Menu
		while (opcion != 4) {
			System.out.println("1. Añadir alumno a un grupo.");
			System.out.println("2. Eliminar alumno de un grupo.");
			System.out.println("3. Mostrar grupo.");
			System.out.println("4. Salir del programa.");
			System.out.println("Escoja una opcion: ");
			opcion = sc.nextInt();
			//Opcion 1
			if (opcion == 1) {
				System.out.println("Seleccione el grupo al que desea añadir el alumno: ");
				System.out.println("1. Clase A");
				System.out.println("2. Clase B");
				int grupo = sc.nextInt();
				Grupo g = grupo == 1 ? claseA : claseB; //Comparo si el valor de la variable "grupo" es igual a 1, si es así, asigna "claseA" a "g" si no asigna "claseB" a "g"
				String continuar = "y";
				//Mientras se quiera introducir un estudiante
				while (continuar.equals("y")) {
					System.out.println("Introduzca el nombre del alumno: ");
					String nombre = sc.next();
					System.out.println("Introduzca la edad del alumno: ");
					int edad = sc.nextInt();
					while(edad < 18 || edad >= 100 ) {
						System.out.println("Edad Incorrecta. ");
						edad = sc.nextInt();
					}
					System.out.println("Introduzca el ID del alumno (8 digitos): ");
					String ID = sc.next();
					while(comprobarID(ID) == false) { //Compruebo si el ID tiene el formato deseado hasta que el usuario lo introduzca correctamente
						System.out.println("ID incorrecto, introduzcalo de nuevo: ");
						ID = sc.next();
					}
					Estudiante estudiante = new Estudiante(nombre, edad, ID); //Creo un estudiante y le añado los datos escritos por teclado
					g.agregarEstudiante(estudiante); //Añadimos el estudiante a la clase
					System.out.println("Desea añadir otro alumno? (y/n)");
					continuar = sc.next();
				}           
			} 
			//Opcion 2
			if (opcion == 2) {
				System.out.println("Seleccione el grupo: ");
				System.out.println("1. Clase A");
				System.out.println("2. Clase B");
				int grupo = sc.nextInt();
				Grupo g = grupo == 1 ? claseA : claseB;
				String continuar = "y";
				while (continuar.equals("y")) {
					System.out.println("Introduzca el DNI del alumno que desea eliminar: ");
					String DNI = sc.next();
					g.borrarEstudiante(DNI); 
					System.out.println("Desea eliminar otro alumno? (y/n)");
					continuar = sc.next();
				}    
			}
			//Opcion 3
			else if (opcion == 3) {
				System.out.println("Seleccione el grupo que desea ver: ");
				System.out.println("1. Clase A");
				System.out.println("2. Clase B");
				int grupo = sc.nextInt();
				Grupo g = grupo == 1 ? claseA : claseB;
				ArrayList<Estudiante> estudiantes = g.getEstudiantes();
				if (estudiantes.size() == 0) {
					System.out.println("No hay estudiantes en este grupo. \n");
				} 
				else {
					g.imprimirGrupo();
				}
			}
			else if (opcion == 4) {
				System.out.println("Fin del Programa");
				System.exit(opcion);
			}
			else {
				System.out.println("Opcion Incorrecta");
			}
		}
	}

	//Funcion para comprobar el formato del ID
	public static boolean comprobarID(String id) {
		if(id.length() != 8) return false;
		for (int i = 0; i < 8; i++) {
			if (!Character.isDigit(id.charAt(i))) {
				return false;
			}
		}
		return true;
	}
}
