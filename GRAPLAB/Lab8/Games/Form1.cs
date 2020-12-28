using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace Games
{
public partial class Form1 : Form {
const int AirplaneMax = 1; // Максимум самолётов на экране
const int BulletsMax = 1; // Максимум снарядов на экране
PictureBox[] Airplanes = new PictureBox[AirplaneMax]; // Самолёты
PictureBox[] Bullets = new PictureBox[BulletsMax]; // Снаряды
PictureBox Gun = new PictureBox(); // Картинка пушки
bool StartFlag; // Флаг игры
bool FireFlag; // Флаг выстрела
int Cooldown = 30; // Скорость зарядки пушки (3/10 секунды)
int Shooted = 0; // Количество тиков до готовности пушки
int AirplaneShootedCount = 5; // Счётчик сбитых самолётов
int AirplaneMissedCount = 0; // Счётчик не сбитых самолётов
int GunSpeed = 5; // Скорость пушки
int AirplaneSpeed = 3; // Скорость самолёта
int BulletSpeed = 14; // Скорость снаряда
int AirplaneCount = 0; // Количество самолётов на экране
int BulletCount = 0; // Количество снарядов на экране
int AirplaneFrequency = 100; // Частота появления самолётов
public Form1() { InitializeComponent(); }

    private void DeleteAirplane(int i) {
Airplanes[i].Dispose(); // освобождение ресурсов Airplanes[i]
for (int j=i; j<AirplaneCount-1; j++)
{ Airplanes[j] = Airplanes[j + 1]; }
AirplaneCount--;
    }
        private void DeleteBullet(int i) {
Bullets[i].Dispose(); // освобождение ресурсов Bullets[i]
for (int j=i; j<BulletCount-1; j++)
{Bullets[j] = Bullets[j + 1];}
BulletCount--;
}

        private void Form1_Load(object sender, EventArgs e)
        {
            // Устнавливаем все флажки при загрузке формы в false
            StartFlag = false; FireFlag = false;
// Загружаем в pictureBox Gun изображение пушки
Gun.Image = Image.FromFile(@"Сам.png");
Gun.BackColor = Color.Transparent; // Прозрачный фон пушки
Gun.Location = new Point(pictureBoxPole.Image.Width / 4,
pictureBoxPole.Image.Height /1 - Gun.Image.Height);
Gun.Size= new Size(Gun.Image.Width, Gun.Image.Height);
Gun.Name = "Game_Gun";
pictureBoxPole.Controls.Add(Gun); // Добавляем пушку на поле игры
Gun.BringToFront();
   
        }
        private void timer1_Tick(object sender, EventArgs e)
        {
            // Если флаг игры установлен
if (StartFlag)
{ // Получаем случайное целое число меньше 900
Random a = new Random();
int RandomEvent = a.Next(900);
// Новый самолёт
if ((RandomEvent >= 0) & (RandomEvent < AirplaneFrequency) &
(AirplaneCount < AirplaneMax))
{ // Увеличиваем счётчик количества самолётов на экране
AirplaneCount++;
// Переименовываем самолёты со старшими номерами
for (int i = AirplaneCount - 1; i > 0; i--) {
Airplanes[i] = Airplanes[i - 1];
}
// Создаём изображение нового самолёта
Airplanes[0] = new PictureBox();
// который будет лететь слева направо
if ((RandomEvent>-1) & (RandomEvent<=AirplaneFrequency/2)){
    Airplanes[0].Image = Image.FromFile(@"Сам.png");
Airplanes[0].Image.Tag = "ЛП";
Airplanes[0].Location = new Point(0,pictureBoxPole.Location.Y +
a.Next(100));
}
else // который будет лететь справа налево
{
    Airplanes[0].Image = Image.FromFile(@"Сам.png");

Airplanes[0].Image.Tag = "ПЛ";
Airplanes[0].Location = new Point(pictureBoxPole.Width -

Airplanes[0].Image.Width,
pictureBoxPole.Location.Y + a.Next(100));
}
// Устанавливаем прозрачный цвет фона самолёта
Airplanes[0].BackColor = Color.Transparent;
Airplanes[0].Size = new Size(Airplanes[0].Image.Width,
Airplanes[0].Image.Height);
Airplanes[0].Name = "Airplane" + AirplaneCount.ToString();
// Добавляем самолёт на поле игры
pictureBoxPole.Controls.Add(Airplanes[0]);
Airplanes[0].BringToFront();
}
}
}

        private void timer2_Tick(object sender, EventArgs e)
        {
            // Если игра запущена
            if (StartFlag)
            {
                // Уменьшаем тики времени до перезарядки пушки
                if (Shooted > 0) { Shooted--; }
                // Если установлен флаг выстрела
                if (FireFlag)
                {
                    // и если пушка готова к выстрелу
                    if (Shooted == 0)
                    {
                        // Увеличиваем количество выпущенных снарядов
                        BulletCount++;
                        // переименовываем снаряды со старшими номерами
                        for (int i = BulletCount - 1; i > 0; i--)
                        {
                            Bullets[i] = Bullets[i - 1];
                        }
                        // Создаём изображение нового снаряда
                        Bullets[0] = new PictureBox();
                        Bullets[0].Image = Image.FromFile(@"Снаряд.png");
                        Bullets[0].Location = new Point(Gun.Location.X +
                        Gun.Image.Width / 2, Gun.Location.Y);
                        Bullets[0].Size = new Size(Bullets[0].Image.Width,
                        Bullets[0].Image.Height);
                        Bullets[0].Name = "Bullets" + BulletCount.ToString();
                        // Добавляем снаряд на поле игры
                        pictureBoxPole.Controls.Add(Bullets[0]);
                        Bullets[0].BringToFront();
                        // Устанавливаем количество тиков до нового выстрела
                        Shooted = Cooldown;
                    }
                }
                // Перемещение самолётов и контроль на выход за границы
                for (int i = 0; i < AirplaneCount; i++)
                {
                    // Если самолёт летит слева направо
                    if (Airplanes[i].Image.Tag.ToString() == "ЛП")
                    { // Смещаем самолёт вправо на AirplaneSpeed точек
                        Airplanes[i].Left = Airplanes[i].Left + AirplaneSpeed;
                        // Если самолёт долетел до правой границы
                        if (Airplanes[i].Left > pictureBoxPole.Image.Width)
                        {
                            DeleteAirplane(i); // Удаляем самолёт

                            AirplaneMissedCount++;// Увеличиваем счётчик пропущенных

                        }
                    }
                    else
                    { // Если самолёт летит справа налево
                        // Смещаем самолёт влево на AirplaneSpeed точек
                        Airplanes[i].Left = Airplanes[i].Left - AirplaneSpeed;
                        // Если самолёт долетел до левой границы
                        if (Airplanes[i].Left < 0 - Airplanes[i].Width)
                        {
                            DeleteAirplane(i); // Удаляем самолёт
                            AirplaneMissedCount++;// Увеличиваем счётчик пропущенных
                        }
                    }
                }
                //Перемещение снарядов, контроль на выход за границы и попадание
                for (int i = 0; i < BulletCount; i++)
                { // Перемещаем снаряд вверх на BulletSpeed точек
                    Bullets[i].Location = new Point(Bullets[i].Location.X,
                    Bullets[i].Location.Y - BulletSpeed);
                    // Если снаряд долетел до верхней границы
                    if (Bullets[i].Location.Y < pictureBoxPole.Location.Y) { DeleteBullet(i); } // Удаляем снаряд
                    // Получаем координаты прямоугольной области снаряда
                    Rectangle r1 = Bullets[i].DisplayRectangle;
                    // Проверка на попадание в самолёт
                    for (int j = 0; j < AirplaneCount; j++)
                    {//Получаем координаты прямоугольной области j-го самолёта
                        Rectangle r2 = Airplanes[j].DisplayRectangle;
                        Rectangle r3 = Gun.DisplayRectangle;
                        r1.Location = Bullets[i].Location;
                        r2.Location = Airplanes[j].Location;
                        r3.Location = Gun.Location;
                        // Если прямоугольные области пересекаются
                        if (r1.IntersectsWith(r2))
                        {
                            DeleteBullet(i); // Удаляем снаряд
                            DeleteAirplane(j); // Удаляем самолёт
                            AirplaneShootedCount--;//Увеличиваем количество сбитых
                            label_AirplaneMissed.Text = AirplaneMissedCount.ToString();
                            label_AirplaneShooted.Text = AirplaneShootedCount.ToString();
                            if (AirplaneShootedCount <= 0)
                            {
                                StartFlag = false;
                                this.KeyPreview = false;
                            }
                            {
                            }
                        }
                    // Изменяем значения счётчиков игры на экране
            }
                }
            }
        }
    private void button1_Click(object sender, EventArgs e)
    {
        if (button1.Text == "Старт") {
button1.Text = "Пауза"; StartFlag = true;
pictureBoxPole.Focus(); // Устанавливаем фокус на поле игры
return;
}
if (button1.Text == "Пауза") {
button1.Text = "Старт"; StartFlag = false;
button1.Focus();// Устанавливаем фокус на клавишу "Старт"
}
}

    private void button2_Click(object sender, EventArgs e)
    {
        { // Обнуляем количество сбитых и пропущенных самолётов
AirplaneShootedCount = 5;
AirplaneMissedCount = 0;
StartFlag = true;
pictureBoxPole.Focus();
this.KeyPreview = true;
button1.Text = "Старт";
// Выводим на экран
label_AirplaneMissed.Text = AirplaneMissedCount.ToString();
label_AirplaneShooted.Text = AirplaneShootedCount.ToString();
}
    }

    private void pictureBoxPole_PreviewKeyDown(object sender, PreviewKeyDownEventArgs e)
    { // чтобы обрабатывались клавиши со стрелками "влево-вправо" 
        e.IsInputKey = true;
    }

    private void Form1_KeyDown(object sender, KeyEventArgs e)
    {
    // Перемещение пушки вправо на GunSpeed точек
if (e.KeyCode == Keys.Right) {
if (Gun.Left + Gun.Width + GunSpeed < pictureBoxPole.Image.Width)
{ Gun.Left = Gun.Left + GunSpeed; }
}
// Перемещение пушки влево на GunSpeed точек
if (e.KeyCode == Keys.Left) {
if (Gun.Left >= GunSpeed) {Gun.Left = Gun.Left - GunSpeed; }
}
// Установка флага FireFlag по нажатию клавиши "пробел"
if (e.KeyCode == Keys.Space) { FireFlag = true; }
// Остановка и возобновление игры по нажатию клавиши "Enter"
if (e.KeyCode == Keys.Enter) { button1_Click(sender,e); }
}

    private void Form1_KeyUp(object sender, KeyEventArgs e)
    {
        // Сброс флага FireFlag по отпусканию клавиши "пробел"
        if (e.KeyCode == Keys.Space) { FireFlag = false; }
    }

    private void timer3_Tick(object sender, EventArgs e)
    {
            {

      if (AirplaneShootedCount <= 0) { StartFlag = false; } {
                        Image img = Image.FromFile("1.jpg");
                        Graphics g;
                        g = pictureBoxPole.CreateGraphics();
                        g.DrawImageUnscaled(img, 0, 0, pictureBoxPole.Size.Width, pictureBoxPole.Size.Height);
      }
    }
            }

    private void label_AirplaneShooted_Click(object sender, EventArgs e)
    {

    }

    private void label1_Click(object sender, EventArgs e)
    {

    }

        private void label_AirplaneMissed_Click(object sender, EventArgs e)
        {

        }
    }
    }
