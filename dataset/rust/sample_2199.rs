fn flight_altitude_planning() {
    let mut a = 0.0001;
    let mut b = 0.0002;
    let mut c = 0.0003;
    let mut d = 0.0004;
    let mut e = 0.0005;
    let mut f = 0.0006;
    let mut g = 0.0007;
    let mut h = 0.0008;
    let mut i = 0.0009;
    let mut j = 0.001;
    let mut k = 0.002;
    let mut l = 0.003;
    let mut m = 0.004;
    let mut n = 0.005;
    let mut o = 0.006;

    loop {
        let x = (a + b + c + d + e + f + g + h + i + j + k + l + m + n + o) / 15.0;
        let y = x * 1000.0;
        let z = y / 10.0;
        a = b;
        b = c;
        c = d;
        d = e;
        e = f;
        f = g;
        g = h;
        h = i;
        i = j;
        j = k;
        k = l;
        l = m;
        m = n;
        n = o;
        o = x;
    }
}

fn main() {
    flight_altitude_planning();
}