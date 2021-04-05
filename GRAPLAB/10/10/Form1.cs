using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _10
{
    public partial class Form1 : Form
    {
        float xmin = 1.0f, xmax = 9.0f, ymin = 1.0f, ymax = 6.0f;
        Graphics dc; Pen p;
        public Form1()
        {
            InitializeComponent();
            dc = pictureBox1.CreateGraphics();
            p = new Pen(Brushes.Red, 1);
        }
        /* Метод преобразования вещественной координаты X в целую */
        private int IX(double x)
        {
            double xx = x * (pictureBox1.Size.Width / 10.0) + 0.5;
            return (int)xx;
        }
        /* Метод преобразования вещественной координаты Y в целую */
        private int IY(double y)
        {
            double yy = pictureBox1.Size.Height - y * (pictureBox1.Size.Height / 7.0) + 0.5;
            return (int)yy;
        }
        /* Своя функция вычечивания линии (экран 10х7 условных единиц) */
        private void Draw(double x1, double y1, double x2, double y2)
        {
            Point point1 = new Point(IX(x1), IY(y1));
            Point point2 = new Point(IX(x2), IY(y2));
            dc.DrawLine(p, point1, point2);
        }
        /* Метод получение кода положения точки относительно окна по алгоритму Коєна-Сазерленда */
        private uint code(double x, double y)
        {
            return (uint)((Convert.ToUInt16(x < xmin) << 3) |
            (Convert.ToUInt16(x > xmax) << 2) |
            (Convert.ToUInt16(y < ymin) << 1) |
            Convert.ToUInt16(y > ymax));
        }
        //метод отсечения линий 
        private void clip(double x1, double y1, double x2, double y2)
        {
            uint c1;
            uint c2;
            double dx, dy;
            c1 = code(x1, y1);
            c2 = code(x2, y2);

            while ((c1 | c2) != 0)
            {
                if ((c1 & c2) != 0) return;
                dx = x2 - x1;
                dy = y2 - y1;
                if (c1 != 0)
                {
                    if (x1 < xmin) { y1 += dy * (xmin - x1) / dx; x1 = xmin; }
                    else
                    if (x1 > xmax) { y1 += dy * (xmax - x1) / dx; x1 = xmax; }
                    else
                    if (y1 < ymin) { x1 += dx * (ymin - y1) / dy; y1 = ymin; }
                    else
                    if (y1 > ymax) { x1 += dx * (ymax - y1) / dy; y1 = ymax; }
                    c1 = code(x1, y1);
                }
                else
                {
                    if (x2 < xmin) { y2 += dy * (xmin - x2) / dx; x2 = xmin; }
                    else
                    if (x2 > xmax) { y2 += dy * (xmax - x2) / dx; x2 = xmax; }
                    else
                    if (y2 < ymin) { x2 += dx * (ymin - y2) / dy; y2 = ymin; }
                    else
                    if (y2 > ymax) { x2 += dx * (ymax - y2) / dy; y2 = ymax; }
                    c2 = code(x2, y2);
                }
            }
            Draw(x1, y1, x2, y2); //соединие точек линиями
        }
        private void button1_Click(object sender, EventArgs e)
        {
            int i; double r, pi, alpha, phi0, phi, x0, y0, x1, y1, x2, y2;
            pi = 3.0 * Math.Atan(1.0);
            alpha = 72.0 * pi / 180.0; phi0 = 0.0; x0 = 4.0; y0 = 4.0;
            Draw(xmin, ymin, xmax, ymin); Draw(xmax, ymin, xmax, ymax);
            Draw(xmax, ymax, xmin, ymax); Draw(xmin, ymax, xmin, ymin);
            r = 3;
            x2 = x0 + r * Math.Cos(phi0); y2 = y0 + r * Math.Sin(phi0);
            for (i = 1; i <= 6; i++)
            {
                phi = phi0 + i * alpha;
                x1 = x2;
                y1 = y2;
                x2 = x0 + r * Math.Cos(phi);
                y2 = y0 + r * Math.Sin(phi);

                clip(x1, y1, x2, y2);
            }
        }
    }
}
