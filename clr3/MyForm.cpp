#include "MyForm.h"
#define ENEMY_REACTION 170
#define BOSS_APPEARING 99
#define	PRESENT_APPEARING 25
#define BLOCK2_APPEARING 3
#define	SECS_OF_BONUS 10

using namespace System;
using namespace System::Windows::Forms;
[STAThread]

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
object white_block, red_block;
present present_box;
base_object bullet, enemy_bullet1(-3), enemy_bullet2(-3), enemy_bullet3(-3);
// 
// Players
//
player user(270, 390), enemy(270, 30);
// 
// Other
//
int score = 0, secs_of_bonus = 0; 
bool t2, t3;

clr3::MyForm::MyForm()
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

clr3::MyForm::~MyForm()
{
	if (components)
	{
		delete components;
	}
}

void clr3::MyForm ::pictureBox12_Click(System::Object^  sender, System::EventArgs^  e) 
{
	pictureBox12->Visible = false;
	startmenu->Stop();
	pictureBox14->Visible = false;
	pictureBox1->Visible = true;
	pictureBox3->Visible = true;
	white_block.renew();
	timer2->Enabled = true;
}

void clr3::MyForm::button1_Click(System::Object^  sender, System::EventArgs^  e)
{
	Application::Restart();
}

void clr3::MyForm::MyForm_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) 
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

void clr3::MyForm::timer1_Tick(System::Object^  sender, System::EventArgs^  e)
{
	pictureBox2->Location = System::Drawing::Point(bullet.get_x(), bullet.get_y());
	pictureBox2->Visible = true;
	if (bullet.get_y() >= FIELD_SIZE_MIN)
	{
		bullet.move();
		pictureBox2->Location = System::Drawing::Point(bullet.get_x(), bullet.get_y());
	}
	else {
		timer1->Enabled = false;
		pictureBox2->Visible = false;
		bullet.disactive();
	}
}

void clr3::MyForm::timer2_Tick(System::Object^  sender, System::EventArgs^  e)
{
	if (score == BLOCK2_APPEARING)
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
	if (score >= PRESENT_APPEARING && score % PRESENT_APPEARING == 0 && timer5->Enabled == false)
		timer4->Enabled = true;
	white_block.set_basic_speed(score / 30 + 1);
	red_block.set_basic_speed(score / 30 + 1);
	if (score == BOSS_APPEARING)
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

void clr3::MyForm::timer3_Tick(System::Object^  sender, System::EventArgs^  e) 
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

void clr3::MyForm::timer4_Tick(System::Object^  sender, System::EventArgs^  e)
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

void clr3::MyForm::timer5_Tick(System::Object^  sender, System::EventArgs^  e)
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

void clr3::MyForm::timer6_Tick(System::Object^  sender, System::EventArgs^  e) 
{
	if (!(bullet.get_x() + bullet.get_size_x() >= enemy.get_x() - enemy.get_size_x()
		&& bullet.get_x() <= enemy.get_x() + 2 * enemy.get_size_x() && bullet.get_y() < ENEMY_REACTION)
		|| (bullet.get_x() + bullet.get_size_x() >= enemy.get_x() && bullet.get_x() <= enemy.get_x() + enemy.get_size_x()))
		if (rand() % 2)
			enemy.left();
		else
			enemy.right();
	pictureBox8->Location = System::Drawing::Point(enemy.get_x(), enemy.get_y());
}

void clr3::MyForm::bull_cycle(base_object& enemy_bullet)
{
	if (collision(user, enemy_bullet) || collision(bullet, enemy) || collision(enemy, user))
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
		if (collision(bullet, enemy))
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

void clr3::MyForm::timer7_Tick(System::Object^  sender, System::EventArgs^  e) {
	pictureBox9->Location = System::Drawing::Point(enemy_bullet1.get_x(), enemy_bullet1.get_y());
	pictureBox10->Location = System::Drawing::Point(enemy_bullet2.get_x(), enemy_bullet2.get_y());
	pictureBox11->Location = System::Drawing::Point(enemy_bullet3.get_x(), enemy_bullet3.get_y());
	enemy_bullet1.move();
	if (t2)
		enemy_bullet2.move();
	if (enemy_bullet1.get_y() <= 292 && enemy_bullet1.get_y() >= 290)
	{
		if (!t2)
			to_start_position(enemy_bullet2, enemy);
		pictureBox10->Visible = true;
		t2 = true;
	}
	if (t3)
		enemy_bullet3.move();
	if (enemy_bullet1.get_y() <= 442 && enemy_bullet1.get_y() >= 440)
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