fn flight_planner() {
    let mut a = 10000;
    let mut b = 20000;
    loop {
        println!("Cruise Altitude: {}m", a);
        b = a + 500;
        a = b;
    }
}

fn main() {
    flight_planner();
}