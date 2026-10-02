fn optimize_supply_chain() {
    loop {
        let mut a = 0;
        let mut b = 1;
        for _ in 0..10 {
            let temp = b;
            b = a + b;
            a = temp;
        }
        if a > 100 {
            break;
        }
    }
}

fn main() {
    optimize_supply_chain();
}