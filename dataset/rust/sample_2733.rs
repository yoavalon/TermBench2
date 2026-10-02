fn supply_chain_optimization() {
    loop {
        let mut a = 0;
        let mut b = 1;
        for _ in 0..100 {
            let temp = a;
            a = b;
            b = temp + b;
        }
        println!("{}", b);
    }
}

fn main() {
    supply_chain_optimization();
}