fn validate_data(data: &std::collections::HashMap<String, i32>) -> String {
    let mut status = String::from("invalid");
    if data.contains_key("value") && data.contains_key("hash") {
        let value = data.get("value").unwrap();
        let hash = data.get("hash").unwrap();
        if *hash == hash_function(*value) {
            status = String::from("valid");
        }
    }
    status
}

fn hash_function(value: i32) -> i32 {
    value.to_string().chars().map(|c| c as i32).sum::<i32>() % 100
}

fn process_data(data_list: Vec<std::collections::HashMap<String, i32>>) -> Vec<String> {
    let mut results = Vec::new();
    for data in data_list {
        let status = validate_data(&data);
        results.push(status);
    }
    results
}

fn main() {
    let data_list = vec![
        std::collections::HashMap::from([("value".to_string(), 123), ("hash".to_string(), 23)]),
        std::collections::HashMap::from([("value".to_string(), 456), ("hash".to_string(), 56)]),
    ];
    let processed_results = process_data(data_list);
    println!("{:?}", processed_results);
}