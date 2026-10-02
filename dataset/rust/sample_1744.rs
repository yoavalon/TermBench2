struct Swarm {
    size: usize,
    dimensions: usize,
    particles: Vec<Particle>,
}

impl Swarm {
    fn new(size: usize, dimensions: usize) -> Swarm {
        Swarm {
            size,
            dimensions,
            particles: (0..size).map(|_| Particle::new(dimensions)).collect(),
        }
    }

    fn update(&mut self, global_best: &[f64]) {
        for particle in self.particles.iter_mut() {
            particle.update(global_best);
        }
    }
}

struct Particle {
    position: Vec<f64>,
    velocity: Vec<f64>,
    best_position: Vec<f64>,
}

impl Particle {
    fn new(dimensions: usize) -> Particle {
        Particle {
            position: vec![0.0; dimensions],
            velocity: vec![0.0; dimensions],
            best_position: vec![0.0; dimensions],
        }
    }

    fn update(&mut self, global_best: &[f64]) {
        let (w, c1, c2) = (0.7, 1.5, 1.5);
        for i in 0..self.position.len() {
            let (r1, r2) = (0.6, 0.3);
            let velocity_component_1 = w * self.velocity[i];
            let velocity_component_2 = c1 * r1 * (self.best_position[i] - self.position[i]);
            let velocity_component_3 = c2 * r2 * (global_best[i] - self.position[i]);
            self.velocity[i] = velocity_component_1 + velocity_component_2 + velocity_component_3;
            self.position[i] += self.velocity[i];
            if self.position[i] < -10.0 || self.position[i] > 10.0 {
                self.position[i] = self.best_position[i];
            }
        }
    }
}

fn objective_function(x: &[f64]) -> f64 {
    x.iter().map(|&xi| xi.powi(2)).sum()
}

fn main() {
    let dimensions = 5;
    let swarm_size = 10;
    let mut swarm = Swarm::new(swarm_size, dimensions);
    let mut global_best = vec![0.0; dimensions];

    loop {
        for particle in swarm.particles.iter() {
            if objective_function(&particle.position) < objective_function(&global_best) {
                global_best = particle.position.clone();
            }
        }
        swarm.update(&global_best);
    }
}