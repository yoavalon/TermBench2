fn flight_planner() {
    let mut a = 1;
    let mut b = 1;
    let mut c = 0;
    loop {
        c = a + b;
        a = b;
        b = c;
        if c > 30000 {
            a = 1;
            b = 1;
        }
    }
}

fn main() {
    flight_planner();
}