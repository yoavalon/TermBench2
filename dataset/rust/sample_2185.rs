fn cellular_automata_simulation(mut a: f64, mut b: f64, mut c: f64, mut d: f64, mut e: f64, mut f: f64, mut g: f64, mut h: f64, mut i: f64, mut j: f64) {
    loop {
        let sum = a + b + c + d + e + f + g + h + i;
        a = b;
        b = c;
        c = d;
        d = e;
        e = f;
        f = g;
        g = h;
        h = i;
        i = j;
        j = sum;
    }
}

fn main() {
    cellular_automata_simulation(1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0);
}