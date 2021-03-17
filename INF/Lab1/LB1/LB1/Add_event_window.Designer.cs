namespace LB1
{
    partial class Add_event_window
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.Ok = new System.Windows.Forms.Button();
            this.label1 = new System.Windows.Forms.Label();
            this.Calendar = new System.Windows.Forms.MonthCalendar();
            this.Time = new System.Windows.Forms.DateTimePicker();
            this.label2 = new System.Windows.Forms.Label();
            this.text = new System.Windows.Forms.TextBox();
            this.label3 = new System.Windows.Forms.Label();
            this.Type = new System.Windows.Forms.ComboBox();
            this.SuspendLayout();
            // 
            // Ok
            // 
            this.Ok.Font = new System.Drawing.Font("Cambria", 15.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.Ok.Location = new System.Drawing.Point(446, 250);
            this.Ok.Margin = new System.Windows.Forms.Padding(2, 2, 2, 2);
            this.Ok.Name = "Ok";
            this.Ok.Size = new System.Drawing.Size(152, 54);
            this.Ok.TabIndex = 0;
            this.Ok.Text = "OK";
            this.Ok.UseVisualStyleBackColor = true;
            this.Ok.Click += new System.EventHandler(this.Ok_Click);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Cambria", 15.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.label1.Location = new System.Drawing.Point(10, 190);
            this.label1.Margin = new System.Windows.Forms.Padding(2, 0, 2, 0);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(62, 25);
            this.label1.TabIndex = 1;
            this.label1.Text = "Time";
            // 
            // Calendar
            // 
            this.Calendar.CalendarDimensions = new System.Drawing.Size(3, 1);
            this.Calendar.Location = new System.Drawing.Point(48, 16);
            this.Calendar.Margin = new System.Windows.Forms.Padding(7, 7, 7, 7);
            this.Calendar.Name = "Calendar";
            this.Calendar.TabIndex = 3;
            // 
            // Time
            // 
            this.Time.Font = new System.Drawing.Font("Microsoft Sans Serif", 15F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.Time.Format = System.Windows.Forms.DateTimePickerFormat.Time;
            this.Time.Location = new System.Drawing.Point(9, 216);
            this.Time.Margin = new System.Windows.Forms.Padding(2, 2, 2, 2);
            this.Time.Name = "Time";
            this.Time.ShowUpDown = true;
            this.Time.Size = new System.Drawing.Size(132, 30);
            this.Time.TabIndex = 4;
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Font = new System.Drawing.Font("Cambria", 15.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.label2.Location = new System.Drawing.Point(159, 190);
            this.label2.Margin = new System.Windows.Forms.Padding(2, 0, 2, 0);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(53, 25);
            this.label2.TabIndex = 5;
            this.label2.Text = "Text";
            // 
            // text
            // 
            this.text.Font = new System.Drawing.Font("Microsoft Sans Serif", 15F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.text.Location = new System.Drawing.Point(163, 216);
            this.text.Margin = new System.Windows.Forms.Padding(2, 2, 2, 2);
            this.text.Name = "text";
            this.text.Size = new System.Drawing.Size(437, 30);
            this.text.TabIndex = 6;
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Font = new System.Drawing.Font("Cambria", 15.75F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.label3.Location = new System.Drawing.Point(10, 248);
            this.label3.Margin = new System.Windows.Forms.Padding(2, 0, 2, 0);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(59, 25);
            this.label3.TabIndex = 7;
            this.label3.Text = "Type";
            // 
            // Type
            // 
            this.Type.Font = new System.Drawing.Font("Microsoft Sans Serif", 15F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.Type.FormattingEnabled = true;
            this.Type.Items.AddRange(new object[] {
            "Памятка",
            "Встреча",
            "Задание"});
            this.Type.Location = new System.Drawing.Point(9, 274);
            this.Type.Margin = new System.Windows.Forms.Padding(2, 2, 2, 2);
            this.Type.Name = "Type";
            this.Type.Size = new System.Drawing.Size(157, 33);
            this.Type.TabIndex = 8;
            // 
            // Add_event_window
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(619, 314);
            this.Controls.Add(this.Type);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.text);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.Time);
            this.Controls.Add(this.Calendar);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.Ok);
            this.Margin = new System.Windows.Forms.Padding(2, 2, 2, 2);
            this.Name = "Add_event_window";
            this.Text = "Add_event_window";
            this.Deactivate += new System.EventHandler(this.Add_event_window_Deactivate);
            this.Load += new System.EventHandler(this.Add_event_window_Load);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button Ok;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.MonthCalendar Calendar;
        private System.Windows.Forms.DateTimePicker Time;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.TextBox text;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.ComboBox Type;
    }
}