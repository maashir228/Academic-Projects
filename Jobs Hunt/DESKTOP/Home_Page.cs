using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace DESKTOP
{
    public partial class Home_Page : Form
    {
        public Home_Page()
        {
            this.BackColor = Color.AntiqueWhite;
            InitializeComponent();
        }

        private void label1_Click(object sender, EventArgs e)
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
            
            var HomeForm = new Home_Page();
            HomeForm.Show();
            this.Hide();
            
            
        }

        private void LinkLabel2Clicked(object sender, LinkLabelLinkClickedEventArgs e)
        {

            var TraineeSignup = new Signup_Trainee();
            TraineeSignup.Show();
            this.Hide();

        }

        private void LinkLabel3Clicked(object sender, LinkLabelLinkClickedEventArgs e)
        {
            var CompSignup = new Signup_Company();
            CompSignup.Show();
            this.Hide();
        }

        private void LinkLabel4Clicked(object sender, LinkLabelLinkClickedEventArgs e)
        {
            var CompLogin = new Company_Login();
            CompLogin.Show();
            this.Hide();
            
        }

        private void LinkLabel5Clicked(object sender, LinkLabelLinkClickedEventArgs e)
        {
            var TraineeLogin = new Trainee_Login();
            TraineeLogin.Show();
            this.Hide();
        }

        private void linkLabel1_LinkClicked(object sender, LinkLabelLinkClickedEventArgs e)
        {
            linkLabel1.LinkClicked += new System.Windows.Forms.LinkLabelLinkClickedEventHandler(LinkLabel1Clicked);

        }

        private void linkLabel2_LinkClicked(object sender, LinkLabelLinkClickedEventArgs e)
        {
            linkLabel2.LinkClicked += new System.Windows.Forms.LinkLabelLinkClickedEventHandler(LinkLabel2Clicked);
        }

        private void linkLabel3_LinkClicked(object sender, LinkLabelLinkClickedEventArgs e)
        {
            linkLabel3.LinkClicked += new System.Windows.Forms.LinkLabelLinkClickedEventHandler(LinkLabel3Clicked);
        }

        private void linkLabel4_LinkClicked(object sender, LinkLabelLinkClickedEventArgs e)
        {
            linkLabel4.LinkClicked += new System.Windows.Forms.LinkLabelLinkClickedEventHandler(LinkLabel4Clicked);
        }

        private void linkLabel5_LinkClicked(object sender, LinkLabelLinkClickedEventArgs e)
        {
            linkLabel5.LinkClicked += new System.Windows.Forms.LinkLabelLinkClickedEventHandler(LinkLabel5Clicked);
        }

        private void pictureBox1_Click(object sender, EventArgs e)
        {

        }

        private void Home_Page_Load(object sender, EventArgs e)
        {

        }
    }
}
