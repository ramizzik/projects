// COMP 051-03 Fall 2021
// Lab 10 - Nov 15
//
// Simulation.h - declaration of the Simulation class
//
#ifndef SIMULATION_DOT_H
#define SIMULATION_DOT_H
#include "InterAct2D.h"
#include "Cannon.h"
#include "Explosion.h"
#include "Slider.h"
#include "MovingBackground.h"
#include "Projectile.h"

// A single Simulation object is created and used to control 
// everything that this happening in the simulated environment.

class Simulation {
public:
	// default constructor
	Simulation();
	// member function to receive and react to events generated by InterAct2D.
	void handleEvent(Event event);

private:
	// Color the entire screen in the specified color.
	// Screen coordinates are extracted from the Event object.
	void clearScreen(Event event, Color color);

	// Reset the simulation (reaction to the RESTART button).
	void resetSimulation(Event event);

	// Draw everything in the simulated environment.
	void drawEverything(Event event);

	// Update everything in the simulated environment based on the passed Event.
	// This includes moving forward in time due to timer events and reacting to keystrokes.
	void updateSimulation(Event event);

	Cannon cannon;
	Slider velocity_slider;
	MovingBackground sky;
	Explosion explosion;
	Projectile projectile;

	// Maintain the state of the five keys that are recognized.
	bool q_key_down, a_key_down, w_key_down, s_key_down, e_key_down;
};

// Every InterAct2D application must have a handleEvent() function.
// This function is called whenever InterAct2D detects a system event.
// It simply passes the event to Simulation::handleEvent().
void handleEvent(Event event);

#endif
