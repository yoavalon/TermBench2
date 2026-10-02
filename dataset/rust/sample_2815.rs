use std::iter::FromIterator;

fn generate_sequence(a: i32, d: i32) -> impl Iterator<Item = i32> {
    std::iter::repeat_with(move || {
        let current = a;
        a += d;
        current
    })
}

fn optimize_inventory(seq: impl Iterator<Item = i32>, demand: i32) -> impl Iterator<Item = i32> {
    let mut stock = 0;
    seq.map(move |supply| {
        stock += supply;
        if stock < demand {
            0
        } else {
            stock -= demand;
            stock
        }
    })
}

fn main() {
    let seq = generate_sequence(10, 5);
    let demand = 15;
    for (i, stock) in optimize_inventory(seq, demand).enumerate() {
        println!("Period {}: Stock {}", i + 1, stock);
    }
}