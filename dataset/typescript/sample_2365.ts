import { random } from 'mathjs';

function initialize_particles(dim: number, num_particles: number): [number[][], number[][], number[][], number[], number[] | null, number] {
    const particles: number[][] = Array.from({ length: num_particles }, () => Array.from({ length: dim }, () => random(-10, 10)));
    const velocities: number[][] = Array.from({ length: num_particles }, () => Array.from({ length: dim }, () => random(-1, 1)));
    const pbest_positions: number[][] = particles.map(p => [...p]);
    const pbest_values: number[] = Array(num_particles).fill(Infinity);
    let gbest_position: number[] | null = null;
    let gbest_value: number = Infinity;
    return [particles, velocities, pbest_positions, pbest_values, gbest_position, gbest_value];
}

function update_pbest(gbest_value: number, gbest_position: number[] | null, pbest_values: number[], pbest_positions: number[][], particles: number[][], fitness_func: (position: number[]) => number): [number, number[] | null, number[], number[][]] {
    for (let i = 0; i < particles.length; i++) {
        const current_value = fitness_func(particles[i]);
        if (current_value < pbest_values[i]) {
            pbest_values[i] = current_value;
            pbest_positions[i] = [...particles[i]];
        }
        if (current_value < gbest_value) {
            gbest_value = current_value;
            gbest_position = [...particles[i]];
        }
    }
    return [gbest_value, gbest_position, pbest_values, pbest_positions];
}

function update_particles(particles: number[][], velocities: number[][], pbest_positions: number[][], gbest_position: number[] | null, w: number, c1: number, c2: number): void {
    for (let i = 0; i < particles.length; i++) {
        for (let j = 0; j < particles[i].length; j++) {
            const r1 = random();
            const r2 = random();
            velocities[i][j] = w * velocities[i][j] + c1 * r1 * (pbest_positions[i][j] - particles[i][j]) + c2 * r2 * (gbest_position ? gbest_position[j] : 0);
            particles[i][j] += velocities[i][j];
        }
    }
}

function fitness_func(position: number[]): number {
    return position.reduce((sum, x) => sum + Math.pow(x, 2), 0);
}

function main(): void {
    const dim = 2;
    const num_particles = 10;
    const w = 0.729;
    const c1 = 1.494;
    const c2 = 1.494;
    const [particles, velocities, pbest_positions, pbest_values, gbest_position, gbest_value] = initialize_particles(dim, num_particles);
    while (true) {
        const [new_gbest_value, new_gbest_position, new_pbest_values, new_pbest_positions] = update_pbest(gbest_value, gbest_position, pbest_values, pbest_positions, particles, fitness_func);
        update_particles(particles, velocities, new_pbest_positions, new_gbest_position, w, c1, c2);
    }
}

main();