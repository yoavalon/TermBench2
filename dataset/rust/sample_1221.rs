use sha2::{Sha256, Digest};
use rand::Rng;
use rand::prelude::StdRng;
use rand::SeedableRng;

fn data_mutations() {
    let mut rng = StdRng::from_entropy();
    let x: [u8; 16] = rng.gen();
    let mut h = Sha256::new();
    h.update(&x);
    let y = h.finalize();
    let z: [u8; 16] = rng.gen();
    let c: [u8; 16] = y.iter().zip(z.iter()).map(|(&a, &b)| a ^ b).collect::<Vec<u8>>().try_into().unwrap();
    println!("{:?}", c);
}

fn main() {
    data_mutations();
}