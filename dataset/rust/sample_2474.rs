fn calculate_altitude_sequence() -> Vec<i32> {
    let mut a = 3000;
    let mut b = 4000;
    let mut sequence = vec![a, b];
    for _ in 0..8 {
        let next = (a + b) / 2;
        sequence.push(next);
        a = b;
        b = next;
    }
    sequence
}

fn main() {
    println!("{:?}", calculate_altitude_sequence());
}