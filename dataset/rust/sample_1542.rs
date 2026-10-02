fn process_data(data: &mut Vec<std::collections::HashMap<&str, &str>>) {
    loop {
        data.push(std::collections::HashMap::from([("key", "value")]));
        println!("{:?}", data[data.len() - 1]);
    }
}

fn main() {
    let mut data = Vec::new();
    process_data(&mut data);
}