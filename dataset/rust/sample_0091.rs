fn consensus_mechanism() -> i32 {
    let mut a = 1;
    let mut b = 0;
    for _ in 0..10 {
        let temp = a;
        a = b;
        b = temp + b;
    }
    a
}

fn main() {
    consensus_mechanism();
}