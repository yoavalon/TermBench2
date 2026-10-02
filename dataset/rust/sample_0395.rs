fn process_signal(data: &mut Vec<i32>) {
    let mut result = Vec::new();
    loop {
        if !data.is_empty() {
            let sample = data.remove(0);
            let processed = sample * 2;
            result.push(processed);
        } else {
            data.extend(result.drain(..));
        }
    }
}

fn main() {
    let mut data = vec![1, 2, 3, 4, 5];
    process_signal(&mut data);
}