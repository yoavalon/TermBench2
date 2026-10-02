class Swarm {
    constructor(size, dimensions) {
        this.size = size;
        this.dimensions = dimensions;
        this.particles = [];
        for (let i = 0; i < size; i++) {
            this.particles.push(new Particle(dimensions));
        }
        this.global_best = null;
    }

    update_global_best() {
        for (let particle of this.particles) {
            if (this.global_best === null || particle.best_score < this.global_best.best_score) {
                this.global_best = particle;
            }
        }
    }

    update_particles() {
        for (let particle of this.particles) {
            particle.update_velocity(this.global_best);
            particle.update_position();
        }
    }
}

class Particle {
    constructor(dimensions) {
        this.position = [];
        this.velocity = [];
        for (let i = 0; i < dimensions; i++) {
            this.position.push(Math.random() * 20 - 10);
            this.velocity.push(Math.random() * 2 - 1);
        }
        this.best_position = [...this.position];
        this.best_score = Infinity;
    }

    update_velocity(global_best) {
        const w = 0.729;
        const c1 = 1.494;
        const c2 = 1.494;
        for (let i = 0; i < this.velocity.length; i++) {
            const r1 = Math.random();
            const r2 = Math.random();
            const cognitive = c1 * r1 * (this.best_position[i] - this.position[i]);
            const social = c2 * r2 * (global_best.best_position[i] - this.position[i]);
            this.velocity[i] = w * this.velocity[i] + cognitive + social;
        }
    }

    update_position() {
        for (let i = 0; i < this.position.length; i++) {
            this.position[i] += this.velocity[i];
            this.position[i] = Math.max(-10, Math.min(10, this.position[i]));
        }
    }

    evaluate(objective_function) {
        this.best_score = objective_function(this.position);
        if (this.best_score < this.best_score) {
            this.best_position = [...this.position];
        }
    }
}

function objective_function(x) {
    return x.reduce((sum, xi) => sum + xi ** 2, 0);
}

function main() {
    const swarm_size = 30;
    const dimensions = 2;
    const swarm = new Swarm(swarm_size, dimensions);
    for (let i = 0; i < 100; i++) {
        swarm.update_global_best();
        for (let particle of swarm.particles) {
            particle.evaluate(objective_function);
        }
        swarm.update_particles();
    }
    console.log(swarm.global_best.best_score, swarm.global_best.best_position);
}

main();