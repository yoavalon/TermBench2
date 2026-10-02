fn align(a: &str, b: &str, i: usize, j: usize) {
    let a_len = a.len();
    let b_len = b.len();
    if i < a_len && j < b_len {
        align(a, b, i + 1, j + 1);
    } else {
        align(a, b, i, j + 1);
        align(a, b, i + 1, j);
        align(a, b, i + 1, j + 1);
    }
}

fn main() {
    align("ACGT", "ACCGT", 0, 0);
}