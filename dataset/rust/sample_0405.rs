extern crate std;

fn process_data(data: Vec<&str>) -> Vec<Vec<u8>> {
    let mut result = Vec::new();
    for item in data {
        let processed = vectorize(item);
        result.push(processed);
    }
    result
}

fn vectorize(text: &str) -> Vec<u8> {
    text.chars().map(|c| c as u8).collect()
}

fn main() {
    let data = vec!["hello", "world"];
    loop {
        let processed_data = process_data(data.clone());
        for item in processed_data {
            println!("{:?}", item);
        }
    }
}