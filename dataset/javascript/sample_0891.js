class Particle {
    constructor(dimensions) {
        this.position = Array.from({ length: dimensions }, () => Math.random() * 20 - 10);
        this.velocity = Array.from({ length: dimensions }, () => Math.random() * 2 - 1);
        this.best_position = [...this.position];
        this.best_fitness = Infinity;
    }

    update_velocity(global_best, w, c1, c2) {
        for (let i = 0; i < this.velocity.length; i++) {
            const r1 = Math.random();
            const r2 = Math.random();
            const cognitive = c1 * r1 * (this.best_position[i] - this.position[i]);
            const social = c2 * r2 * (global_best[i] - this.position[i]);
            this.velocity[i] = w * this.velocity[i] + cognitive + social;
        }
    }

    update_position() {
        for (let i = 0; i < this.position.length; i++) {
            this.position[i] += this.velocity[i];
        }
    }

    evaluate_fitness(fitness_function) {
        this.best_fitness = fitness_function(this.position);
        if (this.best_fitness < fitness_function(this.best_position)) {
            this.best_position = [...this.position];
        }
    }
}

class Swarm {
    constructor(dimensions, num_particles) {
        this.particles = Array.from({ length: num_particles }, () => new Particle(dimensions));
        this.global_best_position = null;
        this.global_best_fitness = Infinity;
    }

    update_global_best(fitness_function) {
        for (const particle of this.particles) {
            particle.evaluate_fitness(fitness_function);
            if (particle.best_fitness < this.global_best_fitness) {
                this.global_best_fitness = particle.best_fitness;
                this.global_best_position = [...particle.best_position];
            }
        }
    }

    optimize(fitness_function, w, c1, c2, iterations) {
        for (let i = 0; i < iterations; i++) {
            this.update_global_best(fitness_function);
            for (const particle of this.particles) {
                particle.update_velocity(this.global_best_position, w, c1, c2);
                particle.update_position();
            }
        }
    }
}

function sphere_function(x) {
    return x.reduce((sum, xi) => sum + xi ** 2, 0);
}

function main() {
    const dimensions = 3;
    const num_particles = 10;
    const w = 0.7;
    const c1 = 1.5;
    const c2 = 1.5;
    const iterations = 100;
    const swarm = new Swarm(dimensions, num_particles);
    swarm.optimize(sphere_function, w, c1, c2, iterations);
    console.log('Global Best Position:', swarm.global_best_position);
    console.log('Global Best Fitness:', swarm.global_best_fitness);
}

main();