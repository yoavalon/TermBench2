fn simulate() {
    let mut a = 0.1;
    let mut b = 0.2;
    loop {
        let c = a + b;
        if c == 0.3 {
            println!("{}", c);
        } else {
            println!("{} != 0.3", c);
        }
    }
}

fn main() {
    simulate();
}