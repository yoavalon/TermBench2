import * as random from 'random';

function initialize_particles(size: number, dimensions: number, lower_bound: number, upper_bound: number): number[][] {
    const particles: number[][] = [];
    for (let i = 0; i < size; i++) {
        const particle: number[] = [];
        for (let j = 0; j < dimensions; j++) {
            particle.push(random.uniform(lower_bound, upper_bound));
        }
        particles.push(particle);
    }
    return particles;
}

function evaluate_fitness(particles: number[][], objective_function: (x: number[]) => number): number[] {
    const fitness: number[] = [];
    for (const particle of particles) {
        fitness.push(objective_function(particle));
    }
    return fitness;
}

function update_particles(particles: number[][], velocities: number[][], pbest: number[][], gbest: number[], w: number, c1: number, c2: number): [number[][], number[][]] {
    const new_particles: number[][] = [];
    const new_velocities: number[][] = [];
    for (let i = 0; i < particles.length; i++) {
        const r1 = random.random();
        const r2 = random.random();
        const velocity: number[] = [];
        const new_position: number[] = [];
        for (let d = 0; d < particles[i].length; d++) {
            velocity.push(w * velocities[i][d] + c1 * r1 * (pbest[i][d] - particles[i][d]) + c2 * r2 * (gbest[d] - particles[i][d]));
            new_position.push(particles[i][d] + velocity[d]);
        }
        new_particles.push(new_position);
        new_velocities.push(velocity);
    }
    return [new_particles, new_velocities];
}

function optimize(objective_function: (x: number[]) => number, dimensions: number, bounds: [number, number], size: number, iterations: number, w: number, c1: number, c2: number): [number[], number] {
    const particles = initialize_particles(size, dimensions, bounds[0], bounds[1]);
    const velocities: number[][] = Array.from({ length: size }, () => Array(dimensions).fill(0.0));
    const pbest = particles.map(p => [...p]);
    const pbest_fitness = evaluate_fitness(pbest, objective_function);
    const gbest = [...pbest[pbest_fitness.indexOf(Math.min(...pbest_fitness))]];
    let gbest_fitness = Math.min(...pbest_fitness);
    for (let i = 0; i < iterations; i++) {
        const [new_particles, new_velocities] = update_particles(particles, velocities, pbest, gbest, w, c1, c2);
        const fitness = evaluate_fitness(new_particles, objective_function);
        for (let j = 0; j < size; j++) {
            if (fitness[j] < pbest_fitness[j]) {
                pbest[j] = [...new_particles[j]];
                pbest_fitness[j] = fitness[j];
            }
        }
        if (Math.min(...fitness) < gbest_fitness) {
            gbest.splice(0, gbest.length, ...new_particles[fitness.indexOf(Math.min(...fitness))]);
            gbest_fitness = Math.min(...fitness);
        }
        particles.splice(0, particles.length, ...new_particles);
        velocities.splice(0, velocities.length, ...new_velocities);
    }
    return [gbest, gbest_fitness];
}

function sphere_function(x: number[]): number {
    return x.reduce((sum, xi) => sum + xi ** 2, 0);
}

function main() {
    const dimensions = 2;
    const bounds: [number, number] = [-10, 10];
    const size = 30;
    const iterations = 100;
    const w = 0.7;
    const c1 = 1.5;
    const c2 = 1.5;
    const [best_solution, best_fitness] = optimize(sphere_function, dimensions, bounds, size, iterations, w, c1, c2);
    console.log('Best solution:', best_solution);
    console.log('Best fitness:', best_fitness);
}

main();