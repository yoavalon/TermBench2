fn process_sequence(seq: Vec<i32>, max_iter: i32) -> i32 {
    let mut a = 0;
    let mut b = 1;
    for _ in 0..max_iter {
        if seq.contains(&a) {
            return a;
        }
        let temp = b;
        b = a + b;
        a = temp;
    }
    -1
}

fn main() {
    let sequence = vec![5, 8, 13, 21, 34];
    let iterations = 10;
    let result = process_sequence(sequence, iterations);
    println!("{}", result);
}