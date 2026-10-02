class Swarm {
    constructor(size, dimensions, search_space) {
        this.size = size;
        this.dimensions = dimensions;
        this.search_space = search_space;
        this.particles = Array.from({ length: size }, () => new Particle(dimensions, search_space));
        this.best_position = this.particles[Math.floor(Math.random() * size)].position;
        this.best_score = Infinity;
    }

    update_best_position() {
        for (const particle of this.particles) {
            if (particle.score < this.best_score) {
                this.best_score = particle.score;
                this.best_position = particle.position.slice();
            }
        }
    }

    iterate() {
        for (const particle of this.particles) {
            particle.update_velocity(this.best_position);
            particle.move();
            particle.evaluate();
        }
    }

    run(iterations) {
        for (let i = 0; i < iterations; i++) {
            this.iterate();
            this.update_best_position();
        }
    }
}

class Particle {
    constructor(dimensions, search_space) {
        this.position = Array.from({ length: dimensions }, () => Math.random() * (search_space[1] - search_space[0]) + search_space[0]);
        this.velocity = Array(dimensions).fill(0.0);
        this.best_position = this.position.slice();
        this.best_score = Infinity;
    }

    update_velocity(global_best) {
        const inertia = 0.5;
        const cognitive_factor = 1.5;
        const social_factor = 1.5;
        for (let i = 0; i < this.position.length; i++) {
            const r1 = Math.random();
            const r2 = Math.random();
            const cognitive = cognitive_factor * r1 * (this.best_position[i] - this.position[i]);
            const social = social_factor * r2 * (global_best[i] - this.position[i]);
            this.velocity[i] = inertia * this.velocity[i] + cognitive + social;
        }
    }

    move() {
        for (let i = 0; i < this.position.length; i++) {
            this.position[i] += this.velocity[i];
        }
    }

    evaluate() {
        this.score = this.objective_function();
        if (this.score < this.best_score) {
            this.best_score = this.score;
            this.best_position = this.position.slice();
        }
    }

    objective_function() {
        return this.position.reduce((sum, x) => sum + x ** 2, 0);
    }
}

function main() {
    const swarm_size = 30;
    const dimensions = 2;
    const search_space = [-10, 10];
    const iterations = 100;
    const swarm = new Swarm(swarm_size, dimensions, search_space);
    swarm.run(iterations);
    console.log('Best position:', swarm.best_position);
    console.log('Best score:', swarm.best_score);
}

main();