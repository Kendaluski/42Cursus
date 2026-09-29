*Este proyecto ha sido creado como parte del currículo de 42 por jojaen-m.*

# Libft

## Descripción

Libft es la primera librería creada durante el cursus de 42. Su objetivo es recrear un conjunto de funciones esenciales de la biblioteca estándar de C junto con funciones adicionales que serán útiles en proyectos posteriores.

La librería está pensada para reforzar conceptos clave de programación en C, como:

- manejo de memoria,
- manipulación de cadenas,
- uso de punteros y estructuras,
- comprensión del comportamiento de funciones de libc,
- y preparación para futuros proyectos del cursus, utilizando, por ejemplo, listas enlazadas.

Este proyecto incluye todas las funciones mencionadas en el subject, compiladas dentro de una librería estática llamada `libft.a`.

## Librería creada

La librería implementa una colección de funciones con el prefijo `ft_`, manteniendo el mismo comportamiento general que sus equivalentes de libc, pero con nombres propios para evitar conflictos con la biblioteca estándar.

Incluye funciones para:

- clasificación de caracteres: `ft_isalpha`, `ft_isdigit`, `ft_isalnum`, `ft_isascii`, `ft_isprint`
- manipulación de cadenas: `ft_strlen`, `ft_strchr`, `ft_strrchr`, `ft_strncmp`, `ft_strnstr`, `ft_strdup`, `ft_substr`, `ft_strjoin`, `ft_strtrim`, `ft_split`
- memoria: `ft_memset`, `ft_bzero`, `ft_memcpy`, `ft_memmove`, `ft_memchr`, `ft_memcmp`, `ft_calloc`
- conversiones: `ft_atoi`, `ft_itoa`
- mayúsculas/minúsculas: `ft_toupper`, `ft_tolower`
- gestión de cadenas con funciones de aplicación: `ft_strmapi`, `ft_striteri`
- escritura en archivos y descriptores: `ft_putchar_fd`, `ft_putstr_fd`, `ft_putendl_fd`, `ft_putnbr_fd`
- listas enlazadas: `ft_lstnew`, `ft_lstadd_front`, `ft_lstsize`, `ft_lstlast`, `ft_lstadd_back`, `ft_lstdelone`, `ft_lstclear`, `ft_lstiter`, `ft_lstmap`

## Instrucciones

### Requisitos

- compilador GCC
- sistema Unix/Linux
- Make

### Compilación

Desde la raíz del proyecto:

```bash
make
```

Esto generará la librería estática:

```bash
libft.a
```

### Limpieza

```bash
make clean
make fclean
```

- `make clean` elimina los archivos objeto.
- `make fclean` elimina tanto los objetos como la librería compilada.

### Reconstrucción

```bash
make re
```

### Uso

Para utilizar la librería en un programa C, compila tu proyecto junto con `libft.a`:

```bash
gcc main.c -L. -lft -o programa
```

Y asegúrate de incluir el header:

```c
#include "libft.h"
```

## Recursos

- Manual de `libc` de GNU/Linux:
  - `man 3 strlen`
  - `man 3 memset`
  - `man 3 strtok`
  - `man 3 malloc`
- Documentación de C y punteros:
  - memoria dinámica,
  - estructuras,
  - listas enlazadas,
  - y funciones de entrada/salida.
- Tutoriales y referencias clásicas sobre listas enlazadas en C.
- Material de 42 y documentación del cursus relacionadas con la creación de librerías y funciones reutilizables.

### Uso de IA

La IA se ha usado únicamente como apoyo para ayudar a la compresión del funcionamiento de ciertas funciones, así como para comprender mejor una serie de conceptos relacionados con el manejo de listas.

## Notas técnicas

- El proyecto sigue la norma de 42 en cuanto a estilo y estructura del código.
- Se utiliza `ar` para crear la librería estática.
- La compilación se realiza con las flags obligatorias: `-Wall -Wextra -Werror`.
- Todos los archivos fuente se mantienen en la raíz del repositorio, conforme al enunciado.

## Conclusión

Este proyecto permite consolidar los fundamentos de la programación en C y preparar el camino para futuros proyectos del cursus. La librería creada resulta útil no solo para esta entrega, sino como herramienta reutilizable para el resto del aprendizaje.
