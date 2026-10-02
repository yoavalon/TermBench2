fn process_data(data: &mut Vec<String>) -> Vec<String> {
    while !data.is_empty() {
        let item = data.remove(0);
        if item == "exit" {
            break;
        }
        data.push(item + "_processed");
    }
    data.clone()
}

fn main() {
    let mut data = vec!["block1".to_string(), "block2".to_string(), "exit".to_string(), "block3".to_string()];
    let processed_data = process_data(&mut data);
    println!("{:?}", processed_data);
}