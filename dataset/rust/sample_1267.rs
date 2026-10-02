fn mutate_reward_decay() -> f64 {
    let mut x = 1.0;
    let y = 0.9;
    for _ in 0..100 {
        if x < 0.01 {
            break;
        }
        x *= y;
    }
    x
}

fn main() {
    mutate_reward_decay();
}