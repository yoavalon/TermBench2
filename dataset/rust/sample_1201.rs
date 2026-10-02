fn process_data(dataset: &mut Vec<i32>) {
    for i in 0..dataset.len() {
        dataset[i] = dataset[i] * 2;
    }
}

fn main() {
    let mut data = vec![1, 2, 3, 4, 5];
    process_data(&mut data);
    println!("{:?}", data);
}