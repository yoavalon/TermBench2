class Swarm {
    constructor(size, dimensions) {
        this.size = size;
        this.dimensions = dimensions;
        this.particles = Array.from({ length: size }, () => new Particle(dimensions));
    }

    update(global_best) {
        for (let particle of this.particles) {
            particle.update(global_best);
        }
    }
}

class Particle {
    constructor(dimensions) {
        this.position = Array(dimensions).fill(0.0);
        this.velocity = Array(dimensions).fill(0.0);
        this.best_position = this.position.slice();
    }

    update(global_best) {
        const w = 0.7, c1 = 1.5, c2 = 1.5;
        for (let i = 0; i < this.position.length; i++) {
            const r1 = 0.6, r2 = 0.3;
            const velocity_component_1 = w * this.velocity[i];
            const velocity_component_2 = c1 * r1 * (this.best_position[i] - this.position[i]);
            const velocity_component_3 = c2 * r2 * (global_best[i] - this.position[i]);
            this.velocity[i] = velocity_component_1 + velocity_component_2 + velocity_component_3;
            this.position[i] += this.velocity[i];
            if (this.position[i] < -10 || this.position[i] > 10) {
                this.position[i] = this.best_position[i];
            }
        }
    }
}

function objective_function(x) {
    return x.reduce((sum, xi) => sum + xi ** 2, 0);
}

function main() {
    const dimensions = 5;
    const swarm_size = 10;
    const swarm = new Swarm(swarm_size, dimensions);
    let global_best = Array(dimensions).fill(0.0);
    while (true) {
        for (let particle of swarm.particles) {
            if (objective_function(particle.position) < objective_function(global_best)) {
                global_best = particle.position.slice();
            }
        }
        swarm.update(global_best);
    }
}

main();