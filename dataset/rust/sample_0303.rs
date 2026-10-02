fn simulate() {
    let mut a = 1;
    let mut b = 1;
    let mut c = 0;
    loop {
        c = a + b;
        a = b;
        b = c;
        println!("{}", c);
    }
}

fn main() {
    simulate();
}