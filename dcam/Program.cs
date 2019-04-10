using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using ManageClass;

namespace dcam
{

    [StructLayout(LayoutKind.Sequential, CharSet = CharSet.Ansi)]
    public struct Test
    {
        public int a;
        public int b;
        //[MarshalAs(UnmanagedType.SysInt, SizeConst = 32)]
        //public String User;
    }

    class Program
    {
        [DllImport("../CAMAPI.dll", EntryPoint = "Add", CallingConvention = CallingConvention.StdCall)]
        public static extern int Add(int x, int y);
        [DllImport("../CAMAPI.dll", EntryPoint = "ceateTest", CallingConvention = CallingConvention.StdCall)]
        //public static extern void  ceateTest(int x, int y, IntPtr test);// IntPtr
        public static extern void createTest(int x, int y, ref Test test);// ref
        [DllImport("../CAMAPI.dll", EntryPoint = "callTestByPoint", CallingConvention = CallingConvention.StdCall)]
        public static extern int callTest(ref Test testPtr);

        static void test()
        {
            // Console.WriteLine(Add(10, 12)); // test transfer by value

            //var res = new Test();
            //IntPtr pP1 = Marshal.AllocHGlobal(Marshal.SizeOf(typeof(Test)));
            //Marshal.WriteByte(pP1, 0);
            //Marshal.StructureToPtr(res, pP1, true);
            //ceateTest(10, 120, pP1);
            //res = (Test)Marshal.PtrToStructure(pP1, typeof(Test));

            var res = new Test();
            createTest(10, 20, ref res);

            //var res = new Test();
            //res.a = 10;
            //res.b = 20;
            Console.WriteLine(callTest(ref res));
            Console.ReadKey();
        }

        static void test_managedNative()
        {
            NativeClassEx test = new NativeClassEx();

            //test.Increase();
            //ClassInfoEx classInfo = new ClassInfoEx();
            //Console.WriteLine(test.GetCount());
            //test.getClassInfo(classInfo);
            String tmp = "hello world";
            test.setBufferContent(tmp, tmp.Length);
            test.getBufferContent();

            Console.ReadKey();

        }
       
        static void Main(string[] args)
        {
            test_managedNative();

        }
    }
}
