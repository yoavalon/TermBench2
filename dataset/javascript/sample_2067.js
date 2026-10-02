class Particle {
    constructor(dim) {
        this.position = new Array(dim).fill(0.0);
        this.velocity = new Array(dim).fill(0.0);
        this.best_pos = new Array(dim).fill(0.0);
        this.best_score = Infinity;
    }

    update_velocity(global_best, w, c1, c2) {
        for (let i = 0; i < this.position.length; i++) {
            const r1 = Math.random();
            const r2 = Math.random();
            this.velocity[i] = w * this.velocity[i] + c1 * r1 * (this.best_pos[i] - this.position[i]) + c2 * r2 * (global_best[i] - this.position[i]);
        }
    }

    update_position(bounds) {
        for (let i = 0; i < this.position.length; i++) {
            this.position[i] += this.velocity[i];
            this.position[i] = Math.max(bounds[0][i], Math.min(bounds[1][i], this.position[i]));
        }
    }
}

class Swarm {
    constructor(num_particles, dim, bounds) {
        this.particles = Array.from({ length: num_particles }, () => new Particle(dim));
        this.best_global_pos = new Array(dim).fill(0.0);
        this.best_global_score = Infinity;
    }

    update_global_best() {
        for (const particle of this.particles) {
            if (particle.best_score < this.best_global_score) {
                this.best_global_score = particle.best_score;
                this.best_global_pos = particle.best_pos.slice();
            }
        }
    }

    optimize(fitness_func, max_iter, w, c1, c2) {
        for (let _ = 0; _ < max_iter; _++) {
            for (const particle of this.particles) {
                particle.update_velocity(this.best_global_pos, w, c1, c2);
                particle.update_position(bounds);
                const score = fitness_func(particle.position);
                if (score < particle.best_score) {
                    particle.best_score = score;
                    particle.best_pos = particle.position.slice();
                }
            }
            this.update_global_best();
        }
    }
}

function fitness_function(position) {
    return position.reduce((sum, x) => sum + Math.pow(x, 2), 0);
}

function main() {
    const num_particles = 30;
    const dim = 2;
    const bounds = [[0.0, 0.0], [10.0, 10.0]];
    const max_iter = 100;
    const w = 0.7;
    const c1 = 2.0;
    const c2 = 2.0;
    const swarm = new Swarm(num_particles, dim, bounds);
    swarm.optimize(fitness_function, max_iter, w, c1, c2);
    console.log(swarm.best_global_pos, swarm.best_global_score);
}

main();