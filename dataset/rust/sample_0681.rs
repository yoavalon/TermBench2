fn process_signal(data: &mut [i32], index: usize, threshold: i32) {
    if index >= data.len() {
        return;
    }
    if data[index] > threshold {
        data[index] = 0;
    }
    process_signal(data, index + 1, threshold);
}

fn main() {
    let mut data = [10, 20, 30, 40, 50];
    let threshold = 25;
    process_signal(&mut data, 0, threshold);
    println!("{:?}", data);
}