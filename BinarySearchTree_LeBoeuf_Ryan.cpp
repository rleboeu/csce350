#include <iostream>
#include <string>
#include <vector>

typedef struct node_t {
    node_t* left;
    node_t* right;
    int data;
    node_t() : left(NULL), right(NULL), data(-1) {}
    node_t(int x) : left(NULL), right(NULL), data(x) {}
} node_t;

int get_choice(std::vector<std::string> choices) {
    bool is_valid_input = false;
    int counter;
    int input;
    while (!is_valid_input) {
        counter = 0;
        for (auto i = choices.begin(); i != choices.end(); i++) {
            counter++;
            std::cout << counter << ". " << *i << std::endl;
        }

        std::cout << "Enter selection: ";
        std::cin >> input;
        std::cout << std::endl;

        if (input > 0 && input <= counter) {
            is_valid_input = true;
        } else {
            std::cout << "Invalid input. Must be between 1 and " << counter << std::endl;
        }
        
        std::cout << std::endl;
    }

    return input-1;
}

void insert(node_t* root, int data) {
    if (root->data == -1) {
        root->data = data;
        return;
    }

    node_t* current = root;
    node_t* new_node = new node_t(data);
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

std::string search(node_t* root, int data) {
    std::string search_path = "Path:";
    node_t* current = root;
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
    std::vector<std::string> choices = { "Insert", "Search", "Exit" };

    int selection;
    int int_input;
    std::string str_input;
    std::string search_result;
    node_t* root = new node_t();
    bool running = true;
   
    while (running) {
        selection = get_choice(choices);

        if (selection != ((int) choices.size() - 1)) {
            if (selection == 0) {
                std::cout << "Enter number to insert: " << std::endl;
                std::cin >> int_input;
                
                insert(root, int_input);
            } else {
                std::cout << "Enter number to search for: " << std::endl;
                std::cin >> int_input;
                search_result = search(root, int_input);
                std::cout << search_result << std::endl;
            }
        } else {
            running = false;
        }
    }

    return 0;
}