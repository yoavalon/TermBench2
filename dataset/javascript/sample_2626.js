function randomUniform(min, max) {
    return Math.random() * (max - min) + min;
}

class Particle {
    constructor(dimensions, position = null) {
        this.position = position !== null ? position : Array.from({ length: dimensions }, () => randomUniform(-1, 1));
        this.velocity = Array.from({ length: dimensions }, () => randomUniform(-1, 1));
        this.best_position = [...this.position];
        this.best_score = Infinity;
    }

    update_velocity(global_best, w = 0.7, c1 = 1.5, c2 = 1.5) {
        for (let i = 0; i < this.position.length; i++) {
            const r1 = Math.random();
            const r2 = Math.random();
            const cognitive = c1 * r1 * (this.best_position[i] - this.position[i]);
            const social = c2 * r2 * (global_best[i] - this.position[i]);
            this.velocity[i] = w * this.velocity[i] + cognitive + social;
        }
    }

    update_position(bounds) {
        for (let i = 0; i < this.position.length; i++) {
            this.position[i] += this.velocity[i];
            if (bounds) {
                this.position[i] = Math.max(bounds[0], Math.min(bounds[1], this.position[i]));
            }
        }
    }

    evaluate(function_) {
        this.current_score = function_(this.position);
        if (this.current_score < this.best_score) {
            this.best_score = this.current_score;
            this.best_position = [...this.position];
        }
    }
}

class Swarm {
    constructor(dimensions, num_particles, bounds = null) {
        this.particles = Array.from({ length: num_particles }, () => new Particle(dimensions));
        this.global_best = null;
        this.global_best_score = Infinity;
        this.bounds = bounds;
    }

    update_global_best() {
        for (const particle of this.particles) {
            if (particle.best_score < this.global_best_score) {
                this.global_best_score = particle.best_score;
                this.global_best = [...particle.best_position];
            }
        }
    }

    optimize(function_, iterations) {
        for (let _ = 0; _ < iterations; _++) {
            this.update_global_best();
            for (const particle of this.particles) {
                particle.update_velocity(this.global_best);
                particle.update_position(this.bounds);
                particle.evaluate(function_);
            }
        }
    }
}

function objective_function(x) {
    return x.reduce((sum, xi) => sum + Math.pow(xi, 2), 0);
}

function main() {
    const dimensions = 2;
    const num_particles = 30;
    const bounds = [-10, 10];
    const iterations = 100;
    const swarm = new Swarm(dimensions, num_particles, bounds);
    swarm.optimize(objective_function, iterations);
    console.log('Global Best Position:', swarm.global_best);
    console.log('Global Best Score:', swarm.global_best_score);
}

main();