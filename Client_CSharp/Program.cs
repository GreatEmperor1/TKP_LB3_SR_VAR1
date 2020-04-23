using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Client_CSharp
{
    class Program
    {
        static void Main(string[] args)
        {
            float z11, d12;
            double out13;
            System.Type objType = System.Type.GetTypeFromProgID("Server.CoFun.1");
            dynamic comObject = System.Activator.CreateInstance(objType);
            z11 = comObject.Fun11(10, 15);
            d12 = comObject.Fun12(10, 15, 5);
            out13 = comObject.Fun13(0.25);
            Console.WriteLine("Fun11 result is " + z11 + "\n");
            Console.WriteLine("Fun12 result is " + d12 + "\n");
            Console.WriteLine("Fun13 result is " + out13 + "\n");
            Console.ReadLine();
        }
    }
}
