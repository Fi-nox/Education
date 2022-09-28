using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CLS_Basics
{
        class ZinsesZins
        {
            // Berechnung des Zinseszins
            // Kn = K0 * q ^n
            // q =  1 + (p/100)

            private double Kapital = 0.0;
            private double Zinsen = 0.0;
            private int Jahre = 0;
            private byte Kommastellen = 0;
            private double Endkapital = 0.0;

            

            // Objektname.Methodenname(parameter,parameter)
            public double ZinsKapital(double kapital, double zinssatz, int jahre, byte kommastellen)
            {
                this.Kapital = kapital;
                this.Zinsen = zinssatz;
                this.Jahre = jahre;
                this.Kommastellen = kommastellen;
                
                double q = 1 + (Zinsen / 100);
                Endkapital = Kapital * Math.Pow(q,Jahre);

                return Math.Round(Endkapital,Kommastellen);

            }


        }

        internal class Program
         {
            static void Main(string[] args)
            {
            
            
            Console.WriteLine("Programmstart!");
        
            ZinsesZins z = new ZinsesZins();

            //Eingabe der Daten
            Console.WriteLine("Geben Sie das Startkapital in Euro ein: ");
            //double StartKapital = Convert.ToDouble(Console.ReadLine());
            double StartKapital = double.Parse(Console.ReadLine());

            Console.WriteLine("Geben Sie die Zinsen in Prozent ein: ");
            double ZinsSatz = Convert.ToDouble(Console.ReadLine());

            Console.WriteLine("Geben Sie die Laufzeit in Jahren ein: "); 
            int Laufzeit = Convert.ToInt32(Console.ReadLine());

            Console.WriteLine("Geben Sie die Kommastellen ein: ");
            byte Stellen = Convert.ToByte(Console.ReadLine());

            // Ausgabe des Ergebniss
            Console.WriteLine("Das Endkapital beträgt: ");
            Console.WriteLine(z.ZinsKapital(StartKapital, ZinsSatz, Laufzeit, Stellen) + "Euro");




            Console.ReadKey();
            }
    }
}
