/*!
\file 
\brief Файл реализации основных функций и методов
\author Solomonov

Данный файл содержит в себе реализации функции и методов класса, объявленного в файле MyForm.h.
*/
#include "MyForm.h"
#define ENEMY_REACTION			170
#define BOSS_APPEARING_SCORE	99
#define	PRESENT_APPEARING_SCORE 25
#define BLOCK2_APPEARING_SCORE	3
#define	SECS_OF_BONUS			10
#define	ENEMY_BULLET_SPEED		-3
#define	ENEMY_BULLET2_START		290
#define	ENEMY_BULLET3_START		440

using namespace System;
using namespace System::Windows::Forms;
[STAThread]

/**
 * @brief      Функция вызывающая выполнение формы. Точка входа в программу.
 *
 * @param[in]  args  аргументы командной строки 
 */
void main(array<String^>^ args) 
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	clr3::MyForm form;
	Application::Run(%form);
}
// 
// Objects
//
object white_block; ///< Белый падающий блок
object red_block; ///< Красный падающий блок
present 	present_box; ///< Подарок
base_object bullet; ///< Пуля игрока
base_object enemy_bullet1(ENEMY_BULLET_SPEED); ///< Пуля босса 1
base_object enemy_bullet2(ENEMY_BULLET_SPEED); ///< Пуля босса 2
base_object	enemy_bullet3(ENEMY_BULLET_SPEED); ///< Пуля босса 3
// 
// Players
//
player 	user(270, 390);///< Игрок
player	enemy(270, 30);///< Босс
// 
// Other
//
int score = 0; ///< Счёт
int secs_of_bonus = 0; ///< Секунд бонуса
bool t2; ///< Условие запуска второй пули босса
bool t3; ///< Условие запуска третьей пули босса

using namespace clr3;
/**
 * @brief      Коструктор формы Windows Forms
 */
MyForm::MyForm()
{
	InitializeComponent();
	sound1->SoundLocation = "sounds\\Sound.wav";
	die->SoundLocation = "sounds\\smb_mariodie.wav";
	powerup->SoundLocation = "sounds\\smb_powerup.wav";
	stage_clear->SoundLocation = "sounds\\smb_stage_clear.wav";
	coin->SoundLocation = "sounds\\smb_bump.wav";
	startmenu->SoundLocation = "sounds\\start.wav";
	startmenu->PlayLooping();
}
/**
 * @brief      Деструктор формы Windows Forms
 */
MyForm::~MyForm()
{
	if (components)
	{
		delete components;
	}
}

/**
 * @brief      Функция обработчик нажатия на картинку 
 *
 * @param[in]  sender	объект, вызывающий обработчик 
 * @param[in]  e	аргумент обработчика 
 */
void MyForm ::pictureBox12_Click(System::Object^  sender, System::EventArgs^  e) 
{
	pictureBox12->Visible = false;
	startmenu->Stop();
	pictureBox14->Visible = false;
	pictureBox1->Visible = true;
	pictureBox3->Visible = true;
	white_block.renew();
	timer2->Enabled = true;
}

/**
 * @brief      Функция обработчик нажатия на кнопку 
 *
 * @param[in]  sender	объект, вызывающий обработчик 
 * @param[in]  e	аргумент обработчика 
 */
void MyForm::button1_Click(System::Object^  sender, System::EventArgs^  e)
{
	Application::Restart();
}

/**
 * @brief      Функция обработчик нажатия на клавишу клавиатуры 
 *
 * @param[in]  sender	объект, вызывающий обработчик 
 * @param[in]  e	аргумент обработчика 
 */
void MyForm::MyForm_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) 
{
	switch (e->KeyValue)
	{
	case 38: user.up();		 break;
	case 40: user.down();	 break;
	case 37: user.left();	 break;
	case 39: user.right();	 break;
	case 32:
		if (!timer1->Enabled)
		{
			to_start_position(bullet, user);
			timer1->Enabled = true;
		}
		break;
	default: break;
	}
	this->pictureBox1->Location = System::Drawing::Point(user.get_x(), user.get_y());
}

/**
 * @brief       Функция таймер. Отвечает за цикл движения пули 
 *
 * @param[in]  sender   объект, вызывающий обработчик 
 * @param[in]  e   аргумент обработчика 
 */
void MyForm::timer1_Tick(System::Object^  sender, System::EventArgs^  e)
{
	pictureBox2->Location = System::Drawing::Point(bullet.get_x(), bullet.get_y());
	pictureBox2->Visible = true;
	if (bullet.get_y() >= FIELD_SIZE_MIN)
	{
		bullet.move();
		pictureBox2->Location = System::Drawing::Point(bullet.get_x(), bullet.get_y());
	}
	else
	{
		timer1->Enabled = false;
		pictureBox2->Visible = false;
		bullet.disactive();
	}
}

/**
 * @brief       Функция таймер. Отвечает за цикл движение белого блока, подсчет очков, 
 * 				появление подарков и босса, а также проверка на стоклконвение с блоками 
 * 
 * @param[in]  sender   объект, вызывающий обработчик 
 * @param[in]  e   аргумент обработчика 
 */
void MyForm::timer2_Tick(System::Object^  sender, System::EventArgs^  e)
{
	if (score == BLOCK2_APPEARING_SCORE)
	{
		timer3->Enabled = true;
		pictureBox4->Visible = true;
	}
	pictureBox3->Location = System::Drawing::Point(white_block.get_x(), white_block.get_y());
	pictureBox3->Size = System::Drawing::Size(white_block.get_size_x(), white_block.get_size_y());
	white_block.move();
	if (collision(white_block, bullet))
	{
		score++;
		coin->Play();
	}
	if (white_block.get_y() >= FIELD_SIZE_MAX || collision(white_block, bullet))
	{
		white_block.renew();
	}
	if (collision(user, white_block) || collision(user, red_block))
	{
		die->Play();
		pictureBox13->Visible = true;
		timer2->Enabled = false;
		timer3->Enabled = false;
		button1->Enabled = true;
		button1->Visible = true;
	}
	this->Text = "Score: " + Convert::ToString(score);
	if (score >= PRESENT_APPEARING_SCORE && score % PRESENT_APPEARING_SCORE == 0 && timer5->Enabled == false)
		timer4->Enabled = true;
	white_block.set_basic_speed(score / 30 + 1);
	red_block.set_basic_speed(score / 30 + 1);
	if (score == BOSS_APPEARING_SCORE)
	{
		sound1->PlayLooping();
		timer2->Enabled = false;
		pictureBox3->Visible = false;
		timer3->Enabled = false;
		pictureBox4->Visible = false;
		timer6->Enabled = true;
		timer7->Enabled = true;
		pictureBox8->Visible = true;
		pictureBox9->Visible = true;
		to_start_position(enemy_bullet1, enemy);
		pictureBox8->Location = System::Drawing::Point(enemy.get_x(), enemy.get_y());
	}
}

/**
 * @brief       Функция таймер. Отвечает за цикл движения красного блока 
 *
 * @param[in]  sender   объект, вызывающий обработчик 
 * @param[in]  e   аргумент обработчика 
 */
void MyForm::timer3_Tick(System::Object^  sender, System::EventArgs^  e) 
{
	pictureBox4->Location = System::Drawing::Point(red_block.get_x(), red_block.get_y());
	pictureBox4->Size = System::Drawing::Size(red_block.get_size_x(), red_block.get_size_y());
	red_block.move();
	if (red_block.get_y() >= FIELD_SIZE_MAX || (collision(red_block, bullet)))
	{
		if (collision(red_block, bullet))
		{
			score++;
			coin->Play();
			timer1->Enabled = false;
			pictureBox2->Visible = false;
			bullet.disactive();
		}
		red_block.renew();
	}
}

/**
 * @brief       Функция таймер. Отвечает за цикл движения подарка 
 *
 * @param[in]  sender   объект, вызывающий обработчик 
 * @param[in]  e   аргумент обработчика 
 */
void MyForm::timer4_Tick(System::Object^  sender, System::EventArgs^  e)
{
	pictureBox6->Location = System::Drawing::Point(present_box.get_x(), present_box.get_y());
	pictureBox6->Visible = true;
	present_box.move();
	if (present_box.get_y() >= FIELD_SIZE_MAX || (collision(user, present_box)))
	{
		if (collision(user, present_box))
		{
			timer4->Enabled = false;
			pictureBox6->Visible = false;
			timer5->Enabled = true;
			powerup->Play();
		}
		present_box.renew();
	}
}

/**
 * @brief       Функция таймер. Отвечает за бонус, полученный в подарке 
 *
 * @param[in]  sender   объект, вызывающий обработчик 
 * @param[in]  e   аргумент обработчика 
 */
void MyForm::timer5_Tick(System::Object^  sender, System::EventArgs^  e)
{
	if (secs_of_bonus <= SECS_OF_BONUS)
	{
		pictureBox7->Visible = true;
		bullet.set_speed(6);
		secs_of_bonus++;
	}
	else
	{
		pictureBox7->Visible = false;
		bullet.set_speed(3);
		secs_of_bonus = 0;
		timer5->Enabled = false;
	}
}

/**
 * @brief        Функция таймер. Отвечает за движение босса 
 *
 * @param[in]  sender   объект, вызывающий обработчик 
 * @param[in]  e   аргумент обработчика 
 */
void MyForm::timer6_Tick(System::Object^  sender, System::EventArgs^  e) 
{
	if (!(bullet.get_x() + bullet.get_size_x() >= enemy.get_x() - enemy.get_size_x()
		&& bullet.get_x() <= enemy.get_x() + 2 * enemy.get_size_x() 
		&& bullet.get_y() < ENEMY_REACTION) 
		|| (bullet.get_x() + bullet.get_size_x() >= enemy.get_x() 
		&& bullet.get_x() <= enemy.get_x() + enemy.get_size_x()))
		if (rand() % 2)
			enemy.left();
		else
			enemy.right();
	pictureBox8->Location = System::Drawing::Point(enemy.get_x(), enemy.get_y());
}

/**
 * @brief       Функция обрабатывающая все события, которые могут произойти с любой 
 * 				пулей при игре против босса
 *
 * @param      enemy_bullet  Пуля
 */
void MyForm::bull_cycle(base_object& enemy_bullet)
{
	if (collision(user, enemy_bullet) || collision(enemy, bullet) || collision(enemy, user))
	{
		pictureBox2->Visible = false;
		timer6->Enabled = false;
		timer7->Enabled = false;
		button1->Enabled = true;
		button1->Visible = true;
		sound1->Stop();
		if (collision(user, enemy_bullet) || collision(enemy, user))
		{
			die->Play();
			pictureBox13->Visible = true;
		}
		if (collision(enemy, bullet))
			stage_clear->Play();
	}
	if (enemy_bullet.get_y() >= FIELD_SIZE_MAX || (collision(enemy_bullet, bullet)))
	{
		if (collision(enemy_bullet, bullet))
		{
			timer1->Enabled = false;
			pictureBox2->Visible = false;
			bullet.disactive();
		}
		to_start_position(enemy_bullet, enemy);
	}
}

/**
 * @brief       Функция таймер. Отвечает за стрельбу босса 
 *
* @param[in]  sender   объект, вызывающий обработчик 
 * @param[in]  e   аргумент обработчика 
 */
void MyForm::timer7_Tick(System::Object^  sender, System::EventArgs^  e) 
{
	pictureBox9->Location = System::Drawing::Point(enemy_bullet1.get_x(), enemy_bullet1.get_y());
	pictureBox10->Location = System::Drawing::Point(enemy_bullet2.get_x(), enemy_bullet2.get_y());
	pictureBox11->Location = System::Drawing::Point(enemy_bullet3.get_x(), enemy_bullet3.get_y());
	enemy_bullet1.move();
	if (t2)
		enemy_bullet2.move();
	if (enemy_bullet1.get_y() >= ENEMY_BULLET2_START)
	{
		if (!t2)
			to_start_position(enemy_bullet2, enemy);
		pictureBox10->Visible = true;
		t2 = true;
	}
	if (t3)
		enemy_bullet3.move();
	if (enemy_bullet1.get_y() >= ENEMY_BULLET3_START)
	{
		if (!t3)
			to_start_position(enemy_bullet3, enemy);
		pictureBox11->Visible = true;
		t3 = true;
	}
	bull_cycle(enemy_bullet1);
	bull_cycle(enemy_bullet2);
	bull_cycle(enemy_bullet3);
}