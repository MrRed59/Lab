using System;
using System.Threading;
using Microsoft.VisualStudio.TestTools.UnitTesting;
using ClassLibraryLab10;


namespace UnitTestProject1
{
    [TestClass]
    public class UnitTestPerson
    {
        [TestMethod]
        public void TestCtor1Person()
        {
            var p = new Person();
            var testP = new Person("-", "-", '-', 0);
            Assert.AreEqual(p, testP);
        }

        [TestMethod]
        public void TestCtor2Person()
        {
            var p = new Person("Alex", "Erypalov", 'м', 24);
            Assert.AreEqual(p, new Person("Alex", "Erypalov", 'м', 24));
        }

        [TestMethod]
        public void TestShallowCopy()
        {
            var obj = new Person();
            var newObj = (Person)obj.ShallowCopy();

            Assert.IsInstanceOfType(obj, typeof(Person));
            Assert.AreNotSame(newObj, obj); //Проверяет, ссылаются ли указанные объекты на разные объекты
        }

        [TestMethod]
        public void TestClone()
        {
            var obj = new Person();
            var newObj = (Person)obj.Clone();

            Assert.IsInstanceOfType(obj, typeof(Person));
            Assert.AreNotSame(newObj, obj);
        }

        [TestMethod]
        public void TestRandomInit()
        {
            for (int i = 0; i < 100000; i++)
            {
                var org = new Person();
                org.RandomInit();
                org.Show();
            }            
        }

        [TestMethod]
        public void TestShowOverload()
        {
            var org = new Person();
            org.ShowOverload();
        }

        [TestMethod]
        public void TestCompareTo()
        {
            var arr = new Person[5] {   new Person(), 
                                        new Person("-", "-", '-', 24), 
                                        new Person("-", "-", '-', 14), 
                                        new Person("-", "-", '-', 24),
                                        new Person("-", "-", '-', 34)};
            Array.Sort(arr);
            Array.Sort(arr, new SortByAge());
        }

        [TestMethod]
        public void TestToString()
        {
            var p = new Person();
            p.ToString();
        }
    }

    [TestClass]
    public class UnitTestStudent
    {
        [TestMethod]
        public void TestCtor1Student()
        {
            var p = new Student();
            var testP = new Student("-", "-", '-', 0, 0, "-");
            Assert.AreEqual(p, testP);
        }

        [TestMethod]
        public void TestCtor2Student()
        {
            var p = new Student("Alex", "Erypalov", 'м', 24, 4, "ПНИПУ");
            Assert.AreEqual(p, new Student("Alex", "Erypalov", 'м', 24, 4, "ПНИПУ"));
        }

        [TestMethod]
        public void TestShallowCopy()
        {
            var obj = new Student();
            var newObj = (Student)obj.ShallowCopy();

            Assert.IsInstanceOfType(obj, typeof(Student));
            Assert.AreNotSame(newObj, obj); //Проверяет, ссылаются ли указанные объекты на разные объекты
        }

        [TestMethod]
        public void TestClone()
        {
            var obj = new Student();
            var newObj = (Student)obj.Clone();

            Assert.IsInstanceOfType(obj, typeof(Student));
            Assert.AreNotSame(newObj, obj);
        }

        [TestMethod]
        public void TestRandomInit()
        {
            for (int i = 0; i < 100000; i++)
            {
                var org = new Student();
                org.RandomInit();
                org.Show();
            }
        }

        [TestMethod]
        public void TestShowOverload()
        {
            var org = new Student();
            org.ShowOverload();
        }

        [TestMethod]
        public void TestCompareTo()
        {
            var arr = new Student[2] { new Student(), new Student() };
            Array.Sort(arr);
        }

        [TestMethod]
        public void TestToString()
        {
            var p = new Student();
            p.ToString();
        }
    }

    [TestClass]
    public class UnitTestEmployee
    {
        [TestMethod]
        public void TestCtor1Student()
        {
            var p = new Employee();
            var testP = new Employee("-", "-", '-', 0, 0, "-");
            Assert.AreEqual(p, testP);
        }

        [TestMethod]
        public void TestCtor2Student()
        {
            var p = new Employee("Alex", "Erypalov", 'м', 24, 4000, "ПНИПУ");
            Assert.AreEqual(p, new Employee("Alex", "Erypalov", 'м', 24, 4000, "ПНИПУ"));
        }

        [TestMethod]
        public void TestShallowCopy()
        {
            var obj = new Employee();
            var newObj = (Employee)obj.ShallowCopy();

            Assert.IsInstanceOfType(obj, typeof(Employee));
            Assert.AreNotSame(newObj, obj); //Проверяет, ссылаются ли указанные объекты на разные объекты
        }

        [TestMethod]
        public void TestClone()
        {
            var obj = new Employee();
            var newObj = (Employee)obj.Clone();

            Assert.IsInstanceOfType(obj, typeof(Employee));
            Assert.AreNotSame(newObj, obj);
        }

        [TestMethod]
        public void TestRandomInit()
        {
            for (int i = 0; i < 100000; i++)
            {
                var org = new Employee();
                org.RandomInit();
                org.Show();
            }
        }

        [TestMethod]
        public void TestShowOverload()
        {
            var org = new Employee();
            org.ShowOverload();
        }

        [TestMethod]
        public void TestCompareTo()
        {
            var arr = new Employee[2] { new Employee(), new Employee() };
            Array.Sort(arr);
        }

        [TestMethod]
        public void TestToString()
        {
            var p = new Employee();
            p.ToString();
        }
    }


    [TestClass]
    public class UnitTestTeacher
    {
        [TestMethod]
        public void TestCtor1Student()
        {
            var p = new Teacher();
            var testP = new Teacher("-", "-", '-', 0, 0, "-", "-");
            Assert.AreEqual(p, testP);
        }

        [TestMethod]
        public void TestCtor2Student()
        {
            var p = new Teacher("Alex", "Erypalov", 'м', 24, 4, "ПНИПУ", "Математика");
            Assert.AreEqual(p, new Teacher("Alex", "Erypalov", 'м', 24, 4, "ПНИПУ", "Математика"));
        }

        [TestMethod]
        public void TestShallowCopy()
        {
            var obj = new Teacher();
            var newObj = (Teacher)obj.ShallowCopy();

            Assert.IsInstanceOfType(obj, typeof(Teacher));
            Assert.AreNotSame(newObj, obj); //Проверяет, ссылаются ли указанные объекты на разные объекты
        }

        [TestMethod]
        public void TestClone()
        {
            var obj = new Teacher();
            var newObj = (Teacher)obj.Clone();

            Assert.IsInstanceOfType(obj, typeof(Teacher));
            Assert.AreNotSame(newObj, obj);
        }

        [TestMethod]
        public void TestRandomInit()
        {
            for (int i = 0; i < 100000; i++)
            {
                var org = new Teacher();
                org.RandomInit();
                org.Show();
            }
        }

        [TestMethod]
        public void TestShowOverload()
        {
            var org = new Teacher();
            org.ShowOverload();
        }

        [TestMethod]
        public void TestCompareTo()
        {
            var arr = new Teacher[2] { new Teacher(), new Teacher() };
            Array.Sort(arr);
        }

        [TestMethod]
        public void TestToString()
        {
            var p = new Teacher();
            p.ToString();
        }
    }
      
}
