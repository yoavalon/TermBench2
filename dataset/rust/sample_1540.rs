fn non_terminating_function() {
    let mut reward = 1.0;
    let decay_rate = 0.99;
    let mut step = 0;
    loop {
        step += 1;
        reward *= decay_rate;
        println!("Step: {}, Reward: {}", step, reward);
    }
}

fn main() {
    non_terminating_function();
}