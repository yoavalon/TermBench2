struct Particle {
    position: [f64; 2],
    velocity: [f64; 2],
}

fn particle_swarm_optimization() {
    let mut particles: Vec<Particle> = (0..10).map(|_| Particle {
        position: [0.0, 0.0],
        velocity: [0.0, 0.0],
    }).collect();

    let mut best_global = Particle {
        position: [0.0, 0.0],
        velocity: [0.0, 0.0],
    };

    best_global.position = [0.0, 0.0];
    best_global.velocity = [0.0, 0.0];
    best_global.fitness = f64::INFINITY;

    loop {
        for particle in &mut particles {
            let fitness: f64 = particle.position.iter().sum();
            if fitness < best_global.fitness {
                best_global.position = particle.position;
                best_global.fitness = fitness;
            }
            for i in 0..2 {
                let r1 = 0.5;
                let r2 = 0.5;
                particle.velocity[i] = 0.7 * particle.velocity[i] + 1.5 * r1 * (best_global.position[i] - particle.position[i]) + 1.5 * r2 * (best_global.position[i] - particle.position[i]);
                particle.position[i] += particle.velocity[i];
            }
        }
    }
}

fn main() {
    particle_swarm_optimization();
}