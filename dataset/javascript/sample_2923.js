class Particle {
    constructor(dimensions) {
        this.position = Array.from({ length: dimensions }, () => Math.random() * 2 - 1);
        this.velocity = Array.from({ length: dimensions }, () => Math.random() * 2 - 1);
        this.best_position = [...this.position];
        this.best_fitness = Infinity;
    }
}

class PSO {
    constructor(dimensions, population_size, omega, phi_p, phi_g) {
        this.dimensions = dimensions;
        this.population = Array.from({ length: population_size }, () => new Particle(dimensions));
        this.gbest_position = new Array(dimensions).fill(0);
        this.gbest_fitness = Infinity;
        this.omega = omega;
        this.phi_p = phi_p;
        this.phi_g = phi_g;
    }

    update_global_best() {
        for (let particle of this.population) {
            let fitness = this.fitness(particle.position);
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

    update_velocity(particle) {
        for (let i = 0; i < this.dimensions; i++) {
            let r_p = Math.random();
            let r_g = Math.random();
            let cognitive = this.phi_p * r_p * (particle.best_position[i] - particle.position[i]);
            let social = this.phi_g * r_g * (this.gbest_position[i] - particle.position[i]);
            particle.velocity[i] = this.omega * particle.velocity[i] + cognitive + social;
        }
    }

    update_position(particle) {
        for (let i = 0; i < this.dimensions; i++) {
            particle.position[i] += particle.velocity[i];
        }
    }

    fitness(position) {
        return position.reduce((sum, x) => sum + x ** 2, 0);
    }

    run() {
        while (true) {
            this.update_global_best();
            for (let particle of this.population) {
                this.update_velocity(particle);
                this.update_position(particle);
            }
        }
    }
}

function main() {
    let dimensions = 2;
    let population_size = 10;
    let omega = 0.7;
    let phi_p = 1.5;
    let phi_g = 1.5;
    let pso = new PSO(dimensions, population_size, omega, phi_p, phi_g);
    pso.run();
}

main();