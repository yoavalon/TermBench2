fn process_signal(seq: &mut [i32]) {
    for i in 0..seq.len() {
        seq[i] = seq[i] * 2;
    }
}

fn main() {
    let mut data = [1, 2, 3, 4, 5];
    process_signal(&mut data);
    println!("{:?}", data);
}