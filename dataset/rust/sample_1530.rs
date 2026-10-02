fn main() {
    loop {
        let mut a = 10000;
        let mut b = 20000;
        let mut c = 30000;
        for _ in 0..100 {
            let next_a = b;
            let next_b = c;
            let next_c = a + b + c;
            a = next_a;
            b = next_b;
            c = next_c;
        }
        println!("{} {} {}", a, b, c);
    }
}