_This project has been created as part of the 42 curriculum by cboucher._

# So Long

![img](so_long.webm)

## Description

This is a 2D game development project from scratch with only the help of a graphic library. The project aims to provide a hands-on experience in game development, allowing participants to create a functional game where players navigate a map, collect items, and reach an exit.

We do that by implementing a parser for checking the map's files, a map rendering, we are listening keyboard events for the movement of the player, we are checking conditions for wall collisions, collecting items, etc...

## Technical Choices

### Library Choice

I used the MacroLibX because we can do that in our school. It's a modern rewritting of the MiniLibX using SDL and Vulkan. It's developed by a classmate from the school.

### Reading tiles from tilesets

I chose to implement a feature to load tiles from a tileset. On one hand, it is more optimized in terms of system calls, and on the other hand, it allows me to anticipate future animations more easily. I load the correct sprites using a function that selects the right column and row based on the size of the sprites.

### Algorithm for checking if the map is playable

To check if a map is playable, I chose the flood fill algorithm, which allows movement on empty tiles. Recursively, we move to the four cardinal points from a tile and "repaint" it to avoid revisiting. Care must be taken to avoid stack overflow since my map is in the stack. There are no problems on that front because the maximum map size is limited.

### Areas for Improvement

Saving my map as an [Array List](https://www.youtube.com/watch?v=xFMXIgvlgcY) can be interesting because it remains optimized and also more flexible.
Given more time, I would like to implement animations and real gameplay.

## Instructions

### Compilation

Use `make` or `make re` to compile the program. For cleaning the generated files use `make clean` or `make fclean`.

### Usage

To use the so_long program, run so_long with a .ber map file.

Example : `./so_long maps/1.ber`

## Resources

1.	MacroLibX Documentation : [https://macrolibx.kbz8.me/]
2.	Peer-to-peer learning for the idea of the [Flood Fill Algorithm](https://en.wikipedia.org/wiki/Flood_fill).
3.	Assets from kevins-moms-house.itch.io : [Terrain](https://kevins-moms-house.itch.io/fantasy) and [Player](https://pixelserial.itch.io/)
4.	[Key codes](https://wiki.libsdl.org/SDL2/SDL_Scancode)
5.	Web research and AI chat for some notions about double linked list.
