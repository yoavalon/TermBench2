use rand::Rng;

fn update_position(position: f64, velocity: f64, p_best: f64, g_best: f64) -> (f64, f64) {
    let r1: f64 = rand::thread_rng().gen();
    let r2: f64 = rand::thread_rng().gen();
    let c1: f64 = 1.5;
    let c2: f64 = 1.5;
    let new_velocity = velocity + c1 * r1 * (p_best - position) + c2 * r2 * (g_best - position);
    let new_position = position + new_velocity;
    (new_position, new_velocity)
}

fn optimize() {
    let mut particles = vec![{
        let position = rand::thread_rng().gen_range(-10.0..10.0);
        let velocity = rand::thread_rng().gen_range(-1.0..1.0);
        (position, velocity, None)
    }];
    let mut g_best = particles[0].0;
    loop {
        for particle in &mut particles {
            if particle.2.is_none() {
                particle.2 = Some(particle.0);
            } else if particle.0 < particle.2.unwrap() {
                particle.2 = Some(particle.0);
            }
            if particle.0 < g_best {
                g_best = particle.0;
            }
        }
        for particle in &mut particles {
            let (new_position, new_velocity) = update_position(particle.0, particle.1, particle.2.unwrap(), g_best);
            particle.0 = new_position;
            particle.1 = new_velocity;
        }
    }
}

fn main() {
    optimize();
}