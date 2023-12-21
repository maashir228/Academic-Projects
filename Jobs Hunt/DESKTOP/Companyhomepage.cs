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
    public partial class Companyhomepage : Form
    {
        public Companyhomepage()
        {
            this.BackColor = Color.AntiqueWhite;
            InitializeComponent();
        }
        private void LinkLabel5Clicked(object sender, LinkLabelLinkClickedEventArgs e)
        {
            var CompLogin = new Company_Login();
            CompLogin.Show();
            this.Hide();
        }
        private void linkLabel5_LinkClicked(object sender, LinkLabelLinkClickedEventArgs e)
        {
            linkLabel5.LinkClicked += new System.Windows.Forms.LinkLabelLinkClickedEventHandler(LinkLabel5Clicked);
        }
        private void LinkLabel3Clicked(object sender, LinkLabelLinkClickedEventArgs e)
        {
            var Compprofile = new Company_details();
            Compprofile.Show();
            this.Hide();
        }
        private void linkLabel3_LinkClicked(object sender, LinkLabelLinkClickedEventArgs e)
        {
            linkLabel3.LinkClicked += new System.Windows.Forms.LinkLabelLinkClickedEventHandler(LinkLabel3Clicked);
        }
        private void LinkLabel2Clicked(object sender, LinkLabelLinkClickedEventArgs e)
        {
            
        }
        private void linkLabel2_LinkClicked(object sender, LinkLabelLinkClickedEventArgs e)
        {
            linkLabel2.LinkClicked += new System.Windows.Forms.LinkLabelLinkClickedEventHandler(LinkLabel2Clicked);
        }

        private void Companyhomepage_Load(object sender, EventArgs e)
        {
            linkLabel4.Text = "Welcome "+Session.Username;
        }

        private void LinkLabel1Clicked(object sender, LinkLabelLinkClickedEventArgs e)
        {
            var trsearch = new traineesearch();
            trsearch.Show();
            this.Hide();
        }
        private void linkLabel1_LinkClicked(object sender, LinkLabelLinkClickedEventArgs e)
        {
            linkLabel1.LinkClicked += new System.Windows.Forms.LinkLabelLinkClickedEventHandler(LinkLabel1Clicked);
        }
    }
}
