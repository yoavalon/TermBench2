import * as random from 'random';

class Particle {
    position: number[];
    velocity: number[];
    best_position: number[];

    constructor(dimensions: number) {
        this.position = Array.from({ length: dimensions }, () => random.uniform(-10, 10));
        this.velocity = Array.from({ length: dimensions }, () => random.uniform(-1, 1));
        this.best_position = [...this.position];
    }

    update_velocity(global_best: number[], inertia: number, cognitive: number, social: number) {
        for (let i = 0; i < this.velocity.length; i++) {
            const r1 = random.random();
            const r2 = random.random();
            this.velocity[i] = inertia * this.velocity[i] + cognitive * r1 * (this.best_position[i] - this.position[i]) + social * r2 * (global_best[i] - this.position[i]);
        }
    }

    update_position() {
        for (let i = 0; i < this.position.length; i++) {
            this.position[i] += this.velocity[i];
        }
    }

    update_best_position(objective_function: (x: number[]) => number) {
        const current_fitness = objective_function(this.position);
        const best_fitness = objective_function(this.best_position);
        if (current_fitness < best_fitness) {
            this.best_position = [...this.position];
        }
    }
}

class Swarm {
    particles: Particle[];
    global_best: number[];
    objective_function: (x: number[]) => number;

    constructor(dimensions: number, num_particles: number, objective_function: (x: number[]) => number) {
        this.particles = Array.from({ length: num_particles }, () => new Particle(dimensions));
        this.global_best = [...this.particles[0].position];
        this.objective_function = objective_function;
    }

    update_global_best() {
        for (const particle of this.particles) {
            const current_fitness = this.objective_function(particle.position);
            const global_best_fitness = this.objective_function(this.global_best);
            if (current_fitness < global_best_fitness) {
                this.global_best = [...particle.position];
            }
        }
    }

    optimize(inertia: number, cognitive: number, social: number) {
        while (true) {
            for (const particle of this.particles) {
                particle.update_velocity(this.global_best, inertia, cognitive, social);
                particle.update_position();
                particle.update_best_position(this.objective_function);
            }
            this.update_global_best();
        }
    }
}

function objective_function(x: number[]): number {
    return x.reduce((sum, xi) => sum + xi ** 2, 0);
}

function main() {
    const dimensions = 2;
    const num_particles = 30;
    const inertia = 0.7;
    const cognitive = 1.5;
    const social = 1.5;
    const swarm = new Swarm(dimensions, num_particles, objective_function);
    swarm.optimize(inertia, cognitive, social);
}

main();