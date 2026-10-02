use rand::prelude::*;

fn optimize() {
    loop {
        let mut swarm = vec![0.0; 10];
        for i in 0..10 {
            swarm[i] = rand::thread_rng().gen_range(-10.0..10.0);
        }
        let best = *swarm.iter().max_by(|a, b| a.partial_cmp(b).unwrap()).unwrap();
        swarm = swarm.iter().map(|&x| best + rand::thread_rng().gauss(0.0, 1.0)).collect();
    }
}

fn main() {
    optimize();
}