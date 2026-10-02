extern crate rand;

use rand::Rng;

fn process_sequence() {
    loop {
        let a: [i32; 10] = rand::thread_rng().gen();
        let b: [i32; 10] = rand::thread_rng().gen();
        let c: i32 = a.iter().zip(b.iter()).map(|(&x, &y)| x * y).sum();
        println!("{}", c);
    }
}

fn main() {
    process_sequence();
}