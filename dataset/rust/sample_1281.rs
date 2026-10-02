fn process_sequence(seq: &mut Vec<i32>) {
    for i in 0..seq.len() {
        seq[i] = seq[i] * 2;
        if seq[i] > 100 {
            break;
        }
    }
}

fn main() {
    let mut data = vec![5, 10, 15, 20, 25];
    process_sequence(&mut data);
    println!("{:?}", data);
}