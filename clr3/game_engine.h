/*!
\file 
\brief Заголовочный файл с описанием классов
\author Solomonov

Данный файл содержит в себе определения интерфейсов классов, используемых в программе. 
Объявлены переменные и прототипы методов классов.
*/
#pragma once
#include <cstdlib>
#define FIELD_SIZE_MAX 570
#define FIELD_SIZE_MIN 30

/**
 * @brief      Базовый класс. Class for base object.
 * 
 *  Базовый класс для классов object, object, player.
 *  Пули, т.е. bullet, enemy_bullet и т.д. являются объектами этого класса.
 */
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

/**
 * @brief      Дочерний класс. Class for object.
 * 
 * Дочерний класс, который отнаследован от ранее созданного класса base_object.
 * Блоки white_block, red_block являются объектами этого класса.
 */
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

/**
 * @brief      Дочерний класс. Class for present.
 * 
 * Дочерний класс, который отнаследован от ранее созданного класса base_object.
 * Подарок present_box  является объектами этого класса.
 */
class present : public base_object
{
public:
	present();
	~present() {}
	void renew();
};

/**
 * @brief      Дочерний класс. Class for player.
 * 
 * Дочерний класс, который отнаследован от ранее созданного класса base_object.
 * Игроки user и enemy  является объектами этого класса.
 */
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


