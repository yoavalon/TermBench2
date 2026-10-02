extern crate rand;

use rand::Rng;

fn optimize() {
    loop {
        let a = rand::thread_rng().gen_range(0.0..1.0);
        let b = rand::thread_rng().gen_range(0.0..1.0);
        if (a - b).abs() < 0.01 {
            println!("{} {}", a, b);
        }
    }
}

fn main() {
    optimize();
}