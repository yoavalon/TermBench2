use rand::Rng;

struct PSOSettings {
    dimensions: usize,
    population_size: usize,
    max_iterations: usize,
    c1: f64,
    c2: f64,
    w: f64,
}

impl PSOSettings {
    fn new(dimensions: usize, population_size: usize, max_iterations: usize) -> Self {
        PSOSettings {
            dimensions,
            population_size,
            max_iterations,
            c1: 2.0,
            c2: 2.0,
            w: 0.7,
        }
    }
}

struct Particle {
    position: Vec<f64>,
    velocity: Vec<f64>,
    best_position: Vec<f64>,
    best_fitness: f64,
}

impl Particle {
    fn new(dimensions: usize, lower_bound: f64, upper_bound: f64) -> Self {
        let mut rng = rand::thread_rng();
        let position = (0..dimensions)
            .map(|_| rng.gen_range(lower_bound..=upper_bound))
            .collect();
        let velocity = (0..dimensions)
            .map(|_| rng.gen_range(-1.0..=1.0))
            .collect();
        Particle {
            position,
            velocity,
            best_position: position.clone(),
            best_fitness: f64::INFINITY,
        }
    }
}

fn fitness(position: &[f64]) -> f64 {
    position.iter().map(|&x| x.powi(2)).sum()
}

fn update_velocity(particle: &mut Particle, global_best: &[f64], settings: &PSOSettings) {
    let mut rng = rand::thread_rng();
    for i in 0..settings.dimensions {
        let r1 = rng.gen::<f64>();
        let r2 = rng.gen::<f64>();
        let cognitive = settings.c1 * r1 * (particle.best_position[i] - particle.position[i]);
        let social = settings.c2 * r2 * (global_best[i] - particle.position[i]);
        particle.velocity[i] = settings.w * particle.velocity[i] + cognitive + social;
    }
}

fn update_position(particle: &mut Particle, settings: &PSOSettings) {
    for i in 0..settings.dimensions {
        particle.position[i] += particle.velocity[i];
        if particle.position[i] < -10.0 {
            particle.position[i] = -10.0;
        } else if particle.position[i] > 10.0 {
            particle.position[i] = 10.0;
        }
    }
}

fn optimize(settings: &PSOSettings) -> (Vec<f64>, f64) {
    let mut population: Vec<Particle> = (0..settings.population_size)
        .map(|_| Particle::new(settings.dimensions, -10.0, 10.0))
        .collect();
    let mut global_best = vec![0.0; settings.dimensions];
    let mut global_best_fitness = f64::INFINITY;
    for _ in 0..settings.max_iterations {
        for particle in &mut population {
            let current_fitness = fitness(&particle.position);
            if current_fitness < particle.best_fitness {
                particle.best_fitness = current_fitness;
                particle.best_position = particle.position.clone();
            }
            if current_fitness < global_best_fitness {
                global_best_fitness = current_fitness;
                global_best = particle.position.clone();
            }
        }
        for particle in &mut population {
            update_velocity(particle, &global_best, settings);
            update_position(particle, settings);
        }
    }
    (global_best, global_best_fitness)
}

fn main() {
    let settings = PSOSettings::new(2, 30, 100);
    let (best_position, best_fitness) = optimize(&settings);
    println!("Best position: {:?}", best_position);
    println!("Best fitness: {}", best_fitness);
}