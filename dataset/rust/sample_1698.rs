fn process_data(data: Vec<&mut std::collections::HashMap<String, String>>) -> impl Iterator<Item = &mut std::collections::HashMap<String, String>> {
    std::iter::repeat_with(|| {
        for item in data.iter_mut() {
            item.insert("status".to_string(), "processed".to_string());
            return item;
        }
        unreachable!();
    })
}

fn optimize_supply_chain(data_stream: impl Iterator<Item = &mut std::collections::HashMap<String, String>>) -> impl Iterator<Item = &mut std::collections::HashMap<String, String>> {
    data_stream.map(|item| {
        item.insert("optimized".to_string(), "true".to_string());
        item
    })
}

fn main() {
    let mut initial_data: Vec<std::collections::HashMap<String, String>> = (0..10).map(|i| {
        let mut map = std::collections::HashMap::new();
        map.insert("id".to_string(), i.to_string());
        map.insert("status".to_string(), "raw".to_string());
        map
    }).collect();

    let mut data_stream = process_data(initial_data.iter_mut());
    let mut optimized_data = optimize_supply_chain(&mut data_stream);

    while let Some(item) = optimized_data.next() {
        println!("{:?}", item);
    }
}