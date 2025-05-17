#include <iostream> // CounterStrike 2 Knife Skin Tracker
#include <fstream>
#include <string>

using namespace std;

// Array of Knife Structs
// A Knife Struct should have the following: Knife name, Knife Type, Knife Seed, Knife Float

struct Knife {
    string name, type;
    int seed;
    double knifeFloat;
};
const int MAX_KNIVES = 100;

// Function to show a List of knives they can view
int knifeList() {
    Knife knives[MAX_KNIVES];
    int count = 0;

    ifstream inputFile("data.txt");

    // Read the data from the file
    while (inputFile >> knives[count].name >> knives[count].type >> knives[count].seed >> knives[count].knifeFloat) {
        count++;
        if (count >= MAX_KNIVES) {
            cout << "Reached maximum capacity of the array." << endl;
            break;
        }
    }

    inputFile.close();

    // Print Data
    cout << "List of knives" << endl;
    for (int i = 0; i < count; i++) {
        cout << knives[i].name << " | " << knives[i].type << endl;
        cout << "Seed: " << knives[i].seed << endl;
        cout << "Float: " << knives[i].knifeFloat << endl;
    }

    return 0;
}

// Function to add a knife to the list
void addKnife(const Knife& knife) {
    ofstream file("data.txt", ios::app); // Opens the file in append mode

    file << knife.name << " " << knife.type << " " << knife.seed << " " << knife.knifeFloat << endl; // Inputs all the information from the user into the file
    file.close();
}

// Function to print out a list of a certain knife
int listKnife(string knife) {
    Knife knives[MAX_KNIVES];
    int count = 0;

    ifstream inputFile("data.txt");

    // Read the data from the file
    while (inputFile >> knives[count].name >> knives[count].type >> knives[count].seed >> knives[count].knifeFloat) {
        count++;
        if (count >= MAX_KNIVES) {
            cout << "Reached maximum capacity of the array." << endl;
            break;
        }
    }

    inputFile.close();

    // Print only the knife we are looking for
    cout << "List of " << knife << "s" << endl;
    for (int i = 0; i < count; i++) {
        if (knives[i].name == knife) {
            cout << knives[i].name << " | " << knives[i].type << endl;
            cout << "Seed: " << knives[i].seed << endl;
            cout << "Float: " << knives[i].knifeFloat << endl;
        }
    }

    return 0;
}