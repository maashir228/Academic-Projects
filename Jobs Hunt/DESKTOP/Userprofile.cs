using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Data.SqlClient;
using System.Configuration;

namespace DESKTOP
{
    public partial class Userprofile : Form
    {
        public Userprofile()
        {
            this.BackColor = Color.AntiqueWhite;
            InitializeComponent();
        }
        void bind()
        {
            try
            {

                SqlConnection conn = new SqlConnection(ConfigurationManager.ConnectionStrings["registraineeConnectionString"].ConnectionString);
                conn.Open();
                string checkuser = "select * from Traineeskills where ID='" + Session.UserID.ToString() + "'";
                SqlCommand com = new SqlCommand(checkuser, conn);
                SqlDataReader dr = com.ExecuteReader();
                if (dr.HasRows)
                {
                    while (dr.Read())
                    {
                        textBox1.Text = dr.GetValue(2).ToString();
                        textBox2.Text = dr.GetValue(3).ToString();
                        textBox3.Text = dr.GetValue(4).ToString();
                        textBox4.Text = dr.GetValue(5).ToString();
                        textBox5.Text = dr.GetValue(6).ToString();

                    }
                }
                conn.Close();





            }

            catch (Exception ex)
            {
                MessageBox.Show(" ex.Message ");
            }
        }
        private void Userprofile_Load(object sender, EventArgs e)
        {
            label1.Text = Session.Username;
            bind();

        }

        private void button1_Click(object sender, EventArgs e)
        {
            try
            {

                SqlConnection conn = new SqlConnection(ConfigurationManager.ConnectionStrings["registraineeConnectionString"].ConnectionString);
                conn.Open();
                string checkuser = "select count(*) from Traineeskills where ID='" + Session.UserID.ToString().Trim() + "'";
                SqlCommand com = new SqlCommand(checkuser, conn);
                int temp = Convert.ToInt32(com.ExecuteScalar().ToString());
                conn.Close();
                if (temp == 1)
                {
                    SqlConnection co = new SqlConnection(ConfigurationManager.ConnectionStrings["registraineeConnectionString"].ConnectionString);
                    co.Open();
                    string update = "update Traineeskills set Personal_statement=@ps, Skills=@skill , Required_rate=@rr, Available=@ava, Experience=@exp where ID=@id";
                    SqlCommand comma = new SqlCommand(update, co);
                    comma.Parameters.AddWithValue("@id", Session.UserID.ToString());
                    comma.Parameters.AddWithValue("@ps", textBox1.Text.ToString());
                    comma.Parameters.AddWithValue("@skill", textBox2.Text.ToString());
                    comma.Parameters.AddWithValue("@rr", textBox3.Text.ToString().Trim());
                    comma.Parameters.AddWithValue("@ava", textBox4.Text.ToString());
                    comma.Parameters.AddWithValue("@exp", textBox5.Text.ToString());
                    comma.ExecuteNonQuery();
                    co.Close();
                }
                else if (temp == 0)
                {
                    SqlConnection conne = new SqlConnection(ConfigurationManager.ConnectionStrings["registraineeConnectionString"].ConnectionString);
                    conne.Open();
                    string insert = "insert into Traineeskills(ID,Personal_statement,Skills,Required_rate,Available,Experience) values (@id,@ps,@skill,@rr,@ava,@exp)";
                    SqlCommand comman = new SqlCommand(insert, conne);
                    comman.Parameters.AddWithValue("@id", Session.UserID.ToString().Trim());
                    comman.Parameters.AddWithValue("@ps", textBox1.Text.ToString().Trim());
                    comman.Parameters.AddWithValue("@skill", textBox2.Text.ToString().Trim());
                    comman.Parameters.AddWithValue("@rr", textBox3.Text.ToString().Trim());
                    comman.Parameters.AddWithValue("@ava", textBox4.Text.ToString().Trim());
                    comman.Parameters.AddWithValue("@exp", textBox5.Text.ToString().Trim());
                    comman.ExecuteNonQuery();
                    conne.Close();
                    MessageBox.Show("inserted Successfully");
                }

                bind();
            }

            catch (Exception ex)
            {
                MessageBox.Show("ex.Message");
            }
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
