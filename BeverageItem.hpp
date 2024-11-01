#pragma once // Ensure NO Repetition of Methods in the class

#include <compare> //std::weak_comparison to ensure no item repetition
#include <iostream> //Input & Output
#include <string>

class BeverageItem{
    private:
        std::string _brandName;
        std::string _productName;
        std::string _upcCode;
        double _price;
        int _invQuant;

    public:
        BeverageItem(std::string brandName = {},
                    std::string productName = {},
                    std::string upcCode = {},
                    double price = 0.0,
                    int invQuant = 0); //Constructor for each Item in the catalog


        //Rule of Five - Ensure Deep Copy in all copy operations (Memory Management)
        BeverageItem & operator=(BeverageItem       &   rhs)    &           ;   //rhs is a l-value & not overloaded r-value
        BeverageItem & operator=(BeverageItem       &&  rhs)    &   noexcept;   //rhs is an overloaded r-value
        BeverageItem            (BeverageItem const &   other)              ;
        BeverageItem            (BeverageItem       &&  other)      noexcept;
        ~BeverageItem           ()                                          ;


        //Accessors - Ensure access to private class variables
        //Returns a constant reference for l-value
        std::string const & getBrandName    ()  const &;
        std::string const & getProductName  ()  const &;
        std::string const & getUpcCode      ()  const &;
        double              getPrice        ()  const &;
        int                 getInvQuant     ()  const &;

        //Returns a r-value by value and not by reference since using reference as r-value would be unsafe 
        //(could be deleted if destructor is called)
        std::string getBrandName        () &&;
        std::string getProductName      () &&;
        std::string getUpcCode          () &&;

        //Modifiers
        BeverageItem & brandName(std::string brandName) &;
        BeverageItem & productName(std::string productName) &;
        BeverageItem & upcCode(std::string upcCode) &;
        BeverageItem & price(double price)          &;
        BeverageItem & invQuant(int invQuant)          &;


        //Relational Operators
        std::weak_ordering  operator<=> (BeverageItem & rhs) const noexcept;
        bool                operator==  (BeverageItem & rhs) const noexcept;

        //Input and Output Handling
        friend std::ostream & operator<<(std::ostream stream, BeverageItem const & beverageItem);
        friend std::istream & operator>>(std::istream stream, BeverageItem         beverageItem);
        
};