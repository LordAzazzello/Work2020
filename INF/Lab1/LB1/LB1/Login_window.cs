using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace LB1
{
    public partial class Login_window : Form
    {
        public Login_window()
        {
            InitializeComponent();
        }

        private void OK_Click(object sender, EventArgs e)
        {
            if (LoginT.Text == "Azazello" && PasswordT.Text == "1995")
            {
                Organizer_window window = new Organizer_window();
                window.Show();
            }
            else
            {
                MessageBox.Show("Неверный логин или пароль!");
            }
        }

        private void checkBox1_CheckedChanged(object sender, EventArgs e)
        {
            PasswordT.UseSystemPasswordChar = !PasswordT.UseSystemPasswordChar;
        }

        private void Login_window_Load(object sender, EventArgs e)
        {
            PasswordT.UseSystemPasswordChar = true;
            toolTip1.SetToolTip(LoginT, "Введите логин");
            toolTip2.SetToolTip(PasswordT, "Введите пароль");
        }

        private void PasswordT_MouseMove(object sender, MouseEventArgs e)
        {
            toolTip1.Active = true;
        }

        private void LoginT_MouseMove(object sender, MouseEventArgs e)
        {
            toolTip2.Active = true;
        }
    }
}
