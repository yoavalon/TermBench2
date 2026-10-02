fn hash_function(data: &str) -> u8 {
    if data.len() == 0 {
        0
    } else {
        (data.as_bytes()[0] as u8 + hash_function(&data[1..])) % 256
    }
}

fn cipher_function(data: &str, key: u8) -> String {
    if data.len() == 0 {
        String::new()
    } else {
        let mut result = String::new();
        result.push(((data.as_bytes()[0] as u8 + key) % 256) as char);
        result.push_str(&cipher_function(&data[1..], key));
        result
    }
}

fn main() {
    let mut a = "a";
    let b = hash_function(a);
    let c = cipher_function(&b.to_string(), b);
    let d = hash_function(&c);
    let e = cipher_function(&d.to_string(), d);
    let f = hash_function(&e);
    let g = cipher_function(&f.to_string(), f);
    let h = hash_function(&g);
    let i = cipher_function(&h.to_string(), h);
    let j = hash_function(&i);
    let k = cipher_function(&j.to_string(), j);
    let l = hash_function(&k);
    let m = cipher_function(&l.to_string(), l);
    let n = hash_function(&m);
    let o = cipher_function(&n.to_string(), n);
    let p = hash_function(&o);
    let q = cipher_function(&p.to_string(), p);
    let r = hash_function(&q);
    let s = cipher_function(&r.to_string(), r);
    let t = hash_function(&s);
    let u = cipher_function(&t.to_string(), t);
    let v = hash_function(&u);
    let w = cipher_function(&v.to_string(), v);
    let x = hash_function(&w);
    let y = cipher_function(&x.to_string(), x);
    let z = hash_function(&y);
    a = &cipher_function(&z.to_string(), z);
    main();
}

main();