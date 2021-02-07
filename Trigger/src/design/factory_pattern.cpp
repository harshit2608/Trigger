#include <iostream>

namespace Trigger
{
    enum VehicleType
    {
        One_Wheeler = 0,
        Two_Wheeler,
        Three_Wheeler,
        Four_Wheeler
    };

    class Vehicle
    {
    public:
        virtual void printVehicle() = 0;
    };

    class OneWheeler : public Vehicle
    {
        void printVehicle() override
        {
            std::cout << "One Wheeler\n";
        }
    };

    class TwoWheeler : public Vehicle
    {
        void printVehicle() override
        {
            std::cout << "Two Wheeler\n";
        }
    };

    class ThreeWheeler : public Vehicle
    {
        void printVehicle() override
        {
            std::cout << "Three Wheeler\n";
        }
    };
    class FourWheeler : public Vehicle
    {
        void printVehicle() override
        {
            std::cout << "Four Wheeler\n";
        }
    };

    class Factory
    {
    public:
        Factory()
        {
            std::cout << "Factory\n";
        }

        static Vehicle *Create(VehicleType type)
        {
            if (type == One_Wheeler)
            {
                return new OneWheeler();
            }
            else if (type == Two_Wheeler)
            {
                return new TwoWheeler();
            }
            else if (type == Three_Wheeler)
            {
                return new ThreeWheeler();
            }
            else if (type == Four_Wheeler)
            {
                return new FourWheeler();
            }
            else
            {
                return NULL;
            }
        }
    };

    // int main()
    // {
    //     VehicleType type = One_Wheeler;
    //     Vehicle *ptr = NULL;
    //     ptr = Factory::Create(type);
    //     ptr->printVehicle();

    //     type = Two_Wheeler;
    //     ptr->printVehicle();

    //     type = Three_Wheeler;
    //     ptr->printVehicle();

    //     type = Four_Wheeler;
    //     ptr->printVehicle();
    //     std::cin.get();
    // }
} // namespace Trigger

// TODO: Factory Design pattern
//     We declared static Vehicle Create because we dont want to compile our code again and again
// and dont want to make tightly coupled