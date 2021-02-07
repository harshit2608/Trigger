#include <iostream>

namespace Trigger
{
    class Singleton
    {
    private:
        Singleton();
        Singleton(const Singleton&);
        Singleton& operator=(const Singleton&);
        static Singleton* single;
        static bool count;
        int i = 0;

    public:
        static Singleton* getInstance()
        {
            if (!count)
            {
                single = new Singleton();
                count = true;
                return single;
            }
            else
            {
                return single;
            }
        }

        void check()
        {
            i++;
            std::cout << "Hello from check!!!" << std::endl;
            std::cout << "Count is : " << i << std::endl;
        }
        ~Singleton()
        {
            count = false;
        }
    };

    bool Singleton::count = false;
    Singleton* Singleton::single = NULL;

    // int main()
    // {
    //     Singleton *ptr1, *ptr2;
    //     ptr1 = Singleton::getInstance();
    //     ptr1->check();
    //     ptr2 = Singleton::getInstance();
    //     ptr2->check();
    //     std::cin.get();
    // }
}

//TODO: Singleton Design Pattern:
//     Singleton design pattern ensures that only one instance of a class is created .
//     Example: Consider 2 transactions are happening from a account one is depositing money and one is depositing money. If there isn't a single instance of the class then both of them will result in different amounts

//         total =100
//         withdrawn = 50, deposited =100

//         final result might be 50 or 200 if there are multiple instances.

//     Singleton design pattern need a private constructor, private assignment operator, private copy constructor so that the client wont be able to create multiple instances of class. And an static public function that will return the object of that class.