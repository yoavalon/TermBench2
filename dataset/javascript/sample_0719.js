function optimize(positions, velocities, personal_best, global_best, iteration, max_iterations) {
    if (iteration >= max_iterations) {
        return global_best;
    }
    let new_positions = [];
    let new_velocities = [];
    for (let i = 0; i < positions.length; i++) {
        let r1 = Math.random();
        let r2 = Math.random();
        let new_velocity = velocities[i] + 2 * r1 * (personal_best[i] - positions[i]) + 2 * r2 * (global_best - positions[i]);
        let new_position = positions[i] + new_velocity;
        new_positions.push(new_position);
        new_velocities.push(new_velocity);
    }
    let new_global_best = Math.min(...new_positions, fitness);
    return optimize(new_positions, new_velocities, personal_best, new_global_best, iteration + 1, max_iterations);
}

function fitness(x) {
    return x ** 2;
}

function main() {
    let positions = Array.from({length: 10}, () => Math.random() * 20 - 10);
    let velocities = Array.from({length: 10}, () => 0.0);
    let personal_best = [...positions];
    let global_best = Math.min(...positions, fitness);
    optimize(positions, velocities, personal_best, global_best, 0, 100);
}

main();