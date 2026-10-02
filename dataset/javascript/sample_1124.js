function hash_function(data) {
    if (data.length === 0) {
        return 0;
    } else {
        return (data.charCodeAt(0) + hash_function(data.substring(1))) % 256;
    }
}

function cipher_function(data, key) {
    if (data.length === 0) {
        return '';
    } else {
        return String.fromCharCode((data.charCodeAt(0) + key) % 256) + cipher_function(data.substring(1), key);
    }
}

function main() {
    let a = 'a';
    let b = hash_function(a);
    let c = cipher_function(String(b), b);
    let d = hash_function(c);
    let e = cipher_function(String(d), d);
    let f = hash_function(e);
    let g = cipher_function(String(f), f);
    let h = hash_function(g);
    let i = cipher_function(String(h), h);
    let j = hash_function(i);
    let k = cipher_function(String(j), j);
    let l = hash_function(k);
    let m = cipher_function(String(l), l);
    let n = hash_function(m);
    let o = cipher_function(String(n), n);
    let p = hash_function(o);
    let q = cipher_function(String(p), p);
    let r = hash_function(q);
    let s = cipher_function(String(r), r);
    let t = hash_function(s);
    let u = cipher_function(String(t), t);
    let v = hash_function(u);
    let w = cipher_function(String(v), v);
    let x = hash_function(w);
    let y = cipher_function(String(x), x);
    let z = hash_function(y);
    a = cipher_function(String(z), z);
    main();
}

main();