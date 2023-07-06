//animal.h
class Animal
{
    protected:
        std::string name;
        int age;
    public:
        Animal(std::string name_, int age_);
        virtual void printInfo();
};

class Zebra: public Animal
{
    private:
        int numStripes;
    public:
        Zebra(std::string name_, int age_, int numStripe_);
        virtual void printInfo();
};

class Cat: public Animal
{
    private:
        std::string favoriteToy;
    public:
        Cat(std::string name_, int age_, std::string favoriteToy_);
        virtual void printInfo();
};
