#ifndef PRODUIT_H
#define PRODUIT_H

#include <iostream>
#include <string>

class Product {
public:
  Product(std::string title = "", std::string description = "",
          unsigned int quantity = 0, float price = 0.0);
  std::string getTitle() const;
  void setTitle(std::string title);
  std::string getDescription() const;
  void setDescription(std::string description);
  unsigned int getQuantity() const;
  void setQuantity(unsigned int quantity);
  float getPrice() const;
  void setPrice(float price);
  void changeQuantity(int quantity);
  friend std::ostream &operator<<(std::ostream &os, Product &product);

private:
  std::string _title;
  std::string _description;
  unsigned int _quantity;
  float _price;
};

bool operator==(Product const &prod1, Product const &prod2);
#endif