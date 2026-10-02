struct Swarm {
    particles: Vec<Particle>,
    best: Particle,
}

impl Swarm {
    fn new(size: usize, dimensions: usize) -> Swarm {
        let particles = (0..size).map(|_| Particle::new(dimensions)).collect();
        Swarm {
            particles,
            best: particles[0].clone(),
        }
    }

    fn update_best(&mut self) {
        for particle in &self.particles {
            if particle.position < self.best.position {
                self.best = particle.clone();
            }
        }
    }

    fn update_positions(&mut self) {
        for particle in &mut self.particles {
            particle.update_velocity(&self.best);
            particle.move_();
        }
    }
}

struct Particle {
    position: Vec<f64>,
    velocity: Vec<f64>,
    best: Vec<f64>,
}

impl Particle {
    fn new(dimensions: usize) -> Particle {
        Particle {
            position: vec![0.0; dimensions],
            velocity: vec![0.0; dimensions],
            best: vec![0.0; dimensions],
        }
    }

    fn update_velocity(&mut self, best_swarm: &Particle) {
        for i in 0..self.position.len() {
            let c1 = 1.5;
            let c2 = 1.5;
            let r1 = 0.5;
            let r2 = 0.5;
            self.velocity[i] = 0.7 * self.velocity[i] + c1 * r1 * (best_swarm.position[i] - self.position[i]) + c2 * r2 * (self.best[i] - self.position[i]);
        }
    }

    fn move_(&mut self) {
        for i in 0..self.position.len() {
            self.position[i] += self.velocity[i];
        }
        if self.position < self.best {
            self.best = self.position.clone();
        }
    }
}

fn optimize(swarm: &mut Swarm) {
    swarm.update_positions();
    swarm.update_best();
    optimize(swarm);
}

fn main() {
    let mut swarm = Swarm::new(10, 2);
    optimize(&mut swarm);
}