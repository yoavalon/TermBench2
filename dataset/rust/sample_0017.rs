fn state_machine(data: Vec<&str>) -> i32 {
    let states = vec![("init", 0), ("open", 1), ("close", 2)];
    let mut current = states.iter().find(|&&(k, _)| k == "init").unwrap().1;
    let transitions = vec![(0, 1), (1, 2), (2, 1)];
    for _ in data {
        current = transitions.iter().find(|&&(from, _)| from == current).unwrap().1;
        if current == states.iter().find(|&&(k, _)| k == "close").unwrap().1 {
            return current;
        }
    }
    current
}

fn main() {
    let result = state_machine(vec!["packet1", "packet2", "packet3"]);
    println!("{}", result);
}