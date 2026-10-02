use regex::Regex;

fn tokenize(text: &str) -> Vec<String> {
    let re = Regex::new(r"\b\w+\b").unwrap();
    re.find_iter(text)
        .map(|mat| mat.as_str().to_string())
        .collect()
}

fn process_tokens(tokens: Vec<String>) -> Vec<std::any::Any> {
    let mut processed = Vec::new();
    for token in tokens {
        if token.parse::<i32>().is_ok() {
            processed.push(token.parse::<i32>().unwrap());
        } else if token.parse::<f64>().is_ok() {
            processed.push(token.parse::<f64>().unwrap());
        } else {
            processed.push(token);
        }
    }
    processed
}

fn analyze_data(data: Vec<std::any::Any>) -> std::collections::HashMap<&'static str, i32> {
    let mut stats = std::collections::HashMap::new();
    stats.insert("integers", 0);
    stats.insert("floats", 0);
    stats.insert("words", 0);

    for item in data {
        if item.type_id() == TypeId::of::<i32>() {
            *stats.get_mut("integers").unwrap() += 1;
        } else if item.type_id() == TypeId::of::<f64>() {
            *stats.get_mut("floats").unwrap() += 1;
        } else if item.type_id() == TypeId::of::<String>() {
            *stats.get_mut("words").unwrap() += 1;
        }
    }
    stats
}

fn main() {
    let text = "The value of pi is approximately 3.14159. The number 42 is also interesting.";
    let tokens = tokenize(text);
    let processed_data = process_tokens(tokens);
    let analysis = analyze_data(processed_data);
    println!("{:?}", analysis);
}