#include <iostream>
#include <string>
#include <stdlib.h>
#include "maxheap.h"

using namespace std;

int main() {
    string input[100000];
    MaxHeap h;

    for(int index = 0; index < 100000; index++) {
        getline(std::cin, input[index]); 

        if(input[index] == "") {
            break;
        }

        if(input[index].find("I ") == 0) {
            string target;
            int pivot = input[index].length()-1;
            target = input[index].substr(1, pivot);

            int value = atoi(target.c_str());

            h.push(value); 

        } else if(input[index].find("D") == 0) {
            if(input[index].length() == 1) { // delete top
                h.pop();
                 
            } else {
                string target;
                int pivot = input[index].length()-1;
                target = input[index].substr(1, pivot);

                int order = atoi(target.c_str());

                h.deleteHeap(order);
            }

        } else if(input[index].find("T") == 0) {
            if(input[index].length() == 1) { // print max item [top]
                h.printTop(); 

            } else {
                string target;
                int pivot = input[index].length()-1;
                target = input[index].substr(1, pivot);

                int order = atoi(target.c_str());

                h.printOrder(order);
            }

        } else if(input[index].find("P") == 0) {
            h.print();
        }
    }

    return 0;
}
