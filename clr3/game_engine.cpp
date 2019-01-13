#include "game_engine.h"

#define TO_THE_CENTER 23;
#define FULL_FIELD_SIZE 600;
#define BLOCK_SIZE_MIN 100;
#define BLOCK_SIZE_MAX_MIN 200;

// base_object

base_object::base_object()
{
	step = -3;
	size_x = 15;
	size_y = 15;
	disactive();
}

base_object::base_object(int s)
{
	base_object();
	step = -s;
}

int base_object::get_x() { return x; }
int base_object::get_y() { return y; }
int base_object::get_size_x() { return size_x; }
int base_object::get_size_y() { return size_y; }

void base_object::set_speed(int s)
{
	step = -s;
}

void base_object::disactive()
{
	x = FULL_FIELD_SIZE;
	y = FULL_FIELD_SIZE;
}

void base_object::move()
{
	y += step;
}

void to_start_position(base_object& bullet, base_object& obj)
{
	if (bullet.step > 0)
	{
		bullet.x = obj.x + TO_THE_CENTER;
		bullet.y = obj.y + obj.get_size_x();
	}
	else
	{
		bullet.x = obj.x + TO_THE_CENTER;
		bullet.y = obj.y;
	}
}

bool collision(base_object& us, base_object& smth)
{
	return (us.x >= smth.x - us.size_x && us.x <= smth.x + smth.size_x 
	     && us.y >= smth.y - us.size_y && us.y <= smth.y + smth.size_y) ? true : false;
}

bool base_object::object_destroyed(base_object& ob)
{
	return (ob.x >= x - 15 && ob.x <= x + size_x && ob.y >= y - 7 && ob.y <= y + 7) ? true : false;
}

// object

object::object() 
{
	basic_speed = 1;
	renew();
}

void object::renew()
{
	step = basic_speed + rand() % 4;
	size_x = BLOCK_SIZE_MIN + rand() % BLOCK_SIZE_MAX_MIN;
	x = FIELD_SIZE_MIN + rand() % (FIELD_SIZE_MAX - FIELD_SIZE_MIN - size_x);
	y = FIELD_SIZE_MIN;
}

void object::set_basic_speed(int s)
{
	basic_speed = s;
}

// present

present::present()
{
	step = 2;
	size_x = 68;
	renew();
}

void present::renew()
{
	x = FIELD_SIZE_MIN + rand() % (FIELD_SIZE_MAX - FIELD_SIZE_MIN - size_x);
	y = FIELD_SIZE_MIN;
}

// player

player::player(int xx,int yy)
{
	x = xx;
	y = yy;
	step = 60;
	size_x = 60;
	size_y = 60;
}

void player::left()
{
	if (x > FIELD_SIZE_MIN)
	x -= step;
}

void player::right() 
{
	if (x < FIELD_SIZE_MAX - size_x)
	x += step;
}

void player::up() 
{
	if (y > FIELD_SIZE_MIN)
	y -= step;
}

void player::down() 
{
	if(y < FIELD_SIZE_MAX - size_y)
	y += step;
}

