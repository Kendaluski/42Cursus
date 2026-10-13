*Este proyecto ha sido creado como parte del currículo de 42 por jojaen-m.*

# get_next_line

## Descripción

`get_next_line` es una función en C que devuelve una línea cada vez que se la llama, leyendo desde un descriptor de archivo. Una línea termina en `\n` cuando ese carácter está presente; si el archivo termina antes, la última llamada devuelve los caracteres restantes. Cuando ya no hay datos, devuelve `NULL`.

El proyecto ofrece dos implementaciones:

- **Obligatoria:** `get_next_line.c`, `get_next_line.h` y `get_next_line_utils.c`. Conserva el texto pendiente entre llamadas mediante una variable estática, para un descriptor de archivo.
- **Bonus:** `get_next_line_bonus.c`, `get_next_line_bonus.h` y `get_next_line_utils_bonus.c`. Mantiene un texto pendiente independiente por descriptor, lo que permite alternar llamadas a varios archivos sin mezclar sus líneas. El tamaño de la tabla está limitado por `FD_MAX` (1024 por defecto); los descriptores usados con esta versión deben ser menores que ese valor.

El tamaño de lectura se configura con `BUFFER_SIZE`; si no se define al compilar, el encabezado usa el valor `1`.

## Instrucciones

No se requiere instalación de dependencias externas. Hace falta un compilador de C, como `cc` o `clang`, y un programa de prueba que invoque `get_next_line`. Este repositorio no incluye una función `main`, así que `main.c` en los ejemplos representa ese archivo de prueba.

Para compilar la versión obligatoria:

```sh
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 main.c get_next_line.c get_next_line_utils.c -o get_next_line
```

Para compilar la versión bonus, en su lugar:

```sh
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 main.c get_next_line_bonus.c get_next_line_utils_bonus.c -o get_next_line_bonus
```

Compila **una sola variante por ejecutable**: ambas exportan una función `get_next_line` con el mismo nombre. Cambia `42` por el tamaño de bloque que quieras probar, vuelve a compilar y ejecuta el programa indicando el archivo que use tu `main`:

```sh
./get_next_line archivo.txt
```

La función recibe un descriptor de archivo (`fd`), normalmente obtenido con `open`, y devuelve una cadena asignada dinámicamente. El programa que la llama debe liberar cada línea con `free` y cerrar el descriptor cuando termine. Sigue llamando a la función hasta que devuelva `NULL`.

## Algoritmo y decisiones

La función conserva en una cadena dinámica (`stack`) los datos leídos que todavía no ha devuelto. El proceso para cada llamada es:

1. **Completar la siguiente línea:** mientras la cadena pendiente no contenga `\n`, `ft_read_file` lee hasta `BUFFER_SIZE` bytes con `read`. Cada bloque se añade al final de la cadena. La lectura se detiene al encontrar un salto de línea o al llegar a EOF.
2. **Extraer la línea:** `ft_get_line` copia desde el inicio de la cadena hasta el primer `\n`, incluyéndolo si existe, a una nueva cadena terminada en nulo. Si EOF dejó caracteres sin salto de línea, devuelve esos caracteres como última línea.
3. **Conservar el sobrante:** `ft_stack_refill` elimina de la cadena pendiente la línea devuelta y conserva el texto posterior al salto de línea para la siguiente llamada.
4. **Finalizar:** si no queda texto, la función devuelve `NULL`. Si `read` falla, la implementación también devuelve `NULL` y libera el búfer y el estado pendiente de esa lectura.

Se elige lectura por bloques porque `read` puede entregar varios bytes en una operación, mientras que el estado pendiente permite que la interfaz devuelva exactamente una línea por llamada incluso cuando un bloque contiene varias. Así, el resultado no depende de que una línea coincida con los límites de `BUFFER_SIZE`, y el mismo flujo funciona con archivos que contienen líneas de longitud variable.

La versión obligatoria usa una única cadena estática porque conserva el estado de una sola secuencia. La versión bonus usa una tabla indexada por descriptor: cada archivo puede retener su propio sobrante y reanudarse de forma independiente. La contrapartida de la implementación actual es que cada concatenación reserva una cadena nueva y copia el contenido acumulado; una línea muy larga puede requerir trabajo de copia cuadrático respecto a su longitud. Una estrategia con capacidad reservada y crecimiento geométrico podría reducir ese coste, pero no es la estrategia implementada aquí.

## Recursos

- [`read(2)` en Linux man-pages](https://man7.org/linux/man-pages/man2/read.2.html): lectura desde descriptores de archivo y tratamiento de EOF y errores.
- [`open(2)` en Linux man-pages](https://man7.org/linux/man-pages/man2/open.2.html): apertura de archivos y obtención de descriptores.
- [`malloc(3)` en Linux man-pages](https://man7.org/linux/man-pages/man3/malloc.3.html): asignación y liberación dinámica de memoria.

### Uso de inteligencia artificial

Se utilizó IA para revisar la estructura y redactar este README, en particular las instrucciones de compilación, la descripción de las dos variantes y la explicación del algoritmo a partir del código fuente. En esta tarea la IA no modificó los archivos de implementación ni generó el algoritmo del proyecto.
