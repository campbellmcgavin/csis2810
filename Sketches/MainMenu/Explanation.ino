/*
 * 
 * 
 * MainMenu ~
 * Sets up code (pins, global vars etc)
 * Tells motor to go home
 * Pushes loop into UserInput phase
 * 
 * GoHome ~
 * Orders x and y motors to go until both limit switches have been pressed down.
 * 
 * UserInput ~
 * Prints main menu
 * allows user to select to enter a point, enter a string, or go home.
 * 
 * Movement
 * areWeThereYet() - checks if both motors are there yet.
 * xThereYet() - checks if x is arrived at location yet. if it has, sets x_move_finished = 1
 * yThereYet() - checks if y is arrived at location yet. if it has, sets y_move_finished = 1
 * printHowFarLeft() - for troubleshooting. prints out how far we have left to go for both motors
 * DrawLine() - calls CalculateLine and then Move motors to draw a line
 * CalculateLine() - determines how fast motors should go to follow line based on p1 and p2.
 * DrawCircle()
 * CalculateCirlce()
 * RunMotors()
 * 
 * 
 * 
 * 
 * 
 */
