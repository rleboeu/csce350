#include <iostream>
#include <string>
#include <vector>

class Node {
    public:
        Node* left;
        Node* right;
        int data;

        Node() {
            data = -1;
            left = NULL;
            right = NULL;
        }

        Node(int x) {
            data = x;
            left = NULL;
            right = NULL;
        }

        ~Node();
};

int getChoice(std::vector<std::string> choices) {
    bool isValidInput = false;
    int counter;
    int input;
    while (!isValidInput) {
        counter = 0;
        for (auto i = choices.begin(); i != choices.end(); i++) {
            counter++;
            std::cout << counter << ". " << *i << std::endl;
        }

        std::cout << "Enter selection: ";
        std::cin >> input;
        std::cout << std::endl;

        if (input > 0 && input <= counter) {
            isValidInput = true;
        } else {
            std::cout << "Invalid input. Must be between 1 and " << counter << std::endl;
        }
        
        std::cout << std::endl;
    }

    return input-1;
}

void insert(Node* root, int data) {
    if (root->data == -1) {
        root->data = data;
        return;
    }

    Node* current = root;
    Node* new_node = new Node(data);
    bool inserted = false;
    while (!inserted) {
        if (new_node->data < current->data) {
            // go left
            if (current->left == NULL) {
                current->left = new_node;
                inserted = true;
            } else {
                current = current->left;
            }
        } else if (new_node->data > current->data) {
            // go right
            if (current->right == NULL) {
                current->right = new_node;
                inserted = true;
            } else {
                current = current->right;
            }
        } else {
            // node already present
            inserted = true;
        }
    }
}

std::string search(Node* root, int data) {
    std::string search_path = "Path:";
    Node* current = root;
    while (current != NULL) {
        search_path += " " + std::to_string(current->data);

        if (data < current->data) {
            // go left
            current = current->left;
        } else if (data > current->data) {
            // go right
            current = current->right;
        } else {
            // MATCH
            break;
        }
    }

    if (current == NULL) {
        // no match found
        search_path += " ... No match found.";
    } else {
        search_path += " ... Match found!";
    }

    return search_path;
}

int main(int argc, char* argv[]) {
    std::vector<std::string> choices = { "Insert", "Search" };

    int selection;
    int intInput;
    std::string strInput;
    std::string searchResult;
    Node* root = new Node();
    bool running = true;
   
    while (running) {
        selection = getChoice(choices);

        if (selection == 0) {
            std::cout << "Enter number to insert: " << std::endl;
            std::cin >> intInput;
            
            insert(root, intInput);
        } else {
            std::cout << "Enter number to search for: " << std::endl;
            std::cin >> intInput;
            searchResult = search(root, intInput);
            std::cout << searchResult << std::endl;
        }

        std::cout << "Go again? [Y/n]: ";
        std::cin >> strInput;
        if (strInput.compare("y") != 0 && strInput.compare("Y") != 0) {
            running = false;
        }
    }

    return 0;
}