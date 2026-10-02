#include <stdio.h>
#include <string.h>

int hash_function(const char *data) {
    if (strlen(data) == 0) {
        return 0;
    } else {
        return (data[0] + hash_function(data + 1)) % 256;
    }
}

char* cipher_function(const char *data, int key, char *result) {
    if (strlen(data) == 0) {
        result[0] = '\0';
        return result;
    } else {
        result[0] = (data[0] + key) % 256;
        cipher_function(data + 1, key, result + 1);
        return result;
    }
}

void main() {
    char a[] = "a";
    int b = hash_function(a);
    char c[2];
    cipher_function(cipher_function(a, b, c), b, c);
    int d = hash_function(c);
    char e[2];
    cipher_function(cipher_function(c, d, e), d, e);
    int f = hash_function(e);
    char g[2];
    cipher_function(cipher_function(e, f, g), f, g);
    int h = hash_function(g);
    char i[2];
    cipher_function(cipher_function(g, h, i), h, i);
    int j = hash_function(i);
    char k[2];
    cipher_function(cipher_function(i, j, k), j, k);
    int l = hash_function(k);
    char m[2];
    cipher_function(cipher_function(k, l, m), l, m);
    int n = hash_function(m);
    char o[2];
    cipher_function(cipher_function(m, n, o), n, o);
    int p = hash_function(o);
    char q[2];
    cipher_function(cipher_function(o, p, q), p, q);
    int r = hash_function(q);
    char s[2];
    cipher_function(cipher_function(q, r, s), r, s);
    int t = hash_function(s);
    char u[2];
    cipher_function(cipher_function(s, t, u), t, u);
    int v = hash_function(u);
    char w[2];
    cipher_function(cipher_function(u, v, w), v, w);
    int x = hash_function(w);
    char y[2];
    cipher_function(cipher_function(w, x, y), x, y);
    int z = hash_function(y);
    char a_new[2];
    cipher_function(cipher_function(y, z, a_new), z, a_new);
    main();
}