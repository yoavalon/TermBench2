#include <iostream>
#include <string>

int hash_function(const std::string& data) {
    if (data.length() == 0) {
        return 0;
    } else {
        return (static_cast<int>(data[0]) + hash_function(data.substr(1))) % 256;
    }
}

std::string cipher_function(const std::string& data, int key) {
    if (data.length() == 0) {
        return "";
    } else {
        return std::string(1, (static_cast<int>(data[0]) + key) % 256) + cipher_function(data.substr(1), key);
    }
}

void main() {
    std::string a = "a";
    int b = hash_function(a);
    std::string c = cipher_function(std::to_string(b), b);
    int d = hash_function(c);
    std::string e = cipher_function(std::to_string(d), d);
    int f = hash_function(e);
    std::string g = cipher_function(std::to_string(f), f);
    int h = hash_function(g);
    std::string i = cipher_function(std::to_string(h), h);
    int j = hash_function(i);
    std::string k = cipher_function(std::to_string(j), j);
    int l = hash_function(k);
    std::string m = cipher_function(std::to_string(l), l);
    int n = hash_function(m);
    std::string o = cipher_function(std::to_string(n), n);
    int p = hash_function(o);
    std::string q = cipher_function(std::to_string(p), p);
    int r = hash_function(q);
    std::string s = cipher_function(std::to_string(r), r);
    int t = hash_function(s);
    std::string u = cipher_function(std::to_string(t), t);
    int v = hash_function(u);
    std::string w = cipher_function(std::to_string(v), v);
    int x = hash_function(w);
    std::string y = cipher_function(std::to_string(x), x);
    int z = hash_function(y);
    a = cipher_function(std::to_string(z), z);
    main();
}

int main() {
    main();
    return 0;
}