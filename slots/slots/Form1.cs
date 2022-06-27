using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Threading;

namespace slots
{
    public partial class Form1 : Form
    {
        int coins;
        public Form1()
        {
            InitializeComponent();
            coins = 100;
            pictureBox1.Image = Properties.Resources.ash_pikachu;
            pictureBox2.Image = Properties.Resources.ash_pikachu;
            pictureBox3.Image = Properties.Resources.ash_pikachu;
            pictureBox4.Image = Properties.Resources.pokeball;
        }

        private void button1_Click(object sender, EventArgs e)
        {
            if (coins < 10)
            {
                return;
            }
            Random r = new Random();
            coins = coins - 10;
            int num1 = r.Next(6);
            int num2 = r.Next(6);
            int num3 = r.Next(6);


            switch (num1)
            {
                case 0:
                    pictureBox1.Image = Properties.Resources.ash_pikachu;
                    break;
                case 1:
                    pictureBox1.Image = Properties.Resources.butterfree; 
                    break;
                case 2:
                    pictureBox1.Image = Properties.Resources.pidgeot;
                    break;
                case 3:
                    pictureBox1.Image = Properties.Resources.bulbasaur;
                    break;
                case 4:
                    pictureBox1.Image = Properties.Resources.squirtle;
                    break;
                case 5:
                    pictureBox1.Image = Properties.Resources.charizard;
                    break;
            }

            switch (num2)
            {
                case 0:
                    pictureBox2.Image = Properties.Resources.ash_pikachu;
                    break;
                case 1:
                    pictureBox2.Image = Properties.Resources.butterfree;
                    break;
                case 2:
                    pictureBox2.Image = Properties.Resources.pidgeot;
                    break;
                case 3:
                    pictureBox2.Image = Properties.Resources.bulbasaur;
                    break;
                case 4:
                    pictureBox2.Image = Properties.Resources.squirtle;
                    break;
                case 5:
                    pictureBox2.Image = Properties.Resources.charizard;
                    break;
            }

            switch (num3)
            {
                case 0:
                    pictureBox3.Image = Properties.Resources.ash_pikachu;
                    break;
                case 1:
                    pictureBox3.Image = Properties.Resources.butterfree;
                    break;
                case 2:
                    pictureBox3.Image = Properties.Resources.pidgeot;
                    break;
                case 3:
                    pictureBox3.Image = Properties.Resources.bulbasaur;
                    break;
                case 4:
                    pictureBox3.Image = Properties.Resources.squirtle;
                    break;
                case 5:
                    pictureBox3.Image = Properties.Resources.charizard;
                    break;
            }

            if (num1 + num2 + num3 == 0)
            {
                coins = coins + 100;
            }
            else if(num1*num2+num1*num3+num2*num3==0)
            {
                coins = coins + 20;
            }
            else if (num1 * num2 * num3 == 0)
            {
                coins = coins + 10;
            }

            label1.Text = coins.ToString();
            
        }
    }
}
