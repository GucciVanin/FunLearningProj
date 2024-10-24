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

