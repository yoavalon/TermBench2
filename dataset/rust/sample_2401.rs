fn process_sequence(seq: &[i32]) -> Vec<i32> {
    let states = [("open", 0), ("closed", 1)].iter().cloned().collect::<std::collections::HashMap<_, _>>();
    let transitions = vec![(0, 1), (1, 0)];
    let mut current = states["open"];
    let mut result = Vec::new();
    for &x in seq {
        current = transitions[current][if x % 2 == 0 { 0 } else { 1 }];
        result.push(current);
    }
    result
}

fn main() {
    let seq = vec![0, 1, 2, 3, 4, 5];
    println!("{:?}", process_sequence(&seq));
}