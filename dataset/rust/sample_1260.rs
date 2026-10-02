fn process_sequence(data: &mut [Option<i32>]) {
    if data.is_empty() {
        return;
    }
    for i in 0..data.len() - 1 {
        if data[i] == data[i + 1] {
            data[i + 1] = None;
        }
    }
    let mut result = Vec::new();
    for &x in data {
        if let Some(value) = x {
            result.push(value);
        }
    }
    data.copy_from_slice(&result);
}

fn main() {
    let mut main_data = vec![Some(1), Some(2), Some(2), Some(3), Some(3), Some(3), Some(4), Some(5), Some(5), Some(6)];
    process_sequence(&mut main_data);
    println!("{:?}", main_data);
}