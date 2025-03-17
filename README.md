# Hello CMake
Proyecto básico con CMake y GTest

## Uso

## Problemas
### P1 - Hello world!
Cree su primer proyecto con CMake, para ello cree la carpeta `src`, en esta carpeta es donde debe ir el código de su proyecto.

Dentro de `src` cree el archivo `main.cpp` donde coloque su función `main` y haga un script que imprima lo siguiente:

```
Hello CC7515!
```

Por ultimo añada el archivo `CMakeLists.txt` donde inicie su proyecto y añada el ejecutable.

Para iniciar CMake:

```sh
cmake -S . -B build
```

Para compilar:
```sh
cmake --build build
```

El ejecutable deberia estar en `build/src/`.

### P2 - Añadirle clase
Hagamos algo más complejo, cree una clase `Ball` que represente 
una bola. Una bola tiene:
- Masa
- Posición
- Radio

Para esto añado los archivos `ball.cpp` dentro de `src` y `ball.h` dentro de `include`.

Adicionalmente, la bola debe cumplir con los siguientes requerimientos:

- A una bola se le puede aplicar una fuerza
- Una bola se debe mover en base a las fuerzas que existen sobre ella

Antes de implementar estas funcionalidades usted considera que es necesario contar con la ayuda de una librería matemática. Su auxiliar favorito le recomienda usar [GLM](https://github.com/g-truc/glm).

Para añadir esta libreria se le recomienda crear la carpeta `extern`, en esta carpeta es donde van todas las librerías extenras que necesita su proyecto, use los súbmodulos de git para añadir la dependencia:

```sh
cd extern
git submodule add <link>
```

También es recomendado añadir un archivo `CMakeLists.txt` tanto dentro de `src` como de `extern`, para segmentar las funcionalidades, usted puede cargar estos archivos usando `add_subdirectory` en CMake.

### P3 - Testing
Muy bien, ahora para corroborar que todo funcione correctamente, haga tests para comprobar dichas funcionalidades.

Cree la carpeta `test` esta carpeta es similar a la de `src` solo que contiene el código que es exclusivo al testing.

En el curso usaremos la libreria de testing de Google: [googletest](https://github.com/google/googletest).

Añada esta dependencia *dentro* de su carpeta `test`.

Para correr los tests puede correr el siguiente comando:

```sh
ctest
```

### P4 - Cositas adicionales
En vez de escribir miles de comando para iniciar CMake, compilar el proyecto y correr los tests o ejecutables, puede
hacer uso de los _presets_ de CMake.

Para ello cree un archivo llamado `CMakePresets.json`, aqui puede establecer perfiles para inicializar CMake, compilar el proyecto y correr los tests.

Al usar los _presets_ VSCode automáticamente se integra para hacerle la vida más fácil. También puede usar los _presets_
desde la terminal con los siguientes comando:

```sh
cmake --presets=<name>
```

Si por el contrario usa otro editor (como Vim), puede activar los _compile commands_ que usa CMake para crear cada archivo dentor de su proyecto, para ello agregue la siguiente linea a su proyecto:

```cmake
set(EXPORT_COMPILE_COMMANDS ON)
```

Otra forma de agrupar los comandos es usando Makefile:

```make
CMAKE=cmake
MAKE=make
BUILD_TYPE=Debug
BUILD_DIR=build
BIN=$(BUILD_DIR)/$(BUILD_TYPE)
TARGET=hello-cmake

.PHONY: build init clean test run

all: run

init:
	@$(CMAKE) -DCMAKE_BUILD_TYPE=$(BUILD_TYPE) -S . -B $(BIN)

build: init
	@$(CMAKE) --build $(BIN) --target $(TARGET)

test: 
	@$(CMAKE) --build $(BIN)
	@cd $(BIN)/test/ && ctest 

run: build
	./$(BIN)/src/$(TARGET) 

```

Con esto puede hacer:

- `make` para compilar y ejecutar `TARGET`.
- `make build` para compilar el proyecto.
- `make test` para compilar y ejecutar los tests.
- `make init` para generar los _compile commands_.
