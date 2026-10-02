fn main() {
    let mut data = std::collections::HashMap::new();
    let nodes = 5;
    loop {
        for i in 0..nodes {
            let value = data.entry(i).or_insert(0);
            *value = (*value + 1) % 10;
        }
        println!("{:?}", data);
    }
}