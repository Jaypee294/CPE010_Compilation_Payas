#include <iostream>
#include <string>

class Fruit {
private:
    std::string name;
    double price;
    int quantity;

public:
    Fruit(std::string n = "", double p = 0, int q = 0) {
        name = n;
        price = p;
        quantity = q;
    }

    ~Fruit() {
    }

    Fruit(const Fruit &copy) {
        name = copy.name;
        price = copy.price;
        quantity = copy.quantity;
    }

    Fruit& operator=(const Fruit &copy) {
        if (this != &copy) {
            name = copy.name;
            price = copy.price;
            quantity = copy.quantity;
        }
        return *this;
    }

    double calculateSum() {
        return price * quantity;
    }

    void display() {
        std::cout << "Fruit: " << name
                << " | Price: PHP " << price
                << " | Quantity: " << quantity
                << " | Total: PHP " << calculateSum()
                << std::endl;
    }
};

class Vegetable {
private:
    std::string name;
    double price;
    int quantity;

public:
    Vegetable(std::string n = "", double p = 0, int q = 0) {
        name = n;
        price = p;
        quantity = q;
    }

    ~Vegetable() {
    }

    Vegetable(const Vegetable &copy) {
        name = copy.name;
        price = copy.price;
        quantity = copy.quantity;
    }

    Vegetable& operator=(const Vegetable &copy) {
        if (this != &copy) {
            name = copy.name;
            price = copy.price;
            quantity = copy.quantity;
        }
        return *this;
    }

    double calculateSum() {
        return price * quantity;
    }

    void display() {
        std::cout << "Vegetable: " << name
                << " | Price: PHP " << price
                << " | Quantity: " << quantity
                << " | Total: PHP " << calculateSum()
                << std::endl;
    }
};

double TotalSum(Fruit *fruits[], int fruitCount,
                Vegetable *vegetables[], int vegetableCount) {

    double total = 0;

    for (int i = 0; i < fruitCount; i++) {
        if (fruits[i] != NULL)
            total += fruits[i]->calculateSum();
    }

    for (int i = 0; i < vegetableCount; i++) {
        if (vegetables[i] != NULL)
            total += vegetables[i]->calculateSum();
    }

    return total;
}

int main() {

    Fruit *fruits[2];

    fruits[0] = new Fruit("Apple", 10, 7);
    fruits[1] = new Fruit("Banana", 10, 8);

    Vegetable *vegetables[2];

    vegetables[0] = new Vegetable("Broccoli", 60, 12);
    vegetables[1] = new Vegetable("Lettuce", 50, 10);

    std::cout << "Jenna's Grocery List\n\n";

    fruits[0]->display();
    fruits[1]->display();
    vegetables[0]->display();
    vegetables[1]->display();

    std::cout << "\nTotal Amount: PHP "
            << TotalSum(fruits, 2, vegetables, 2)
            << std::endl;

    delete vegetables[1];
    vegetables[1] = NULL;

    std::cout << "\nAfter deleting Lettuce:\n\n";

    fruits[0]->display();
    fruits[1]->display();
    vegetables[0]->display();

    std::cout << "\nUpdated Total Amount: PHP "
            << TotalSum(fruits, 2, vegetables, 2)
            << std::endl;

    delete fruits[0];
    delete fruits[1];
    delete vegetables[0];

    return 0;
}