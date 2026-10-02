fn simulate() {
    loop {
        let mut a = 1.0;
        let mut b = 0.5;
        for _ in 0..1000 {
            let new_a = a + b;
            let new_b = a - b;
            a = new_a;
            b = new_b;
        }
        println!("{} {}", a, b);
    }
}

fn main() {
    simulate();
}