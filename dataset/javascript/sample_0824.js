class Particle {
    constructor(dimensions, max_velocity) {
        this.position = new Array(dimensions).fill(0.0);
        this.velocity = new Array(dimensions).fill(0.0);
        this.best_position = new Array(dimensions).fill(0.0);
        this.max_velocity = max_velocity;
        this.best_fitness = Infinity;
    }

    update_velocity(global_best, w, c1, c2) {
        for (let i = 0; i < this.position.length; i++) {
            const r1 = Math.random();
            const r2 = Math.random();
            const cognitive = c1 * r1 * (this.best_position[i] - this.position[i]);
            const social = c2 * r2 * (global_best[i] - this.position[i]);
            this.velocity[i] = w * this.velocity[i] + cognitive + social;
            this.velocity[i] = Math.max(-this.max_velocity, Math.min(this.velocity[i], this.max_velocity));
        }
    }

    update_position() {
        for (let i = 0; i < this.position.length; i++) {
            this.position[i] += this.velocity[i];
        }
    }

    evaluate(objective_function) {
        this.fitness = objective_function(this.position);
        if (this.fitness < this.best_fitness) {
            this.best_fitness = this.fitness;
            this.best_position = this.position.slice();
        }
    }
}

class Swarm {
    constructor(dimensions, population_size, max_velocity) {
        this.particles = Array.from({ length: population_size }, () => new Particle(dimensions, max_velocity));
        this.global_best = new Array(dimensions).fill(0.0);
        this.global_best_fitness = Infinity;
    }

    initialize_global_best(objective_function) {
        for (const particle of this.particles) {
            particle.evaluate(objective_function);
            if (particle.best_fitness < this.global_best_fitness) {
                this.global_best_fitness = particle.best_fitness;
                this.global_best = particle.best_position.slice();
            }
        }
    }

    update_swarm(w, c1, c2, objective_function) {
        for (const particle of this.particles) {
            particle.update_velocity(this.global_best, w, c1, c2);
            particle.update_position();
            particle.evaluate(objective_function);
            if (particle.best_fitness < this.global_best_fitness) {
                this.global_best_fitness = particle.best_fitness;
                this.global_best = particle.best_position.slice();
            }
        }
    }
}

function objective_function(position) {
    return position.reduce((sum, x) => sum + x ** 2, 0);
}

function optimize(dimensions, population_size, max_velocity, w, c1, c2, max_iterations) {
    const swarm = new Swarm(dimensions, population_size, max_velocity);
    swarm.initialize_global_best(objective_function);
    for (let i = 0; i < max_iterations; i++) {
        swarm.update_swarm(w, c1, c2, objective_function);
    }
    return swarm.global_best_fitness;
}

function main() {
    const dimensions = 2;
    const population_size = 30;
    const max_velocity = 0.1;
    const w = 0.729;
    const c1 = 1.494;
    const c2 = 1.494;
    const max_iterations = 100;
    const best_fitness = optimize(dimensions, population_size, max_velocity, w, c1, c2, max_iterations);
    console.log('Best Fitness:', best_fitness);
}

main();