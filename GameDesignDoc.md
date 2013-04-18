# Digit Defender
  _You Can Count on an Adventure_

----

## Game Breakdown

### Gamepley Overview
The object of the game is to survive oncoming waves of enemies for as long as possible. Points are earned for each enemy killed. Players control a stationary character that can turn in any direction and ward off foes with a basic shooting attack. Enhancing the player's basic attack are the numbers in the **binary** scoring display. The player can choose either 1 or 0 **from the score display** to enhance his/her basic attack. Taking a digit from the score display decreases the score by that amount. The player loses health upon colliding with an enemy. The enemy is destroyed in the process. Once the player's health has been depleted, the game is over and the (non-binary) score will be displayed.

### Ordered Game Flow
    1. Start screen
    2. Main Game Screen
    3. Game over screen

### Main Game Objects
    1. Player
    2. Basic player projectile
    2. Two scoring displays
    3. Heads-up display for the inventory of special attacks
    4. Various weapons and powers in the form of the digits 0 and 1
    5. Two different enemy types - one weak and fast, the other strong and slow.


### Detailed Description of Game Objects and Controls
>  1. **Player**
    * Remains stationary at the center of the screen.
    * Can turn 360 degrees.
  2. **Basic Attack**
    * Simple projectile that does minimal damage to enemies
  3. **Weapons/powers**
    * A slicing projectile that goes through multiple enemies. It is slightly more damaging than the simple projectile
    * An area of effect projectile that explodes on contact with an enemy, doing damage in a radius around the projectile
  4. **Score displays**
    * Score is displayed in binary in the main game screen, and in decimal in the game over screen.
    * Player may click on a digit in the score display to gain a special. Clicking on a 1 will add a slicing projectile to the player's inventory, a 0 will add an exploding projectile

  5. **Enemy types**
    * **Strong/slow** enemies will come in the form of bold letters, while _weak/fast_ enemies will be italicized letters

### Controls
Mouse is used for all control
      * Player faces the direction of the mouse
      * Left-click anywhere outside of the score display to shoot
      * Left-click on a digit in the score display to gain the corresponding ability
      * Right-click to use special weapon
      * Mouse wheel changes projectile type

### Code

```
# Header 1
## Header 2
### Header 3
#### Header 4
##### Header 5

You can also write in **bold** or _italics_. You can also ~~strike through~~ or write inline `Code Segments`

>Blockquotes are done as such.

Just make sure to separate paragraphs with an emptyline. 
Otherwise, they are considered in the same paragraph.

You link to [Google](https://www.google.com) as such and lists are written has follows:
  1. First you indent with two empty spaces.
  1. Then, you use:
    * `1.` to signal an ordered (i.e. numbered) list, or
    * `*`, `-`, `+` to represent an unordered list.
      1. Make sure to maintain indentation
      1. As it is used to identify sub-lists
  1. Numbering and symboles don't matter as they are auto-generated later.

Tables are pretty easy to make:

| Tables        | Are           | Easy          |
| ------------- |:-------------:| -------------:|
| left-aligned  | centered      | right-aligned |
| header are    | bolded and    | centered      |
| zebra stripes | are neat      | 1             |


Images are added inline by using the following syntax
![alt text](http://octodex.github.com/images/Professortocat_v2.png "Image Title")
```

----

### Rendering
This section shows the rendering of the plain text above.

# Header 1
## Header 2
### Header 3
#### Header 4
##### Header 5

You can also write in **bold** or _italics_. You can also ~~strike through~~ or write inline `Code Segments`

>Blockquotes are done as such.

Just make sure to separate paragraphs with an emptyline. 
Otherwise, they are considered in the same paragraph.

You link to [Google](https://www.google.com) as such and lists are written has follows:
  1. First you indent with two empty spaces.
  1. Then, you use:
    * `1.` to signal an ordered (i.e. numbered) list, or
    * `*`, `-`, `+` to represent an unordered list.
      1. Make sure to maintain indentation
      1. As it is used to identify sub-lists
  1. Numbering and symboles don't matter as they are auto-generated later.

Tables are pretty easy to make:

| Tables        | Are           | Easy          |
| ------------- |:-------------:| -------------:|
| left-aligned  | centered      | right-aligned |
| header are    | bolded and    | centered      |
| zebra stripes | are neat      | 1             |


Images are added inline by using the following syntax
![alt text](http://octodex.github.com/images/Professortocat_v2.png "Image Title")

