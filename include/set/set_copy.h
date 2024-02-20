#pragma once
#include<iostream>
#include <random>
#include <string>
#include <chrono>
#include <cstdint>

using namespace std; 

namespace set_c {
    template<typename T>
    class Node {
    public:
        T data;
        Node<T>* left;
        Node<T>* right;
        Node(T value){ 
            data = value;
            left = nullptr;
            right = nullptr;
        }
    };

    template<typename T>
    class Set_c {
    public:
        Set_c() {
            root = nullptr;
        }

        ~Set_c() {
            dest(root);
        }

        Set_c(const Set_c<T>& other) {
            root = copy(other.root);
        }
        
        Set_c<T>& operator=(const Set_c<T>& other) {
            if (this != &other) {
                dest(root);
                root = copy(other.root);
            }
            return *this;
        }

        Set_c<T> operator+(const Set_c<T>& other) {
            Set_c<T> newSet(*this);

            insertNodesFromOther(newSet.root, other.root);

            return newSet;
        }

        void print() {
            print(root);
            std::cout << std::endl;
        }

        bool insert(T value) {
            return insert(root, value);
        }
        
        bool contains(T value) {
            return contains(root, value);
        }
        size_t count(T value) {
            return count(root, value);
        }
        bool erase(T value) {
            return erase(root, value);
        }

        Node<T>* get_root() const {
            return root;
        }

        void XoRHelper(Node<T>* node1, Node<T>* node2) {
            if (node2) {
                if (contains(node2->data)) {
                    erase(node2->data);
                }
                else {
                    insert(node2->data);
                }
                XoRHelper(node1, node2->left);
                XoRHelper(node1, node2->right);
            }
        }

    private:
        Node<T>* root;

        Node<T>* copy(Node<T>* node) {
            if (node) {
                Node<T>* new_node = new Node<T>(node->data);
                new_node->left = copy(node->left);
                new_node->right = copy(node->right);
                return new_node;
            }
            return nullptr;
        }
        void insertNodesFromOther(Node<T>*& dest, Node<T>* src) {
            if (src == nullptr) {
                return;
            }
            insert(dest, src->data);
            insertNodesFromOther(dest, src->left);
            insertNodesFromOther(dest, src->right);
        }

        bool insert(Node<T>*& node, T value) {
            if (node == nullptr ) {
                node = new Node<T>(value);
                return true;
            }
            if (value <= node->data) {
                return insert(node->left, value);
            }
            else if (value > node->data) {
                return insert(node->right, value);
            }
            return false;
        }

        void print(Node<T>* node) {
            if (node) {
                print(node->left);
                std::cout << node->data << " ";
                print(node->right);
            }
        }

        void dest(Node<T>* node) {
            if (node) {
                dest(node->left);
                dest(node->right);
                delete node;
            }
        }

        size_t count(Node<T>* node, T value) {

            if (node == nullptr) {
                return 0;
            }
            size_t c = 0;

            if (node->data == value) {
                c++;
            }
            c += count(node->left, value);
            c += count(node->right, value);

            return c;
        }

        bool contains(Node<T>* node, T value) {
            if (node == nullptr) {
                return false;
            }
            if (value < node->data) {
                return contains(node->left, value);
            }
            else if (value > node->data) {
                return contains(node->right, value);
            }
            return true;
        }

        bool erase(Node<T>*& node, T value) {
            if (node == nullptr) {
                return false;
            }
            if (value < node->data) {
                return erase(node->left, value);
            }
            else if (value > node->data) {
                return erase(node->right, value);
            }
            else {
                if (node->left == nullptr) {
                    Node<T>* temp = node->right;
                    delete node;
                    node = temp;
                }
                else if (node->right == nullptr) {
                    Node<T>* temp = node->left;
                    delete node;
                    node = temp;
                }
                else {
                    Node<T>* temp = node->right;
                    while (temp->left) {
                        temp = temp->left;
                    }
                    node->data = temp->data;
                    erase(node->right, temp->data);
                }
                return true;
            }
        }
    };

    bool operator<(const std::string& lhs, const std::string& rhs) {
        return lhs.compare(rhs) <= 0;
    }
    bool operator>(const std::string& lhs, const std::string& rhs) {
        return lhs.compare(rhs) > 0;
    }


    int random_seed(int a, int b, int seed) {
        std::mt19937 generator(seed);
        std::uniform_int_distribution<> distribution(a, b);
        int res = distribution(generator);
        return res;
    }
    int random(int a, int b) {
        std::random_device random_device;
        std::mt19937 generator(random_device());
        std::uniform_int_distribution<> distribution(a, b);
        int res = distribution(generator);
        return res;
    }

    uint64_t time() {
        using namespace std::chrono;
        return duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
    }

    /*double fill_time(int n, int attempts) {
        double res = 0;
        for (int att = 0; att < attempts; att++) {
            Set_c<int> a;
            uint64_t now = time();
            int cur_count = 0;
            while (cur_count != n) {
                if (a.insert(random(-5*n, 5*n))) {
                    cur_count++;
                }
            }
            uint64_t end = time();
            res += (end - now);
        }
        return res/attempts;
    }

    double contain_time(int n, int attempts) {
        double res = 0;
        for (int att = 0; att < attempts; att++) {
            Set_c<int> a;
            int cur_count = 0;
            while (cur_count != n) {
                if (a.insert(random(-5 * n, 5 * n))) {
                    cur_count++;
                }
            }
            uint64_t now = time();
            a.contains(random(-n, n));
            uint64_t end = time();
            res += (end - now);
        }
        return res / attempts;
    }
    double insert_time(int n, int attempts) {
        double res = 0;
        for (int att = 0; att < attempts; att++) {
            Set_c<int> a;
            int cur_count = 0;
            while (cur_count != n) {
                if (a.insert(random(-5 * n, 5 * n))) {
                    cur_count++;
                }
            }
            uint64_t now = time();
            a.insert(random(-n, n));
            uint64_t end = time();
            res += (end - now);
        }
        return res / attempts;
    }
    double erase_time(int n, int attempts) {
        double res = 0;
        for (int att = 0; att < attempts; att++) {
            Set_c<int> a;
            int cur_count = 0;
            while (cur_count != n) {
                if (a.insert(random(-5 * n, 5 * n))) {
                    cur_count++;
                }
            }
            uint64_t now = time();
            a.erase(random(-n, n));
            uint64_t end = time();
            res += (end - now);
        }
        return res / attempts;
    }

    double fill_time_vect(int n, int attempts) {
        double res = 0;
        for (int att = 0; att < attempts; att++) {
            std::vector<int> a;
            uint64_t now = time();
            for (int i = 0; i < n; i++) {
                a.push_back(random(-n, n));
            }
            uint64_t end = time();
            res += (end - now);
        }
        return res / attempts;
    }
    
    bool linear_search_vect(std::vector<int> data, int x) {
        int len = data.size();
        for (int i = 0; i < len; i++) {
            if (data[i] == x) {
                return true;
            }
        }
        return false;
    }

    double contain_time_vect(int n, int attempts) {
        double res = 0;
        for (int att = 0; att < attempts; att++) {
            std::vector<int> a;
            for (int i = 0; i < n; i++) {
                a.push_back(random(-n, n));
            }
            uint64_t now = time();
            linear_search_vect(a, random(-n, n));
            uint64_t end = time();
            res += (end - now);
        }
        return res / attempts;
    }
    double insert_time_vect(int n, int attempts) {
        double res = 0;
        for (int att = 0; att < attempts; att++) {
            vector<int> a;
            for (int i = 0; i < n; i++) {
                a.push_back(random(-n, n));
            }
            uint64_t now = time();
            a.push_back(random(-n, n));
            uint64_t end = time();
            res += (end - now);
        }
        return res / attempts;
    }

    bool erase_vect(vector<int> data, int x) {
        int len = data.size();
        for (int i = 0; i < len; i++) {
            if (data[i] == x) {
                data.erase(data.begin() + i);
                return true;
            }
        }
        return false;
    }
    double erase_time_vect(int n, int attempts) {
        double res = 0;
        for (int att = 0; att < attempts; att++) {
            vector<int> a;
            for (int i = 0; i < n; i++) {
                a.push_back(random(-n, n));
            }
            uint64_t now = time();
            erase_vect(a, random(-n, n));
            uint64_t end = time();
            res += (end - now);
        }
        return res / attempts;
    }*/

    template<typename T>
    Set_c<T> set_union(const Set_c<T>& lhs, const Set_c<T>& rhs) {
        Set_c<T> newSet(lhs);
        newSet = newSet + rhs;

        return newSet;
    } 
    
    template<typename T>
    Set_c<T> XoR(Set_c<T>& lhs, Set_c<T>& rhs) {
        Set_c<T> newSet(lhs);

        newSet.XoRHelper(lhs.get_root(), rhs.get_root());

        return newSet;
    }
}