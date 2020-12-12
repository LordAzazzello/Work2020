using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WindowsFormsApp7
{
    public partial class Form1 : Form
    {
        // Битовая картинка pictureBox
        Bitmap pictureBoxBitMap;
        // Битовая картинка динамического изображения
        Bitmap spriteBitMap;
        // Битовая картинка для временного хранения области экрана
        Bitmap cloneBitMap;
        // Графический контекст picturebox
        Graphics g_pictureBox;
        // Графический контекст спрайта
        Graphics g_sprite;
        int x, y; // Координаты машины
        int width = 451, height = 209; // Ширина и высота машины
        Timer timer;

        public Form1()
        {
            InitializeComponent();
        }

        void DrawSprite()
        {
            
            // Рисуем корпус машины
            Point[] points = new Point[7] { new Point(25,50), new Point(330,50),
                new Point(340, 110),new Point(370, 130), new Point(370, 180),
                new Point(1, 180), new Point(25, 50) 
            };

            g_sprite.FillPolygon(Brushes.DarkRed, points);
            g_sprite.DrawPolygon(new Pen(Color.Black, 2), points);
            // Рисуем колеса
            g_sprite.DrawEllipse(new Pen(Color.Black, 2), 10, 130, 75, 80);
            g_sprite.FillEllipse(new SolidBrush(Color.Black), 10, 130, 75, 80);
            g_sprite.DrawEllipse(new Pen(Color.Black, 2), 250, 130, 75, 80);
            g_sprite.FillEllipse(new SolidBrush(Color.Black), 250, 130, 75, 80);
            //Рисуем окна
            g_sprite.DrawRectangle(new Pen(Color.Blue, 2), 60, 55, 50, 55);
            g_sprite.FillRectangle(new SolidBrush(Color.Blue), 60, 55, 50, 55);
            g_sprite.DrawRectangle(new Pen(Color.Blue, 2), 150, 55, 50, 55);
            g_sprite.FillRectangle(new SolidBrush(Color.Blue), 150, 55, 50, 55);
            g_sprite.DrawRectangle(new Pen(Color.Blue, 2), 250, 55, 50, 55);
            g_sprite.FillRectangle(new SolidBrush(Color.Blue), 250, 55, 50, 55);
        }

        void SavePart(int xt, int yt)
        {
            Rectangle cloneRect = new Rectangle(xt, yt, width, height);
            System.Drawing.Imaging.PixelFormat format =
            pictureBoxBitMap.PixelFormat;
            // Клонируем изображение, заданное прямоугольной областью
            cloneBitMap = pictureBoxBitMap.Clone(cloneRect, format);
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            // Создаём Bitmap для pictureBox1 и графический контекст
            pictureBox1.Image = Image.FromFile(@"fon.jpg");
            pictureBoxBitMap = new Bitmap(pictureBox1.Image);
            g_pictureBox = Graphics.FromImage(pictureBox1.Image);
            // Создаём Bitmap для спрайта и графический контекст
            spriteBitMap = new Bitmap(width, height);
            g_sprite = Graphics.FromImage(spriteBitMap);
            // Рисуем машину на графическом контексте g_sprite
            DrawSprite();
            // Создаём Bitmap для временного хранения части изображения
            cloneBitMap = new Bitmap(width, height);
            // Задаем начальные координаты вывода движущегося объекта
            x = 0; y = 300;
            // Сохраняем область экрана перед первым выводом объекта
            SavePart(x, y);
            // Выводим авто на графический контекст g_pictureBox
            g_pictureBox.DrawImage(spriteBitMap, x, y);
            // Перерисовываем pictureBox1
            pictureBox1.Invalidate();
            // Создаём таймер с интервалом 100 миллисекунд
            timer = new Timer();
            timer.Interval = 100;
            timer.Tick += new EventHandler(timer1_Tick);
        }

        private void button1_Click(object sender, EventArgs e)
        {
            timer.Enabled = true;
        }

        private void timer1_Tick(object sender, EventArgs e)
        {
            // Восстанавливаем затёртую область статического изображения
            g_pictureBox.DrawImage(cloneBitMap, x, y);
            // Изменяем координаты для следующего вывода авто
            x += 6;
            // Проверяем на выход изображения авто за правую границу
            if (x > pictureBox1.Width - 1) x = pictureBox1.Location.X;
            // Сохраняем область экрана перед первым выводом Танка
            SavePart(x, y);
            // Выводим авто
            g_pictureBox.DrawImage(spriteBitMap, x, y);
            // Перерисовываем pictureBox1
            pictureBox1.Invalidate();
        }
    }
}
