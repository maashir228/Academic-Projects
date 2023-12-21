namespace DESKTOP
{
    partial class traineesearch
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
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(traineesearch));
            this.pictureBox1 = new System.Windows.Forms.PictureBox();
            this.button1 = new System.Windows.Forms.Button();
            this.textBox1 = new System.Windows.Forms.TextBox();
            this.dataGridView1 = new System.Windows.Forms.DataGridView();
            this.fn = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.ln = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.Email = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.State = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.Con = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.ssn = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.ps = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.Skills = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.rr = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.Availale = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.exp = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.linkLabel1 = new System.Windows.Forms.LinkLabel();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView1)).BeginInit();
            this.SuspendLayout();
            // 
            // pictureBox1
            // 
            this.pictureBox1.Image = ((System.Drawing.Image)(resources.GetObject("pictureBox1.Image")));
            this.pictureBox1.Location = new System.Drawing.Point(379, 90);
            this.pictureBox1.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.pictureBox1.Name = "pictureBox1";
            this.pictureBox1.Size = new System.Drawing.Size(606, 305);
            this.pictureBox1.SizeMode = System.Windows.Forms.PictureBoxSizeMode.AutoSize;
            this.pictureBox1.TabIndex = 0;
            this.pictureBox1.TabStop = false;
            // 
            // button1
            // 
            this.button1.Location = new System.Drawing.Point(618, 490);
            this.button1.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(148, 25);
            this.button1.TabIndex = 1;
            this.button1.Text = "search";
            this.button1.UseVisualStyleBackColor = true;
            this.button1.Click += new System.EventHandler(this.button1_Click);
            // 
            // textBox1
            // 
            this.textBox1.Location = new System.Drawing.Point(485, 435);
            this.textBox1.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.textBox1.Name = "textBox1";
            this.textBox1.Size = new System.Drawing.Size(396, 22);
            this.textBox1.TabIndex = 2;
            // 
            // dataGridView1
            // 
            this.dataGridView1.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dataGridView1.Columns.AddRange(new System.Windows.Forms.DataGridViewColumn[] {
            this.fn,
            this.ln,
            this.Email,
            this.State,
            this.Con,
            this.ssn,
            this.ps,
            this.Skills,
            this.rr,
            this.Availale,
            this.exp});
            this.dataGridView1.Location = new System.Drawing.Point(1, 554);
            this.dataGridView1.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.dataGridView1.Name = "dataGridView1";
            this.dataGridView1.RowHeadersWidth = 62;
            this.dataGridView1.Size = new System.Drawing.Size(1527, 286);
            this.dataGridView1.TabIndex = 3;
            // 
            // fn
            // 
            this.fn.DataPropertyName = "FirstName";
            this.fn.HeaderText = "First Name";
            this.fn.MinimumWidth = 8;
            this.fn.Name = "fn";
            this.fn.Width = 150;
            // 
            // ln
            // 
            this.ln.DataPropertyName = "LastName";
            this.ln.HeaderText = "Last name";
            this.ln.MinimumWidth = 8;
            this.ln.Name = "ln";
            this.ln.Width = 150;
            // 
            // Email
            // 
            this.Email.DataPropertyName = "Email";
            this.Email.HeaderText = "Email";
            this.Email.MinimumWidth = 8;
            this.Email.Name = "Email";
            this.Email.Width = 150;
            // 
            // State
            // 
            this.State.DataPropertyName = "State";
            this.State.HeaderText = "State";
            this.State.MinimumWidth = 8;
            this.State.Name = "State";
            this.State.Width = 150;
            // 
            // Con
            // 
            this.Con.DataPropertyName = "Contact";
            this.Con.HeaderText = "Contact";
            this.Con.MinimumWidth = 8;
            this.Con.Name = "Con";
            this.Con.Width = 150;
            // 
            // ssn
            // 
            this.ssn.DataPropertyName = "Social_security_number";
            this.ssn.HeaderText = "SSN";
            this.ssn.MinimumWidth = 8;
            this.ssn.Name = "ssn";
            this.ssn.Width = 150;
            // 
            // ps
            // 
            this.ps.DataPropertyName = "Personal_statement";
            this.ps.HeaderText = "Personal Statement";
            this.ps.MinimumWidth = 8;
            this.ps.Name = "ps";
            this.ps.Width = 150;
            // 
            // Skills
            // 
            this.Skills.DataPropertyName = "Skills";
            this.Skills.HeaderText = "Skills";
            this.Skills.MinimumWidth = 8;
            this.Skills.Name = "Skills";
            this.Skills.Width = 150;
            // 
            // rr
            // 
            this.rr.DataPropertyName = "Required_rate";
            this.rr.HeaderText = "Required Rate";
            this.rr.MinimumWidth = 8;
            this.rr.Name = "rr";
            this.rr.Width = 150;
            // 
            // Availale
            // 
            this.Availale.DataPropertyName = "Available";
            this.Availale.HeaderText = "Available";
            this.Availale.MinimumWidth = 8;
            this.Availale.Name = "Availale";
            this.Availale.Width = 150;
            // 
            // exp
            // 
            this.exp.DataPropertyName = "Experience";
            this.exp.HeaderText = "Experience";
            this.exp.MinimumWidth = 8;
            this.exp.Name = "exp";
            this.exp.Width = 150;
            // 
            // linkLabel1
            // 
            this.linkLabel1.AutoSize = true;
            this.linkLabel1.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F, ((System.Drawing.FontStyle)((System.Drawing.FontStyle.Bold | System.Drawing.FontStyle.Italic))), System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.linkLabel1.LinkColor = System.Drawing.Color.Black;
            this.linkLabel1.Location = new System.Drawing.Point(40, 42);
            this.linkLabel1.Name = "linkLabel1";
            this.linkLabel1.Size = new System.Drawing.Size(98, 20);
            this.linkLabel1.TabIndex = 4;
            this.linkLabel1.TabStop = true;
            this.linkLabel1.Text = "< Go Back";
            this.linkLabel1.LinkClicked += new System.Windows.Forms.LinkLabelLinkClickedEventHandler(this.linkLabel1_LinkClicked);
            // 
            // traineesearch
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1528, 840);
            this.Controls.Add(this.linkLabel1);
            this.Controls.Add(this.dataGridView1);
            this.Controls.Add(this.textBox1);
            this.Controls.Add(this.button1);
            this.Controls.Add(this.pictureBox1);
            this.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.Name = "traineesearch";
            this.Text = "traineesearch";
            this.Load += new System.EventHandler(this.traineesearch_Load_1);
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView1)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.PictureBox pictureBox1;
        private System.Windows.Forms.Button button1;
        private System.Windows.Forms.TextBox textBox1;
        private System.Windows.Forms.DataGridView dataGridView1;
        private System.Windows.Forms.DataGridViewTextBoxColumn fn;
        private System.Windows.Forms.DataGridViewTextBoxColumn ln;
        private System.Windows.Forms.DataGridViewTextBoxColumn Email;
        private System.Windows.Forms.DataGridViewTextBoxColumn State;
        private System.Windows.Forms.DataGridViewTextBoxColumn Con;
        private System.Windows.Forms.DataGridViewTextBoxColumn ssn;
        private System.Windows.Forms.DataGridViewTextBoxColumn ps;
        private System.Windows.Forms.DataGridViewTextBoxColumn Skills;
        private System.Windows.Forms.DataGridViewTextBoxColumn rr;
        private System.Windows.Forms.DataGridViewTextBoxColumn Availale;
        private System.Windows.Forms.DataGridViewTextBoxColumn exp;
        private System.Windows.Forms.LinkLabel linkLabel1;
    }
}