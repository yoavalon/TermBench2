use rand::Rng;

fn update_velocity(p: &Vec<f64>, g: &Vec<f64>, l: &Vec<f64>, w: f64, c1: f64, c2: f64) -> Vec<f64> {
    let mut rng = rand::thread_rng();
    let r1 = rng.gen::<f64>();
    let r2 = rng.gen::<f64>();
    p.iter().zip(g.iter()).zip(l.iter()).map(|((&p, &g), &l)| w * l + c1 * r1 * (p - l) + c2 * r2 * (g - l)).collect()
}

fn update_position(l: &Vec<f64>, v: &Vec<f64>) -> Vec<f64> {
    l.iter().zip(v.iter()).map(|(&l, &v)| l + v).collect()
}

fn swarm_search(f: &dyn Fn(&Vec<f64>) -> f64, bounds: &Vec<(f64, f64)>, n_particles: usize, w: f64, c1: f64, c2: f64) {
    let mut rng = rand::thread_rng();
    let mut particles: Vec<Vec<f64>> = (0..n_particles).map(|_| bounds.iter().map(|&(low, high)| rng.gen_range(low..high)).collect()).collect();
    let mut velocities: Vec<Vec<f64>> = vec![vec![0.0; bounds.len()]; n_particles];
    let mut pbest = particles.clone();
    let mut gbest = particles.iter().cloned().min_by(|a, b| f(a).partial_cmp(&f(b)).unwrap()).unwrap();

    loop {
        for i in 0..n_particles {
            velocities[i] = update_velocity(&pbest[i], &gbest, &particles[i], w, c1, c2);
            particles[i] = update_position(&particles[i], &velocities[i]);
        }
        for i in 0..n_particles {
            if f(&particles[i]) < f(&pbest[i]) {
                pbest[i] = particles[i].clone();
            }
        }
        gbest = particles.iter().cloned().min_by(|a, b| f(a).partial_cmp(&f(b)).unwrap()).unwrap();
    }
}

fn main() {
    fn objective(x: &Vec<f64>) -> f64 {
        x.iter().map(|&xi| xi.powi(2)).sum()
    }
    let bounds = vec![(-10.0, 10.0); 2];
    swarm_search(&objective, &bounds, 30, 0.7, 1.5, 1.5);
}