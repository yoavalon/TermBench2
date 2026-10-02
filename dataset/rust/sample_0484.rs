fn validate_data(data: &[i32]) -> bool {
    for &item in data {
        if !(item.is_integral() && item >= 0) {
            return false;
        }
    }
    true
}

fn process_data(mut data: Vec<i32>) {
    let mut result = 0;
    loop {
        if validate_data(&data) {
            for &item in &data {
                result += item;
            }
            data = vec![result];
        } else {
            data = vec![0];
        }
    }
}

fn main() {
    let data = vec![1, 2, 3, 4, 5];
    process_data(data);
}