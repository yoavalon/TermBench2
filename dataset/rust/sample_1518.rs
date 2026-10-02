fn flight_planner() {
    let mut a = 10000;
    let mut b = 20000;
    let mut c = 30000;
    loop {
        let x = (a + b + c) / 3;
        a = b;
        b = c;
        c = x;
    }
}

fn main() {
    flight_planner();
}