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
    public partial class Signup_Company : Form
    {
        SqlConnection conn = new SqlConnection(ConfigurationManager.ConnectionStrings["registraineeConnectionString"].ConnectionString);
        public Signup_Company()
        {
            this.BackColor = Color.AntiqueWhite;
            InitializeComponent();
        }

        private void label3_Click(object sender, EventArgs e)
        {

        }

        private void label8_Click(object sender, EventArgs e)
        {

        }

        private void Form5_Load(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            
        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {

        }

        private void textBox2_TextChanged(object sender, EventArgs e)
        {

        }

        private void textBox4_TextChanged(object sender, EventArgs e)
        {

        }

        private void textBox3_TextChanged(object sender, EventArgs e)
        {

        }

        private void textBox12_TextChanged(object sender, EventArgs e)
        {

        }

        private void textBox13_TextChanged(object sender, EventArgs e)
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

        private void button1_Click_1(object sender, EventArgs e)
        {
            try
            {
                Guid newid = Guid.NewGuid();
                conn.Open();
                string checkuser = "select count(*) from Employerregisteration where Username='" + textBox1.Text + "'";
                SqlCommand comm = new SqlCommand(checkuser, conn);
                int temp = Convert.ToInt32(comm.ExecuteScalar().ToString());
                if (temp == 1)
                {
                    MessageBox.Show("Username not available");
                }
                else
                {
                    string insertq = "insert into Employerregisteration (id,UserName,CompanyName,ManagerName,Password,State,BranchID,Address,Contact_no,CompanyEmail) values (@id,@Uname ,@cname,@mname,@password ,@state,@Bid ,@address ,@contact,@cemail)";
                    SqlCommand com = new SqlCommand(insertq, conn);
                    com.Parameters.AddWithValue("@id", newid.ToString());
                    com.Parameters.AddWithValue("@Uname", textBox1.Text);
                    com.Parameters.AddWithValue("@cname", textBox4.Text);
                    com.Parameters.AddWithValue("@mname", textBox3.Text);
                    com.Parameters.AddWithValue("@password", textBox12.Text);
                    com.Parameters.AddWithValue("@state", textBox10.Text);
                    com.Parameters.AddWithValue("@Bid", textBox13.Text);
                    com.Parameters.AddWithValue("@address", textBox9.Text);
                    com.Parameters.AddWithValue("@contact", textBox5.Text);
                    com.Parameters.AddWithValue("@cemail", textBox2.Text);
                    com.ExecuteNonQuery();
                    MessageBox.Show("Registeration successful");
                    var CompLogin = new Company_Login();
                    CompLogin.Show();
                    this.Hide();
                    conn.Close();
                }


            }
            catch (Exception ex)
            {

                MessageBox.Show("Error:" + ex.ToString());
            }
        }
    }
}
