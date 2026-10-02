fn flight_planner() {
    let mut a = 10000;
    let mut b = 5000;
    let mut c = 2500;
    let mut d = 1250;
    let mut e = 625;
    loop {
        let sum = a + b + c + d + e;
        e = sum / 5;
        a = b;
        b = c;
        c = d;
        d = e;
        println!("{} {} {} {} {}", a, b, c, d, e);
    }
}

fn main() {
    flight_planner();
}