#pragma once
#include "game_engine.h"
// 
// Objects
//
object white_block, red_block;
present present_box;
base_object bullet, enemy_bullet1(-3), enemy_bullet2(-3), enemy_bullet3(-3);
// 
// Players
//
player user(270, 330),enemy(270,30);

namespace clr3 {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	System::Media::SoundPlayer^ sound1 = gcnew System::Media::SoundPlayer();
	System::Media::SoundPlayer^ die = gcnew System::Media::SoundPlayer();
	System::Media::SoundPlayer^ powerup = gcnew System::Media::SoundPlayer();
	System::Media::SoundPlayer^ stage_clear = gcnew System::Media::SoundPlayer();
	System::Media::SoundPlayer^ coin = gcnew System::Media::SoundPlayer();
	
	private: System::Windows::Forms::PictureBox^  pictureBox2;
	private: System::Windows::Forms::Timer^  timer1;
	private: System::Windows::Forms::Timer^  timer2;
	private: System::Windows::Forms::PictureBox^  pictureBox3;
	private: System::Windows::Forms::PictureBox^  pictureBox4;
	private: System::Windows::Forms::Timer^  timer3;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::PictureBox^  pictureBox5;
	private: System::Windows::Forms::Timer^  timer4;
	private: System::Windows::Forms::PictureBox^  pictureBox6;
	private: System::Windows::Forms::PictureBox^  pictureBox7;
	private: System::Windows::Forms::Timer^  timer5;
	private: System::Windows::Forms::PictureBox^  pictureBox8;
	private: System::Windows::Forms::PictureBox^  pictureBox9;
	private: System::Windows::Forms::Timer^  timer6;
	private: System::Windows::Forms::Timer^  timer7;
	private: System::Windows::Forms::PictureBox^  pictureBox10;
	private: System::Windows::Forms::PictureBox^  pictureBox11;

	private: System::Windows::Forms::Button^  button2;

	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
			sound1->SoundLocation = "Sound.wav";
			die->SoundLocation = "smb_mariodie.wav";
			powerup->SoundLocation = "smb_powerup.wav";
			stage_clear->SoundLocation = "smb_stage_clear.wav";
			coin->SoundLocation = "smb_bump.wav";
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	protected:

	protected:
	private: System::ComponentModel::IContainer^  components;

	protected:

	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->timer2 = (gcnew System::Windows::Forms::Timer(this->components));
			this->pictureBox3 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox4 = (gcnew System::Windows::Forms::PictureBox());
			this->timer3 = (gcnew System::Windows::Forms::Timer(this->components));
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->pictureBox5 = (gcnew System::Windows::Forms::PictureBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->timer4 = (gcnew System::Windows::Forms::Timer(this->components));
			this->pictureBox6 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox7 = (gcnew System::Windows::Forms::PictureBox());
			this->timer5 = (gcnew System::Windows::Forms::Timer(this->components));
			this->pictureBox8 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox9 = (gcnew System::Windows::Forms::PictureBox());
			this->timer6 = (gcnew System::Windows::Forms::Timer(this->components));
			this->timer7 = (gcnew System::Windows::Forms::Timer(this->components));
			this->pictureBox10 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox11 = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox5))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox6))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox7))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox8))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox9))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox10))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox11))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(270, 330);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(60, 60);
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			// 
			// pictureBox2
			// 
			this->pictureBox2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.Image")));
			this->pictureBox2->Location = System::Drawing::Point(600, 600);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(15, 15);
			this->pictureBox2->TabIndex = 1;
			this->pictureBox2->TabStop = false;
			this->pictureBox2->Visible = false;
			// 
			// timer1
			// 
			this->timer1->Interval = 10;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// timer2
			// 
			this->timer2->Interval = 10;
			this->timer2->Tick += gcnew System::EventHandler(this, &MyForm::timer2_Tick);
			// 
			// pictureBox3
			// 
			this->pictureBox3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox3.Image")));
			this->pictureBox3->Location = System::Drawing::Point(207, 12);
			this->pictureBox3->Name = L"pictureBox3";
			this->pictureBox3->Size = System::Drawing::Size(187, 15);
			this->pictureBox3->TabIndex = 2;
			this->pictureBox3->TabStop = false;
			this->pictureBox3->Visible = false;
			// 
			// pictureBox4
			// 
			this->pictureBox4->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox4.Image")));
			this->pictureBox4->Location = System::Drawing::Point(207, 52);
			this->pictureBox4->Name = L"pictureBox4";
			this->pictureBox4->Size = System::Drawing::Size(187, 15);
			this->pictureBox4->TabIndex = 3;
			this->pictureBox4->TabStop = false;
			this->pictureBox4->Visible = false;
			// 
			// timer3
			// 
			this->timer3->Interval = 10;
			this->timer3->Tick += gcnew System::EventHandler(this, &MyForm::timer3_Tick);
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->button1->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button1->Enabled = false;
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->button1->Font = (gcnew System::Drawing::Font(L"Forte", 26.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->ForeColor = System::Drawing::SystemColors::MenuHighlight;
			this->button1->Location = System::Drawing::Point(206, 184);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(187, 68);
			this->button1->TabIndex = 4;
			this->button1->Text = L"play again";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Visible = false;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// pictureBox5
			// 
			this->pictureBox5->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox5.Image")));
			this->pictureBox5->Location = System::Drawing::Point(206, 586);
			this->pictureBox5->Name = L"pictureBox5";
			this->pictureBox5->Size = System::Drawing::Size(182, 13);
			this->pictureBox5->TabIndex = 5;
			this->pictureBox5->TabStop = false;
			// 
			// button2
			// 
			this->button2->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button2->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->button2->Font = (gcnew System::Drawing::Font(L"Forte", 26.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button2->Location = System::Drawing::Point(206, 390);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(187, 80);
			this->button2->TabIndex = 6;
			this->button2->Text = L"Start";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// timer4
			// 
			this->timer4->Interval = 10;
			this->timer4->Tick += gcnew System::EventHandler(this, &MyForm::timer4_Tick);
			// 
			// pictureBox6
			// 
			this->pictureBox6->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox6.Image")));
			this->pictureBox6->Location = System::Drawing::Point(440, 12);
			this->pictureBox6->Name = L"pictureBox6";
			this->pictureBox6->Size = System::Drawing::Size(68, 68);
			this->pictureBox6->TabIndex = 7;
			this->pictureBox6->TabStop = false;
			this->pictureBox6->Visible = false;
			// 
			// pictureBox7
			// 
			this->pictureBox7->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox7.Image")));
			this->pictureBox7->Location = System::Drawing::Point(192, 161);
			this->pictureBox7->Name = L"pictureBox7";
			this->pictureBox7->Size = System::Drawing::Size(336, 223);
			this->pictureBox7->TabIndex = 8;
			this->pictureBox7->TabStop = false;
			this->pictureBox7->Visible = false;
			// 
			// timer5
			// 
			this->timer5->Interval = 1000;
			this->timer5->Tick += gcnew System::EventHandler(this, &MyForm::timer5_Tick);
			// 
			// pictureBox8
			// 
			this->pictureBox8->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox8.Image")));
			this->pictureBox8->Location = System::Drawing::Point(270, 30);
			this->pictureBox8->Name = L"pictureBox8";
			this->pictureBox8->Size = System::Drawing::Size(60, 60);
			this->pictureBox8->TabIndex = 9;
			this->pictureBox8->TabStop = false;
			this->pictureBox8->Visible = false;
			// 
			// pictureBox9
			// 
			this->pictureBox9->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox9.Image")));
			this->pictureBox9->Location = System::Drawing::Point(292, 99);
			this->pictureBox9->Name = L"pictureBox9";
			this->pictureBox9->Size = System::Drawing::Size(15, 15);
			this->pictureBox9->TabIndex = 10;
			this->pictureBox9->TabStop = false;
			this->pictureBox9->Visible = false;
			// 
			// timer6
			// 
			this->timer6->Interval = 300;
			this->timer6->Tick += gcnew System::EventHandler(this, &MyForm::timer6_Tick);
			// 
			// timer7
			// 
			this->timer7->Interval = 10;
			this->timer7->Tick += gcnew System::EventHandler(this, &MyForm::timer7_Tick);
			// 
			// pictureBox10
			// 
			this->pictureBox10->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox10.Image")));
			this->pictureBox10->Location = System::Drawing::Point(292, 121);
			this->pictureBox10->Name = L"pictureBox10";
			this->pictureBox10->Size = System::Drawing::Size(15, 15);
			this->pictureBox10->TabIndex = 11;
			this->pictureBox10->TabStop = false;
			this->pictureBox10->Visible = false;
			// 
			// pictureBox11
			// 
			this->pictureBox11->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox11.Image")));
			this->pictureBox11->Location = System::Drawing::Point(292, 140);
			this->pictureBox11->Name = L"pictureBox11";
			this->pictureBox11->Size = System::Drawing::Size(15, 15);
			this->pictureBox11->TabIndex = 12;
			this->pictureBox11->TabStop = false;
			this->pictureBox11->Visible = false;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->ClientSize = System::Drawing::Size(600, 600);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->pictureBox11);
			this->Controls->Add(this->pictureBox8);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->pictureBox10);
			this->Controls->Add(this->pictureBox5);
			this->Controls->Add(this->pictureBox4);
			this->Controls->Add(this->pictureBox3);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->pictureBox6);
			this->Controls->Add(this->pictureBox9);
			this->Controls->Add(this->pictureBox7);
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Bai";
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyDown);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox5))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox6))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox7))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox8))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox9))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox10))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox11))->EndInit();
			this->ResumeLayout(false);

		}

#pragma endregion

	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		Application::Restart();
	}

	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
		button2->Visible = false;
		button2->Enabled = false;
		pictureBox3->Visible = true;
		timer2->Enabled = true;
	}

	private: System::Void MyForm_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
		switch (e->KeyValue)
		{
		case 38: user.up();		 break;
		case 40: user.down();	 break;
		case 37: user.left();	 break;
		case 39: user.right();	 break;
		case 32:
			if (!timer1->Enabled)
			{
				fire(bullet,user);
				timer1->Enabled = true;  break;
			}
		default: break;
		}
		this->pictureBox1->Location = System::Drawing::Point(user.get_x(), user.get_y());
	}

	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
		pictureBox2->Location = System::Drawing::Point(bullet.get_x(), bullet.get_y());
		pictureBox2->Visible = true;
		if (bullet.get_y() >= 30)
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

	int score = 0, secs_of_bonus = 0;

	private: System::Void timer2_Tick(System::Object^  sender, System::EventArgs^  e) {
		    if (score >= 3) { timer3->Enabled = true; pictureBox4->Visible = true; }
			pictureBox3->Location = System::Drawing::Point(white_block.get_x(), white_block.get_y());
			pictureBox3->Size = System::Drawing::Size(white_block.get_size_y(), 15);
			white_block.move();
			if (white_block.object_destroyed(bullet))
			{
				score++; 
				coin->Play();
			}
			if (white_block.get_y() >= 570|| white_block.object_destroyed(bullet))
			{
				white_block.renew();
			}
			if (block_collision(user, white_block)|| block_collision(user, red_block))
			{ 
				die->Play();
				timer2->Enabled = false;
				timer3->Enabled = false;
				button1->Enabled = true;
				button1->Visible = true;
			}
			this->Text = "Score: " + Convert::ToString(score);
			if (score >= 5 && score % 5 == 0 && timer5->Enabled == false) 
				timer4->Enabled = true;
			white_block.set_basic_speed(score / 30 + 1);
			red_block.set_basic_speed(score / 30 + 1);
			if (score == 0)
			{
				sound1->PlayLooping();
				timer2->Enabled = false;
				pictureBox3->Visible = false;
				timer3->Enabled = false;
				pictureBox4->Visible = false;
				timer6->Enabled = true;
				timer7->Enabled = true;
				pictureBox8->Visible= true;
				pictureBox9->Visible = true;
				set_start_position(enemy_bullet1, enemy);
				pictureBox8->Location = System::Drawing::Point(enemy.get_x(), enemy.get_y());
			}
	}

	private: System::Void timer3_Tick(System::Object^  sender, System::EventArgs^  e) {
			pictureBox4->Location = System::Drawing::Point(red_block.get_x(), red_block.get_y());
			pictureBox4->Size = System::Drawing::Size(red_block.get_size_y(), 15);
			red_block.move();
			if (red_block.get_y() >= 570 || (red_block.object_destroyed(bullet)))
			{
			if (red_block.object_destroyed(bullet))
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

	private: System::Void timer4_Tick(System::Object^  sender, System::EventArgs^  e) {
	pictureBox6->Location = System::Drawing::Point(present_box.get_x(), present_box.get_y());
	pictureBox6->Visible = true;
	present_box.move();
	if (present_box.get_y() >= 570 || (box_collision(user, present_box)))
	{
		if (box_collision(user, present_box))
		{
			timer4->Enabled = false;
			pictureBox6->Visible = false;
			timer5->Enabled = true;
			powerup->Play();
		}
		present_box.renew();
	}
	}

	private: System::Void timer5_Tick(System::Object^  sender, System::EventArgs^  e) {
	if (secs_of_bonus <= 10)
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

	private: System::Void timer6_Tick(System::Object^  sender, System::EventArgs^  e) {
		if (!(bullet.get_x() + 15 >= enemy.get_x()- enemy.get_size_y() && bullet.get_x() <= enemy.get_x() + 2 * enemy.get_size_y() && bullet.get_y() < 170)||(bullet.get_x() + 15 >= enemy.get_x() && bullet.get_x() <= enemy.get_x() + enemy.get_size_y()))
		if (rand() % 2)
			enemy.left();
		else
			enemy.right();
		pictureBox8->Location = System::Drawing::Point(enemy.get_x(), enemy.get_y());
	}

	void bull_cycle(base_object& enemy_bullet)
	{
		if (block_collision(user, enemy_bullet) || box_collision(bullet, enemy) || box_collision(enemy, user))
		{
			pictureBox2->Visible = false;
			timer6->Enabled = false;
			timer7->Enabled = false;
			button1->Enabled = true;
			button1->Visible = true;
			sound1->Stop();
			if (block_collision(user, enemy_bullet) || box_collision(enemy, user))
				die->Play();
			if (box_collision(bullet,enemy))
				stage_clear->Play();
		}
		if (enemy_bullet.get_y() >= 570 || (enemy_bullet.object_destroyed(bullet)))
		{
			if (enemy_bullet.object_destroyed(bullet))
			{
				timer1->Enabled = false;
				pictureBox2->Visible = false;
				bullet.disactive();
			}
			set_start_position(enemy_bullet, enemy);
		}
	}

	bool t2,t3;

	private: System::Void timer7_Tick(System::Object^  sender, System::EventArgs^  e) {
	pictureBox9->Location = System::Drawing::Point(enemy_bullet1.get_x(), enemy_bullet1.get_y());
	pictureBox10->Location = System::Drawing::Point(enemy_bullet2.get_x(), enemy_bullet2.get_y());
	pictureBox11->Location = System::Drawing::Point(enemy_bullet3.get_x(), enemy_bullet3.get_y());
	enemy_bullet1.move();
	if(t2)
		enemy_bullet2.move();
	if(enemy_bullet1.get_y() <= 292&& enemy_bullet1.get_y() >= 290)
	{
		if(!t2)
		set_start_position(enemy_bullet2, enemy);
		pictureBox10->Visible = true;
		t2 = true;
	}
	if (t3)
		enemy_bullet3.move();
	if (enemy_bullet1.get_y() <= 442 && enemy_bullet1.get_y() >= 440)
	{
		if (!t3)
			set_start_position(enemy_bullet3, enemy);
		pictureBox11->Visible = true;
		t3 = true;
	}
	bull_cycle(enemy_bullet1);
	bull_cycle(enemy_bullet2);
	bull_cycle(enemy_bullet3);
}
};
}
