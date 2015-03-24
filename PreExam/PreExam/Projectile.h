#include "Point2d.h"

#ifndef _Projectile_H_
#define _Projectile_H_


class Projectile
{
public:
	float pos_x, pos_y;
	float vel_x, vel_y;

	//Constructor
	Projectile(){ pos_x = pos_y = vel_x = vel_y = 0; }

	//destructor
	~Projectile(){}

	//
	
	 Point2d<float> GetCurrentPosition(unsigned int time)
	{
		Point2d<float> result;

		result.x = pos_x + (vel_x * time);
		result.y = pos_y + (vel_y * time);

		return result;
	}

	
	

};


#endif _Projectile_H_