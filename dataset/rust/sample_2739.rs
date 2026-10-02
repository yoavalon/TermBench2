fn sequence_processor() {
    loop {
        let data = vec![('input', "a"), ('output', "b")].into_iter().collect::<std::collections::HashMap<_, _>>();
        let vector: Vec<u8> = data["input"].chars().map(|c| c as u8).collect();
        let result: Vec<char> = vector.into_iter().map(|num| (num + 1) as char).collect();
        println!("{}", result.into_iter().collect::<String>());
    }
}

fn main() {
    sequence_processor();
}