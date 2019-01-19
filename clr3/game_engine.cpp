/*!
\file 
\brief Файл реализации методов классов
\author Solomonov

Данный файл содержит в себе реализации методов классов, объявленных в файле game_engine.h.
*/
#include "game_engine.h"

#define TO_THE_CENTER	23
#define OUT_OF_FIELD	600
#define BLOCK_SIZE_MIN	100
#define BLOCK_SIZE_MAX	300
#define SPEED_RANGE		4

// base_object

/**
 * @brief      Коструктор объекта
 */
base_object::base_object()
{
	step = -3;
	size_x = 15;
	size_y = 15;
	disactive();
}

/**
 * @brief      Коструктор объекта
 *
 * @param[in]  s     Шаг
 */
base_object::base_object(int s) : base_object()
{
	step = -s;
}

/**
 * @brief      Функция получения координаты X объекта.
 *
 * @return     Координата X объекта.
 */
int base_object::get_x() { return x; }

/**
 * @brief      Функция получения координаты Y объекта.
 *
 * @return     Координата Y объекта.
 */
int base_object::get_y() { return y; }

/**
 * @brief      Функция получения ширины объекта.
 *
 * @return     Ширина объекта.
 */
int base_object::get_size_x() { return size_x; }

/**
 * @brief      Функция получения высоты объекта.
 *
 * @return     Высота объекта.
 */
int base_object::get_size_y() { return size_y; }

/**
 * @brief      Функция установки шага(скорости)
 *
 * @param[in]  s     Шаг
 */
void base_object::set_speed(int s)
{
	step = -s;
}

/**
 * @brief      Функция делает объект неактивным (присваивает координаты, 
 * 				находящиеся вне игрового поля)
 */
void base_object::disactive()
{
	x = OUT_OF_FIELD;
	y = OUT_OF_FIELD;
}

/**
 * @brief       Функция движения объекта 
 */
void base_object::move()
{
	y += step;
}

/**
 * @brief       Функция установки объекта (пули) на стартовую позицию 
 *
 * @param      bullet  Пуля
 * @param      obj     Объект владелец пули
 */
void to_start_position(base_object& bullet, base_object& obj)
{
	bullet.x = obj.x + TO_THE_CENTER;
	if (bullet.step > 0)
		bullet.y = obj.y + obj.get_size_x();
	else
		bullet.y = obj.y;
}

/**
 * @brief       Функция проверки на столкновение между объектами
 *
 * @param      us    объект 1
 * @param      smth  объект 2
 *
 * @return      true - если столкновение, false - при его отсутвии 
 */
bool collision(base_object& us, base_object& smth)
{
	return (us.x >= smth.x - us.size_x && us.x <= smth.x + smth.size_x 
	     && us.y >= smth.y - us.size_y && us.y <= smth.y + smth.size_y-smth.step) ? true : false;
}

// object

/**
 * @brief      Коструктор объекта
 */
object::object() : base_object()
{
	basic_speed = 1;
}

/**
 * @brief       Функция запуска блока с новыми параметрами 
 */
void object::renew()
{
	step = basic_speed + rand() % SPEED_RANGE;
	size_x = BLOCK_SIZE_MIN + rand() % (BLOCK_SIZE_MAX - BLOCK_SIZE_MIN);
	x = FIELD_SIZE_MIN + rand() % (FIELD_SIZE_MAX - FIELD_SIZE_MIN - size_x);
	y = FIELD_SIZE_MIN;
}

/**
 * @brief      Функция установки базовой скорости
 *
 * @param[in]  s      Базовая скорость блока 
 */
void object::set_basic_speed(int s)
{
	basic_speed = s;
}

// present

/**
 * @brief      Коструктор объекта
 */
present::present()
{
	step = 2;
	size_x = 68;
	size_y = 68;
	renew();
}

/**
 * @brief        Функция запуска подарка с новыми параметрами 
 */
void present::renew()
{
	x = FIELD_SIZE_MIN + rand() % (FIELD_SIZE_MAX - FIELD_SIZE_MIN - size_x);
	y = FIELD_SIZE_MIN;
}

// player

/**
 * @brief      Коструктор объекта 
 *
 * @param[in]  xx     Стартовая координата X 
 * @param[in]  yy     Стартовая координата Y 
 */
player::player(int xx,int yy)
{
	x = xx;
	y = yy;
	step = 60;
	size_x = 60;
	size_y = 60;
}

/**
 * @brief       Функция движения влево 
 */
void player::left()
{
	if (x > FIELD_SIZE_MIN)
	{
		x -= step;
	}
}

/**
 * @brief       Функция движения вправо 
 */
void player::right() 
{
	if (x < FIELD_SIZE_MAX - size_x)
	{
		x += step;
	}
}

/**
 * @brief       Функция движения вверх 
 */
void player::up() 
{
	if (y > FIELD_SIZE_MIN)
	{
		y -= step;
	}
}

/**
 * @brief      Функция движения вниз 
 */
void player::down() 
{
	if(y < FIELD_SIZE_MAX - size_y)
	{
		y += step;
	}
}

