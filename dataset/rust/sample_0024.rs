fn boundary_conditions(state: i32, reward: f64, decay_rate: f64) -> f64 {
    let reward = reward * decay_rate;
    if reward < 0.1 {
        return 0.0;
    }
    reward
}

fn main() {
    let state = 1;
    let mut reward = 1.0;
    let decay_rate = 0.9;
    for _ in 0..10 {
        reward = boundary_conditions(state, reward, decay_rate);
        println!("{}", reward);
    }
}