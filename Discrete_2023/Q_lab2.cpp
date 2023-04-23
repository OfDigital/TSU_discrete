#include <iostream>
#include <set>

using namespace std;

// ფუნქციას განვსაზღვრავთ აქ
int f(int x) {
    return 2 * x;
}

// ვადგენთ არის თუ არა ფუნქცია შექცევადი მოცემულ დომეინსა და კოდომეინზე.
bool is_invertible(set<int> domain, set<int> codomain) {
    set<int> image;
    for (auto x : domain) { // ციკლი დომეინების ელემენტებზე
        int y = f(x); 
        if (codomain.count(y) == 0 || image.count(y) > 0) {
            return false;
        }
        image.insert(y);
    }
    return true;
}

int main() {
    // მაგალითი 1: ფუნქცია შექცევადი მოცემულ დომეინსა და კოდომეინზე.
    set<int> domain1 = {1, 2, 3};
    set<int> codomain1 = {2, 4, 6};
    if (is_invertible(domain1, codomain1)) {
        cout << "ფუნქცია არის შექცევადი მოცემულ დომეინსა და კოდომეინზე." << endl;
    } else {
        cout << "ფუნქცია არ არის შექცევადი მოცემულ დომეინსა და კოდომეინზე." << endl;
    }
    
    // მაგალითი 2: ფუნქცია არ არის შექცევადი მოცემულ დომეინსა და კოდომეინზე.
    set<int> domain2 = {1, 2, 3};
    set<int> codomain2 = {2, 4};
    if (is_invertible(domain2, codomain2)) {
        cout << "ფუნქცია არის შექცევადი მოცემულ დომეინსა და კოდომეინზე." << endl;
    } else {
        cout << "ფუნქცია არ არის შექცევადი მოცემულ დომეინსა და კოდომეინზე." << endl;
    }
    
    return 0;
}