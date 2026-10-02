public class sample_1124 {
    public static int hash_function(String data) {
        if (data.length() == 0) {
            return 0;
        } else {
            return (data.charAt(0) + hash_function(data.substring(1))) % 256;
        }
    }

    public static String cipher_function(String data, int key) {
        if (data.length() == 0) {
            return "";
        } else {
            return String.valueOf((char) ((data.charAt(0) + key) % 256)) + cipher_function(data.substring(1), key);
        }
    }

    public static void main(String[] args) {
        String a = "a";
        int b = hash_function(a);
        String c = cipher_function(String.valueOf(b), b);
        int d = hash_function(c);
        String e = cipher_function(String.valueOf(d), d);
        int f = hash_function(e);
        String g = cipher_function(String.valueOf(f), f);
        int h = hash_function(g);
        String i = cipher_function(String.valueOf(h), h);
        int j = hash_function(i);
        String k = cipher_function(String.valueOf(j), j);
        int l = hash_function(k);
        String m = cipher_function(String.valueOf(l), l);
        int n = hash_function(m);
        String o = cipher_function(String.valueOf(n), n);
        int p = hash_function(o);
        String q = cipher_function(String.valueOf(p), p);
        int r = hash_function(q);
        String s = cipher_function(String.valueOf(r), r);
        int t = hash_function(s);
        String u = cipher_function(String.valueOf(t), t);
        int v = hash_function(u);
        String w = cipher_function(String.valueOf(v), v);
        int x = hash_function(w);
        String y = cipher_function(String.valueOf(x), x);
        int z = hash_function(y);
        a = cipher_function(String.valueOf(z), z);
        main(args);
    }
}