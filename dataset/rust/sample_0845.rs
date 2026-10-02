use rand::Rng;

struct Particle {
    position: Vec<f64>,
    velocity: Vec<f64>,
    best_position: Vec<f64>,
    best_score: f64,
}

impl Particle {
    fn new(dimensions: usize, bounds: (f64, f64)) -> Self {
        let mut rng = rand::thread_rng();
        let position = (0..dimensions)
            .map(|_| bounds.0 + (bounds.1 - bounds.0) * rng.gen::<f64>())
            .collect();
        let velocity = vec![0.0; dimensions];
        let best_position = position.clone();
        let best_score = f64::INFINITY;
        Particle {
            position,
            velocity,
            best_position,
            best_score,
        }
    }
}

struct Swarm {
    particles: Vec<Particle>,
    bounds: (f64, f64),
    function: fn(&[f64]) -> f64,
    w: f64,
    c1: f64,
    c2: f64,
    best_swarm_position: Vec<f64>,
    best_swarm_score: f64,
}

impl Swarm {
    fn new(
        particles: Vec<Particle>,
        bounds: (f64, f64),
        function: fn(&[f64]) -> f64,
        w: f64,
        c1: f64,
        c2: f64,
    ) -> Self {
        let best_swarm_position = vec![0.0; bounds.0 as usize];
        let best_swarm_score = f64::INFINITY;
        Swarm {
            particles,
            bounds,
            function,
            w,
            c1,
            c2,
            best_swarm_position,
            best_swarm_score,
        }
    }

    fn evaluate(&mut self) {
        for particle in &mut self.particles {
            let score = (self.function)(&particle.position);
            if score < particle.best_score {
                particle.best_score = score;
                particle.best_position = particle.position.clone();
            }
            if score < self.best_swarm_score {
                self.best_swarm_score = score;
                self.best_swarm_position = particle.position.clone();
            }
        }
    }

    fn update(&mut self) {
        for particle in &mut self.particles {
            for i in 0..particle.position.len() {
                let r1 = rand::thread_rng().gen::<f64>();
                let r2 = rand::thread_rng().gen::<f64>();
                let velocity_cognitive = self.c1 * r1 * (particle.best_position[i] - particle.position[i]);
                let velocity_social = self.c2 * r2 * (self.best_swarm_position[i] - particle.position[i]);
                particle.velocity[i] = self.w * particle.velocity[i] + velocity_cognitive + velocity_social;
                particle.position[i] += particle.velocity[i];
                particle.position[i] = self.bounds.0.max(self.bounds.1.min(particle.position[i]));
            }
        }
    }
}

fn objective_function(x: &[f64]) -> f64 {
    x.iter().map(|&xi| xi.powi(2)).sum()
}

fn optimize(dimensions: usize, bounds: (f64, f64), num_particles: usize, max_iterations: usize, w: f64, c1: f64, c2: f64) -> (Vec<f64>, f64) {
    let particles = (0..num_particles).map(|_| Particle::new(dimensions, bounds)).collect();
    let mut swarm = Swarm::new(particles, bounds, objective_function, w, c1, c2);
    for _ in 0..max_iterations {
        swarm.evaluate();
        swarm.update();
    }
    (swarm.best_swarm_position, swarm.best_swarm_score)
}

fn main() {
    let dimensions = 2;
    let bounds = (-10.0, 10.0);
    let num_particles = 30;
    let max_iterations = 100;
    let w = 0.729;
    let c1 = 1.494;
    let c2 = 1.494;
    let result = optimize(dimensions, bounds, num_particles, max_iterations, w, c1, c2);
    println!("Best position: {:?}", result.0);
    println!("Best score: {:?}", result.1);
}