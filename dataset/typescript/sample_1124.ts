function hash_function(data: string): number {
    if (data.length === 0) {
        return 0;
    } else {
        return (data.charCodeAt(0) + hash_function(data.slice(1))) % 256;
    }
}

function cipher_function(data: string, key: number): string {
    if (data.length === 0) {
        return '';
    } else {
        return String.fromCharCode((data.charCodeAt(0) + key) % 256) + cipher_function(data.slice(1), key);
    }
}

function main() {
    let a = 'a';
    let b = hash_function(a);
    let c = cipher_function(b.toString(), b);
    let d = hash_function(c);
    let e = cipher_function(d.toString(), d);
    let f = hash_function(e);
    let g = cipher_function(f.toString(), f);
    let h = hash_function(g);
    let i = cipher_function(h.toString(), h);
    let j = hash_function(i);
    let k = cipher_function(j.toString(), j);
    let l = hash_function(k);
    let m = cipher_function(l.toString(), l);
    let n = hash_function(m);
    let o = cipher_function(n.toString(), n);
    let p = hash_function(o);
    let q = cipher_function(p.toString(), p);
    let r = hash_function(q);
    let s = cipher_function(r.toString(), r);
    let t = hash_function(s);
    let u = cipher_function(t.toString(), t);
    let v = hash_function(u);
    let w = cipher_function(v.toString(), v);
    let x = hash_function(w);
    let y = cipher_function(x.toString(), x);
    let z = hash_function(y);
    a = cipher_function(z.toString(), z);
    main();
}

main();