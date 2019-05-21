#include "car.h"

car::car()
{
	x = float(Graphics::ScreenWidth / 2);
	y = float(Graphics::ScreenHeight / 2);
	theta = 45.0f*M_PI / 180.0f;
	vx = vy = 0.0f;
	v = 0.0f;
	ax = 11.1f;
	ay = 0.0f;
	braking_a = 0.5f;
	mass = 10.0f;
	g = 9.8f;
	coeff_friction_static = 0.4f;
	coeff_friction_kinetic = 0.25f;
	ang_v = 0.05f;

}

void car::move_car(float distance)
{
	x += distance * cos(theta);
	y += distance * sin(theta);
}

void car::move_car()
{
	x += v * cos(theta);
	y += v * sin(theta);
}

void car::rotate(float del_theta)
{
	theta += del_theta;
}

void car::display_car(Graphics& gfx)
{
	float y_i, x_j;
	float xr, yr;
	for (int i = int(y-2); i < int(y+5); i++)
	{
		for (int j = int(x - 1); j <= x + 1; j++)
		{
			y_i = y - i;							// i - y axis
			x_j = j - x;							// j - x- axis

			xr = x_j * cos((theta-M_PI/2)) + y_i * sin((theta-M_PI/2));
			yr = -x_j * sin((theta-M_PI/2)) + y_i * cos((theta-M_PI/2));

			y_i = y - yr;
			x_j = x + xr;
			
			gfx.PutPixel(int(x_j),int (y_i), 255, 255, 255);
		}
	}
	int c = 1;
	for (int i = int(y - 5); i < int(y -1); i++,c++)
	{
		for (int j = int(x - c + 1); j<int(x + c); j++)
		{
			y_i = y - i;							// i - y axis
			x_j = j - x;							// j - x- axis

			xr = x_j * cos((theta-M_PI/2)) + y_i * sin((theta-M_PI/2));
			yr = -x_j * sin((theta-M_PI/2)) + y_i * cos((theta-M_PI/2));

			y_i = y - yr;
			x_j = x + xr;

			gfx.PutPixel(int(x_j), int(y_i), 255, 255, 255);
		}
	}
}

void car::up()
{
	v -= ax;
}

void car::down()
{
	if (fabs(v) >= fabs(braking_a))
	{
		if (v > 0)
		{
			v = v - braking_a;
		}
		else
			v = v + braking_a;
	}
	else
	{
		v = 0;
	}
}

void car::left()
{
	rotate(ang_v);
}

void car::right()
{
	rotate(-ang_v);
}

void car::reorient()
{
	if (y > (float(Graphics::ScreenHeight)) * 88 / 100)
	{
		y = 7;
	}
	if (y < 7)
	{
		y = (float(Graphics::ScreenHeight)) * 88 / 100;
	}

	if (x > (float(Graphics::ScreenWidth)) * 88 / 100)
	{
		x = 7;
	}
	if (x < 7)
	{
		x = (float(Graphics::ScreenWidth)) * 88 / 100;
	}
}
