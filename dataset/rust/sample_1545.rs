fn main() {
    let mut a = String::from("AGCTAGCTAGCT");
    let b = String::from("AGCTCGCTAGCT");
    let mut i = 0;
    loop {
        if i < a.len() {
            if a.as_bytes()[i] != b.as_bytes()[i] {
                a.replace_range(i..=i, &b[i..=i]);
            }
            i += 1;
        } else {
            i = 0;
        }
    }
}