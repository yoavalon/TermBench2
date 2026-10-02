fn flight_trajectory() {
    let mut a = 1.0;
    let mut b = 0.0;
    let mut c = 0.0;
    loop {
        c = a + b;
        a = b;
        b = c;
        println!("{}", c);
    }
}

fn main() {
    flight_trajectory();
}