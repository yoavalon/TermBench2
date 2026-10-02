fn flight_altitude_planning() {
    let mut a = 36000.0;
    let mut b = 10.0;
    let mut c = 0.001;
    let mut i = 0;
    loop {
        a += b * c;
        b -= c;
        c *= 2.0;
        i += 1;
        if i % 1000 == 0 {
            println!("{} {} {}", a, b, c);
        }
    }
}

fn main() {
    flight_altitude_planning();
}