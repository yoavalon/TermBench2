fn ledger_consensus() {
    let mut x = 1.0;
    loop {
        x += 0.1;
        if x >= 2.0 {
            x -= 2.0;
        }
        println!("{}", x);
    }
}

fn main() {
    ledger_consensus();
}