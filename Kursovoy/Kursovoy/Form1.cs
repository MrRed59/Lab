using System;
using System.Windows.Forms;

namespace Kursovoy
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
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
            int flagOV = 0;
            string c = Miltiplication(textBox3.Text, textBox4.Text, ref flagOV);
            CTextDec.Text = c; //вывод на экран
            CTextBin.Text = ConvBinToDec(c).ToString();

            isOVText.Text = flagOV.ToString();

            isPText.Text = FlagP(c).ToString();
        }

        private void disjunctionButtom_Click(object sender, EventArgs e)
        {
            string str = Disjunction(textBox3.Text, textBox4.Text);//результат дизъюнкции записывается в переменную

            CTextDec.Text = str;//вывод на экран
            CTextBin.Text = ConvBinToDec(str).ToString();

            isOVText.Text = "0";
            isPText.Text = FlagP(str).ToString();//проверка флага
        }

        static string Disjunction(string a, string b)
        {
            char[] arr = new char[16];

            for (int i = 0; i <= 15; i++)
            {
                if (a[i] == '1' || b[i] == '1')
                    arr[i] = '1';
                else
                    arr[i] = '0';
            }            

            return new string(arr);
        }

        static string Miltiplication(string a, string b, ref int flagOV)
        {
            string aShort = GetShortStr(a);
            string bShort = GetShortStr(b);
            string strFin = "";

            if (a[0] == '1' ^ b[0] == '1')
                strFin += '1';
            else
                strFin += '0';

            int lenghtArr = aShort.Length + bShort.Length;//длина массива

            if (lenghtArr >= 15)//ограничение длины массива в 15 бит
            {
                lenghtArr = 15;
                flagOV = 0;
            }

            char[] binary = new char[lenghtArr];//массив символов для рассчета умжонения

            for (int i = 0; i < binary.Length; i++)
                binary[i] = '0';

            for (int i = bShort.Length - 1; i >= 0; i--)
            {
                if (bShort[i] == '1')
                    AddWithElem(ref binary, aShort, ref flagOV);//битовое сложение

                if (lenghtArr == 15 && i == 0)
                    break;
                
                MakeRightShift(ref binary);//сдвиг вправо

                if (flagOV == 1)
                {
                    binary[i] = '1';
                    flagOV = 0;
                }
            }

            for (int i = 1; i <= 16 - binary.Length - 1; i++)
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

            for (int i = 0; i < arr.Length - 1; i++)
                tempArr[i + 1] = arr[i];

            arr = tempArr;
        }

        static void AddWithElem(ref char[] arr, string a, ref int flagOV)
        {
            char transferDischarge = '0';

            for (int i = a.Length - 1; i >= 0; i--)
            {
                if (transferDischarge == '1')
                {
                    if (i == 0)
                        flagOV = 1;

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

        static int ConvBinToDec(string binary)
        {
            if (binary.Length != 16)
            {
                throw new ArgumentException("Длина двоичного числа должна быть равна 16 бит");
            }

            // Определение знака числа
            int sign = (binary[0] == '1') ? -1 : 1;

            // Конвертация в десятичное число с учетом знака
            int decimalNumber = sign * Convert.ToInt32(binary.Substring(1), 2);
            return decimalNumber;
        }

        static int FlagP(string str)
        {
            int counterP = 0;

            for (int i = 0; i < str.Length; i++)
                if (str[i] == '1')
                    counterP++;

            if (counterP % 2 == 0)
                return 1;
            
            return 0;
        }
    }
}
