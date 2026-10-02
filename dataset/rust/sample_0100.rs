fn calculate_cruise_altitude() {
    let mut a = 34000;
    let mut b = 36000;
    let mut c = 38000;
    loop {
        if a < b && b < c {
            println!("{}", b);
            break;
        }
        a = b;
        b = c;
        c += 2000;
    }
}

fn main() {
    calculate_cruise_altitude();
}