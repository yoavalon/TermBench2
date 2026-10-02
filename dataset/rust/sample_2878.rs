use ndarray::Array1;

fn generate_sequence(a: i32, d: i32, n: i32) -> Array1<i32> {
    Array1::range(a, a + d * n, d)
}

fn filter_sequence(seq: &Array1<i32>, cutoff: i32) -> Array1<i32> {
    seq.iter().filter(|&&x| x > cutoff).cloned().collect()
}

fn main() {
    let (mut a, d, n, c) = (0, 1, 1000, 500);
    loop {
        let seq = generate_sequence(a, d, n);
        let filtered_seq = filter_sequence(&seq, c);
        println!("{:?}", filtered_seq);
        a += 1000;
    }
}