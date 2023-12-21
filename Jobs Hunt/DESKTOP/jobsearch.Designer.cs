namespace DESKTOP
{
    partial class jobsearch
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
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(jobsearch));
            this.textBox1 = new System.Windows.Forms.TextBox();
            this.button1 = new System.Windows.Forms.Button();
            this.pictureBox1 = new System.Windows.Forms.PictureBox();
            this.dataGridView1 = new System.Windows.Forms.DataGridView();
            this.cn = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.mn = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.jn = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.state = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.ms = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.mh = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.con = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.Email = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.address = new System.Windows.Forms.DataGridViewTextBoxColumn();
            this.linkLabel1 = new System.Windows.Forms.LinkLabel();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView1)).BeginInit();
            this.SuspendLayout();
            // 
            // textBox1
            // 
            this.textBox1.Location = new System.Drawing.Point(432, 380);
            this.textBox1.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.textBox1.Name = "textBox1";
            this.textBox1.Size = new System.Drawing.Size(396, 22);
            this.textBox1.TabIndex = 6;
            // 
            // button1
            // 
            this.button1.Location = new System.Drawing.Point(556, 423);
            this.button1.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(148, 25);
            this.button1.TabIndex = 5;
            this.button1.Text = "search";
            this.button1.UseVisualStyleBackColor = true;
            this.button1.Click += new System.EventHandler(this.button1_Click_1);
            // 
            // pictureBox1
            // 
            this.pictureBox1.Image = ((System.Drawing.Image)(resources.GetObject("pictureBox1.Image")));
            this.pictureBox1.Location = new System.Drawing.Point(321, 40);
            this.pictureBox1.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.pictureBox1.Name = "pictureBox1";
            this.pictureBox1.Size = new System.Drawing.Size(606, 305);
            this.pictureBox1.SizeMode = System.Windows.Forms.PictureBoxSizeMode.AutoSize;
            this.pictureBox1.TabIndex = 4;
            this.pictureBox1.TabStop = false;
            // 
            // dataGridView1
            // 
            this.dataGridView1.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dataGridView1.Columns.AddRange(new System.Windows.Forms.DataGridViewColumn[] {
            this.cn,
            this.mn,
            this.jn,
            this.state,
            this.ms,
            this.mh,
            this.con,
            this.Email,
            this.address});
            this.dataGridView1.Location = new System.Drawing.Point(1, 465);
            this.dataGridView1.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.dataGridView1.Name = "dataGridView1";
            this.dataGridView1.RowHeadersWidth = 62;
            this.dataGridView1.Size = new System.Drawing.Size(1253, 377);
            this.dataGridView1.TabIndex = 7;
            // 
            // cn
            // 
            this.cn.DataPropertyName = "CompanyName";
            this.cn.HeaderText = "Company Name";
            this.cn.MinimumWidth = 8;
            this.cn.Name = "cn";
            this.cn.Width = 150;
            // 
            // mn
            // 
            this.mn.DataPropertyName = "ManagerName";
            this.mn.HeaderText = "Manager Name";
            this.mn.MinimumWidth = 8;
            this.mn.Name = "mn";
            this.mn.Width = 150;
            // 
            // jn
            // 
            this.jn.DataPropertyName = "job_name";
            this.jn.HeaderText = "Job";
            this.jn.MinimumWidth = 8;
            this.jn.Name = "jn";
            this.jn.Width = 150;
            // 
            // state
            // 
            this.state.DataPropertyName = "State";
            this.state.HeaderText = "State";
            this.state.MinimumWidth = 8;
            this.state.Name = "state";
            this.state.Width = 150;
            // 
            // ms
            // 
            this.ms.DataPropertyName = "minimum_salary";
            this.ms.HeaderText = "Minimum salary";
            this.ms.MinimumWidth = 8;
            this.ms.Name = "ms";
            this.ms.Width = 150;
            // 
            // mh
            // 
            this.mh.DataPropertyName = "min_hours";
            this.mh.HeaderText = "minimum hours";
            this.mh.MinimumWidth = 8;
            this.mh.Name = "mh";
            this.mh.Width = 150;
            // 
            // con
            // 
            this.con.DataPropertyName = "Contact_no";
            this.con.HeaderText = "Contact";
            this.con.MinimumWidth = 8;
            this.con.Name = "con";
            this.con.Width = 150;
            // 
            // Email
            // 
            this.Email.DataPropertyName = "CompanyEmail";
            this.Email.HeaderText = "Email";
            this.Email.MinimumWidth = 8;
            this.Email.Name = "Email";
            this.Email.Width = 150;
            // 
            // address
            // 
            this.address.DataPropertyName = "Address";
            this.address.HeaderText = "Address";
            this.address.MinimumWidth = 8;
            this.address.Name = "address";
            this.address.Width = 150;
            // 
            // linkLabel1
            // 
            this.linkLabel1.AutoSize = true;
            this.linkLabel1.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F, ((System.Drawing.FontStyle)((System.Drawing.FontStyle.Bold | System.Drawing.FontStyle.Italic))), System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.linkLabel1.LinkColor = System.Drawing.Color.Black;
            this.linkLabel1.Location = new System.Drawing.Point(12, 26);
            this.linkLabel1.Name = "linkLabel1";
            this.linkLabel1.Size = new System.Drawing.Size(98, 20);
            this.linkLabel1.TabIndex = 8;
            this.linkLabel1.TabStop = true;
            this.linkLabel1.Text = "< Go Back";
            this.linkLabel1.LinkClicked += new System.Windows.Forms.LinkLabelLinkClickedEventHandler(this.linkLabel1_LinkClicked);
            // 
            // jobsearch
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1256, 840);
            this.Controls.Add(this.linkLabel1);
            this.Controls.Add(this.dataGridView1);
            this.Controls.Add(this.textBox1);
            this.Controls.Add(this.button1);
            this.Controls.Add(this.pictureBox1);
            this.Margin = new System.Windows.Forms.Padding(4, 4, 4, 4);
            this.Name = "jobsearch";
            this.Text = "jobsearch";
            this.Load += new System.EventHandler(this.jobsearch_Load);
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView1)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.TextBox textBox1;
        private System.Windows.Forms.Button button1;
        private System.Windows.Forms.PictureBox pictureBox1;
        private System.Windows.Forms.DataGridView dataGridView1;
        private System.Windows.Forms.DataGridViewTextBoxColumn cn;
        private System.Windows.Forms.DataGridViewTextBoxColumn mn;
        private System.Windows.Forms.DataGridViewTextBoxColumn jn;
        private System.Windows.Forms.DataGridViewTextBoxColumn state;
        private System.Windows.Forms.DataGridViewTextBoxColumn ms;
        private System.Windows.Forms.DataGridViewTextBoxColumn mh;
        private System.Windows.Forms.DataGridViewTextBoxColumn con;
        private System.Windows.Forms.DataGridViewTextBoxColumn Email;
        private System.Windows.Forms.DataGridViewTextBoxColumn address;
        private System.Windows.Forms.LinkLabel linkLabel1;
    }
}