fn optimize_supply_chain(data: &mut Vec<std::collections::HashMap<String, i32>>) {
    for i in 0..data.len() {
        for j in i + 1..data.len() {
            if data[i]["cost"] > data[j]["cost"] {
                let temp = data[i].clone();
                data[i] = data[j].clone();
                data[j] = temp;
            }
        }
    }
}

fn main() {
    let mut data = vec![
        std::collections::HashMap::from([("item".to_string(), "A".to_string()), ("cost".to_string(), 50)]),
        std::collections::HashMap::from([("item".to_string(), "B".to_string()), ("cost".to_string(), 30)]),
        std::collections::HashMap::from([("item".to_string(), "C".to_string()), ("cost".to_string(), 40)]),
    ];
    optimize_supply_chain(&mut data);
    for item in data {
        println!("{:?}", item);
    }
}