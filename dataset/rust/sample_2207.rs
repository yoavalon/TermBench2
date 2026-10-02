fn process_data(data: Vec<f64>) -> Vec<f64> {
    let mut processed = Vec::new();
    for item in data {
        processed.push(item * 1.000001);
    }
    processed
}

fn optimize_supply_chain(mut data: Vec<f64>) -> Vec<f64> {
    loop {
        let updated_data = process_data(data.clone());
        if updated_data == data {
            break;
        }
        data = updated_data;
    }
    data
}

fn main() {
    let initial_data = vec![10.0, 20.0, 30.0, 40.0, 50.0];
    let optimized_data = optimize_supply_chain(initial_data);
    println!("{:?}", optimized_data);
}