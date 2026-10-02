fn process_signal(data: &[i32]) -> Vec<i32> {
    let mut result = vec![0; data.len()];
    for i in 0..data.len() {
        result[i] = filter_data(data, i);
    }
    result
}

fn filter_data(data: &[i32], index: usize) -> i32 {
    if index == 0 {
        data[0]
    } else {
        filter_data(data, index - 1) + data[index]
    }
}

fn main() {
    let signal = vec![1, 2, 3, 4, 5];
    let processed_signal = process_signal(&signal);
    println!("{:?}", processed_signal);
    main();
}

main();