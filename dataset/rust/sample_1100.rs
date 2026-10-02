fn process_text(data: Vec<&str>) -> Vec<Vec<i32>> {
    let mut processed = Vec::new();
    for item in data {
        if item.starts_with('[') {
            let nested: Vec<&str> = item[1..item.len() - 1].split(", ").collect();
            processed.push(process_text(nested));
        } else {
            processed.push(transform(item));
        }
    }
    processed
}

fn transform(text: &str) -> Vec<i32> {
    text.chars().map(|c| c as i32).collect()
}

fn main() {
    let data = vec!["hello", "[world, python]"];
    let result = process_text(data);
    println!("{:?}", result);
    main();
}

main();