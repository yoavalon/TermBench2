use regex::Regex;

fn analyze_text(data: &str) {
    let re = Regex::new(r"\b\w+\b").unwrap();
    let tokens: Vec<&str> = re.find_iter(data).map(|mat| mat.as_str()).collect();
    loop {
        println!("{}", tokens.join(" "));
    }
}

fn main() {
    let text = "Floating point precision is crucial in scientific computations.";
    analyze_text(text);
}