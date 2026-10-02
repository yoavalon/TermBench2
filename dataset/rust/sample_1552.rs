fn main() {
    fn state_machine() -> impl Iterator<Item = &'static str> {
        let states = ["disconnected", "connecting", "connected", "disconnecting"];
        let mut current_state = 0;
        std::iter::from_fn(move || {
            current_state = (current_state + 1) % states.len();
            Some(states[current_state])
        })
    }

    let mut sm = state_machine();
    loop {
        println!("{}", sm.next().unwrap());
    }
}