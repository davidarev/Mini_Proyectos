//Interfaz de la tarea
interface Task { 
    id: number; 
    description: string;
    completed: boolean;
}

//Clase de la lista de tareas
class TaskList { 
    private tasks: Task[];

    constructor() {
        this.tasks = [];
    }

    //Función para añadir una tarea
    addTask(description: string): void { 
        this.tasks.push({ 
            id: this.tasks.length + 1, //El id de la tarea es el número de tareas + 1
            description: description, //La descripción de la tarea es la que se pasa como parámetro
            completed: false //La tarea no está completada
        });
    }

    //Función para eliminar una tarea
    removeTask(id: number): void { 
        this.tasks = this.tasks.filter(task => task.id !== id); //Se filtran las tareas que no tengan el id que se pasa como parámetro
    }

    //Función para marcar una tarea como completada
    markTaskCompleted(id: number): void { 
        for (const task of this.tasks) { //Se recorren las tareas
            if (task.id === id) {
                task.completed = true; //Si la tarea tiene el id que se pasa como parámetro, se marca como completada
                break;
            }
        }
    }
}

const taskList = new TaskList(); //Se crea una instancia de la clase TaskList

//Añado 3 tareas
taskList.addTask('Hacer la compra');
taskList.addTask('Pasear al perro');
taskList.addTask('Lavar los platos');

//Muestro las tareas
console.log(taskList.tasks);

//Marco las tareas con id 1 y 3 como completada
taskList.markTaskCompleted(1);
taskList.markTaskCompleted(3);

console.log(taskList.tasks);

//Elimino la tarea con id 2
taskList.removeTask(2);

console.log(taskList.tasks);
