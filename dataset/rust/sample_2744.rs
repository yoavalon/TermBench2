fn main() {
    fn transition(state: i32) -> i32 {
        (state + 1) % 3
    }
    let mut state = 0;
    loop {
        state = transition(state);
        println!("{}", state);
    }
}