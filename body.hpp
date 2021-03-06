/** Copyright 2015 Daniel Santos & Hung Nguyen
*  @file     body.hpp
*  @author   Daniel Santos & Hung Nguyen
*  @date     04/20/2016
*  @version  1.0
*
*  @brief    This file contains the namespace
*  Universe which contains the classes definition
*  for Body
* */
#ifndef BODY_HPP_
#define BODY_HPP_

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <math.h>
#include <iostream>
#include <string>
#include <vector>

#include "SpaceObject.hpp"
#include "nonCopyClass.hpp"

namespace Universe {
class Body : public SpaceObject, virtual private NonCopyClass {
 public:
  /*  @author: Hung Q Nguyen
   *	@brief: A default constructor of the Planet itself.
   *	A Planet will be inheritanced from the SpaceObject so
   *	It will have the drawable feature by itself.
   *	The job of this function will provide the global information
   *	of each planet
   *
   *	@params: int window size
   *	@note: added on 5/1
   */
  explicit Body(int window_size);

  /*
   *   @brief: Destructor of the Body object
   *   @params: none
   *   @return: none
   */
  ~Body();

  /** @author: Hung Q Nguyen
   *   @brief  Step Function to get the XOR value of the seed with space position
   *	The step() function will look for the space position on the initial seed.
   *	After that, it will generate another integer by getting the result of XOR
   *	operation of two integers, one is the value at tab position, one is the value
   *	at the end of the current seed.
   *
   *	After that, it will shift the current seed one to the left and then put the
   *	current generated value to the last position of the seed.
   *   @param  double times
   *   @return nothing
   */
  void step(double times);

  /*  @author: Hung Q Nguyen
   *	@brief: Calculating the netforce between the planet to the sun
   *	at the current times
   *
   *	@param: radius, mass of planet1, mass of planet2
   *	@return: double
   *	Edited: 4/26 -- Hung Q Nguyen
   */
  double calNetforce(double radius, double planet1_mass, double planet2_mass);

  /*  @author: Hung Q Nguyen
   *	@brief: Calculating the vector of velocity at the current time
   *	After Calculating the velocity, it will set the velocity to
   * 	the current spaceobject by calling this->setVelocity()
   *	@param: double times: -- the current time calculating
   *	@return: void -- Getting the values calculated through setter
   */
  void updateVelocity(double times);

  /**************************************
	LIST OF GETTERS AND SETTERS
  ***************************************/

  /*  @author: Hung Q Nguyen
   *   @brief: Setting value of x velocity
   *   @params: double -- value of time to cal
   *   @return: void
   **/
  void set_xVel(double xvel) {
    x_vel = xvel;
  }

  /*  @author: Hung Q Nguyen
   *   @brief: Setting value of y velocity
   *   @params: double -- value of time to cal
   *   @return: void
   **/
  void set_yVel(double yvel) {
    y_vel = yvel;
  }

  /*  @author: Hung Q Nguyen
  *   @brief: Getting value of x velocity
  *   @params: none
  *   @return: double -- value of vel
  **/
  double get_xVel() {return x_vel;}

  /*  @author: Hung Q Nguyen
   *   @brief: Getting value of y velocity
   *   @params: none
   *   @return: double -- value of vel
   **/
  double get_yVel() {return y_vel;}

  /*  @author: Hung Q Nguyen
   *   @brief: Setting value of x coordinate
   *           Used for unit test only
   *   @params: double -- value of x
   *   @return: void
   **/
  void set_xPos(double x) {
    x_pos = x;
  }

  /*  @author: Hung Q Nguyen
   *   @brief: Setting value of y coordinate
   *           Used for unit test only
   *   @params: double -- value of y
   *   @return: void
   **/
  void set_yPos(double y) {
    y_pos = y;
  }

  /*  @author: Hung Q Nguyen
  *   @brief: Getting value of x position
  *   @params: none
  *   @return: double -- value of position
  **/
  double get_xPos() {return x_pos;}

  /*  @author: Hung Q Nguyen
   *   @brief: Getting value of y position
   *   @params: none
   *   @return: double -- value of y position
   **/
  double get_yPos() {return y_pos;}

  /*  @author: Hung Q Nguyen
   *   @brief: Setting value of times
   *   @params: double -- value of times to assign
   *   @return: void
   **/
  void setTimes(double times) {times_ = times;}

  /*  @author: Hung Q Nguyen
   *   @brief: Getting the value of times
   *   @params: None
   *   @return: double -- Value of times
   */
  double getTimes() {return times_;}

  /*  @author: Hung Q Nguyen
   *   @brief: Setting value of mass
   *   @params: double -- value of mass to assign
   *   @return: void
   **/
  void setMass(float mass) {mass_ = mass;}

  /*  @author: Hung Q Nguyen
   *   @brief: Getting the value of times
   *   @params: None
   *   @return: double -- Value of times
   */
  double getMass() {return mass_;}

  /*  @author: Hung Q Nguyen
   *   @brief: Setting the texture from
   *	file name loaded from text tile.
   *   @params: none
   *   @return: none
   */
  void setBodyTexture(sf::Texture texture) {pTexture_ = texture;}

  /*  @author: Hung Q Nguyen
   *   @brief: Create the sprite from
   *	the texture;
   *   @params: none
   *   @return: none
   *	Added -- 4/26/2016
   */
  void createBodyTexture();

  /*  @author: Hung Q Nguyen
   *   @brief: Create the texture from
   *	file name loaded from text tile.
   *   @params: none
   *   @return: none
   *	Added -- 4/26/2016
   */
  void createBodySprite();

  /*  @author: Hung Q Nguyen
   *   @brief: Setting the texture from
   *	file name loaded from text tile.
   *   @params: none
   *   @return: none
   *	Added -- 4/26/2016
   */
  void setBodySprite(sf::Sprite sprite) {pSprite_ = sprite;}

  /*  @author: Hung Q Nguyen
   *   @brief: Getting the Sprite of Body
   *   @params: None
   *   @return: Sprite
   *	Added: 4/26/2016
   */
  sf::Sprite getSprite() {return pSprite_;}

  /*  @author: Hung Q Nguyen
   *   @brief: Getting the Texture of Body
   *   @params: None
   *   @return: Texture
   */
  sf::Texture getBodyTexture() {return pTexture_;}

  /*  @author: Hung Q Nguyen
   *   @brief: Getting the value of netforce
   *   @params: None
   *   @return: double -- Value of Netforce
   */
  double getNetForce() {return netForce_;}

  /*  @author: Hung Q Nguyen
   *   @brief: Getting the value of acceleration
   *   @params: None
   *   @return: sf::Vector2f -- Value of acceleration
   */
  sf::Vector2f getAcceleration() {return acceleration_;}

  /*  @author: Hung Q Nguyen
   *   @brief: Getting the value of Position
   *   @params: None
   *   @return: sf::Vector2f -- Value of Position
   */
  sf::Vector2f getPosition() { return pSprite_.getPosition();}

  /*  @author: Daniel Santos & Hung Q Nguyen
   *   @brief: Getting the name of current planet
   *   @params: None
   *   @return: std::string name
   */
  std::string getPlanetName();

  /*  @author: Hung Q Nguyen
   *   @brief: Setting the value of acceleration
   *   @params: sf::Vector2f -- Value of acceleration
   *   @return: none
   */
  void setAcceleration(double x_accel, double y_accel) {
    x_accel_ = x_accel;
    y_accel_ = y_accel;
    acceleration_ = sf::Vector2f(x_accel, y_accel);
  }

  /*  @author: Hung Q Nguyen
   *   @brief: Setting the position for sprite
   *   @params: sf::Vector2f -- Value of new position
   *   @return: none
   */
  void setSpritePosition(double x, double y) {
    pSprite_.setPosition(sf::Vector2f(x, y));
  }

  /*  @author: Hung Q Nguyen
   *   @brief: Getting the value of inital scale
   *   @params: None
   *   @return: sf::Vector2f -- Value of Scale
   *		@note: Added on 5/3
   */
  sf::Vector2f getInitScale() {
    sf::Vector2f temp = sf::Vector2f(x_pos, y_pos);
    return temp;
  }

  /*  @author: Hung Q Nguyen
   *   @brief: Calculating the center
   *   @params: none
   *   @return: file name
   *  Added -- 5/4/2016
   */
  std::string getBodyName() {return planet_name_;}

  /**
   *  @brief  This is a virtual method inherited from
   *  the sf::Drawable abstract class. SpaceObject does
   *  not implement this method, because this will work
   *  as another abstract class for other object in the
   *  project.
   *
   *  @param  sf::RenderTarget &target, sf::RenderStates states
   * */
  void draw(sf::RenderTarget& target, sf::RenderStates states) const;

  /** @author: Hung Q Nguyen
   *   @brief toString() method of SpaceObject class
   *	Overloading function will make a cast to SpaceObject class and treat
   *	object (constructor) as a string.
   *	Using to display the coordiates at the bottom of window
   *
   *   @param  output stream
   *   @return ostream&
   *	@note added on 4/30/2016
   */
  friend std::ostream& operator <<(std::ostream& out_stream,
     const Universe::Body& body) {
    out_stream << " " << body.x_pos << " ";
    out_stream << " " << body.y_pos << " ";
    out_stream << " " << body.x_vel << " ";
    out_stream << " " << body.y_vel << " ";
    out_stream << " " << body.mass_ << " ";
    out_stream << " " << body.file_name << " ";

    return out_stream;
  }

  /** @author: Hung Q Nguyen
   *   @brief input method of SpaceObject class
   *	Overloading function will make a cast to SpaceObject class and treat
   *	object (constructor) as a string.
   *	Using to display the coordiates at the bottom of window
   *
   *   @param  input stream and the current object
   *   @return istream&
   */
  friend std::istream& operator >>(std::istream& in_stream,
     Universe::Body& body) {
    in_stream >> body.x_pos
              >> body.y_pos
              >> body.x_vel
              >> body.y_vel
              >> body.mass_;
    std::string image_name;
    std::cin >> image_name;

    std::cout << body.x_vel << " " << body.y_vel << std::endl;
    body.planet_name_ = image_name;
    body.parsePlanetName();
    body.file_name = "res/" + image_name;
    body.pTexture_.loadFromFile(body.file_name);
    body.pSprite_.setTexture(body.pTexture_);

    return in_stream;
  }

  /**
   *  @author Hung Nguyen & Daniel Santos
   *  @brief  This method extract the planet name
   *  from the image name.
   * */
  void parsePlanetName();

 private:
  int wSize_;  ///< Size of the window
  double times_;  ///< Counting the time that the planet has moved

  sf::Texture pTexture_;  ///< Texture of the planet
  sf::Sprite pSprite_;  ///< Sprite of the planet
  sf::Vector2f acceleration_;  ///< the acceleration of

  // Added more variables for the need -- 4/26/2016 -- Hung Nguyen
  double x_pos, y_pos, x_vel, y_vel, mass_;
  double x_accel_, y_accel_;
  std::string file_name;  ///< Taking the name of the planet file: e.g: sun.gif
  std::string planet_name_;  ///< Taking the name of the planet
  double universe_rad;  ///< Radius of the Universe
  double netForce_;  ///< net force between planet and the Sun
  double x_center, y_center;  ///< The center of the Window
  ///< This is also the sun position
};
}  // namespace Universe

#endif  // BODY_HPP_
