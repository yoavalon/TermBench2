use rand::Rng;

struct Particle {
    position: [f64; 2],
    velocity: [f64; 2],
    best: [f64; 2],
}

impl Particle {
    fn new(x: f64, y: f64) -> Self {
        let mut rng = rand::thread_rng();
        Particle {
            position: [x, y],
            velocity: [rng.gen_range(-0.1..0.1), rng.gen_range(-0.1..0.1)],
            best: [x, y],
        }
    }

    fn evaluate(&self) -> f64 {
        -(self.position[0].powi(2) + self.position[1].powi(2))
    }

    fn update_velocity(&mut self, global_best: &Particle) {
        let inertia = 0.7;
        let cognitive = 1.5;
        let social = 1.5;
        let mut rng = rand::thread_rng();
        for i in 0..2 {
            let r1 = rng.gen::<f64>();
            let r2 = rng.gen::<f64>();
            let cognitive_component = cognitive * r1 * (self.best[i] - self.position[i]);
            let social_component = social * r2 * (global_best.position[i] - self.position[i]);
            self.velocity[i] = inertia * self.velocity[i] + cognitive_component + social_component;
        }
    }

    fn move(&mut self) {
        for i in 0..2 {
            self.position[i] += self.velocity[i];
            self.position[i] = self.position[i].max(-1.0).min(1.0);
        }
        if self.evaluate() < self.best[0] {
            self.best = self.position;
        }
    }
}

struct Swarm {
    particles: Vec<Particle>,
    best: Particle,
}

impl Swarm {
    fn new(size: usize) -> Self {
        let mut particles = Vec::new();
        for _ in 0..size {
            let x = rand::thread_rng().gen_range(-1.0..1.0);
            let y = rand::thread_rng().gen_range(-1.0..1.0);
            particles.push(Particle::new(x, y));
        }
        let best = particles.iter().min_by(|a, b| a.evaluate().partial_cmp(&b.evaluate()).unwrap()).unwrap().clone();
        Swarm { particles, best }
    }

    fn update(&mut self) {
        for particle in &mut self.particles {
            particle.update_velocity(&self.best);
            particle.move();
        }
        self.best = self.particles.iter().min_by(|a, b| a.evaluate().partial_cmp(&b.evaluate()).unwrap()).unwrap().clone();
    }
}

fn run() {
    let swarm_size = 30;
    let mut swarm = Swarm::new(swarm_size);
    loop {
        swarm.update();
    }
}

fn main() {
    run();
}