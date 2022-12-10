# Laberinto

Trabajo final de Programación I

Desarrollar un programa para que un jugador pueda buscar la salida para un robot
de un laberinto mediante el teclado y el terminal.
Para ello tu programa debe:

- Disponer de un tipo de datos adecuado para representar un robot, que tendrá un
campo para el nombre y otro para el % de energía que disponen sus baterías.

- Cargar un laberinto desde un fichero de texto. El programa debe elegir de manera
aleatoria un laberinto de entre los disponibles en 5 ficheros de texto distintos. En los
ficheros de texto:

  - Las paredes se representarán con X, las celdas disponibles con guiones
medios, la casilla de entrada con la letra I y la de salida con la letra O.

  - En el laberinto podrá haber como máximo 3 casillas de carga inalámbrica
representadas con la letra C. Al ubicarse el robot encima de esa casilla
recargará completamente su energía.

- Una vez que esté cargado el mapa del laberinto en una variable del tipo que
consideres oportuno de tu programa, este deberá funcionar como se indica a
continuación:
  - La posición del robot se visualizará en el terminal con la letra R.
  - El robot partirá de la posición marcada como I en el mapa.
  - Los sensores del robot únicamente le permiten tener un alcance de visión de
1 casilla a su alrededor.
  - El robot puede moverse en 4 direcciones (arriba, abajo, izquierda y derecha),
no permitiéndose movimientos en diagonal.
  - Cada vez que el robot se desplaza una casilla consume un 1% de su batería,
y si intenta avanzar sobre una pared consumirá el 10% (las paredes están
representadas con las letras X y con los límites de tamaño de la variable que
utilices para representar el tablero).
- El objetivo del juego es alcanzar con el robot la salida del laberinto (celda con la letra
O) antes de consumir completamente su batería.
○ Si se agota la batería antes de encontrar la salida el jugador habrá perdido y
tendrá 0 puntos.
○ Si se encuentra la salida antes de consumir la batería el jugador habrá
ganado y su puntuación será el % de batería restante
