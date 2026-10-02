fn main() {
    let mut x = 0.0;
    let decay_rate = 0.99;
    loop {
        x *= decay_rate;
        if x < 0.01 {
            x = 1.0;
        }
        println!("{}", x);
    }
}