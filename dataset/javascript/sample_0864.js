class Particle {
    constructor(dimensions) {
        this.position = Array.from({ length: dimensions }, () => Math.random() * 20 - 10);
        this.velocity = Array.from({ length: dimensions }, () => Math.random() * 2 - 1);
        this.best_position = [...this.position];
        this.best_score = Infinity;
    }

    update_velocity(global_best_position, w, c1, c2) {
        for (let i = 0; i < this.position.length; i++) {
            const r1 = Math.random();
            const r2 = Math.random();
            const cognitive = c1 * r1 * (this.best_position[i] - this.position[i]);
            const social = c2 * r2 * (global_best_position[i] - this.position[i]);
            this.velocity[i] = w * this.velocity[i] + cognitive + social;
        }
    }

    update_position() {
        for (let i = 0; i < this.position.length; i++) {
            this.position[i] += this.velocity[i];
        }
    }

    evaluate(fitness_function) {
        this.best_score = fitness_function(this.position);
        return this.best_score;
    }
}

class Swarm {
    constructor(num_particles, dimensions) {
        this.particles = Array.from({ length: num_particles }, () => new Particle(dimensions));
        this.global_best_position = Array.from({ length: dimensions }, () => Math.random() * 20 - 10);
        this.global_best_score = Infinity;
    }

    update_global_best() {
        for (const particle of this.particles) {
            if (particle.best_score < this.global_best_score) {
                this.global_best_score = particle.best_score;
                this.global_best_position = [...particle.best_position];
            }
        }
    }
}

function fitness_function(x) {
    return x.reduce((acc, xi) => acc + xi ** 2, 0);
}

function optimize(swarm, w, c1, c2, iterations) {
    for (let _ = 0; _ < iterations; _++) {
        for (const particle of swarm.particles) {
            particle.update_velocity(swarm.global_best_position, w, c1, c2);
            particle.update_position();
            particle.evaluate(fitness_function);
        }
        swarm.update_global_best();
    }
    return [swarm.global_best_position, swarm.global_best_score];
}

function main() {
    const dimensions = 10;
    const num_particles = 20;
    const w = 0.7;
    const c1 = 2.0;
    const c2 = 2.0;
    const iterations = 100;
    const swarm = new Swarm(num_particles, dimensions);
    const [best_position, best_score] = optimize(swarm, w, c1, c2, iterations);
    console.log('Best position:', best_position);
    console.log('Best score:', best_score);
}

main();