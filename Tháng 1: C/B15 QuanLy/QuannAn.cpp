#include <iostream>
#include <string>
#include <list> 

using namespace std;

class Food {
    private:
        uint8_t id;
        string name;
        double price;
    public:
        Food(string Name, double Price);
        uint8_t getId();
        void setName(string Name);
        string getName();
        void setPrice(double Price);
        double getPrice();
};

Food::Food(string Name, double Price){
    static uint8_t ID = 100;
    id = ID;
    ID++;
    this->name = Name;
    this->price = Price;
}

uint8_t Food::getId(){
    return this->id;
}

void Food::setName(string Name){
    this->name = Name;
}

string Food::getName(){
    return this->name;
}

void Food::setPrice(double Price){
    this->price = Price;
}

double Food::getPrice(){
    return this->price;
}

class Manager{
    private:
        int tableQuantity;
    protected:
        list <Food> Menu;
    public:
        void addMenu();
        void editMenu();
        void eraserMenu();
        void screenMenu();
        void setTableQuantity(int numOfTable);
        int getTableQuantity();
        list <Food> getMenu();
};

list <Food> Manager::getMenu(){
    return Menu;
}

void Manager::addMenu(){    
    int choice;    
    do {
        string name;
        double price;

        cout << "Enter the name of the food: ";
        cin >> name;
        cout << "Enter the price of the food: ";
        cin >> price;

        Food newFood(name, price);
        Menu.push_back(newFood);

        cout << "ID\t" << "Name\t\t" << "Price" << endl;
        cout << newFood.getId() << "." << "\t" << newFood.getName() << "\t\tVND" << newFood.getPrice() << endl;

        cout << "1. Continue to add food" << endl;
        cout << "0. Turn back" << endl;
        cout << "Enter option: \n";
        cin >> choice;

    } while (choice != 0);
}

void Manager::screenMenu(){

        cout << "=======Menu=======" << endl;
        cout << "ID\tName\t\tPrice\n";
        for (auto& food : Menu) {
            cout << food.getId() << "." << "\t" << food.getName() << "\t\tVND" << food.getPrice() << endl;
        }
    }

void Manager::editMenu(){
        
    int id;
    screenMenu();
    cout << "Enter Id: ";
    cin >> id;

    for(auto& food : Menu){
        if(food.getId() == id) {
            string newName;
            double newPrice;
            int choice;

        do {
            cout << "1. Edit name\n2. Edit Price\n0. Turn back\n";
            cout << "Enter option: ";
            cin >> choice;

            switch (choice){
                case 0:
                    break;
                case 1:
                    cout << "Enter the new name of food: ";
                    cin >> newName;
                    if(!newName.empty())
                        food.setName(newName);
                    break;
                case 2: 
                    cout << "Enter the new price of food: ";
                    cin >> newPrice;
                    if(newPrice != 0.0)
                        food.setPrice(newPrice);
                    break;
                default: 
                    cout << "Invalid choice. Please try again.\n";
                    break;
            }
        } while (choice != 0);

        cout << "Food with Id: " << id << " has been updated\n";
        return;
        }
    }
    cout << "Food with Id: " << id << " not found!\n";
}

void Manager::eraserMenu(){
        
    int id;
    screenMenu();
    cout << "Enter Id to delete: ";
    cin >> id;

    for(auto it = Menu.begin()    ; it != Menu.end(); ++it){
        if(it -> getId() == id){
            Menu.erase(it);
            cout << "Food with Id: " << id << " has been deleted." << endl;
            return;
        }
    }
    cout << "Food with Id: " << id << " not found!" << endl;
}

void Manager::setTableQuantity(int numOfTable){
    this -> tableQuantity = numOfTable;
}

int Manager::getTableQuantity() {
    return tableQuantity;
}

enum TableStatus {Open, Close};

class Table {
    public:
        int id;
        TableStatus status;
        list<Food> orders;

        Table(int _id);
        void addFood(Food& food);
        void removeFood(int foodId);
        void Bill();
};

Table::Table(int _id) : id(_id) {status = Open;}

void Table::addFood(Food& food) {
    if (status == Close) {
        cout << "Table " << id << " is closed. Cannot add food." << endl;
    }
    else {
        orders.push_back(food);
        cout << "Added \"" << food.getName() << "\" to table " << id << endl;
        status = Close;
    }
}

void Table::removeFood(int foodId) {
    if (status == Close) {
        cout << "Table " << id << " is closed. Cannot remove food." << endl;
    }
    else {
        bool found = false;
        for (auto it = orders.begin(); it != orders.end(); ++it) {
            if (it->getId() == foodId) {
                orders.erase(it);
                cout << "Removed food with ID " << foodId << " from table " << id << endl;
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "Food with ID " << foodId << " is not found in table " << id << endl;
        }
    }
}

void Table::Bill() {
    double total = 0;
    cout << "==== Bill for table " << id << " ====" << endl;
    for (Food& food : orders) {
        total += food.getPrice();
        cout << food.getName() << ": \t\t$" << food.getPrice() << endl;
    }
    cout << "Total: \t\t$" << total << endl;

    orders.clear();
    status = Open;
}

class Employee : public Manager {
    private:
        bool isTableCreated;
    public:
        Employee() : isTableCreated(false) {}
        list <Table> tables;
        void createTables(int num);
        void displayTableList();
        void displayMenu();
        void addFoodToTable(int tableId, int foodId);
        void removeFoodFromTable(int tableId, int foodId);
        void calculateBillForTable(int tableId);
        void printTableStatus() ;
};

void Employee::createTables(int num) {
    if (!isTableCreated) {
        for (int i = 1; i <= num; i++) {
            Table table(i);
            tables.push_back(table);
        }
        isTableCreated = true;
    }
}

void Employee::displayTableList() {
    if (!tables.empty()) {
        cout << "=== Table list ===" << endl;
        cout << "Table\tStatus" << endl;
        for ( const Table& table : tables) {
            cout << "  " << table.id << "   -   ";
            if (table.status == Open) {
               cout << "O";
            }
            else {
                cout << "X";
            }
            cout << endl;
        }
    } else {
        cout << "Table list is empty." << endl;
    }
}

void Employee::displayMenu() {
    cout << "==== Restaurant Menu ====" << endl;
    for (auto& food : Menu) {
        cout << "ID: " << food.getId() << " - Name: " << food.getName() << " - Price: $" << food.getPrice() << endl;
    }
}

void Employee::addFoodToTable(int tableId, int foodId) {
    for (Table& table : tables) {
        if (table.id == tableId) {
            for (Food& food : Menu) {
                if (food.getId() == foodId) {
                    table.addFood(food);
                    return;
                }
            }
            cout << "Food with ID " << foodId << " does not exist in the menu." << endl;
            return;
        }
    }
    cout << "Table " << tableId << " does not exist." << endl;
}

void Employee::removeFoodFromTable(int tableId, int foodId) {
    for (Table& table : tables) {
        if (table.id == tableId) {
            table.removeFood(foodId);
            return;
        }
    }
    cout << "Table " << tableId << " does not exist." << endl;
}

void Employee::calculateBillForTable(int tableId) {
    for (Table& table : tables) {
        if (table.id == tableId) {
            table.Bill();
            return;
        }
    }
    cout << "Table " << tableId << " does not exist." << endl;
}

void Employee::printTableStatus() {
    cout << "Table status:" << endl;
    for (const Table& table : tables) {
        cout << "Table " << table.id << ": ";
        if (table.status == Open) {
            cout << "Open";
        }
        else {
            cout << "Close";
        }
        cout << endl;
    }
}

void displayToConsoleScreen(){
    Manager manager;
    Employee employee;
    int option, choice;

    do {
        cout << "=== Menu ===\n1. MANAGER\n2. EMPLOYEE\n";
        cout << "0.TURN BACK!\n";
        cin >> option;

        switch (option){
            case 1:
                do {
                    cout << "======== MANAGER ========\n1. Add Food to Menu\n2. Edit Food in Menu\n";
                    cout << "3. Delete Menu Food\n4. Show Menu\n5. Set up number of Table\n";
                    cout << "0. Turn back!\n";
                    cin >> choice;

                    switch (choice){
                        case 0:
                            break;
                        case 1:
                            employee.addMenu();
                            break;
                        case 2: 
                            employee.editMenu();
                            break;
                        case 3:
                            employee.eraserMenu();
                            break;
                        case 4: 
                            employee.displayMenu();
                            break;
                        case 5:
                            int num;
                            cout << "Enter number of Table: \n";
                            cin >> num;
                            employee.setTableQuantity(num);
                            break;
                        default:
                            cout << "Invalid choice. Please try again.\n";
                            break;
                    }
                } while (choice != 0);
                break;

            case 2:
                employee.createTables(employee.getTableQuantity());
                employee.displayTableList();

                int tableId;
                cout << "Enter table ID: ";
                cin >> tableId;

                do {
                    cout << "====== EMPLOYEE ======\n1. Add Food to Table\n";
                    cout << "2. Delete Table Food\n3. Show Menu\n4. Paying\n";
                    cout << "0. Turn back!\n";
                    cin >> choice;

                    switch (choice){
                        case 0:
                            break;
                        case 1:
                            int foodId;
                            cout << "Enter food ID: ";
                            cin >> foodId;
                            employee.addFoodToTable(tableId, foodId);
                            break;
                        case 2:
                            cout << "Enter food ID: ";
                            cin >> foodId;
                            employee.removeFoodFromTable(tableId, foodId);
                            break;
                        case 3: 
                            employee.displayMenu();
                            break;
                        case 4:
                            employee.calculateBillForTable(tableId);
                            break;
                        default:
                            cout << "Invalid choice. Please try again.\n";
                            break;
                    }
                } while (choice != 0);
                break;
        }
    } while (option != 0);
}

int main()
{
    displayToConsoleScreen();
    return 0;
}
