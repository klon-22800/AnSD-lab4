#pragma once
#include<iostream>
#include <random>
#include <string>
#include <chrono>
#include <cstdint>

using namespace std; 

namespace set {
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
    class Set {
    public:
        Set() {
            root = nullptr;
        }

        ~Set() {
            dest(root);
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
        bool erase(T value) {
            return erase(root, value);
        }
    private:
        Node<T>* root;

        bool insert(Node<T>*& node, T value) {
            if (node == nullptr ) {
                node = new Node<T>(value);
                return true;
            }
            if (value < node->data) {
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
        return lhs.compare(rhs) < 0;
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

    double fill_time(int n, int attempts) {
        double res = 0;
        for (int att = 0; att < attempts; att++) {
            Set<int> a;
            uint64_t now = time();
            for (int i = 0; i < n; i++) {
                a.insert(random(-n, n));
            }
            uint64_t end = time();
            res += (end - now);
        }
        return res/attempts;
    }
}