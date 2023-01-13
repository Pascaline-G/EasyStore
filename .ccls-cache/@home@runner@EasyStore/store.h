#ifndef H_MAGASIN
#define H_MAGASIN

#include "client.h"
#include "order.h"
#include "product.h"
#include <vector>

class Store {
public:
  Store(std::vector<Product> products = {}, std::vector<Client> clients = {},
        std::vector<Order> orders = {});
  void addProduct(Product product);
  void addClient(Client client);
  void showClients() const;
  void showClient(unsigned id);
  void showProducts();
  void showProduct(std::string title);
  void showPreviousOrder() const;
  void showPreviousOrder(const Client &c) const;
  void setQuantity(std::string title, unsigned int quantity);
  void addProductToClient(unsigned idClient, Product product);
  void deleteProductToClient(unsigned idClient, Product product);
  void setQuantityProductToClient(unsigned idClient, Product product, unsigned quantity);
  void validateOrder(Client &client);
  void changeStatusOrder(Order order, STATUS_ORDER status);

private:
  std::vector<Product> _products;
  std::vector<Client> _clients;
  std::vector<Order> _orders;
  Product *findProduct(std::string title);
  Client *findClient(unsigned id);
};

#endif