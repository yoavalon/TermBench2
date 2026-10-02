rust
fn main() {
    let mut a = 36000;
    let mut b = 500;
    loop {
        a -= b;
        if a <= 10000 {
            b = 50;
        }
        if a <= 3000 {
            b = 10;
        }
        if a <= 0 {
            a = 0;
        }
        println!("Altitude: {} feet, Descent Rate: {} ft/min", a, b);
    }
}