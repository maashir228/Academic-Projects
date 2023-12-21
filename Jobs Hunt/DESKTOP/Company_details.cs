using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Configuration;
using System.Data.SqlClient;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;


namespace DESKTOP
{
    public partial class Company_details : Form
    {
        public Company_details()
        {
            this.BackColor = Color.Green;
            InitializeComponent();
        }
        SqlConnection conn = new SqlConnection(ConfigurationManager.ConnectionStrings["registraineeConnectionString"].ConnectionString);

        private void Form2_Load(object sender, EventArgs e)
        {
            datalist();
        }
        void datalist()
        {
            conn.Open();
            string checkuser = "SELECT job_name, minimum_salary, min_hours, vacant FROM Employerjobs WHERE (ID =  '" + Session.UserID + "' )";
            SqlCommand com = new SqlCommand(checkuser, conn);
            SqlDataReader dr = com.ExecuteReader();
            DataTable dt = new DataTable();
            dt.Load(dr);
            dataGridView1.DataSource = dt;
            conn.Close();
        }
       //add
        protected void button1_Click(object sender, EventArgs e)
        {
            try
            {
                if (textBox1.Text == "" || textBox2.Text == "" || textBox3.Text == "")
                {
                    MessageBox.Show("Please fill fields");
                }
                else
                {
                    if (job_exist())
                    {
                        MessageBox.Show("job already EXISTS");
                    }
                    else
                    {
                        add_job();
                        datalist();
                        textBox1.Text = "";
                        textBox2.Text = "";
                        textBox3.Text = "";
                        this.Refresh();
                        

                    }
                }
            }
            catch (Exception ex)
            {
                MessageBox.Show("Error:" + ex.ToString());
            }


        }
        //update
        private void button2_Click_1(object sender, EventArgs e)
        {
            try
            {
                if (textBox1.Text == "" || textBox2.Text == "" || textBox3.Text == "")
                {
                    MessageBox.Show("Please fill fields");
                }
                else
                {
                    if (job_exist())
                    {
                        update_job();
                        datalist();
                        textBox1.Text = "";
                        textBox2.Text = "";
                        textBox3.Text = "";
                        this.Refresh();

                    }
                    else
                    {
                        MessageBox.Show("job does not EXIST");

                    }
                }
            }
            catch (Exception ex)
            {
                MessageBox.Show("Error:" + ex.ToString());
            }
        }
        //delete
        private void button3_Click_1(object sender, EventArgs e)
        {
            try
            {
                if (textBox3.Text == "")
                {
                    MessageBox.Show("Please Enter job name");
                }
                else
                {
                    if (job_exist())
                    {
                        delete_job();
                        datalist();
                        textBox1.Text = "";
                        textBox2.Text = "";
                        textBox3.Text = "";
                        this.Refresh();
                    }
                    else
                    {
                        MessageBox.Show("job does not EXIST");

                    }
                }
            }
            catch (Exception ex)
            {
                MessageBox.Show("Error:" + ex.ToString());
            }
        }


        //functions
        bool job_exist()
        {
            conn.Open();
            string checkuser = "select count(*) from Employerjobs where job_name='" + textBox3.Text.ToString() + "'";
            SqlCommand comm = new SqlCommand(checkuser, conn);
            int temp = Convert.ToInt32(comm.ExecuteScalar().ToString());
            conn.Close();
            if (temp == 1)
            {
                return true;
            }
            else
            {

                return false;
            }
        }
        //add job if doesnt exist
        void add_job()
        {
            conn.Open();

            string insert = "insert into Employerjobs(ID,job_name,minimum_salary,min_hours,vacant) values (@ID,@job_name,@minimum_salary,@min_hours,@vacant)";
            SqlCommand comman = new SqlCommand(insert, conn);
            comman.Parameters.AddWithValue("@ID", Session.UserID.ToString().Trim());
            comman.Parameters.AddWithValue("@job_name", textBox3.Text.ToString().Trim());
            comman.Parameters.AddWithValue("@minimum_salary", textBox1.Text.ToString().Trim());
            comman.Parameters.AddWithValue("@min_hours", textBox2.Text.ToString().Trim());
            comman.Parameters.AddWithValue("@vacant", checkBox1.Checked);
            comman.ExecuteNonQuery();
            conn.Close();
        }

        void update_job()
        {
            conn.Open();
            string update = "update Employerjobs set job_name=@jn , minimum_salary=@ms, min_hours=@mh , vacant=@va where job_name=@jn";
            SqlCommand comma = new SqlCommand(update, conn);

            comma.Parameters.AddWithValue("@jn", textBox3.Text.ToString().Trim());
            comma.Parameters.AddWithValue("@ms", textBox1.Text.ToString().Trim());
            comma.Parameters.AddWithValue("@mh", textBox2.Text.ToString().Trim());
            comma.Parameters.AddWithValue("@va", checkBox1.Checked);
            comma.ExecuteNonQuery();
            conn.Close();
        }
        void delete_job()
        {
            conn.Open();
            string delete = "Delete from Employerjobs where job_name=@jn";
            SqlCommand comma = new SqlCommand(delete, conn);
            comma.Parameters.AddWithValue("@jn", textBox3.Text.ToString().Trim());
            comma.ExecuteNonQuery();
            conn.Close();
        }

        protected void CheckBox1_CheckedChanged(object sender, EventArgs e)
        {

        }
        

        private void label2_Click(object sender, EventArgs e)
        {

        }

        private void label3_Click(object sender, EventArgs e)
        {

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

        private void dataGridView1_CellContentClick(object sender, DataGridViewCellEventArgs e)
        {

        }
    }
}
