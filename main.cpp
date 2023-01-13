#include "client.h"
#include "order.h"
#include "store.h"
#include <iostream>

int main() {
  Store mag;
  Product p("test", "produit test", 5, 1.2);
  Product p2("tes2t", "produit tes2t", 5, 7.2);
  Product p3("salut", "produit tes2t", 5, 7.2);
  mag.addProduct(p);
  mag.addProduct(p);
  mag.addProduct(p2);
  mag.addProduct(p3);
  mag.showProducts();
  mag.showProduct("test");

  Client c(1, "a", "b");
  Client c2(2, "aaa", "bcc");
  c.addProduct(p);
  c.addProduct(p);
  c.addProduct(p2);
  c.deleteProduct(p2);
  c.addProduct(p2);

  mag.addClient(c);
  mag.addClient(c2);
  mag.showClients();
  mag.addProductToClient(c.getId(), p3);
  ;
  mag.showClient(c.getId());

  mag.validateOrder(c);

  std::cout << c << std::endl;

  mag.showPreviousOrder();
}