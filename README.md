# AdaShip
Adaship is a game of battleships made in C++.

# UML Diagram
![UML Diagram](diagrams/uml.png)

# Breakdown of Tasks to complete
- [x] Create a main-menu system
    - [x] going to sub-menu
- [x] ~~User a map (map[[0,0],[0,0]]) to build and print out a boards~~
    -  Later updated for better memory storage capabilities
- [x] Pull in data from .ini file, as a cofiguration for the whole game
    - [x] Store this list for objects to use as reference
- [x] Create a number input system that verifies the users response (check validation)
- [x] Create a character input system for further validation
- [x] Create new ship based on the users input coordinates
    - [x]  Validate that the users ship does not overlap a current ship/go off the board
- [x] Create a random x and y chooser for the computer player / auto place function
    - [x] Use the same validation for when placing ships, not allowing overlaps/off board etc
- [x] Implement the auto-place function for the AI player
- [x] Create new menu system now with turn based prompts
- [x] Print both the board to attack, and my own board
- [x] Collect another coordinate from the users
    - [x] Validate this coordinate to see if it's already hit. Loop if failing
- [x] Notify if this is a hit or a miss, printing this within the of the other players board (where you're shooting) 
  (Shows on the board as specific icon with colors)
- [x] Have an auto-fire option using the auto-select function
    - [x] Validate again to ensure shots are not wasted on the same already shot at location
- [x] Notify where the user has been shot, through their board
- [x] Have options to "quit game" and "end turn".
- [x] After every turn check if all ships have been destroyed
    - [x] If yes, end the game with the winner being shown on the screen
    - [x] If no, repeat the turn based game until this criteria is filled.
- [x] Go back to main-menu when game is complete.

# Housekeeping
- [x] Refactor code, ensuring there is no duplicate.
    - [x] If there is duplicate, see where it is best to be stored, and use OOP functionality.
- [x] Remove any "code smells", ensuring code is easy and efficient
- [x] Ensure the code is well commented, explaining what classes/functions/code does within the software. Make it readable, as if a document were to be made from it and you can understand the whole project through this C++ comment doc.