#include<bits/stdc++.h>
using namespace std;



class IDGenerator {
    static IDGenerator* instance;
    static mutex mtx;
    atomic<int> next_id;
    IDGenerator() : next_id(0) {}
public:
    static IDGenerator* getInstance() {
        lock_guard<mutex> lock(mtx);
        if (!instance) {
            instance = new IDGenerator();
        }
        return instance;
    }

    int getNextId() {
        return next_id.fetch_add(1, memory_order_relaxed);
    }
};

IDGenerator* IDGenerator::instance = nullptr;
mutex IDGenerator::mtx;

class IDGenerator2 {
    atomic<int> next_id;
public:
    IDGenerator2() : next_id(0) {}
    int getNextId() {
        return next_id.fetch_add(1, memory_order_relaxed);
    }
};


class PaymentStrategy {

};

class Wallet : public PaymentStrategy {

}


enum class PaymentStatus {
    PENDING = 0,
    SUCCESS,
    FAILED
};

class User {
protected:
    string name;
    string email;
public:
    User(const string& name, const string& email) {
        this->name = name;
        this->email = email;
    }
    string getEmail() { return email; }
    virtual void printDetails() {
        cout << "User: " << name << " (" << email << ")\n";
    }
};

class Customer : public User {
    Wallet
public:
    Customer(const string& n, const string& e) : User(n, e) {}
};

class Product {
    int product_id;
    string name;
    int    price;
    static IDGenerator2 i;

public:
    Product(const string& name, int price) {
        product_id = i.getNextId();
        this->name = name;
        this->price = price;
    }
    int getPrice() const {
        return price;
    }
    void printProduct() {
        cout << "Product: " << product_id << " " << name << " | Price: Rs" << price << endl;
    }
};

IDGenerator2 Product::i;

class Invoice {
    int invoice_id;
    vector<Product*> product_list;
    int total_price;
    PaymentStatus status;
public:
    Invoice(int id) : invoice_id(id), total_price(0), status(PaymentStatus::PENDING) {}

    void addProduct(Product* product) {
        product_list.push_back(product);
        total_price += product->getPrice();
    }

    void processPayment() {
        // Simulate payment gateway (Success 90% of the time)
        status = (rand() % 10 < 9) ? PaymentStatus::SUCCESS : PaymentStatus::FAILED;
    }

    void printInvoice() {
        cout << "\n===== Invoice ID: " << invoice_id << " =====\n";
        for (const auto& product : product_list) {
            product->printProduct();
        }
        cout << "Total Amount: Rs" << total_price << "\n";
        cout << "Payment Status: " << (status == PaymentStatus::SUCCESS ? "Success" : "Failed") << "\n";
    }

    ~Invoice() {
        for (auto product : product_list) {
            delete product;
        }
    }
};

class Order {
    int order_id;
    Customer* c;
    Invoice* invoice;

public:
    Order(Customer* c) : order_id(IDGenerator::getInstance()->getNextId()), c(c), invoice(new Invoice(IDGenerator::getInstance()->getNextId())) {}
    void addProductToOrder(Product* p) {
        invoice->addProduct(p);
    }
    void ProcessOrder() {
        cout << "\nProcessing order for " << c->getEmail() << "id = " << order_id << "...\n";
        invoice->processPayment();
        invoice->printInvoice();
    }

    ~Order() {
        delete invoice;
        delete c;
    }

};


int main() {
    Customer* c = new Customer("srv", "ss@gmai.com");
    Product* p1 = new Product("dell-laptop", 75000);
    Product* p2 = new Product("iphone", 80000);

    Order* o = new Order(c);

    o->addProductToOrder(p1);
    o->addProductToOrder(p2);

    o->ProcessOrder();

    delete o;

    return 0;
}
























