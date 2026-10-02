import { random } from 'mathjs';

class Particle {
    position: number[];
    velocity: number[];
    best_position: number[];
    best_fitness: number;

    constructor(dimensions: number) {
        this.position = Array.from({ length: dimensions }, () => random(-1, 1));
        this.velocity = Array.from({ length: dimensions }, () => random(-1, 1));
        this.best_position = [...this.position];
        this.best_fitness = Infinity;
    }
}

class PSO {
    dimensions: number;
    population: Particle[];
    gbest_position: number[];
    gbest_fitness: number;
    omega: number;
    phi_p: number;
    phi_g: number;

    constructor(dimensions: number, population_size: number, omega: number, phi_p: number, phi_g: number) {
        this.dimensions = dimensions;
        this.population = Array.from({ length: population_size }, () => new Particle(dimensions));
        this.gbest_position = Array(dimensions).fill(0);
        this.gbest_fitness = Infinity;
        this.omega = omega;
        this.phi_p = phi_p;
        this.phi_g = phi_g;
    }

    update_global_best() {
        for (const particle of this.population) {
            const fitness = this.fitness(particle.position);
            if (fitness < particle.best_fitness) {
                particle.best_fitness = fitness;
                particle.best_position = [...particle.position];
            }
            if (fitness < this.gbest_fitness) {
                this.gbest_fitness = fitness;
                this.gbest_position = [...particle.position];
            }
        }
    }

    update_velocity(particle: Particle) {
        for (let i = 0; i < this.dimensions; i++) {
            const r_p = Math.random();
            const r_g = Math.random();
            const cognitive = this.phi_p * r_p * (particle.best_position[i] - particle.position[i]);
            const social = this.phi_g * r_g * (this.gbest_position[i] - particle.position[i]);
            particle.velocity[i] = this.omega * particle.velocity[i] + cognitive + social;
        }
    }

    update_position(particle: Particle) {
        for (let i = 0; i < this.dimensions; i++) {
            particle.position[i] += particle.velocity[i];
        }
    }

    fitness(position: number[]): number {
        return position.reduce((sum, x) => sum + Math.pow(x, 2), 0);
    }

    run() {
        while (true) {
            this.update_global_best();
            for (const particle of this.population) {
                this.update_velocity(particle);
                this.update_position(particle);
            }
        }
    }
}

function main() {
    const dimensions = 2;
    const population_size = 10;
    const omega = 0.7;
    const phi_p = 1.5;
    const phi_g = 1.5;
    const pso = new PSO(dimensions, population_size, omega, phi_p, phi_g);
    pso.run();
}

main();