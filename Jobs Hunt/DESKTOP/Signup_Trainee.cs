using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Data.SqlClient;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Configuration;
using System.Globalization;

namespace DESKTOP
{
    public partial class Signup_Trainee : Form
    {
        SqlConnection conn = new SqlConnection(ConfigurationManager.ConnectionStrings["registraineeConnectionString"].ConnectionString);
        public Signup_Trainee()
        {
            this.BackColor = Color.AntiqueWhite;
            InitializeComponent();
        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void label7_Click(object sender, EventArgs e)
        {

        }

        private void textBox3_TextChanged(object sender, EventArgs e)
        {

            
        }

        private void button1_Click(object sender, EventArgs e)
        {
           
            try
            {
                Guid newid = Guid.NewGuid();
                conn.Open();
                string checkuser = "select count(*) from RegisterationTrainee where UserName='" + textBox1.Text + "'";
                SqlCommand comm = new SqlCommand(checkuser, conn);
                int temp = Convert.ToInt32(comm.ExecuteScalar().ToString());
                if (temp == 1)
                {
                    MessageBox.Show("Username not available");
                }
                else
                {

                    string theDate = dateTimePicker1.Value.ToShortDateString();
                    MessageBox.Show(theDate);
                    string insertq = "insert into RegisterationTrainee (ID,UserName,FirstName,LastName,Date,Email,Password,Country,State,Address,Contact,License_number,Social_security_number) values (@id,@Uname ,@firstname,@lastname ,@age ,@email ,@password ,@country ,@state ,@address ,@contact ,@licensenumber ,@socialsecurity)";
                    SqlCommand com = new SqlCommand(insertq, conn);
                    com.Parameters.AddWithValue("@id", newid.ToString());
                    com.Parameters.AddWithValue("@Uname", textBox1.Text);
                    com.Parameters.AddWithValue("@firstname", textBox3.Text);
                    com.Parameters.AddWithValue("@lastname", textBox4.Text);
                    com.Parameters.AddWithValue("@age", theDate);
                    com.Parameters.AddWithValue("@email", textBox2.Text);
                    com.Parameters.AddWithValue("@password", textBox12.Text);
                    com.Parameters.AddWithValue("@country", textBox10.ToString());
                    com.Parameters.AddWithValue("@state", textBox9.Text);
                    com.Parameters.AddWithValue("@address", textBox5.Text);
                    com.Parameters.AddWithValue("@contact", textBox8.Text);
                    com.Parameters.AddWithValue("@licensenumber", textBox6.Text);
                    com.Parameters.AddWithValue("@socialsecurity", textBox7.Text);
                    try
                    {
                        com.ExecuteNonQuery();
                        conn.Close();
                    }
                    catch(Exception )
                    {
                        conn.Close();
                    }
                    MessageBox.Show("registered succesfully");
                    var TraineeLogin = new Trainee_Login();
                    TraineeLogin.Show();
                    this.Hide();
                }

                


            }
            catch (Exception ex)
            {

                MessageBox.Show("Error:" + ex.ToString());
            }
        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {

        }

        private void textBox2_TextChanged(object sender, EventArgs e)
        {

        }

        private void textBox13_TextChanged(object sender, EventArgs e)
        {
 
        }

        private void textBox12_TextChanged(object sender, EventArgs e)
        {

        }

        private void textBox10_TextChanged(object sender, EventArgs e)
        {

        }

        private void textBox9_TextChanged(object sender, EventArgs e)
        {

        }

        private void textBox5_TextChanged(object sender, EventArgs e)
        {

        }

        private void textBox8_TextChanged(object sender, EventArgs e)
        {

        }

        private void textBox6_TextChanged(object sender, EventArgs e)
        {

        }

        private void textBox7_TextChanged(object sender, EventArgs e)
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

        private void Signup_Trainee_Load(object sender, EventArgs e)
        {

        }

        private void label5_Click(object sender, EventArgs e)
        {

        }
    }
}
