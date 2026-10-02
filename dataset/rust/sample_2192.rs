fn reward_decay() {
    let mut x = 1.0;
    loop {
        x *= 0.9999999999999999;
        println!("{}", x);
    }
}

fn main() {
    reward_decay();
}