#pragma once
#include <cstdlib>
#define FIELD_SIZE_MAX 570
#define FIELD_SIZE_MIN 30

class base_object 
{
protected:
	int step;
	int x;
	int y;
	int size_x;
	int size_y;
public:
	base_object();
	base_object(int);
	~base_object() {}
	int get_x();
	int get_y();
	int get_size_x();
	int get_size_y();
	void set_speed(int);
	void disactive();
	void move();
	friend bool collision(base_object&, base_object&);
	friend void to_start_position(base_object&, base_object&);
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
};


