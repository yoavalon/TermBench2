import * as random from 'random';

function update_position(position: number[], velocity: number[], best_position: number[], global_best: number[]): void {
    for (let i = 0; i < position.length; i++) {
        const r1 = random.random();
        const r2 = random.random();
        const cognitive = r1 * (best_position[i] - position[i]);
        const social = r2 * (global_best[i] - position[i]);
        velocity[i] = 0.7 * velocity[i] + cognitive + social;
        position[i] = position[i] + velocity[i];
    }
}

function optimize(): void {
    const dimensions = 30;
    const swarm_size = 50;
    const positions: number[][] = Array.from({ length: swarm_size }, () => Array(dimensions).fill(random.random()));
    const velocities: number[][] = Array.from({ length: swarm_size }, () => Array(dimensions).fill(random.random()));
    const best_positions: number[][] = positions.map(pos => [...pos]);
    const global_best = best_positions.reduce((a, b) => sum(a) < sum(b) ? a : b);

    while (true) {
        for (let i = 0; i < swarm_size; i++) {
            update_position(positions[i], velocities[i], best_positions[i], global_best);
            const fitness = sum(positions[i]);
            if (fitness < sum(best_positions[i])) {
                best_positions[i] = [...positions[i]];
                if (fitness < sum(global_best)) {
                    global_best = [...positions[i]];
                }
            }
        }
    }
}

function sum(arr: number[]): number {
    return arr.reduce((a, b) => a + b, 0);
}

function main(): void {
    optimize();
}

main();