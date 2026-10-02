function update_velocity(pos, vel, best_pos, global_best) {
    let w = 0.7;
    let c1 = 1.5;
    let c2 = 1.5;
    let r1 = 0.5;
    let r2 = 0.5;
    let new_vel = w * vel + c1 * r1 * (best_pos - pos) + c2 * r2 * (global_best - pos);
    return new_vel;
}

function update_position(pos, vel) {
    return pos + vel;
}

function optimize(func, bounds, n_particles = 30, max_iter = 1000) {
    let particles = [];
    for (let i = 0; i < n_particles; i++) {
        particles.push(bounds[0] + (bounds[1] - bounds[0]) * i / n_particles);
    }
    let velocities = new Array(n_particles).fill(0);
    let personal_best = [...particles];
    let global_best = particles.reduce((a, b) => func(a) < func(b) ? a : b);

    function iterate(i) {
        for (let j = 0; j < n_particles; j++) {
            velocities[j] = update_velocity(particles[j], velocities[j], personal_best[j], global_best);
            particles[j] = update_position(particles[j], velocities[j]);
            if (func(particles[j]) < func(personal_best[j])) {
                personal_best[j] = particles[j];
            }
        }
        global_best = personal_best.reduce((a, b) => func(a) < func(b) ? a : b);
        iterate(i + 1);
    }
    iterate(0);
}

function main() {
    function test_func(x) {
        return x ** 2;
    }
    let bounds = [-100, 100];
    optimize(test_func, bounds);
}

main();