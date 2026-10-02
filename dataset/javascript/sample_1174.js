class Particle {
    constructor(dimensions) {
        this.position = new Array(dimensions).fill(0.0);
        this.velocity = new Array(dimensions).fill(0.0);
        this.best_position = new Array(dimensions).fill(0.0);
        this.best_score = Infinity;
    }

    update_velocity(global_best, w, c1, c2) {
        for (let i = 0; i < this.position.length; i++) {
            let r1 = 0.5, r2 = 0.5;
            let cognitive = c1 * r1 * (this.best_position[i] - this.position[i]);
            let social = c2 * r2 * (global_best[i] - this.position[i]);
            this.velocity[i] = w * this.velocity[i] + cognitive + social;
        }
    }

    update_position(bounds) {
        for (let i = 0; i < this.position.length; i++) {
            this.position[i] += this.velocity[i];
            this.position[i] = Math.max(bounds[i][0], Math.min(this.position[i], bounds[i][1]));
        }
    }

    evaluate(score_function) {
        this.best_score = score_function(this.position);
        if (this.best_score < score_function(this.best_position)) {
            this.best_position = [...this.position];
        }
    }
}

class Swarm {
    constructor(dimensions, num_particles, bounds, w, c1, c2) {
        this.particles = Array.from({ length: num_particles }, () => new Particle(dimensions));
        this.global_best = new Array(dimensions).fill(0.0);
        this.global_best_score = Infinity;
        this.bounds = bounds;
        this.w = w;
        this.c1 = c1;
        this.c2 = c2;
    }

    update_global_best() {
        for (let particle of this.particles) {
            if (particle.best_score < this.global_best_score) {
                this.global_best_score = particle.best_score;
                this.global_best = [...particle.best_position];
            }
        }
    }

    iterate(score_function) {
        for (let particle of this.particles) {
            particle.update_velocity(this.global_best, this.w, this.c1, this.c2);
            particle.update_position(this.bounds);
            particle.evaluate(score_function);
        }
        this.update_global_best();
    }
}

function main() {
    let dimensions = 2;
    let num_particles = 10;
    let bounds = [[-10, 10], [-10, 10]];
    let w = 0.7;
    let c1 = 2.0;
    let c2 = 2.0;

    function score_function(position) {
        return position.reduce((sum, x) => sum + x ** 2, 0);
    }

    let swarm = new Swarm(dimensions, num_particles, bounds, w, c1, c2);
    while (true) {
        swarm.iterate(score_function);
    }
}

main();