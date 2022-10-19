#include <iostream>
#include <string>
#include <vector>
#include <limits>

class Node {
    public:
        Node* left = NULL;
        Node* right = NULL;
        int data;

        Node(int data) {
            this->data = data;
        }

        ~Node();
};

class BST {

    private:
        Node* root = NULL;

    public:
        
        BST() {}
        ~BST();

        void insert(int data) {
            Node* newNode = new Node(data);
            if (this->root == NULL) {
                this->root = newNode;
                return;
            }

            bool inserted = false;
            Node* currentNode = this->root;
            while (!inserted) {
                if (newNode->data < currentNode->data) {
                    // go left
                    if (currentNode->left == NULL) {
                        currentNode->left = newNode;
                        inserted = true;
                    } else {
                        currentNode = currentNode->left;
                    }
                } else if (newNode->data > currentNode->data) {
                    // go right 
                    if (currentNode->right == NULL) {
                        currentNode->right = newNode;
                        inserted = true;
                    } else {
                        currentNode = currentNode->right;
                    }
                } else {
                    // already exists
                    return;
                }
            }
        }

        std::string search(int data) {
            std::string path = "";
            Node* currentNode = this->root;
            path.append("" + this->root->data);
            while (currentNode != NULL) {
                if (currentNode->data == data) {
                    // found
                }

                path.append(", " + currentNode->data);
                break;  // REMOVETHIS
            }
        }
};

bool isNumber(std::string x) {
    for (long unsigned int i = 0; i < x.length(); i++) {
        if (isdigit(x[i]) == false) {
            return false;
        }
    }

    return true;
}

int getChoice(std::vector<std::string> choices) {
    bool isValidInput = false;
    int counter;
    std::string input;
    int choice;
    while (!isValidInput) {
        counter = 0;
        for (auto i = choices.begin(); i != choices.end(); i++) {
            counter++;
            std::cout << counter << ". " << *i << std::endl;
        }

        std::cout << "Enter selection: ";
        std::cin >> input;
        std::cout << std::endl;

        if (isNumber(input)) {
            choice = std::stoi(input);
            if (choice > 0 && choice <= counter) {
                isValidInput = true;
            } else {
                std::cout << "Invalid input. Choice must be between 1 and " << counter << std::endl;
            }
        } else {
            std::cout << "Invalid input. Choice must be a NUMBER between 1 and " << counter << std::endl;
        }
        

        std::cout << std::endl;
    }

    return choice-1;
}

int main(int argc, char* argv[]) {
    std::vector<std::string> choices = { "Insert", "Search" };
    BST* bst = new BST();
    
    bool running = true;
    while (running) {
        getChoice(choices);
        running = false;
    }

    return 0;
}