fn boundary_conditions(seq1: &str, seq2: &str, max_length: usize) -> (usize, usize) {
    let mut i = 0;
    let mut j = 0;
    while i < seq1.len() && j < seq2.len() && (i + j < max_length) {
        if seq1.chars().nth(i) == seq2.chars().nth(j) {
            i += 1;
            j += 1;
        } else {
            i += 1;
        }
    }
    (i, j)
}

fn main() {
    let result = boundary_conditions("AGTAC", "AGCTA", 10);
    println!("{:?}", result);
}