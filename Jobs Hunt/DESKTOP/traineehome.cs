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
    public partial class traineehome : Form
    {
        public traineehome()
        {
            this.BackColor = Color.AntiqueWhite;
            InitializeComponent();
        }

        private void traineehome_Load(object sender, EventArgs e)
        {
            linkLabel4.Text = "Welcome " + Session.Username;
        }
        private void LinkLabel5Clicked(object sender, LinkLabelLinkClickedEventArgs e)
        {
            var tlogin = new Trainee_Login();
            tlogin.Show();
            this.Hide();
        }
        private void linkLabel5_LinkClicked_1(object sender, LinkLabelLinkClickedEventArgs e)
        {
            linkLabel5.LinkClicked += new System.Windows.Forms.LinkLabelLinkClickedEventHandler(LinkLabel5Clicked);
        }
        private void linkLabel2_LinkClicked(object sender, LinkLabelLinkClickedEventArgs e)
        {

        }
        private void LinkLabel3Clicked(object sender, LinkLabelLinkClickedEventArgs e)
        {
            var up = new Userprofile();
            up.Show();
            this.Hide();
        }
        private void linkLabel3_LinkClicked(object sender, LinkLabelLinkClickedEventArgs e)
        {
            linkLabel3.LinkClicked += new System.Windows.Forms.LinkLabelLinkClickedEventHandler(LinkLabel3Clicked);
        }
        private void LinkLabel1Clicked(object sender, LinkLabelLinkClickedEventArgs e)
        {
            var js = new jobsearch();
            js.Show();
            this.Hide();
        }
        private void linkLabel1_LinkClicked(object sender, LinkLabelLinkClickedEventArgs e)
        {
            linkLabel1.LinkClicked += new System.Windows.Forms.LinkLabelLinkClickedEventHandler(LinkLabel1Clicked);
        }
    }
}
