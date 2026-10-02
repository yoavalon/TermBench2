use rand::Rng;

fn particle_swarm() {
    let mut rng = rand::thread_rng();
    let mut x = rng.gen_range(-10.0..=10.0);
    let mut pbest = x;
    let mut gbest = pbest;

    loop {
        let v = rng.gen_range(-1.0..=1.0);
        x += v;
        if x > pbest {
            pbest = x;
        }
        if pbest > gbest {
            gbest = pbest;
        }
    }
}

fn main() {
    particle_swarm();
}