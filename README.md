*Este proyecto ha sido creado como parte del currículo de 42 por frgonzal.*

# ft_printf

## Descripción

`ft_printf` es un proyecto del currículo de 42 cuyo objetivo es recrear una parte del comportamiento de la función estándar `printf()` de C.

El proyecto permite trabajar con uno de los conceptos fundamentales de C: las **funciones variádicas**, que permiten recibir un número variable de argumentos mediante `va_list`, `va_start`, `va_arg` y `va_end`.

La implementación analiza una cadena de formato carácter a carácter. Cuando encuentra un carácter normal, lo imprime directamente; cuando encuentra `%`, interpreta el carácter siguiente como un especificador de conversión y procesa el argumento correspondiente.

Actualmente, la implementación soporta las siguientes conversiones:

| Conversión | Descripción |
|---|---|
| `%c` | Imprime un carácter. |
| `%s` | Imprime una cadena de caracteres. |
| `%p` | Imprime una dirección de memoria en hexadecimal. |
| `%d` | Imprime un número decimal con signo. |
| `%i` | Imprime un entero decimal con signo. |
| `%u` | Imprime un entero decimal sin signo. |
| `%x` | Imprime un número hexadecimal en minúsculas. |
| `%X` | Imprime un número hexadecimal en mayúsculas. |
| `%%` | Imprime el carácter `%`. |

La función principal tiene el siguiente prototipo:

    int ft_printf(const char *format, ...);

Al igual que `printf()`, `ft_printf()` devuelve el número de caracteres escritos.

---

## Instrucciones

### Compilación

El proyecto incluye un `Makefile` que genera la biblioteca estática `libftprintf.a`.

Para compilar el proyecto:

    make

El `Makefile` utiliza las siguientes opciones de compilación:

    -Wall -Wextra -Werror

### Limpieza

Para eliminar los archivos objeto:

    make clean

Para eliminar los archivos objeto y la biblioteca:

    make fclean

Para recompilar completamente el proyecto:

    make re

### Uso

Una vez compilada la biblioteca, puede utilizarse desde otro programa en C incluyendo `ft_printf.h` y enlazando `libftprintf.a`.

Ejemplo:

    #include "ft_printf.h"

    int main(void)
    {
        ft_printf("Hola %s!\n", "42");
        ft_printf("Número: %d\n", 42);
        ft_printf("Hexadecimal: %x\n", 255);
        return (0);
    }

Compilación:

    cc main.c -I. ./libftprintf.a -o program

Ejecución:

    ./program

---

## Estructura del proyecto

    ft_printf/
    ├── Makefile
    ├── ft_printf.h
    ├── ft_printf.c
    ├── ft_putnbr.c
    ├── ft_putptr.c
    └── ft_putstr.c

### Archivos principales

- `ft_printf.c`: contiene `ft_printf()` y el procesamiento de los especificadores de conversión.
- `ft_printf.h`: contiene las inclusiones necesarias y los prototipos de las funciones.
- `ft_putstr.c`: contiene las funciones encargadas de escribir caracteres y cadenas.
- `ft_putnbr.c`: contiene la conversión y escritura de números.
- `ft_putptr.c`: contiene la conversión y escritura de punteros.
- `Makefile`: automatiza la compilación y creación de la biblioteca estática.

---

## Algoritmo y estructura de datos

### Algoritmo de procesamiento

La función `ft_printf()` utiliza un algoritmo de recorrido secuencial de la cadena de formato.

El funcionamiento es el siguiente:

1. Se recorre la cadena de formato carácter a carácter.
2. Si el carácter actual no es `%`, se imprime directamente.
3. Si se encuentra `%`, se analiza el siguiente carácter.
4. El carácter determina qué conversión debe realizarse.
5. Se obtiene el argumento correspondiente mediante `va_arg()`.
6. Se llama a la función encargada de realizar la conversión.
7. Se acumula el número de caracteres escritos.
8. Finalmente, `ft_printf()` devuelve el número total de caracteres escritos.

Este algoritmo tiene una complejidad temporal aproximada de **O(n)** respecto a la longitud de la cadena de formato.

### Conversión de números

La conversión de números se realiza mediante división sucesiva por la base.

Para decimal se utiliza:

    0123456789

Para hexadecimal en minúsculas:

    0123456789abcdef

Para hexadecimal en mayúsculas:

    0123456789ABCDEF

El algoritmo obtiene cada dígito utilizando el resto de una división:

    i % base_len

y continúa con:

    i / base_len

La implementación utiliza recursividad para imprimir los dígitos en el orden correcto.

Para un número de `d` dígitos, la conversión requiere aproximadamente **O(d)** operaciones.

---

## Estructuras de datos

El proyecto no necesita estructuras de datos complejas como listas enlazadas, árboles o tablas hash.

La principal estructura utilizada para gestionar los argumentos variables es `va_list`, proporcionada por la librería estándar `<stdarg.h>`.

También se utilizan:

- Cadenas de caracteres (`char *`) para el formato y las bases numéricas.
- Un índice entero para recorrer la cadena de formato.
- Variables enteras para realizar las conversiones numéricas.
- Variables `unsigned` para trabajar con números sin signo y direcciones.
- La pila de ejecución para la conversión recursiva de números.

La elección de estas estructuras permite mantener la implementación sencilla y adecuada para los objetivos del proyecto.

---

## Justificación del diseño

Se ha elegido un **parser secuencial** porque los especificadores de conversión aparecen directamente después del carácter `%`.

No es necesario almacenar toda la cadena ni construir estructuras complejas para interpretar el formato.

La implementación separa las diferentes responsabilidades en funciones independientes:

- `ft_printf()` controla el recorrido de la cadena.
- `ft_check_conversion()` determina qué conversión debe utilizarse.
- `ft_putchar()` y `ft_putstr()` gestionan la salida de caracteres y cadenas.
- `ft_putnbr()` realiza las conversiones numéricas.
- `ft_putptr()` gestiona específicamente las direcciones de memoria.

Esta separación facilita la lectura, reutilización y mantenimiento del código.

Además, `ft_putnbr()` utiliza una cadena que representa la base numérica, permitiendo reutilizar el mismo algoritmo para decimal y hexadecimal.

Por ejemplo:

    0123456789
    0123456789abcdef
    0123456789ABCDEF

De esta forma se evita duplicar código para `%u`, `%x` y `%X`.

---

## Decisiones técnicas

### Funciones variádicas

La función principal utiliza:

    va_list
    va_start
    va_arg
    va_end

Esto permite acceder a un número variable de argumentos y es fundamental para reproducir el comportamiento de `printf()`.

### Números con signo

Los formatos `%d` e `%i` se procesan como números enteros con signo.

Cuando el valor es negativo, se imprime primero el carácter `-` y posteriormente se realiza la conversión del valor numérico.

### Números hexadecimales

Los formatos `%x` y `%X` utilizan el mismo algoritmo de conversión.

La diferencia es la cadena utilizada para representar los dígitos:

    %x -> 0123456789abcdef
    %X -> 0123456789ABCDEF

### Punteros

El formato `%p` representa una dirección de memoria utilizando hexadecimal y el prefijo:

    0x

En el caso de un puntero nulo, se utiliza:

    (nil)

### Cadenas nulas

Cuando `%s` recibe un puntero nulo, la implementación utiliza:

    (null)

en lugar de intentar acceder a una dirección de memoria inválida.

---

## Funcionalidades

La implementación actual soporta:

- `%c` — caracteres.
- `%s` — cadenas.
- `%p` — punteros.
- `%d` — enteros decimales con signo.
- `%i` — enteros decimales con signo.
- `%u` — enteros decimales sin signo.
- `%x` — hexadecimal en minúsculas.
- `%X` — hexadecimal en mayúsculas.
- `%%` — carácter `%`.

---

## Bonus

La versión actual está centrada en la parte obligatoria del proyecto.

No se han implementado actualmente los flags y funcionalidades adicionales de la parte bonus, como:

- `-`
- `0`
- `#`
- `+`
- espacio
- Ancho mínimo (`width`)
- Precisión (`precision`)
- Combinaciones de flags y ancho

---

## Recursos

### Documentación

- `printf(3)` — documentación de la función `printf()` de C.
- `stdarg(3)` — documentación sobre funciones variádicas.
- `write(2)` — documentación de la función utilizada para escribir en la salida.
- `ar(1)` — documentación sobre la creación de bibliotecas estáticas.
- Subject oficial de `ft_printf` de 42.

### Funciones variádicas

La documentación de `<stdarg.h>` ha sido utilizada para comprender el funcionamiento de:

    va_list
    va_start
    va_arg
    va_end

Estas herramientas permiten recorrer los argumentos variables recibidos por `ft_printf()`.

### Uso de inteligencia artificial

La inteligencia artificial se ha utilizado como herramienta de apoyo durante el desarrollo y documentación del proyecto.

Se ha utilizado principalmente para:

- Resolver dudas conceptuales sobre funciones variádicas de C.
- Revisar conceptos va_arg.
- Revisar la estructura y claridad de la documentación.
- Ayudar a organizar y redactar este `README.md`.