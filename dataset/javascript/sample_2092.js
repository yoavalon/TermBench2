class Particle {
    constructor(dimensions) {
        this.position = Array.from({ length: dimensions }, () => Math.random() * 20 - 10);
        this.velocity = Array.from({ length: dimensions }, () => Math.random() * 2 - 1);
        this.best_position = [...this.position];
        this.best_score = Infinity;
    }
}

class Swarm {
    constructor(num_particles, dimensions) {
        this.particles = Array.from({ length: num_particles }, () => new Particle(dimensions));
        this.gbest_position = null;
        this.gbest_score = Infinity;
    }

    update_gbest() {
        for (let particle of this.particles) {
            if (particle.best_score < this.gbest_score) {
                this.gbest_score = particle.best_score;
                this.gbest_position = [...particle.best_position];
            }
        }
    }

    update_particles(w, c1, c2) {
        for (let particle of this.particles) {
            for (let i = 0; i < particle.position.length; i++) {
                let r1 = Math.random();
                let r2 = Math.random();
                particle.velocity[i] = w * particle.velocity[i] + c1 * r1 * (particle.best_position[i] - particle.position[i]) + c2 * r2 * (this.gbest_position[i] - particle.position[i]);
                particle.position[i] += particle.velocity[i];
            }
        }
    }

    evaluate(objective_function) {
        for (let particle of this.particles) {
            let score = objective_function(particle.position);
            if (score < particle.best_score) {
                particle.best_score = score;
                particle.best_position = [...particle.position];
            }
        }
    }
}

function objective_function(x) {
    return x.reduce((sum, xi) => sum + xi ** 2, 0);
}

function main() {
    let dimensions = 3;
    let num_particles = 20;
    let w = 0.7;
    let c1 = 1.5;
    let c2 = 1.5;
    let iterations = 100;
    let swarm = new Swarm(num_particles, dimensions);
    for (let _ = 0; _ < iterations; _++) {
        swarm.update_gbest();
        swarm.update_particles(w, c1, c2);
        swarm.evaluate(objective_function);
    }
    console.log('Best score:', swarm.gbest_score);
    console.log('Best position:', swarm.gbest_position);
}

main();