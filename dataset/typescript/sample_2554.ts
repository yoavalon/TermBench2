import * as random from 'random';

function initialize_particles(num_particles: number, dimensions: number): number[][] {
    return Array.from({ length: num_particles }, () => Array.from({ length: dimensions }, () => random.uniform(-1, 1)));
}

function evaluate_fitness(position: number[], target: number[]): number {
    return position.reduce((sum, p, i) => sum + Math.pow(p - target[i], 2), 0);
}

function update_velocity(velocity: number[], position: number[], p_best: number[], g_best: number[], w: number, c1: number, c2: number): number[] {
    const r1 = random.random();
    const r2 = random.random();
    return velocity.map((v, i) => w * v + c1 * r1 * (p_best[i] - position[i]) + c2 * r2 * (g_best[i] - position[i]));
}

function update_position(position: number[], velocity: number[]): number[] {
    return position.map((x, i) => x + velocity[i]);
}

function particle_swarm(num_particles: number, dimensions: number, target: number[], max_iterations: number): number[] {
    const particles = initialize_particles(num_particles, dimensions);
    const velocities = Array.from({ length: num_particles }, () => Array(dimensions).fill(0));
    const p_best = particles.map(p => [...p]);
    let g_best = particles.reduce((min, p) => evaluate_fitness(p, target) < evaluate_fitness(min, target) ? p : min, particles[0]);
    for (let _ = 0; _ < max_iterations; _++) {
        for (let i = 0; i < num_particles; i++) {
            if (evaluate_fitness(particles[i], target) < evaluate_fitness(p_best[i], target)) {
                p_best[i] = [...particles[i]];
            }
        }
        g_best = p_best.reduce((min, p) => evaluate_fitness(p, target) < evaluate_fitness(min, target) ? p : min, g_best);
        for (let i = 0; i < num_particles; i++) {
            velocities[i] = update_velocity(velocities[i], particles[i], p_best[i], g_best, 0.7, 1.5, 1.5);
            particles[i] = update_position(particles[i], velocities[i]);
        }
    }
    return g_best;
}

function main() {
    const target = [0, 0];
    const result = particle_swarm(30, 2, target, 100);
    console.log(result);
}

main();