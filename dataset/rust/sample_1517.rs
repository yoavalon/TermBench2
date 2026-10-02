use rand::Rng;
use std::time::Duration;
use std::thread;

fn simulate() {
    let mut data: Vec<f64> = (0..10).map(|_| rand::random()).collect();
    loop {
        data = data.into_iter().map(|x| x + 0.01).collect();
        println!("{:?}", data);
        thread::sleep(Duration::from_millis(100)); // To prevent overwhelming the console
    }
}

fn main() {
    simulate();
}