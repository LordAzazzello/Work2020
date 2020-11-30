using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Drawing.Drawing2D;

namespace WindowsFormsApp6
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        protected override void OnPaint(PaintEventArgs e) 

        {
            Graphics g = e.Graphics;
            //Серый цвет для фона
            SolidBrush myBak = new SolidBrush(Color.Gray);
            // Задаем желтый и оранжевый цвет для рыбки
            SolidBrush myFish1 = new SolidBrush(Color.Yellow);
            SolidBrush myFish2 = new SolidBrush(Color.Orange);
            // Задаем коричневый цвет для стола
            SolidBrush myTabl = new SolidBrush(Color.Brown);
            // Задаем цвет аквариума - голубой
            SolidBrush myAkv = new SolidBrush(Color.Blue);
            //Задаём белый цвет для стекла аквариума
            SolidBrush myGlass = new SolidBrush(Color.White);
            //Задаём чёрный цвет
            SolidBrush myXto = new SolidBrush(Color.Black);
            //Задаём зелёный цвет
            SolidBrush myGrays = new SolidBrush(Color.Green);

            //Закрашиваю фон серым
            g.FillRectangle(myBak, 0, 0, 450, 500);
            //***************Рисую аквариум************
            g.FillEllipse(myGlass, 150, 147, 160, 160);
            //*******************Висую воду************
            g.FillEllipse(myAkv, 155, 150, 150, 150);
            //****Рисую стол на котором стоит аквариум*
            g.FillRectangle(myTabl, 20, 300, 390, 300);
            //*************Рисуем дно аквариума********
            //Определяю контейнер
            GraphicsPath myGraphicsPath = new GraphicsPath();
            Pen p = new Pen(Brushes.Red, 1);
            // Задаем координаты точек первой кривой
            Point[] myPointArray1 = { new Point(163, 260), new Point(160, 260), new Point(200, 297), new Point(241, 299), new Point(270, 296), new Point(297, 260)};
            // Добавляем кривую в контейнер
            myGraphicsPath.AddCurve(myPointArray1);
            // Выводим дно
            g.FillPath(myFish1, myGraphicsPath);
            //Камни на дне
            g.FillEllipse(myXto, 173, 268, 20, 10);
            g.FillEllipse(myXto, 197, 280, 20, 10);
            g.FillEllipse(myXto, 197, 270, 20, 10);
            //Водоросли
            g.FillRectangle(myGrays, 200, 240, 10, 40);
            g.FillRectangle(myGrays, 220, 220, 10, 40);
            g.FillRectangle(myGrays, 250, 240, 7, 40);
            //Тело рыбы
            g.FillEllipse(myFish2, 180, 200, 70, 30);
            //Плавник задний
            g.FillPolygon(myFish1, new Point[]
            {
                new Point(248,215),new Point(260,190), new Point(270,240)
            });
            //Плавник боковой
            g.FillRectangle(myFish1, 204, 214, 30, 3);
            //Плавник верхний
            g.FillPolygon(myFish1, new Point[] 
            {
                new Point(200,203),new Point(240,180), new Point(240,210)
            });
            //Рисую глаз рыбе
            g.FillEllipse(myXto, 185, 210, 5, 5);
        }


        private void Form1_Load(object sender, EventArgs e)
        {

        }
    }
}
