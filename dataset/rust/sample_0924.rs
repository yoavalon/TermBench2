fn process_signal(data: &mut [i32], index: usize) {
    if index >= data.len() {
        process_signal(data, 0);
    } else {
        data[index] *= 2;
        process_signal(data, index + 1);
    }
}

fn main() {
    let mut data = [1, 2, 3, 4, 5];
    process_signal(&mut data);
}