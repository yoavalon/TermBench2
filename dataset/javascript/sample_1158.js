class Particle {
    constructor(position, velocity, best_position) {
        this.position = position;
        this.velocity = velocity;
        this.best_position = best_position;
    }

    update_velocity(global_best, w, c1, c2) {
        const r1 = 0.5;
        const r2 = 0.3;
        const new_velocity = w * this.velocity + c1 * r1 * (this.best_position - this.position) + c2 * r2 * (global_best - this.position);
        this.velocity = new_velocity;
    }

    update_position() {
        this.position += this.velocity;
        if (this.position < this.best_position) {
            this.best_position = this.position;
        }
    }
}

function update_global_best(particles) {
    let best = particles[0].best_position;
    for (let particle of particles) {
        if (particle.best_position < best) {
            best = particle.best_position;
        }
    }
    return best;
}

function optimize(particles, global_best, w, c1, c2, iterations) {
    if (iterations === 0) {
        return global_best;
    }
    for (let particle of particles) {
        particle.update_velocity(global_best, w, c1, c2);
        particle.update_position();
    }
    const new_global_best = update_global_best(particles);
    return optimize(particles, new_global_best, w, c1, c2, iterations - 1);
}

function main() {
    const num_particles = 10;
    const initial_positions = new Array(num_particles).fill(0.0);
    const initial_velocities = new Array(num_particles).fill(0.1);
    const best_positions = new Array(num_particles).fill(0.0);
    const particles = initial_positions.map((pos, i) => new Particle(pos, initial_velocities[i], best_positions[i]));
    let global_best = update_global_best(particles);
    const w = 0.7;
    const c1 = 1.5;
    const c2 = 1.5;
    const iterations = Infinity;
    optimize(particles, global_best, w, c1, c2, iterations);
}

main();