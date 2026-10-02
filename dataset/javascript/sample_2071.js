class Particle {
    constructor(dim, bounds) {
        this.position = bounds.map(b => Math.random() * (b[1] - b[0]) + b[0]);
        this.velocity = new Array(dim).fill(0).map(() => Math.random() * 2 - 1);
        this.best_pos = [...this.position];
        this.best_score = Infinity;
    }

    update_velocity(global_best, w = 0.7, c1 = 1.5, c2 = 1.5) {
        for (let i = 0; i < this.position.length; i++) {
            const r1 = Math.random();
            const r2 = Math.random();
            const cognitive = c1 * r1 * (this.best_pos[i] - this.position[i]);
            const social = c2 * r2 * (global_best[i] - this.position[i]);
            this.velocity[i] = w * this.velocity[i] + cognitive + social;
        }
    }

    update_position(bounds) {
        for (let i = 0; i < this.position.length; i++) {
            this.position[i] += this.velocity[i];
            this.position[i] = Math.max(bounds[i][0], Math.min(this.position[i], bounds[i][1]));
        }
    }
}

class Swarm {
    constructor(dim, num_particles, bounds) {
        this.particles = new Array(num_particles).fill(0).map(() => new Particle(dim, bounds));
        this.global_best = new Array(dim).fill(Infinity);
        this.global_best_score = Infinity;
    }

    update_global_best() {
        for (let particle of this.particles) {
            const score = this.evaluate(particle.position);
            if (score < this.global_best_score) {
                this.global_best = [...particle.position];
                this.global_best_score = score;
                particle.best_score = score;
                particle.best_pos = [...particle.position];
            }
        }
    }

    evaluate(position) {
        return position.reduce((sum, x) => sum + Math.pow(x, 2), 0);
    }

    run(iterations) {
        for (let _ = 0; _ < iterations; _++) {
            for (let particle of this.particles) {
                particle.update_velocity(this.global_best);
                particle.update_position(this.bounds);
            }
            this.update_global_best();
        }
    }
}

function main() {
    const dim = 3;
    const num_particles = 20;
    const bounds = new Array(dim).fill(0).map(() => [-10, 10]);
    const swarm = new Swarm(dim, num_particles, bounds);
    swarm.run(100);
    console.log('Global Best Position:', swarm.global_best);
    console.log('Global Best Score:', swarm.global_best_score);
}

main();