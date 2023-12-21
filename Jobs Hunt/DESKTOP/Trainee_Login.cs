using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Data.SqlClient;
using System.Windows.Forms;
using System.Configuration;

namespace DESKTOP
{
    public partial class Trainee_Login : Form
    {
        public Trainee_Login()
        {
            InitializeComponent();
        }

        private void label1_Click(object sender, EventArgs e)
        {

        }


        private void button2_Click(object sender, EventArgs e)
        {
            SqlConnection conn = new SqlConnection(ConfigurationManager.ConnectionStrings["registraineeConnectionString"].ConnectionString);
            conn.Open();
            string checkuser = "select * from RegisterationTrainee where UserName='" + textBox2.Text + "'";
            SqlCommand com = new SqlCommand(checkuser, conn);
            SqlDataReader dr = com.ExecuteReader();

            if (dr.HasRows)
            {

                while (dr.Read())
                {
                    string password = dr.GetValue(6).ToString().Replace(" ", "");

                    if (password == textBox1.Text)
                    {
                        Session.Username = textBox2.Text;
                        Session.UserID = dr.GetValue(0).ToString();
                        Session.Client = "trainee";
                        MessageBox.Show("correct password ballay ballay");
                        var userhome = new traineehome();
                        userhome.Show();
                        this.Hide();
                    }
                    else
                    {
                        MessageBox.Show("Password incorrect");
                    }
                }


            }
            else
            {
                MessageBox.Show("Username incorrect");
            }
            conn.Close();
        }

        private void Trainee_Login_Load(object sender, EventArgs e)
        {

        }

        private void LinkLabel1Clicked(object sender, LinkLabelLinkClickedEventArgs e)
        {
            var HomePage = new Home_Page();
            HomePage.Show();
            this.Hide();

        }

        

        private void linkLabel1_LinkClicked(object sender, LinkLabelLinkClickedEventArgs e)
        {
            linkLabel1.LinkClicked += new System.Windows.Forms.LinkLabelLinkClickedEventHandler(LinkLabel1Clicked);
        }
    }
}
