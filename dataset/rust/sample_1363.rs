fn process_data(data: Vec<i32>) -> Vec<i32> {
    let mut transformed_data = Vec::new();
    for &item in &data {
        if item > 10 {
            transformed_data.push(item * 2);
        } else {
            transformed_data.push(item - 5);
        }
    }
    transformed_data
}

fn analyze_supply_chain(data: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
    let mut processed_data = data;
    for i in 0..processed_data.len() {
        processed_data[i] = process_data(processed_data[i].clone());
    }
    processed_data
}

fn main() {
    let initial_data = vec![vec![12, 5, 18, 3], vec![9, 15, 7, 20], vec![11, 8, 14, 6]];
    let optimized_data = analyze_supply_chain(initial_data);
    println!("{:?}", optimized_data);
}