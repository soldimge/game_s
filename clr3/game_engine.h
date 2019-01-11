#pragma once
#include <cstdlib>
#include <string>

class base_object 
{
protected:
	int step, x, y, size_y;
public:
	base_object();
	base_object(int);
	~base_object() {}
	void move();
	void set_speed(int);
	void disactive();
	int get_x();
	int get_y();
	int get_size_y();
	bool object_destroyed(base_object&);
	friend void fire(base_object&, base_object&);
	friend bool block_collision(base_object&, base_object&);
	friend bool box_collision(base_object&, base_object&);
	friend void set_start_position(base_object&, base_object&);
};

class object : public base_object
{
private: 
	int basic_speed;
public: 
	object();
	~object() {}
	void renew();
	void set_basic_speed(int);
};

class present : public base_object
{
public:
	present();
	~present() {}
	void renew();
};

class player : public base_object
{
public:
	player(int,int);
	~player() {}
	void left();
	void right();
	void up();
	void down();
	bool is_m_in_field(int&);
	bool is_p_in_field(int&);
};


