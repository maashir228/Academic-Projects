using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Configuration;
using System.Data.SqlClient;

namespace DESKTOP
{
    public partial class jobsearch : Form
    {
        public jobsearch()
        {
            this.BackColor = Color.AntiqueWhite;
            InitializeComponent();
        }
        SqlConnection conn = new SqlConnection(ConfigurationManager.ConnectionStrings["registraineeConnectionString"].ConnectionString);

        private void jobsearch_Load(object sender, EventArgs e)
        {
            textBox1.Text = "";
            datalist();

        }
        void datalist()
        {
            conn.Open();
            string checkuser = "SELECT Employerregisteration.CompanyName, Employerregisteration.ManagerName, Employerjobs.job_name, Employerregisteration.State, Employerjobs.minimum_salary, Employerjobs.min_hours, Employerregisteration.Contact_no, Employerregisteration.CompanyEmail, Employerregisteration.Address FROM Employerjobs INNER JOIN Employerregisteration ON Employerjobs.ID = Employerregisteration.Id WHERE (Employerregisteration.CompanyName LIKE '%' + '" + textBox1.Text + "' + '%') OR (Employerregisteration.ManagerName LIKE '%' +'" + textBox1.Text + "' + '%') OR (Employerjobs.job_name LIKE '%' + '" + textBox1.Text + "' + '%') OR (Employerregisteration.State LIKE '%' + '" + textBox1.Text + "' + '%')";
            SqlCommand com = new SqlCommand(checkuser, conn);
            SqlDataReader dr = com.ExecuteReader();
            DataTable dt = new DataTable();
            dt.Load(dr);
            dataGridView1.DataSource = dt;
            conn.Close();
        }

        private void button1_Click_1(object sender, EventArgs e)
        {
            datalist();
        }
        private void LinkLabel1Clicked(object sender, LinkLabelLinkClickedEventArgs e)
        {
            var HomePage = new traineehome();
            HomePage.Show();
            this.Hide();
        }
        private void linkLabel1_LinkClicked(object sender, LinkLabelLinkClickedEventArgs e)
        {
            linkLabel1.LinkClicked += new System.Windows.Forms.LinkLabelLinkClickedEventHandler(LinkLabel1Clicked);
        }
    }
}
