#include "game_engine.h"

// base_object

base_object::base_object()
{
	disactive();
}

void base_object::set_speed(int s)
{
	step = -s;
}
void base_object::disactive()
{
	x = 600;
	y = 600;
	step = -3;
}
void fire(base_object& bullet, base_object& user)
{
	bullet.x = user.x + 23; 
	bullet.y = user.y + 5;
}

void base_object::move()
{
	y += step;
}
void set_start_position(base_object& bullet, base_object& obj)
{
	bullet.x = obj.x + 23;
	bullet.y = obj.y + 60;
}
int base_object::get_x() { return x; }
int base_object::get_y() { return y; }
int base_object::get_size_y() { return size_y; }

bool block_collision(base_object& pl, base_object& ob)
{
	return (pl.x >= ob.x - 59 && pl.x <= ob.x + ob.size_y && pl.y >= ob.y - 45 && pl.y <= ob.y + 12) ? true : false;
}

bool box_collision(base_object& us, base_object& smth)
{
	return (us.x >= smth.x - 59 && us.x <= smth.x + smth.size_y && us.y >= smth.y - 45 && us.y <= smth.y + 68) ? true : false;
}

bool top_collision(base_object& us, base_object& smth)
{
	return (us.x >= smth.x - 59 && us.x <= smth.x + smth.size_y && us.y >= smth.y - 60 && us.y <= smth.y ) ? true : false;
}

bool base_object::object_destroyed(base_object& ob)
{
	return (ob.x >= x - 15 && ob.x <= x + size_y && ob.y >= y - 7 && ob.y <= y + 7) ? true : false;
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
	x = rand() % 400;
	y = 10;
	size_y = 100 + rand() % 200;
}

void object::set_basic_speed(int s)
{
	basic_speed = s;
}

// present

present::present()
{
	renew();
}

void present::renew()
{
	step = 2;
	x = 30 + rand() % 450;
	y = 10;
	size_y = 68;
}

//player

player::player()
{
	x = 270;
	y = 270;
	step = 60;
	size_y = 60;
}

player::player(int xx,int yy)
{
	x = xx;
	y = yy;
	step = 60;
	size_y = 60;
}

void player::left()
{
	if (is_m_in_field(x))
	x -= step;
}

void player::right() 
{
	if (is_p_in_field(x))
	x += step;
}

void player::up() 
{
	if (is_m_in_field(y))
	y -= step;
}

void player::down() 
{
	if(is_p_in_field(y))
	y += step;
}

bool player::is_m_in_field(int &xy)
{
	return (xy > 30 && xy <= 510) ? true : false;
}

bool player::is_p_in_field(int &xy)
{
	return (xy >= 30 && xy < 510) ? true : false;
}

//enemy_bull

enemy_bull::enemy_bull()
{
	size_y = 15;
	base_object();
}
