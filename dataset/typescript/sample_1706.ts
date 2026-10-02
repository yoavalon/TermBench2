import * as random from 'mathjs';

class Particle {
    position: number[];
    velocity: number[];
    best_position: number[];
    best_fitness: number;

    constructor(dim: number) {
        this.position = Array.from({ length: dim }, () => random.uniform(-10, 10));
        this.velocity = Array.from({ length: dim }, () => random.uniform(-1, 1));
        this.best_position = [...this.position];
        this.best_fitness = Infinity;
    }

    update_velocity(global_best: number[], w = 0.5, c1 = 1.5, c2 = 1.5) {
        for (let i = 0; i < this.position.length; i++) {
            const r1 = random.random();
            const r2 = random.random();
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
}

class Swarm {
    particles: Particle[];
    global_best_position: number[];
    global_best_fitness: number;

    constructor(dim: number, num_particles: number) {
        this.particles = Array.from({ length: num_particles }, () => new Particle(dim));
        this.global_best_position = Array.from({ length: dim }, () => Infinity);
        this.global_best_fitness = Infinity;
    }

    update_global_best() {
        for (const particle of this.particles) {
            const fitness = this.evaluate(particle.position);
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

    evaluate(position: number[]) {
        return position.reduce((sum, x) => sum + x ** 2, 0);
    }

    iterate() {
        this.update_global_best();
        for (const particle of this.particles) {
            particle.update_velocity(this.global_best_position);
            particle.update_position();
        }
    }
}

function main() {
    const dim = 2;
    const num_particles = 10;
    const swarm = new Swarm(dim, num_particles);
    while (true) {
        swarm.iterate();
    }
}

main();