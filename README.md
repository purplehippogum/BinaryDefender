# Game - Programming Assignments Private Repository
### Student Information
  + Name: Zachary Vega-Perkins
  + USC Email: vegaperk@usc.edu
  + USC ID: 5292489073

### Game Information
  + Game Name: Binary Defender
  + Game Description: Fight the evil swarms of the letter A with an arsenal of numbers
  + [Game Design Doc](GameDesignDoc.md)
  + Known bugs: collision detection is finicky around corners of blocks. Just restart the game if it happens.
  + For some reason restarting the application resets the GUI appearance to a Windows 95 kind of interface. The main game still functions fine despite this.


### Compile & Run Instructions
The grader should use the following procedure to compile and run the code:
```shell
#Compile Instructions
echo "qmake -project"
echo "qmake"
echo "make"
#Doxygen Instructions
echo "doxygen -g config.txt"
echo "doxygen config.txt"
#Command to run
echo "./game_vegaperk"
```
