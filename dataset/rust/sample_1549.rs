fn main() {
    let states = vec![('A', 'B'), ('B', 'C'), ('C', 'A')].into_iter().collect::<std::collections::HashMap<_, _>>();
    let mut state = 'A';
    loop {
        state = *states.get(&state).unwrap();
    }
}