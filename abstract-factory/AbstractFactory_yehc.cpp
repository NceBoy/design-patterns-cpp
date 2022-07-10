# include "stdio.h"

class BaseCloth
{
public:
    virtual int get_cloth_prices() = 0;
};

class BaseShoes
{
public:
    virtual int get_shoes_prices() = 0;
};


class AdwCloth: public BaseCloth
{
public:
    int get_cloth_prices()
    {
        return price;
    }
private:
    int price = 20;
};

class AdwShoes: public BaseShoes
{
public:
    int get_shoes_prices()
    {
        return price;
    }
private:
    int price = 10;
};

class HxekCloth: public BaseCloth
{
public:
    int get_cloth_prices()
    {
        return price;
    }
private:
    int price = 20;
};

class HxekShoes: public BaseShoes
{
public:
    int get_shoes_prices()
    {
        return price;
    }
private:
    int price = 10;
};

int sum_price(BaseCloth* cloth, BaseShoes* shoes)
{
    return cloth->get_cloth_prices() + shoes->get_shoes_prices();
};


class BaseFactory
{
public:
    virtual BaseCloth* create_cloth() = 0;
    virtual BaseShoes* create_shoes() = 0;
};


class HxekFactory: public BaseFactory
{
public:
    BaseCloth* create_cloth()
    {
        return new HxekCloth();
    }

    BaseShoes* create_shoes()
    {
        return new HxekShoes();
    }
};

class AdwFactory: public BaseFactory
{
public:
    AdwCloth* create_cloth()
    {
        return new AdwCloth();
    }

    AdwShoes* create_shoes()
    {
        return new AdwShoes();
    }
};

int sum_price(BaseFactory* factory)
{
    return factory->create_cloth()->get_cloth_prices() + 
        factory->create_shoes()->get_shoes_prices();
};

int main()
{
    AdwFactory* adw_factory_ptr = new AdwFactory();
    int price = sum_price(adw_factory_ptr);
    printf("adw price is: %d\n", price);
    delete adw_factory_ptr;
}