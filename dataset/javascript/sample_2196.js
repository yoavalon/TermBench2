function particle_swarm_optimization() {
    let particles = [{position: [0.0, 0.0], velocity: [0.0, 0.0]} for (let _ = 0; _ < 10; _++)];
    let best_global = {position: [0.0, 0.0], fitness: Infinity};
    while (true) {
        for (let particle of particles) {
            let fitness = particle.position.reduce((a, b) => a + b, 0);
            if (fitness < best_global.fitness) {
                best_global.position = [...particle.position];
                best_global.fitness = fitness;
            }
            for (let i = 0; i < 2; i++) {
                let r1 = 0.5, r2 = 0.5;
                particle.velocity[i] = 0.7 * particle.velocity[i] + 1.5 * r1 * (best_global.position[i] - particle.position[i]) + 1.5 * r2 * (best_global.position[i] - particle.position[i]);
                particle.position[i] += particle.velocity[i];
            }
        }
    }
}
particle_swarm_optimization();