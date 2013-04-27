# Binary Defender
  _Where you really only have a couple choices_

## Gameplay Overview

The object of the game is to survive oncoming waves of enemies for as long as possible. Points are earned for each enemy killed, and an enemy wave (or round) ends when a certain number of enemies have been killed. Players control a ~~stationary~~ character that can move in ~~any direction~~ four directions and ward off foes with a basic shooting attack. Enhancing the player's basic attack are the numbers in the **binary** scoring display. The player can choose either 1 or 0 **from the score display** to enhance his/her basic attack. Taking a digit from the score display decreases the score as if that digit was removed. Once a round, the player may use a SMASH ability that destroys all enemies in a lane. The player loses health upon colliding with an enemy. The enemy is destroyed in the process. Once the player's health has been depleted, the game is over and the (non-binary) score will be displayed.

## Mock-Up Screenshots
   ![Main Menu](http://www-scf.usc.edu/~vegaperk/main%20menu%20screen.jpg "Main Menu")
   ![Main Game Screen](http://www-scf.usc.edu/~vegaperk/game%20screen.jpg "Game Screen")
   ![Game Over](http://www-scf.usc.edu/~vegaperk/game%20over%20screen.jpg "Game Over Screen")

----

## Game Breakdown

### Ordered Game Flow
  1. Start screen
  2. Main Game Screen
  3. Game over screen

### Main Game Objects
  1. Player
  2. Basic player projectile
  3. Health bar for player hit points
  4. Special projectiles in the form of the digits 0 and 1
  5. Two scoring displays
  6. Heads-up display for the inventory of special projectiles
  7. Two different enemy types

----

## Controls
#### Mouse is used for all shooting control
  * Player faces the direction of the mouse
  * Left-click anywhere outside of the HUD and score display to shoot in that direction
  * What is shot depends on what type of projectile is selected
  * Left-click on a digit in the score display to gain the corresponding ability
  * Right-click in a lane to use SMASH ability
  * Mouse wheel changes projectile type
#### WASD Keys used for up, down, left, and right movement
  * W is up
  * S is down
  * A is left
  * D is right

----

## Detailed Description of Game Objects and Controls
####  1. Player
  * Takes the form of a triangle (like the spaceship in Asteroids)
  * Remains stationary at the center of the screen.
  * ~~Can turn 360 degrees.~~ Moves and shoots in four directions: up, down, left, right

####  2. Basic Player Projectile
  * Simple projectile that does minimal damage to enemies
  * Unlimited ammunition

#### 3. Health Bar For Hitpoints
  * Simple horizontal bar that depletes with the player's health
  * Game ends when this reaches zero

####  4. Two Special Projectiles
  * Limited ammunition for each
  * Ammunition gained by sacrificing score
  * First special type is a slicing projectile that goes through multiple enemies. It is slightly more damaging than the simple projectile
  * Second special type is an area of effect projectile that explodes on contact with an enemy, doing serious damage in a radius around the projectile
  * Blast does not hurt the player

####  5. Score displays
  * Score is displayed in binary in the main game screen, and in decimal in the game over screen.
  * Player may click on a digit in the score display to gain a special. Clicking on a 1 will add a slicing projectile to the player's inventory, clicking a 0 will add an exploding projectile. Clicking on a digit in the score will remove it from the score and add it to the player inventory

#### 6. HUD For Special Projectiles
  * Simple counters for the special projectile types. Will display an icon of the projectile with a number next to the icon

####  7. Two Different Enemy types
  * Enemies come in the form of English letters
  * **Strong/slow** enemies will come in the form of bold letters, while _weak/fast_ enemies will be italicized letters
  * Enemies spawn at random locations outside of the screen, moving directly towards the player
