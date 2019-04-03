using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;

namespace dcam
{
    class Program
    {
        [DllImport("../CAMAPI.dll", EntryPoint = "Add", CallingConvention = CallingConvention.StdCall)]
        public static extern int Add(int x, int y);

        static void Main(string[] args)
        {
            Console.WriteLine(Add(10, 12));
            Console.ReadKey();
        }
    }
}
