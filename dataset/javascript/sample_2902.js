const { random } = Math;

class Particle {
    constructor(dimensions) {
        this.position = Array.from({ length: dimensions }, () => random() * 2 - 1);
        this.velocity = Array.from({ length: dimensions }, () => random() * 2 - 1);
        this.best_position = [...this.position];
        this.best_fitness = Infinity;
    }

    update_velocity(global_best, w, c1, c2) {
        for (let i = 0; i < this.position.length; i++) {
            const r1 = random();
            const r2 = random();
            const cognitive = c1 * r1 * (this.best_position[i] - this.position[i]);
            const social = c2 * r2 * (global_best[i] - this.position[i]);
            this.velocity[i] = w * this.velocity[i] + cognitive + social;
        }
    }

    update_position(bounds) {
        for (let i = 0; i < this.position.length; i++) {
            this.position[i] += this.velocity[i];
            this.position[i] = Math.max(bounds[0][i], Math.min(bounds[1][i], this.position[i]));
        }
    }

    evaluate_fitness(fitness_function) {
        this.fitness = fitness_function(this.position);
        if (this.fitness < this.best_fitness) {
            this.best_fitness = this.fitness;
            this.best_position = [...this.position];
        }
    }
}

class Swarm {
    constructor(num_particles, dimensions, bounds, fitness_function) {
        this.particles = Array.from({ length: num_particles }, () => new Particle(dimensions));
        this.global_best = Array.from({ length: dimensions }, () => random() * 2 - 1);
        this.global_best_fitness = Infinity;
        this.fitness_function = fitness_function;
        this.bounds = bounds;
    }

    update_global_best() {
        for (const particle of this.particles) {
            if (particle.best_fitness < this.global_best_fitness) {
                this.global_best_fitness = particle.best_fitness;
                this.global_best = [...particle.best_position];
            }
        }
    }

    optimize(w, c1, c2) {
        while (true) {
            for (const particle of this.particles) {
                particle.update_velocity(this.global_best, w, c1, c2);
                particle.update_position(this.bounds);
                particle.evaluate_fitness(this.fitness_function);
            }
            this.update_global_best();
        }
    }
}

function fitness_function(x) {
    return x.reduce((sum, xi) => sum + xi ** 2, 0);
}

function main() {
    const dimensions = 2;
    const num_particles = 30;
    const bounds = [[-10, -10], [10, 10]];
    const swarm = new Swarm(num_particles, dimensions, bounds, fitness_function);
    const w = 0.729;
    const c1 = 1.494;
    const c2 = 1.494;
    swarm.optimize(w, c1, c2);
}

main();