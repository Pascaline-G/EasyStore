#ifndef CLIENT_H
#define CLIENT_H

#include "product.h"
#include <string>
#include <unordered_map>
#include <iostream>

class Client {
public:
  Client(unsigned id, std::string firstname, std::string name);

  unsigned getId() const;
  std::string getFirstName() const;
  std::string getName() const;
  void setFirstName(std::string firstname);
  void setName(std::string name);
  std::unordered_map<std::string, unsigned> getProducts() const;
  void setQuantity(const Product &product, unsigned quantity);
  void showPanier() const;
  void addProduct(const Product &product);
  void deleteProduct(const Product &product);
  void clearProducts();

friend std::ostream &operator<<(std::ostream &os, const Client &client);

private:
  unsigned _id;
  std::string _firstname;
  std::string _name;

  //Hash map en C++
  std::unordered_map<std::string, unsigned> _products;
};



#endif