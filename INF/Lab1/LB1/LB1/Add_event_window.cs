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
    public partial class Add_event_window : Form
    {
        string Action = "";
        public Add_event_window()
        {
            InitializeComponent();
        }
        public Add_event_window(string temp)
        {
            InitializeComponent();
            Action = temp;
        }

        private void Ok_Click(object sender, EventArgs e)
        {
            if (Calendar.SelectionRange.Start < System.DateTime.Now) { MessageBox.Show("Введите актуальную дату"); return; }
            Temp.temp = true;
            Close();
        }

        private void Add_event_window_Load(object sender, EventArgs e)
        {
            if (Action != "")
            {
                Time.Text = Temp.time;
                text.Text = Temp.text;
                Type.Text = Temp.type;
            }
        }

        private void Add_event_window_Deactivate(object sender, EventArgs e)
        {
            Temp.data = Calendar.SelectionRange.Start.ToShortDateString();
            Temp.time = Time.Text;
            Temp.text = text.Text;
            Temp.type = Type.Text;
        }
    }
}
