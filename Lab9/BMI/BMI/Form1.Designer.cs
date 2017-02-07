namespace BMI
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
            this.HeightTextBox = new System.Windows.Forms.TextBox();
            this.HeightLable = new System.Windows.Forms.Label();
            this.inches = new System.Windows.Forms.Label();
            this.lbs = new System.Windows.Forms.Label();
            this.Weight = new System.Windows.Forms.Label();
            this.WeightBox = new System.Windows.Forms.TextBox();
            this.SuspendLayout();
            // 
            // HeightTextBox
            // 
            this.HeightTextBox.Location = new System.Drawing.Point(170, 16);
            this.HeightTextBox.Name = "HeightTextBox";
            this.HeightTextBox.Size = new System.Drawing.Size(79, 20);
            this.HeightTextBox.TabIndex = 0;
            // 
            // HeightLable
            // 
            this.HeightLable.AutoSize = true;
            this.HeightLable.Location = new System.Drawing.Point(126, 19);
            this.HeightLable.Name = "HeightLable";
            this.HeightLable.Size = new System.Drawing.Size(38, 13);
            this.HeightLable.TabIndex = 1;
            this.HeightLable.Text = "Height";
            this.HeightLable.Click += new System.EventHandler(this.label1_Click);
            // 
            // inches
            // 
            this.inches.AutoSize = true;
            this.inches.Location = new System.Drawing.Point(255, 19);
            this.inches.Name = "inches";
            this.inches.Size = new System.Drawing.Size(15, 13);
            this.inches.TabIndex = 2;
            this.inches.Text = "in";
            // 
            // lbs
            // 
            this.lbs.AutoSize = true;
            this.lbs.Location = new System.Drawing.Point(255, 45);
            this.lbs.Name = "lbs";
            this.lbs.Size = new System.Drawing.Size(20, 13);
            this.lbs.TabIndex = 5;
            this.lbs.Text = "lbs";
            this.lbs.Click += new System.EventHandler(this.label1_Click_1);
            // 
            // Weight
            // 
            this.Weight.AutoSize = true;
            this.Weight.Location = new System.Drawing.Point(126, 45);
            this.Weight.Name = "Weight";
            this.Weight.Size = new System.Drawing.Size(41, 13);
            this.Weight.TabIndex = 4;
            this.Weight.Text = "Weight";
            this.Weight.Click += new System.EventHandler(this.label2_Click);
            // 
            // WeightBox
            // 
            this.WeightBox.Location = new System.Drawing.Point(170, 42);
            this.WeightBox.Name = "WeightBox";
            this.WeightBox.Size = new System.Drawing.Size(79, 20);
            this.WeightBox.TabIndex = 3;
            this.WeightBox.TextChanged += new System.EventHandler(this.textBox1_TextChanged);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(284, 261);
            this.Controls.Add(this.lbs);
            this.Controls.Add(this.Weight);
            this.Controls.Add(this.WeightBox);
            this.Controls.Add(this.inches);
            this.Controls.Add(this.HeightLable);
            this.Controls.Add(this.HeightTextBox);
            this.Name = "Form1";
            this.Text = "Form1";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.TextBox HeightTextBox;
        private System.Windows.Forms.Label HeightLable;
        private System.Windows.Forms.Label inches;
        private System.Windows.Forms.Label lbs;
        private System.Windows.Forms.Label Weight;
        private System.Windows.Forms.TextBox WeightBox;
    }
}

