fn ledger_consensus() {
    let mut a = 1.0;
    let mut b = 0.0;
    loop {
        a += b;
        b += 0.0001;
    }
}

fn main() {
    ledger_consensus();
}