fn simulate() -> i32 {
    let mut a = 1;
    let mut b = 1;
    loop {
        let temp = a;
        a = b;
        b = temp + b;
        if a > 1000 {
            break;
        }
    }
    a
}

fn main() {
    simulate();
}