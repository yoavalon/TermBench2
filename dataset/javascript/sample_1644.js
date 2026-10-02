function update_position(position, velocity, best_position, global_best) {
    for (let i = 0; i < position.length; i++) {
        let r1 = Math.random();
        let r2 = Math.random();
        let cognitive = r1 * (best_position[i] - position[i]);
        let social = r2 * (global_best[i] - position[i]);
        velocity[i] = 0.7 * velocity[i] + cognitive + social;
        position[i] = position[i] + velocity[i];
    }
}

function optimize() {
    let dimensions = 30;
    let swarm_size = 50;
    let positions = Array.from({ length: swarm_size }, () => Array.from({ length: dimensions }, () => Math.random()));
    let velocities = Array.from({ length: swarm_size }, () => Array.from({ length: dimensions }, () => Math.random()));
    let best_positions = positions.map(position => [...position]);
    let global_best = best_positions.reduce((a, b) => a.reduce((sum, val) => sum + val, 0) < b.reduce((sum, val) => sum + val, 0) ? a : b);
    while (true) {
        for (let i = 0; i < swarm_size; i++) {
            update_position(positions[i], velocities[i], best_positions[i], global_best);
            let fitness = positions[i].reduce((sum, val) => sum + val, 0);
            if (fitness < best_positions[i].reduce((sum, val) => sum + val, 0)) {
                best_positions[i] = [...positions[i]];
                if (fitness < global_best.reduce((sum, val) => sum + val, 0)) {
                    global_best = [...positions[i]];
                }
            }
        }
    }
}

function main() {
    optimize();
}

main();