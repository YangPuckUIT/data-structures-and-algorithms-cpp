#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Customer {
    string id;
    string name;
    string station;
    double price;
    Customer* prev;
    Customer* next;
};


struct List {
    Customer* head;
    Customer* tail;
};

void initList(List& l) {
    l.head = l.tail = NULL;
}


bool isEmpty(List l) {
    return l.head == NULL;
}


Customer* findById(List l, string id) {
    Customer* p = l.head;
    while (p != NULL) {
        if (p->id == id)
            return p;
        p = p->next;
    }
    return NULL;
}

void addCustomer(List& l, string id, string name, string station, double price) {
    if (findById(l, id) != NULL) {
        cout << "Customer already exists!\n";
        return;
    }

    Customer* p = new Customer;
    p->id = id;
    p->name = name;
    p->station = station;
    p->price = price;
    p->prev = p->next = NULL;

    if (isEmpty(l)) {
        l.head = l.tail = p;
    } else {
        l.tail->next = p;
        p->prev = l.tail;
        l.tail = p;
    }
}

double sellTicket(List& l) {
    if (isEmpty(l)) {
        cout << "No customer in queue!\n";
        return 0;
    }

    Customer* p = l.head;
    double money = p->price;

    cout << "Sold ticket to: " << p->name << " | Station: " << p->station << endl;

    l.head = p->next;
    if (l.head == NULL)
        l.tail = NULL;
    else
        l.head->prev = NULL;

    delete p;
    return money;
}


void removeCustomer(List& l, string id) {
    Customer* p = findById(l, id);
    if (p == NULL) {
        cout << "Customer not found!\n";
        return;
    }

    if (p == l.head)
        l.head = p->next;
    if (p == l.tail)
        l.tail = p->prev;

    if (p->prev != NULL)
        p->prev->next = p->next;
    if (p->next != NULL)
        p->next->prev = p->prev;

    delete p;
    cout << "Customer removed.\n";
}

void display(List l) {
    Customer* p = l.head;
    while (p != NULL) {
        cout << p->id << " | " << p->name << " | "
             << p->station << " | " << p->price << endl;
        p = p->next;
    }
}

void loadFromFile(List& l, string filename) {
    ifstream fin(filename);
    if (!fin) {
        cout << "Cannot open file!\n";
        return;
    }

    string id, name, station, priceStr;
    while (getline(fin, id, ';')) {
        getline(fin, name, ';');
        getline(fin, station, ';');
        getline(fin, priceStr);

        addCustomer(l, id, name, station, stod(priceStr));
    }

    fin.close();
}

void saveToFile(List l, string filename) {
    ofstream fout(filename);
    Customer* p = l.head;

    while (p != NULL) {
        fout << p->id << ";"
             << p->name << ";"
             << p->station << ";"
             << p->price << endl;
        p = p->next;
    }

    fout.close();
}

void displayStations(List l) {
    Customer* p = l.head;
    while (p != NULL) {
        cout << p->station << endl;
        p = p->next;
    }
}

void stationStatistics(List l) {
    Customer* p = l.head;

    while (p != NULL) {
        int count = 0;
        Customer* q = l.head;
        while (q != NULL) {
            if (q->station == p->station)
                count++;
            q = q->next;
        }
        cout << p->station << ": " << count << endl;
        p = p->next;
    }
}

int main() {
    List l;
    initList(l);

    double totalSales = 0;
    int choice;

    do {
        cout << "\n TRAIN TICKET SYSTEM \n";
        cout << "1. Load from file\n";
        cout << "2. Add customer\n";
        cout << "3. Sell ticket\n";
        cout << "4. Display list\n";
        cout << "5. Remove customer\n";
        cout << "6. Ticket sales statistics\n";
        cout << "7. Save to file\n";
        cout << "8. Display stations\n";
        cout << "9. Station statistics\n";
        cout << "0. Exit\n";
        cout << "Choose: ";
        cin >> choice;
        cin.ignore();

        if (choice == 1) {
            loadFromFile(l, "input.txt");
        }
        else if (choice == 2) {
            string id, name, station;
            double price;
            cout << "ID: "; getline(cin, id);
            cout << "Name: "; getline(cin, name);
            cout << "Station: "; getline(cin, station);
            cout << "Price: "; cin >> price;
            addCustomer(l, id, name, station, price);
        }
        else if (choice == 3) {
            totalSales += sellTicket(l);
        }
        else if (choice == 4) {
            display(l);
        }
        else if (choice == 5) {
            string id;
            cout << "ID to remove: ";
            cin >> id;
            removeCustomer(l, id);
        }
        else if (choice == 6) {
            cout << "Total sales: " << totalSales << endl;
        }
        else if (choice == 7) {
            saveToFile(l, "output.txt");
        }
        else if (choice == 8) {
            displayStations(l);
        }
        else if (choice == 9) {
            stationStatistics(l);
        }

    } while (choice != 0);

    return 0;
}
