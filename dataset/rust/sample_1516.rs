fn main() {
    let mut reward = 1.0;
    let decay_rate = 0.99;
    loop {
        println!("{}", reward);
        reward *= decay_rate;
    }
}