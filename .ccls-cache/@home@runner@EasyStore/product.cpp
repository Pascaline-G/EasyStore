#include "product.h"

Product::Product(std::string title, std::string description, unsigned int quantity, float price): _title(title), _description(description), _quantity(quantity), _price(price)
{
  
}


std::string Product::getTitle() const
{
  return _title;
}

void Product::setTitle(std::string title)
{
  if(title != "")
    _title = title;
}

std::string Product::getDescription() const
{
  return _description;
}

void Product::setDescription(std::string description)
{
  if(description != "")
    _description = description;
}
unsigned int Product::getQuantity() const
{
  return _quantity;  
}

void Product::setQuantity( unsigned int quantity)
{
  _quantity = quantity;
}

float Product::getPrice() const
{
  return _price;
}
void Product::setPrice(float price)
{
  if(price > 0)
    _price = price;
}

void Product::changeQuantity(int quantity)
{
  _quantity += quantity;
}

std::ostream& operator<<(std::ostream& os, Product& product)
{
    os << product.getTitle() << ':' <<  product.getDescription() << std::endl;
    os << "quantité restante : " <<  product.getQuantity() << " . Prix unitaire : " << product.getPrice() << std::endl;
    return os;
}

bool operator == (Product const &prod1, Product const &prod2)
{
  return (prod1.getTitle() == prod2.getTitle());
}