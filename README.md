# AdaShip

## Challenge Outline
This is an assignment provided by Ada. Its purpose is to provide a console-style based game of "battleships".

The code provided here is the code for the battleships game. This should be done at least to a "Merit" standard but also contains some
criteria for "Distinction" level.

This assignment is part of the "Advanced Programming" module.

The code in this project follows the standards of OOP programming using polymorphism, inheritance, reusable and efficient code.

### UML Diagram
Below the image will show you the UML diagram of this project.
![UML Diagram](diagrams/uml.png)

### Tasks/Features
- [x] Take settings of the game state from a ini file.
  - [x] Use sections
  - [x] Use proper .ini file format
  - [x] Board Configuration
    - [x] Size X
    - [x] Size Y
  - [x] Ship Configurations
    - [x] ShipName=Length
- [x] Main Menu
  - [x] Player vs Computer
  - [x] Quit
- [x] Ship Placements
  - [x] Automatic
  - [x] Manual
  - [x] Automatic (per ship)
- [x] Grids
  - [x] See my board
  - [x] See opponents board
  - [x] Proper table system
    - [x] Rows
    - [x] Columns
  - [x] Support any size specified in .ini file
- [x] Validation
  - [x] Validate user input
  - [x] Validate AI input
  - [x] Validate .ini input
- [x] AI
  - [x] Targets on its own
  - [x] Fires randomly
  - [x] Clear hit/miss by showing color and icon on the opponents board.
  
### Refactoring
- [x] Remove duplicates
- [x] Make custom player objects inherit from one player
- [x] Use polymorphism to override Player::takeTurn();
- [x] Remove code "smells"
  - [x] Efficient code
  - [x] Easy to read code
- [x] Well commented code.

## Development
### Adoption/Use of good standards
The most important part about this program is to build code that is "of to a good standard". This is done by picking up good
standard industry practices for example:
 - Comments/Documentation: 
   Properly commented code will help a tonn when coming back to a project helping the developer know whats what.
 - Readable but efficient code: 
   Build methods that are easy to read and understand but also does the job efficiently.
 - No hard coding: 
   We want to make our program scale, so we try to avoid hard coding variables as much as possible (Like the board size)
  so we can modify these via a .ini file.
 - Helper Methods: Repeatable tasks should be done via helper methods to keep code succinct and concise.

### Phase 1 Development
I decided to go with an agile way of working on this application. I would build a few features, test and deploy them. And when this
cycle comes to an end I go back over the features I implemented and refactor them and make any changes I feel should be made to make
the program easier to use, or more efficient to use.

The first iteration of the development cycle I started off with the basics. User input, menu, etc. No core game mechanics were implemented yet.
Once the first iteration was over I then went back, and refactored the code. Some code turned into helper methods like user input. Some code
was refactored into their own classes like the Menu. All-in-all this made the code much easier to write later on in the development process.

### Phase n Development

Over the next iterations of the development phase, I implemented core game mechanics like the grid system, coordinate system.
Even though this was implemented, in subsequent phases of the development cycle, many features in this game mechanic systems were changed. 
This was due to many things that were being added/changed like bombs in the game where it needed its own specific gameplay logic.

For objects like map entities, I ended up creating a base class called "MapEntity" this contains a coordinate vector, this allows for forcing
every map entity to have a coordinate. With this data I can check for things like overlapping with other entities by just checking the
base MapEntity object on the bomb or ship etc.

### Quality Control
When I was implementing features, I would implement small snippets at a time and run through to test them. 
I would repeat this process over and over again until the feature was complete. If during my testing of a feature there was something
that broke. I would run the code through a debugger and figure out why its not working in the first place rather than just throwing in 
a few fixes that I felt "might be the issue".

When I was reaching "end-game" features, during testing I would run through the program from start to finish tracing down bugs that I may
of missed during the agile development phases. If bugs arose I would go ahead and fix them and when a fix is implemented I would ensure that
the fix did not break anything else further down the code. Git really became helpful for this for rolling back code that was changed into
a broken state.

### Key Design Challenges/Innovations
One of the most challenging part of the program is the Player. Specifically changing the player's logic when its Ai based or controlled
by a real user.
The way I was over to overcome this was to make use of polymorphism. I had a base object called Player. This object didn't do anything
special, it was more of a criteria that all derived classes should inherit and override.
The Player base object contained everything that is needed for gameplay to commence, like the game board, access to the current game,
access to the ships the player has control of on their board etc. But then it also has virtual methods like takeTurn(). The point of this
method isn't for Player to implement the logic. But for derived classes to. E.G.

 - `RealPlayer::takeTurn()` This will override the `Player::takeTurn()` method and take user input. With this user input we can
   get the RealPlayer to input coordinates for where they would like to shoot and then control the player using its properties from the
   base class to shoot into a specific location into the opponent, or by checking if there is a bomb present on that coordinate, or even
   if that coordinate is valid at all.
   
 - `AiPlayer::takeTurn()` This will override the `Player::takeTurn()` method but instead of taking user input it will instead use a simple
   algorithm to select a row and column on the grid. It will then use these values to do the other same logic to shoot into a location.
   This is sort of like emulating what the user is doing. 