class Particle {
    constructor(dim) {
        this.position = new Array(dim).fill(0.0);
        this.velocity = new Array(dim).fill(0.0);
        this.pbest = new Array(dim).fill(0.0);
        this.pbest_value = Infinity;
    }

    update_velocity(gbest, w = 0.7, c1 = 1.5, c2 = 1.5) {
        for (let i = 0; i < this.position.length; i++) {
            let r1 = 0.5, r2 = 0.5;
            this.velocity[i] = w * this.velocity[i] + c1 * r1 * (this.pbest[i] - this.position[i]) + c2 * r2 * (gbest[i] - this.position[i]);
        }
    }

    update_position(bounds) {
        for (let i = 0; i < this.position.length; i++) {
            this.position[i] += this.velocity[i];
            this.position[i] = Math.max(bounds[i][0], Math.min(bounds[i][1], this.position[i]));
        }
    }

    update_pbest(value) {
        if (value < this.pbest_value) {
            this.pbest = [...this.position];
            this.pbest_value = value;
        }
    }
}

class Swarm {
    constructor(num_particles, dim, bounds) {
        this.particles = Array.from({ length: num_particles }, () => new Particle(dim));
        this.gbest = new Array(dim).fill(0.0);
        this.gbest_value = Infinity;
        this.bounds = bounds;
    }

    update_gbest() {
        for (let particle of this.particles) {
            if (particle.pbest_value < this.gbest_value) {
                this.gbest = [...particle.pbest];
                this.gbest_value = particle.pbest_value;
            }
        }
    }

    iterate() {
        for (let particle of this.particles) {
            particle.update_velocity(this.gbest);
            particle.update_position(this.bounds);
            particle.update_pbest(objective_function(particle.position));
        }
    }
}

function objective_function(x) {
    return x.reduce((sum, xi) => sum + xi ** 2, 0);
}

function optimize(num_particles, dim, max_iterations, bounds) {
    let swarm = new Swarm(num_particles, dim, bounds);
    for (let _ = 0; _ < max_iterations; _++) {
        swarm.iterate();
        swarm.update_gbest();
    }
    return [swarm.gbest, swarm.gbest_value];
}

function main() {
    let num_particles = 30;
    let dim = 2;
    let max_iterations = 100;
    let bounds = Array(dim).fill([-10, 10]);
    let [best_position, best_value] = optimize(num_particles, dim, max_iterations, bounds);
    console.log('Best position:', best_position);
    console.log('Best value:', best_value);
}

main();