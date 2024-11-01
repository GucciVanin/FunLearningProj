#include <string>
#include <compare>
#include <iostream>
#include <cmath>
#include <utility>
#include "BeverageItem.hpp"

namespace {
    template<typename T, typename U> requires std::is_floating_point_v<std::common_type_t<T, U>>
    constexpr bool floating_point_is_equal(T const lhs, U const rhs, double const EPSILON=1e-4) noexcept{
        return std::abs(lhs - rhs) < EPSILON;
    }
}

//Constructor
BeverageItem::BeverageItem(std::string brandName, std::string productName, std::string upcCode, double price, int invQuant):_brandName(std::move(brandName)), _productName(std::move(productName)), _upcCode(std::move(upcCode)), _price(std::move(price)), _invQuant(std::move(invQuant)){}


//Rule of Five
BeverageItem::BeverageItem(BeverageItem const & other):_productName(other.getProductName()), _brandName(other.getBrandName()), _upcCode(other.getUpcCode()), _price(other.getPrice()), _invQuant(other.getInvQuant()){}

BeverageItem::BeverageItem(BeverageItem && other) noexcept: _productName(std::move(other.getProductName())), _brandName(std::move(other.getBrandName())), _upcCode(std::move(other.getUpcCode())), _price(std::move(other.getPrice())), _invQuant(std::move(other.getInvQuant())){}

BeverageItem & BeverageItem::operator=(BeverageItem & rhs) & {
    _productName = rhs.getProductName();
    _brandName = rhs.getBrandName();
    _upcCode = rhs.getUpcCode();
    _price = rhs.getPrice();
    _invQuant = rhs.getInvQuant();

    return *this;
}

BeverageItem & BeverageItem::operator=(BeverageItem && rhs) & noexcept {
    _productName = std::move(rhs.getProductName());
    _brandName = std::move(rhs.getBrandName());
    _upcCode = std::move(rhs.getUpcCode());
    _price = std::move(rhs.getPrice());
    _invQuant = std::move(rhs.getInvQuant());

    return *this;
}

//Destructor
BeverageItem::~BeverageItem(){};

//Accessors
std::string const & BeverageItem::getBrandName() const & {
    return _brandName;
}
std::string const & BeverageItem::getProductName() const & {
    return _productName;
}
std::string const & BeverageItem::getUpcCode() const & {
    return _upcCode;
}
double BeverageItem::getPrice() const & {
    return _price;
}
int BeverageItem::getInvQuant() const & {
    return _invQuant;
}

//Accessor for r-values
std::string BeverageItem::getBrandName() && {
    return std::move(this->_brandName);
}
std::string BeverageItem::getProductName() && {
    return std::move(this->_productName);
}
std::string BeverageItem::getUpcCode() && {
    return std::move(this->_upcCode);
}

//Modifiers
BeverageItem & BeverageItem::brandName(std::string brandName) & {
    _brandName = std::move(brandName);
    return *this;
}
BeverageItem & BeverageItem::productName(std::string productName) & {
    _productName = std::move(productName);
    return *this;
}
BeverageItem & BeverageItem::upcCode(std::string upcCode) & {
    _upcCode = std::move(upcCode);
    return *this;
}
BeverageItem & BeverageItem::price(double price)          & {
    _price = std::move(price);
    return *this;
}
BeverageItem & BeverageItem::invQuant(int invQuant)          & {
    _invQuant = std::move(invQuant);
    return *this;
}

//Relational Operators
std::weak_ordering BeverageItem::operator<=>(BeverageItem & rhs ) const noexcept {
    /*Compare based on a set hierarchy: brandName -> productName -> upcCode */

    if(auto result = _brandName <=> rhs.getBrandName(); result != 0) return result;
    if(auto result = _productName <=> rhs.getProductName(); result != 0) return result;
    if(auto result = _upcCode <=> rhs.getUpcCode(); result != 0) return result;

    if(floating_point_is_equal(_price, rhs.getPrice())) return std::weak_ordering::equivalent;
    if(_price > rhs.getPrice()) return std::weak_ordering::greater;
    if(_price < rhs.getPrice()) return std::weak_ordering::less;

}

bool BeverageItem::operator==(BeverageItem & rhs ) const noexcept {
    return _brandName == rhs.getBrandName() && _productName == rhs.getProductName() && 
    _upcCode == rhs.getUpcCode() && 
    floating_point_is_equal(_price, rhs.getPrice());
}




