namespace Games
{
    partial class Form1
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
            this.components = new System.ComponentModel.Container();
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(Form1));
            this.button1 = new System.Windows.Forms.Button();
            this.button2 = new System.Windows.Forms.Button();
            this.label_AirplaneMissed = new System.Windows.Forms.Label();
            this.label_AirplaneShooted = new System.Windows.Forms.Label();
            this.pictureBoxPole = new System.Windows.Forms.PictureBox();
            this.timer1 = new System.Windows.Forms.Timer(this.components);
            this.timer2 = new System.Windows.Forms.Timer(this.components);
            this.timer3 = new System.Windows.Forms.Timer(this.components);
            this.label1 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBoxPole)).BeginInit();
            this.SuspendLayout();
            // 
            // button1
            // 
            this.button1.Location = new System.Drawing.Point(658, 448);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(206, 25);
            this.button1.TabIndex = 0;
            this.button1.Text = "Старт";
            this.button1.UseVisualStyleBackColor = true;
            this.button1.Click += new System.EventHandler(this.button1_Click);
            // 
            // button2
            // 
            this.button2.Location = new System.Drawing.Point(658, 479);
            this.button2.Name = "button2";
            this.button2.Size = new System.Drawing.Size(206, 21);
            this.button2.TabIndex = 1;
            this.button2.Text = "Сброс";
            this.button2.UseVisualStyleBackColor = true;
            this.button2.Click += new System.EventHandler(this.button2_Click);
            // 
            // label_AirplaneMissed
            // 
            this.label_AirplaneMissed.AutoSize = true;
            this.label_AirplaneMissed.Location = new System.Drawing.Point(655, 22);
            this.label_AirplaneMissed.Name = "label_AirplaneMissed";
            this.label_AirplaneMissed.Size = new System.Drawing.Size(13, 13);
            this.label_AirplaneMissed.TabIndex = 2;
            this.label_AirplaneMissed.Text = "0";
            this.label_AirplaneMissed.Click += new System.EventHandler(this.label_AirplaneMissed_Click);
            // 
            // label_AirplaneShooted
            // 
            this.label_AirplaneShooted.AutoSize = true;
            this.label_AirplaneShooted.Location = new System.Drawing.Point(655, 58);
            this.label_AirplaneShooted.Name = "label_AirplaneShooted";
            this.label_AirplaneShooted.Size = new System.Drawing.Size(13, 13);
            this.label_AirplaneShooted.TabIndex = 3;
            this.label_AirplaneShooted.Text = "0";
            this.label_AirplaneShooted.Click += new System.EventHandler(this.label_AirplaneShooted_Click);
            // 
            // pictureBoxPole
            // 
            this.pictureBoxPole.ErrorImage = ((System.Drawing.Image)(resources.GetObject("pictureBoxPole.ErrorImage")));
            this.pictureBoxPole.Image = ((System.Drawing.Image)(resources.GetObject("pictureBoxPole.Image")));
            this.pictureBoxPole.InitialImage = ((System.Drawing.Image)(resources.GetObject("pictureBoxPole.InitialImage")));
            this.pictureBoxPole.Location = new System.Drawing.Point(12, 12);
            this.pictureBoxPole.Name = "pictureBoxPole";
            this.pictureBoxPole.Size = new System.Drawing.Size(637, 488);
            this.pictureBoxPole.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage;
            this.pictureBoxPole.TabIndex = 4;
            this.pictureBoxPole.TabStop = false;
            this.pictureBoxPole.PreviewKeyDown += new System.Windows.Forms.PreviewKeyDownEventHandler(this.pictureBoxPole_PreviewKeyDown);
            // 
            // timer1
            // 
            this.timer1.Enabled = true;
            this.timer1.Interval = 40;
            this.timer1.Tick += new System.EventHandler(this.timer1_Tick);
            // 
            // timer2
            // 
            this.timer2.Enabled = true;
            this.timer2.Interval = 10;
            this.timer2.Tick += new System.EventHandler(this.timer2_Tick);
            // 
            // timer3
            // 
            this.timer3.Tick += new System.EventHandler(this.timer3_Tick);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(655, 9);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(182, 13);
            this.label1.TabIndex = 5;
            this.label1.Text = "Количесво пропущенных мишеней";
            this.label1.Click += new System.EventHandler(this.label1_Click);
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(655, 42);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(115, 13);
            this.label2.TabIndex = 6;
            this.label2.Text = "Количество мишеней";
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(876, 512);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.pictureBoxPole);
            this.Controls.Add(this.label_AirplaneShooted);
            this.Controls.Add(this.label_AirplaneMissed);
            this.Controls.Add(this.button2);
            this.Controls.Add(this.button1);
            this.KeyPreview = true;
            this.Name = "Form1";
            this.Text = "Form1";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.KeyDown += new System.Windows.Forms.KeyEventHandler(this.Form1_KeyDown);
            this.KeyUp += new System.Windows.Forms.KeyEventHandler(this.Form1_KeyUp);
            ((System.ComponentModel.ISupportInitialize)(this.pictureBoxPole)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button button1;
        private System.Windows.Forms.Button button2;
        private System.Windows.Forms.Label label_AirplaneMissed;
        private System.Windows.Forms.Label label_AirplaneShooted;
        private System.Windows.Forms.Timer timer1;
        private System.Windows.Forms.Timer timer2;
        private System.Windows.Forms.PictureBox pictureBoxPole;
        private System.Windows.Forms.Timer timer3;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label label2;
    }
}

