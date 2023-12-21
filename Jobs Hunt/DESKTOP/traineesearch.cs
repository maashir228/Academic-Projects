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
    public partial class traineesearch : Form
    {
        public traineesearch()
        {
            InitializeComponent();
        }
        SqlConnection conn = new SqlConnection(ConfigurationManager.ConnectionStrings["registraineeConnectionString"].ConnectionString);

        private void traineesearch_Load_1(object sender, EventArgs e)
        {
            this.BackColor = Color.AntiqueWhite;
            textBox1.Text = "";
            datalist();
            
        }
        void datalist()
        {
            conn.Open();
            string checkuser = "SELECT RegisterationTrainee.FirstName, RegisterationTrainee.LastName, RegisterationTrainee.Email, RegisterationTrainee.State, RegisterationTrainee.Contact, RegisterationTrainee.Social_security_number, Traineeskills.Personal_statement, Traineeskills.Skills, Traineeskills.Required_rate, Traineeskills.Available, Traineeskills.Experience FROM RegisterationTrainee INNER JOIN Traineeskills ON RegisterationTrainee.ID = Traineeskills.ID WHERE (RegisterationTrainee.FirstName LIKE '%' + '" + textBox1.Text + "' + '%') OR(RegisterationTrainee.LastName LIKE '%' + '" + textBox1.Text + "' + '%') OR(RegisterationTrainee.State LIKE '%' + '" + textBox1.Text + "' + '%') OR(Traineeskills.Skills LIKE '%' + '" + textBox1.Text + "' + '%') OR(Traineeskills.Available LIKE '%' + '" + textBox1.Text + "' + '%') OR(Traineeskills.Experience LIKE '%' +'" + textBox1.Text + "' + '%')";
            SqlCommand com = new SqlCommand(checkuser, conn);
            SqlDataReader dr = com.ExecuteReader();
            DataTable dt = new DataTable();
            dt.Load(dr);
            dataGridView1.DataSource = dt;
            conn.Close();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            datalist();
        }
        private void LinkLabel1Clicked(object sender, LinkLabelLinkClickedEventArgs e)
        {
            var HomePage = new Companyhomepage();
            HomePage.Show();
            this.Hide();
        }
        private void linkLabel1_LinkClicked(object sender, LinkLabelLinkClickedEventArgs e)
        {
            linkLabel1.LinkClicked += new System.Windows.Forms.LinkLabelLinkClickedEventHandler(LinkLabel1Clicked);
        }
    }
}
