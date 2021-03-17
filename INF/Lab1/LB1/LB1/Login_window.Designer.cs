namespace LB1
{
    partial class Login_window
    {
        /// <summary>
        /// Обязательная переменная конструктора.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Освободить все используемые ресурсы.
        /// </summary>
        /// <param name="disposing">истинно, если управляемый ресурс должен быть удален; иначе ложно.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Код, автоматически созданный конструктором форм Windows

        /// <summary>
        /// Требуемый метод для поддержки конструктора — не изменяйте 
        /// содержимое этого метода с помощью редактора кода.
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            this.LoginL = new System.Windows.Forms.Label();
            this.LoginT = new System.Windows.Forms.TextBox();
            this.PasswordL = new System.Windows.Forms.Label();
            this.PasswordT = new System.Windows.Forms.TextBox();
            this.OK = new System.Windows.Forms.Button();
            this.Clacel = new System.Windows.Forms.Button();
            this.checkBox1 = new System.Windows.Forms.CheckBox();
            this.tableLayoutPanel1 = new System.Windows.Forms.TableLayoutPanel();
            this.toolTip1 = new System.Windows.Forms.ToolTip(this.components);
            this.toolTip2 = new System.Windows.Forms.ToolTip(this.components);
            this.tableLayoutPanel1.SuspendLayout();
            this.SuspendLayout();
            // 
            // LoginL
            // 
            this.LoginL.Anchor = System.Windows.Forms.AnchorStyles.None;
            this.LoginL.AutoSize = true;
            this.LoginL.Font = new System.Drawing.Font("Cambria", 24F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.LoginL.Location = new System.Drawing.Point(39, 16);
            this.LoginL.Margin = new System.Windows.Forms.Padding(2, 0, 2, 0);
            this.LoginL.Name = "LoginL";
            this.LoginL.Size = new System.Drawing.Size(99, 37);
            this.LoginL.TabIndex = 0;
            this.LoginL.Text = "Login";
            // 
            // LoginT
            // 
            this.LoginT.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Left | System.Windows.Forms.AnchorStyles.Right)));
            this.LoginT.Font = new System.Drawing.Font("Microsoft Sans Serif", 20F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.LoginT.Location = new System.Drawing.Point(179, 15);
            this.LoginT.Margin = new System.Windows.Forms.Padding(2);
            this.LoginT.Name = "LoginT";
            this.LoginT.Size = new System.Drawing.Size(350, 38);
            this.LoginT.TabIndex = 1;
            this.LoginT.MouseMove += new System.Windows.Forms.MouseEventHandler(this.LoginT_MouseMove);
            // 
            // PasswordL
            // 
            this.PasswordL.Anchor = System.Windows.Forms.AnchorStyles.None;
            this.PasswordL.AutoSize = true;
            this.PasswordL.Font = new System.Drawing.Font("Cambria", 26.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.PasswordL.Location = new System.Drawing.Point(2, 83);
            this.PasswordL.Margin = new System.Windows.Forms.Padding(2, 0, 2, 0);
            this.PasswordL.Name = "PasswordL";
            this.PasswordL.Size = new System.Drawing.Size(172, 41);
            this.PasswordL.TabIndex = 2;
            this.PasswordL.Text = "Password";
            // 
            // PasswordT
            // 
            this.PasswordT.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Left | System.Windows.Forms.AnchorStyles.Right)));
            this.PasswordT.Font = new System.Drawing.Font("Microsoft Sans Serif", 20F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.PasswordT.Location = new System.Drawing.Point(179, 84);
            this.PasswordT.Margin = new System.Windows.Forms.Padding(2);
            this.PasswordT.Name = "PasswordT";
            this.PasswordT.Size = new System.Drawing.Size(350, 38);
            this.PasswordT.TabIndex = 3;
            this.PasswordT.MouseMove += new System.Windows.Forms.MouseEventHandler(this.PasswordT_MouseMove);
            // 
            // OK
            // 
            this.OK.Anchor = System.Windows.Forms.AnchorStyles.None;
            this.OK.AutoSize = true;
            this.OK.Font = new System.Drawing.Font("Cambria", 26.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.OK.Location = new System.Drawing.Point(9, 199);
            this.OK.Margin = new System.Windows.Forms.Padding(2);
            this.OK.Name = "OK";
            this.OK.Size = new System.Drawing.Size(159, 62);
            this.OK.TabIndex = 4;
            this.OK.Text = "OK";
            this.OK.UseVisualStyleBackColor = true;
            this.OK.Click += new System.EventHandler(this.OK_Click);
            // 
            // Clacel
            // 
            this.Clacel.Anchor = System.Windows.Forms.AnchorStyles.None;
            this.Clacel.AutoSize = true;
            this.Clacel.Font = new System.Drawing.Font("Cambria", 26.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.Clacel.Location = new System.Drawing.Point(273, 199);
            this.Clacel.Margin = new System.Windows.Forms.Padding(2);
            this.Clacel.Name = "Clacel";
            this.Clacel.Size = new System.Drawing.Size(161, 62);
            this.Clacel.TabIndex = 5;
            this.Clacel.Text = "Exit";
            this.Clacel.UseVisualStyleBackColor = true;
            // 
            // checkBox1
            // 
            this.checkBox1.Anchor = System.Windows.Forms.AnchorStyles.None;
            this.checkBox1.AutoSize = true;
            this.checkBox1.Font = new System.Drawing.Font("Cambria", 26.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.checkBox1.Location = new System.Drawing.Point(211, 143);
            this.checkBox1.Margin = new System.Windows.Forms.Padding(2);
            this.checkBox1.Name = "checkBox1";
            this.checkBox1.Size = new System.Drawing.Size(285, 45);
            this.checkBox1.TabIndex = 6;
            this.checkBox1.Text = "Show Password";
            this.checkBox1.UseVisualStyleBackColor = true;
            this.checkBox1.CheckedChanged += new System.EventHandler(this.checkBox1_CheckedChanged);
            // 
            // tableLayoutPanel1
            // 
            this.tableLayoutPanel1.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.tableLayoutPanel1.ColumnCount = 2;
            this.tableLayoutPanel1.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 33.33333F));
            this.tableLayoutPanel1.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 66.66666F));
            this.tableLayoutPanel1.Controls.Add(this.Clacel, 1, 3);
            this.tableLayoutPanel1.Controls.Add(this.checkBox1, 1, 2);
            this.tableLayoutPanel1.Controls.Add(this.OK, 0, 3);
            this.tableLayoutPanel1.Controls.Add(this.PasswordT, 1, 1);
            this.tableLayoutPanel1.Controls.Add(this.PasswordL, 0, 1);
            this.tableLayoutPanel1.Controls.Add(this.LoginT, 1, 0);
            this.tableLayoutPanel1.Controls.Add(this.LoginL, 0, 0);
            this.tableLayoutPanel1.Location = new System.Drawing.Point(9, 10);
            this.tableLayoutPanel1.Margin = new System.Windows.Forms.Padding(2);
            this.tableLayoutPanel1.Name = "tableLayoutPanel1";
            this.tableLayoutPanel1.RowCount = 4;
            this.tableLayoutPanel1.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 50F));
            this.tableLayoutPanel1.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 50F));
            this.tableLayoutPanel1.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Absolute, 55F));
            this.tableLayoutPanel1.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Absolute, 75F));
            this.tableLayoutPanel1.Size = new System.Drawing.Size(531, 268);
            this.tableLayoutPanel1.TabIndex = 8;
            // 
            // Login_window
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(542, 287);
            this.Controls.Add(this.tableLayoutPanel1);
            this.Margin = new System.Windows.Forms.Padding(2);
            this.Name = "Login_window";
            this.Text = "Авторизация";
            this.Load += new System.EventHandler(this.Login_window_Load);
            this.tableLayoutPanel1.ResumeLayout(false);
            this.tableLayoutPanel1.PerformLayout();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Label LoginL;
        private System.Windows.Forms.TextBox LoginT;
        private System.Windows.Forms.Label PasswordL;
        private System.Windows.Forms.TextBox PasswordT;
        private System.Windows.Forms.Button OK;
        private System.Windows.Forms.Button Clacel;
        private System.Windows.Forms.CheckBox checkBox1;
        private System.Windows.Forms.TableLayoutPanel tableLayoutPanel1;
        private System.Windows.Forms.ToolTip toolTip1;
        private System.Windows.Forms.ToolTip toolTip2;
    }
}

