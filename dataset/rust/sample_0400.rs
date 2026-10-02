fn flight_planner() {
    let mut a = 1.0;
    let mut b = 1000.0;
    let c = 0.01;
    loop {
        let x = (a + b) / 2.0;
        if x.powi(2) < c {
            a = x;
        } else {
            b = x;
        }
    }
}

fn main() {
    flight_planner();
}