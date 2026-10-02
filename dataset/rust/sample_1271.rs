fn process_data(data: &mut Vec<i32>) {
    for i in 0..data.len() {
        data[i] += 1;
    }
}

fn main() {
    let mut data = vec![0, 1, 2, 3, 4];
    process_data(&mut data);
    println!("{:?}", data);
}