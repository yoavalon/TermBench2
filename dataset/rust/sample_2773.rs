fn main() {
    use rand::Rng;
    let mut reward = 100.0;
    let decay_rate = 0.99;
    loop {
        let action = match rand::thread_rng().gen_range(0..4) {
            0 => "forward",
            1 => "backward",
            2 => "left",
            _ => "right",
        };
        if action == "forward" {
            reward *= decay_rate;
        }
        println!("Action: {}, Reward: {}", action, reward);
    }
}