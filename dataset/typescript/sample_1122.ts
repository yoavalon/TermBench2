class Swarm {
    particles: Particle[];
    best: Particle;

    constructor(size: number, dimensions: number) {
        this.particles = Array.from({ length: size }, () => new Particle(dimensions));
        this.best = this.particles[0];
    }

    update_best() {
        for (const particle of this.particles) {
            if (particle.position < this.best.position) {
                this.best = particle;
            }
        }
    }

    update_positions() {
        for (const particle of this.particles) {
            particle.update_velocity(this.best);
            particle.move();
        }
    }
}

class Particle {
    position: number[];
    velocity: number[];
    best: number[];

    constructor(dimensions: number) {
        this.position = Array(dimensions).fill(0.0);
        this.velocity = Array(dimensions).fill(0.0);
        this.best = this.position;
    }

    update_velocity(best_swarm: Particle) {
        for (let i = 0; i < this.position.length; i++) {
            const c1 = 1.5, c2 = 1.5, r1 = 0.5, r2 = 0.5;
            this.velocity[i] = 0.7 * this.velocity[i] + c1 * r1 * (best_swarm.position[i] - this.position[i]) + c2 * r2 * (this.best[i] - this.position[i]);
        }
    }

    move() {
        for (let i = 0; i < this.position.length; i++) {
            this.position[i] += this.velocity[i];
        }
        if (this.position < this.best) {
            this.best = this.position;
        }
    }
}

function optimize(swarm: Swarm) {
    swarm.update_positions();
    swarm.update_best();
    optimize(swarm);
}

function main() {
    const swarm = new Swarm(10, 2);
    optimize(swarm);
}

main();