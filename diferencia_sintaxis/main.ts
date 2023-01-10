const arr: number[] = [];
const posiciones: number[] = new Array(20).fill(0);

//Función para calcular la moda
function hallarModa(arr: number[], posiciones: number[]): number {
    let max = 0;
    let resultado = 0;
    posiciones.forEach((valor, i) => {
        if(valor > max){
            max = valor;
            resultado = i;
        }
    });
    return resultado;
}

//Función para imprimir el array
function print(arr: number[]): void {
    console.log(arr.join(', '));
}

//Función para calcular la mediana
function hallarMediana(arr: number[]): number {
    const num = arr.length;
    if(num % 2 === 0){
        return (arr[num / 2] + arr[(num / 2) - 1]) / 2; 
    }else{
        return arr[Math.floor(num / 2)];
    }
}

//Paso 1: Generar array de números aleatorios
for(let i = 0; i < 40; i++){
    const numero = 5 + Math.floor(Math.random() * (20 - 5 + 1));
    arr.push(numero);
}
console.log("El array generado es: ");
print(arr);

arr.forEach(elem => posiciones[elem] += 1);
const moda = hallarModa(arr, posiciones);
console.log(`La moda es el número ${moda}`);

//Paso 2: Ordenar y eliminar duplicados
const ordenados = Array.from(new Set(arr));
console.log("Los números ordenados y sin duplicar son: ");
print(ordenados);

//Paso 3: Calcular mediana
const mediana = hallarMediana(ordenados);
console.log(`La mediana es: ${mediana}`);
