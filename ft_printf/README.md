*Este proyecto ha sido creado como parte del currículo de 42 por jojaen-m.*

# ft_printf

## Descripción

`ft_printf` es una reimplementación en C de una parte de la función estándar `printf`. Su objetivo es interpretar una cadena de formato, obtener los argumentos variádicos correspondientes y escribir el resultado en la salida estándar.

La biblioteca implementa las conversiones `%c`, `%s`, `%p`, `%d`, `%i`, `%u`, `%x`, `%X` y `%%`. La función pública `ft_printf` devuelve el número de caracteres escritos.

## Instrucciones

### Compilación

Desde la carpeta `ft_printf`, ejecuta:

```sh
make
```

Esto genera la biblioteca estática `libftprintf.a`. Para eliminar los archivos objeto, utiliza `make clean`; para eliminar también la biblioteca, utiliza `make fclean`. `make re` limpia y vuelve a compilar.

### Uso desde otro programa

Incluye `ft_printf.h` y enlaza la biblioteca al compilar tu programa. Por ejemplo:

```c
#include "ft_printf.h"

int main(void)
{
    ft_printf("Hola, %s. Valor: %d\n", "42", 42);
    return (0);
}
```

Si guardas ese ejemplo como `main.c` dentro de `ft_printf`, compílalo desde esa carpeta así:

```sh
cc -Wall -Wextra -Werror -I. main.c -L. -lftprintf -o ejemplo
./ejemplo
```

El proyecto contiene una biblioteca, no un programa ejecutable independiente; para probarla hace falta enlazarla desde un `main`.

## Algoritmo y estructuras de datos

La función principal recorre la cadena de formato de izquierda a derecha. Los caracteres ordinarios se escriben directamente; cuando encuentra `%`, deriva el especificador siguiente a una función de selección (`ft_check_format`), que llama al conversor correspondiente. Los argumentos se leen en orden mediante `va_list`, la interfaz estándar de C para funciones variádicas.

Los conversores de enteros y hexadecimal usan divisiones sucesivas por la base correspondiente. Para emitir los dígitos en el orden correcto, la implementación recurre primero con el cociente y escribe después el resto, que se transforma en carácter mediante una cadena de dígitos (`0123456789abcdef` o su variante en mayúsculas). Los punteros se representan en hexadecimal con el prefijo `0x`; el puntero nulo se muestra como `(nil)`. Los caracteres se escriben con `write`, y cada conversor devuelve su cantidad de caracteres para que `ft_printf` acumule el total.

La estructura de datos principal para gestionar argumentos es `va_list`. La cadena de formato y las cadenas constantes que sirven como alfabetos de dígitos son suficientes para este alcance: no se necesitan asignaciones dinámicas, listas ni mapas de conversión. La selección de formatos se realiza con condiciones explícitas, una opción pequeña y directa para el conjunto limitado de especificadores implementado.

El recorrido del formato es lineal respecto a su longitud. Convertir un número requiere un paso por cada dígito, por lo que cuesta $O(\log_b n)$ para un valor `n` en base `b`; la recursión usa una pila proporcional al número de dígitos. Esta estrategia evita invertir cadenas o reservar memoria auxiliar y mantiene la lógica de cada conversión compacta. Para formatos más extensos, con flags, anchuras o precisiones, sería conveniente ampliar el análisis del formato y separar sus opciones de la selección del conversor.

## Recursos

- `man 3 printf`: referencia de comportamiento y especificadores de la función estándar.
- `man 3 stdarg`: documentación de `va_list`, `va_start`, `va_arg` y `va_end`.
- `man 2 write`: documentación de la llamada al sistema usada para escribir caracteres.
- [cppreference: printf](https://en.cppreference.com/w/c/io/fprintf): referencia de las funciones de formato de C.
- [cppreference: stdarg](https://en.cppreference.com/w/c/variadic): referencia sobre funciones variádicas en C.
- El enunciado de `ft_printf` del currículo de 42: requisitos y límites específicos de la versión del proyecto.

### Uso de inteligencia artificial

En esta entrega se ha utilizado IA para organizar y redactar este README, resumir el flujo de formato y las técnicas de conversión presentes en los archivos fuente, y preparar las instrucciones de compilación y uso. La IA no ha generado ni modificado el código fuente del proyecto como parte de esta tarea; la descripción técnica se ha elaborado a partir de la implementación existente.
