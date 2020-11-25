#include <iostream>
#include <string>
#include "PriorityQueue.h"

using namespace std;

struct Patient {
    string name;
    string medicalDescription;
};

int main() {
    PriorityQueue<struct Patient> waitingList;
    struct Patient patient;

    // Add a bunch of random patients to the queue.
    patient = { "Traci Wilkins", "" };
    waitingList.insert(patient, 0);

    patient = { "Amba Vo", "" };
    waitingList.insert(patient, 3);

    patient = { "Kiera Morrow", "" };
    waitingList.insert(patient, 2);

    patient = { "Amiee Cooper", "" };
    waitingList.insert(patient, 5);

    patient = { "Brenna Marks", "" };
    waitingList.insert(patient, 5);

    patient = { "Fatema Mclellan", "" };
    waitingList.insert(patient, 0);

    patient = { "Haroon Caldwell", "" };
    waitingList.insert(patient, 3);

    patient = { "Nicolas Yates", "" };
    waitingList.insert(patient, 4);

    patient = { "Jacqueline Alvarado", "" };
    waitingList.insert(patient, 0);

    patient = { "Lylah Greig", "" };
    waitingList.insert(patient, 1);

    // print out the queue
    waitingList.display();

    // print out all the patients in order of urgency.
    for (int i = 0; i < 10; i++) {
        cout << waitingList.pop().name << endl;
    }
}
