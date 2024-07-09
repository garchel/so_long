## So Long
# Description
So Long is a simple 2D game project developed as part of the 42 school curriculum. The goal is to create a basic game where a character (by default, a dolphin) escapes Earth after eating some fish.
Features

Uses the MiniLibX graphics library
2D map with top-down or profile view
Character movement using W, A, S, D keys (or ZQSD/arrow keys)
Item collection and exit finding
Map parsing from .ber files
Movement counter

Requirements

MiniLibX
C Compiler (gcc recommended)
Make

Installation

Clone the repository:
```
git clone https://github.com/your-username/so_long.git
```

Enter the project directory:

```
cd so_long
```


Compile the project:
```
make
```



Usage
Run the program by passing a valid map as an argument:
```
./so_long maps/map.ber
```

Controls

W/↑: Move up
A/←: Move left
S/↓: Move down
D/→: Move right
ESC: Exit the game

Map Format
Maps should be .ber files containing:

1: Wall
0: Empty space
C: Collectible
E: Exit
P: Player's starting position

Example of a valid map:
```
1111111111111
10010000000C1
1000011111001
1P0011E000001
1111111111111
```
