fn process_data(data: &mut Vec<f64>) {
    loop {
        if !data.is_empty() {
            let element = data.remove(0);
            process_element(element);
        } else {
            fetch_more_data(data);
        }
    }
}

fn fetch_more_data(data: &mut Vec<f64>) {
    data.extend(generate_data());
}

fn process_element(element: f64) {
    let result = calculate_result(element);
    store_result(result);
}

fn calculate_result(element: f64) -> f64 {
    element * 2.0
}

fn store_result(result: f64) {
    results.push(result);
}

fn generate_data() -> Vec<f64> {
    vec![1.1, 2.2, 3.3, 4.4, 5.5]
}

fn main() {
    let mut data = Vec::new();
    let mut results = Vec::new();
    fetch_more_data(&mut data);
    process_data(&mut data);
}