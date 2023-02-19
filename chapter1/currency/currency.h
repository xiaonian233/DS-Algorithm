#ifndef Currency_
#define Currency_
#include<iostream>
using namespace std;

class currency
{
friend ostream& operator<<(ostream& out, const currency& x)
{
    x.output(out);
    return out;
}
private:
    long amount;
public:
    currency()
    {
        setValue(0,0);
    }
    currency(unsigned long theDollars, unsigned int theCent)
    {
        setValue(theDollars,theCent);
    }
    void setValue(unsigned long theDollors, unsigned int theCents)
    {
        amount = theDollors * 100 + theCents;
        if(amount < 0)amount=(-amount);
    }
    void setValue(double theAmount)
    {
        if(theAmount < 0)amount = (long)((theAmount - 0.001) * 100);
        else amount = (long)((theAmount + 0.001) * 100);
    }
    unsigned long getDollars() const
    {
        if(amount < 0)return (-amount) / 100;
        else return amount / 100;
    }
    unsigned int getCents() const
    {
        if(amount < 0)return -amount - getDollars() * 100;
        else return amount - getDollars() * 100;
    }
    //1-16-1
    currency& input()
    {
        unsigned long theDollors = 0;
        unsigned int theCents = 0;
        printf("Input dollars amount: \n");
        scanf("%d",&theDollors);
        printf("Input cents amount: \n");
        scanf("%d",&theCents);
        setValue(theDollors,theCents);
        return *this;
    }
    //1-16-2
    currency& subtract(const currency &x)
    {
        amount -= x.amount;
        return *this;
    }//后面几个方法同理，这里不写了
    currency operator+(const currency &x) const
    {
        currency rel;
        rel.amount = amount + x.amount;
        return rel;
    }
    currency& operator+=(const currency &x)
    {
        amount+= x.amount;
        return *this;
    }
    void output(ostream& out) const
    {
        long theAmount = amount;
        if(theAmount < 0)
        {
            out << '-';
            theAmount =- theAmount;
        }
        long dollars = theAmount / 100;
        out << '$' << dollars <<'.';
        int cents = theAmount - dollars * 100;
        if(cents < 10) out << '0';
        out << cents;
    }
};
#endif