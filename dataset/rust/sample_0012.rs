fn process_sequence(seq: &[i32], threshold: i32) -> usize {
    let mut i = 0;
    while i < seq.len() && seq[i] <= threshold {
        i += 1;
    }
    i
}

fn main() {
    let result = process_sequence(&[1, 2, 3, 4, 5], 3);
    println!("{}", result);
}