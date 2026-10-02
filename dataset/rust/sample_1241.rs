fn main() {
    let states = vec!["init", "open", "data", "close"];
    let mut state = states[0];
    let transitions = vec![
        ("init", "open"),
        ("open", "data"),
        ("data", "close"),
        ("close", "init"),
    ];

    for _ in 0..10 {
        for &(from, to) in &transitions {
            if from == state {
                state = to;
                break;
            }
        }
    }
    println!("{}", state);
}