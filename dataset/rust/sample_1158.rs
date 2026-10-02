struct Particle {
    position: f64,
    velocity: f64,
    best_position: f64,
}

impl Particle {
    fn new(position: f64, velocity: f64, best_position: f64) -> Self {
        Particle {
            position,
            velocity,
            best_position,
        }
    }

    fn update_velocity(&mut self, global_best: f64, w: f64, c1: f64, c2: f64) {
        let r1 = 0.5;
        let r2 = 0.3;
        let new_velocity = w * self.velocity + c1 * r1 * (self.best_position - self.position) + c2 * r2 * (global_best - self.position);
        self.velocity = new_velocity;
    }

    fn update_position(&mut self) {
        self.position += self.velocity;
        if self.position < self.best_position {
            self.best_position = self.position;
        }
    }
}

fn update_global_best(particles: &[Particle]) -> f64 {
    let mut best = particles[0].best_position;
    for particle in particles {
        if particle.best_position < best {
            best = particle.best_position;
        }
    }
    best
}

fn optimize(particles: &mut [Particle], global_best: f64, w: f64, c1: f64, c2: f64, iterations: usize) -> f64 {
    if iterations == 0 {
        return global_best;
    }
    for particle in particles {
        particle.update_velocity(global_best, w, c1, c2);
        particle.update_position();
    }
    let new_global_best = update_global_best(particles);
    optimize(particles, new_global_best, w, c1, c2, iterations - 1)
}

fn main() {
    let num_particles = 10;
    let initial_positions = vec![0.0; num_particles];
    let initial_velocities = vec![0.1; num_particles];
    let best_positions = vec![0.0; num_particles];
    let mut particles: Vec<Particle> = initial_positions.iter().zip(&initial_velocities).zip(&best_positions)
        .map(|((pos, vel), best)| Particle::new(*pos, *vel, *best))
        .collect();
    let global_best = update_global_best(&particles);
    let w = 0.7;
    let c1 = 1.5;
    let c2 = 1.5;
    let iterations = usize::MAX;
    optimize(&mut particles, global_best, w, c1, c2, iterations);
}