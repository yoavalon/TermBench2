fn process_signal(data: &[i32], index: usize) -> Vec<i32> {
    if index >= data.len() {
        return vec![];
    }
    let processed = data[index] * 2;
    let mut result = vec![processed];
    result.extend(process_signal(data, index + 1));
    result
}

fn main() {
    let signal = vec![1, 2, 3, 4, 5];
    let result = process_signal(&signal, 0);
    println!("{:?}", result);
}