#include <iostream>
#include <string>
#include <vector>

typedef struct node_t {
    node_t* left;
    node_t* right;
    int data;
} node_t;

node_t* new_node(int data) {
    node_t* temp = (node_t*) malloc(sizeof(node_t));
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

int get_choice(std::vector<std::string> choices) {
    bool is_valid_input = false;
    int counter;
    int input;
    while (!is_valid_input) {
        counter = 0;
        std::cout << std::endl << "Menu" << std::endl;
        for (auto i = choices.begin(); i != choices.end(); i++) {
            counter++;
            std::cout << counter << ". " << *i << std::endl;
        }

        std::cout << "\nEnter selection: ";
        std::cin >> input;

        if (input > 0 && input <= counter) {
            is_valid_input = true;
        } else {
            std::cout << "Invalid input. Must be between 1 and " << counter << std::endl;
        }
        
    }

    return input-1;
}


node_t* min_value_node(node_t* node)
{
    node_t* current = node;
  
    /* loop down to find the leftmost leaf */
    while (current && current->left != NULL)
        current = current->left;
  
    return current;
}

node_t* delete_node(node_t* root, int key) {
    if (root == NULL)
        return root;

    if (key < root->data)
        root->left = delete_node(root->left, key);
    else if (key > root->data)
        root->right = delete_node(root->right, key);
    else {
        if (root->left==NULL and root->right==NULL)
            return NULL;
        else if (root->left == NULL) {
            node_t* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            node_t* temp = root->left;
            free(root);
            return temp;
        }
  
        node_t* temp = min_value_node(root->right);
  
        root->data = temp->data;
  
        root->right = delete_node(root->right, temp->data);
    }
    
    return root;
}

node_t* insert(node_t* node, int data) {
    if (node == NULL) {
        return new_node(data);
    }

    if (data < node->data) {
        // go left
        node->left = insert(node->left, data);
    } else {
        // go right
        node->right = insert(node->right, data);
    }

    return node;
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
        search_path += " ... No match found.\n";
    } else {
        search_path += " ... Match found!\n";
    }

    return search_path;
}

int main(int argc, char* argv[]) {
    std::vector<std::string> choices = { "Insert", "Search", "Delete", "Exit" };

    int selection;
    int int_input;
    std::string str_input;
    std::string search_result;
    node_t* root = NULL;
    bool running = true;
   
    while (running) {
        selection = get_choice(choices);

        if (selection != ((int) choices.size() - 1)) {
            if (selection == 0) {
                std::cout << "Enter number to insert: " << std::endl;
                std::cin >> int_input;
                
                root = insert(root, int_input);
            } else if (selection == 1) {
                std::cout << "Enter number to search for: " << std::endl;
                std::cin >> int_input;
                search_result = search(root, int_input);
                std::cout << search_result << std::endl;
            } else {
                std::cout << "Enter node to delete: " << std::endl;
                std::cin >> int_input;
                root = delete_node(root, int_input);
            }
        } else {
            running = false;
        }
    }

    if (root != NULL) {
        free(root);
        if (root->left != NULL) {
            free(root->left);
        }

        if (root->right != NULL) {
            free(root->right);
        }
    }

    return 0;
}