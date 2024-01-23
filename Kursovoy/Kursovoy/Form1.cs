using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Kursovoy
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        string DecimalToBinary(short value)
        {
            char[] binary = new char[16];

            if (value >= 0)
                binary[0] = '0';
            else
                binary[0] = '1';

            
            for (int i = 15; i > 0; i--)
            {
                binary[i] = (value % 2 == 0) ? '0' : '1';
                value = (short)(value / 2);
            }

            return new string(binary);
        }

        private void button1_Click(object sender, EventArgs e)
        {
            string str = textBox1.Text;
            textBox3.Text = DecimalToBinary(Convert.ToInt16(str));
            str = textBox2.Text;
            textBox4.Text = DecimalToBinary(Convert.ToInt16(str));
        }

        private void multiplicationButtom_Click(object sender, EventArgs e)
        {
            textBox5.Text = Miltiplication(textBox3.Text, textBox4.Text);
        }

        private void disjunctionButtom_Click(object sender, EventArgs e)
        {
            textBox5.Text = Disjunction(textBox3.Text, textBox4.Text);
        }

        static string Disjunction(string a, string b)
        {
            char[] arr = new char[16];

            for (int i = 0; i < 15; i++)
            {
                if (a[i] == '1' || b[i] == '1')
                    arr[i] = '1';
                else
                    arr[i] = '0';
            }            

            return new string(arr);
        }

        static string Miltiplication(string a, string b)
        {
            string aShort = GetShortStr(a);
            string bShort = GetShortStr(b);
            string strFin = "";

            if (a[0] == '1' ^ b[0] == '1')
                strFin += '1';
            else
                strFin += '0';

            char[] binary = new char[aShort.Length + bShort.Length];

            for (int i = 0; i < binary.Length - 1; i++)
                binary[i] = '0';

            for (int i = 0; i < bShort.Length - 1; i++)
            {
                if (bShort[i] == '1')
                    AddWithElem(ref binary, aShort);     //битовое сложение
                
                MakeRightShift(ref binary);         //сдвиг вправо
            }

            for (int i = 1; i <= 16 - binary.Length; i++)
            {
                strFin += '0';
            }

            strFin += new string(binary);

            return strFin;
        }

        static void MakeRightShift(ref char[] arr)
        {
            char[] tempArr = new char[arr.Length];

            tempArr[0] = '0';

            for (int i = 0; i < arr.Length - 2; i++)
                tempArr[i + 1] = arr[i];

            arr = tempArr;
        }

        static void AddWithElem(ref char[] arr, string a)
        {
            char transferDischarge = '0';

            for (int i = arr.Length - a.Length - 1; i >= 0; i--)
            {
                if (transferDischarge == '1')
                {
                    if (arr[i] == '1' && a[i] == '1')
                        transferDischarge = '1';
                    else if(arr[i] == '1' || a[i] == '1')
                    {
                        arr[i] = '0';
                        transferDischarge = '1';
                    }
                    else
                    {
                        arr[i] = '1';
                        transferDischarge = '0';
                    }
                }
                else
                {
                    if (arr[i] == '1' && a[i] == '1')
                    {
                        arr[i] = '0';
                        transferDischarge = '1';
                    }
                    else if (arr[i] == '1' || a[i] == '1')
                    {
                        arr[i] = '1';
                        transferDischarge = '0';
                    }
                    else
                    {
                        arr[i] = '0';
                        transferDischarge = '0';
                    }
                }
            }
        }

        static string GetShortStr(string str)
        {
            string newStr = "";

            bool isStart = false;

            for (int i = 1; i < str.Length; i++)
            {
                if (str[i] == '1' || isStart)
                {
                    newStr += str[i];
                    isStart = true;
                }
            }

            return newStr;
        }
    }
}
