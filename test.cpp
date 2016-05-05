/**
 *  Copyright 2016 Hung Q. Nguyen && Daniel Santos
 *  @file    ring_buffer_test.cpp
 *  @author  Hung Q. Nguyen && Daniel Santos
 *  @date    5/3/2016
 *  @version Doxygen 1.8.11
 *  
 *  @brief Test cases to check if the universe works
 *    correctly or not.
 */

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Main
#include <boost/test/unit_test.hpp>

#include <stdint.h>
#include <iostream>
#include <string>
#include <exception>
#include <stdexcept>

#include "Universe.hpp"
#include "SpaceObject.hpp"
#include "body.hpp"

BOOST_AUTO_TEST_CASE(UniObject) {	
	// Temp list for making the universe purpose
	std::vector<Universe::Body*> temp;
	for (int i = 0; i < 5; i++) {
		Universe::Body* planet = new Universe::Body(500);
		temp.push_back(planet);
	}

	Universe::Universe uni(500000, 500, temp);

  // Check valid capacnumber_of_planetsity for the list buffer
  // the run will display universe's properties before it stops
  BOOST_REQUIRE_NO_THROW(uni.run());

  // Throw exception if peek an empty buffer
  BOOST_REQUIRE_THROW(Universe::Universe(1e12, -500, temp), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(TotalTime) {	
	// Temp list for making the universe purpose
	std::vector<Universe::Body*> temp;
	for (int i = 0; i < 5; i++) {
		Universe::Body* planet = new Universe::Body(500);
		temp.push_back(planet);
	}

	// create a universe
	Universe::Universe uni1(500000, 500, temp);

	// Check function set Totaltime running of the universe
	BOOST_REQUIRE_NO_THROW(uni1.setTotalTime(50000));

	// Check if the variable got the right value
	BOOST_REQUIRE_EQUAL(uni1.getTotalTime(), 50000);

	// it should throw is we passed in something invalid
	BOOST_REQUIRE_THROW(uni1.setTotalTime(-1), std::runtime_error);
}

BOOST_AUTO_TEST_CASE(StepTime) {	
	// Temp list for making the universe purpose
	std::vector<Universe::Body*> temp;
	for (int i = 0; i < 5; i++) {
		Universe::Body* planet = new Universe::Body(500);
		temp.push_back(planet);
	}

	// create a universe
	Universe::Universe uni2(500000, 500, temp);

	// Check function set Totaltime running of the universe
	BOOST_REQUIRE_NO_THROW(uni2.setTotalTime(150000));
	BOOST_REQUIRE_NO_THROW(uni2.setStepTime(50000));

	// Check if the variable got the right value
	BOOST_REQUIRE_EQUAL(uni2.getStepTime(), 50000);

	// it should throw is we passed in something invalid, such as
	// step time is negative
	BOOST_REQUIRE_THROW(uni2.setStepTime(-1), std::runtime_error);
	// or steptime is greater than totaltime
	BOOST_REQUIRE_THROW(uni2.setStepTime(150001), std::runtime_error);
}

BOOST_AUTO_TEST_CASE(StepFunction) {	
	// Temp list for making the universe purpose
	std::vector<Universe::Body*> temp;
	for (int i = 0; i < 5; i++) {
		Universe::Body* planet = new Universe::Body(500);
		temp.push_back(planet);
	}

	// create a universe
	Universe::Universe uni3(500000, 500, temp);

	// Setting up the universe
	uni3.setTotalTime(1000000);
	uni3.setStepTime(1000);

	// Getting the first body
	std::vector<Universe::Body*>::iterator firstBody = temp.begin();
	// Set initial position
 	(*firstBody)->set_xPos(0);
  (*firstBody)->set_yPos(0);
	// Set velocity
	(*firstBody)->set_xVel(500);
	(*firstBody)->set_yVel(500);

	// Now call the step
	(*firstBody)->step(1000);

	// Now check the results after step
	// Check if the variable got the right value
	BOOST_REQUIRE_EQUAL((*firstBody)->get_xPos(), 500000);
	BOOST_REQUIRE_EQUAL((*firstBody)->get_yPos(), -500000);
}