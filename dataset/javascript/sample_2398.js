const random = require('random');

class Particle {
    constructor(dimensions, lower_bound, upper_bound) {
        this.position = Array.from({ length: dimensions }, () => random.uniform(lower_bound, upper_bound));
        this.velocity = Array.from({ length: dimensions }, () => random.uniform(-1, 1));
        this.best_position = [...this.position];
        this.best_fitness = Infinity;
    }

    update_velocity(global_best_position, w, c1, c2) {
        for (let i = 0; i < this.position.length; i++) {
            const r1 = random.float(0, 1);
            const r2 = random.float(0, 1);
            const cognitive_velocity = c1 * r1 * (this.best_position[i] - this.position[i]);
            const social_velocity = c2 * r2 * (global_best_position[i] - this.position[i]);
            this.velocity[i] = w * this.velocity[i] + cognitive_velocity + social_velocity;
        }
    }

    update_position(lower_bound, upper_bound) {
        for (let i = 0; i < this.position.length; i++) {
            this.position[i] += this.velocity[i];
            this.position[i] = Math.max(lower_bound, Math.min(upper_bound, this.position[i]));
        }
    }
}

class Swarm {
    constructor(num_particles, dimensions, lower_bound, upper_bound) {
        this.particles = Array.from({ length: num_particles }, () => new Particle(dimensions, lower_bound, upper_bound));
        this.global_best_position = Array.from({ length: dimensions }, () => random.uniform(lower_bound, upper_bound));
        this.global_best_fitness = Infinity;
    }

    evaluate_fitness(objective_function) {
        for (const particle of this.particles) {
            const fitness = objective_function(particle.position);
            if (fitness < particle.best_fitness) {
                particle.best_fitness = fitness;
                particle.best_position = [...particle.position];
            }
            if (fitness < this.global_best_fitness) {
                this.global_best_fitness = fitness;
                this.global_best_position = [...particle.position];
            }
        }
    }

    update_particles(w, c1, c2) {
        for (const particle of this.particles) {
            particle.update_velocity(this.global_best_position, w, c1, c2);
            particle.update_position(-10, 10);
        }
    }
}

function objective_function(x) {
    return x.reduce((sum, xi, i) => sum + Math.sin(xi) * Math.sin(xi + (i + 1) * Math.PI / x.length), 0);
}

function main() {
    const num_particles = 30;
    const dimensions = 30;
    const lower_bound = -10;
    const upper_bound = 10;
    const w = 0.729;
    const c1 = 1.494;
    const c2 = 1.494;
    const swarm = new Swarm(num_particles, dimensions, lower_bound, upper_bound);
    while (true) {
        swarm.evaluate_fitness(objective_function);
        swarm.update_particles(w, c1, c2);
    }
}

main();