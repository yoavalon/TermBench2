use rand::Rng;

fn simulate() {
    let mut state = [0.5, 0.5, 0.5];
    loop {
        for i in 0..3 {
            let mut rng = rand::thread_rng();
            let delta = rng.gen_range(-0.1..=0.1);
            state[i] += delta;
            state[i] = state[i].clamp(0.0, 1.0);
        }
        println!("{:?}", state);
    }
}

fn main() {
    simulate();
}