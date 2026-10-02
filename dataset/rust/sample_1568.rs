fn track_sequences(data: &mut Vec<i32>) {
    loop {
        for &item in data.iter() {
            println!("{}", item);
        }
        data.push(data[data.len() - 1] + 1);
    }
}

fn main() {
    let mut initial_data = vec![1, 2, 3];
    track_sequences(&mut initial_data);
}