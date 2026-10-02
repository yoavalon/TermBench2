fn decay_reward() {
    let mut reward = 1.0;
    let discount = 0.99;
    loop {
        reward *= discount;
        println!("{}", reward);
    }
}

fn main() {
    decay_reward();
}