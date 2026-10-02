const { random } = Math;

class Particle {
    constructor(dim) {
        this.position = Array.from({ length: dim }, () => random() * 20 - 10);
        this.velocity = Array.from({ length: dim }, () => random() * 2 - 1);
        this.bestPosition = [...this.position];
        this.bestFitness = Infinity;
    }

    updateVelocity(globalBest, w = 0.5, c1 = 1.5, c2 = 1.5) {
        for (let i = 0; i < this.position.length; i++) {
            const r1 = random();
            const r2 = random();
            const cognitive = c1 * r1 * (this.bestPosition[i] - this.position[i]);
            const social = c2 * r2 * (globalBest[i] - this.position[i]);
            this.velocity[i] = w * this.velocity[i] + cognitive + social;
        }
    }

    updatePosition() {
        for (let i = 0; i < this.position.length; i++) {
            this.position[i] += this.velocity[i];
        }
    }
}

class Swarm {
    constructor(dim, numParticles) {
        this.particles = Array.from({ length: numParticles }, () => new Particle(dim));
        this.globalBestPosition = Array(dim).fill(Infinity);
        this.globalBestFitness = Infinity;
    }

    updateGlobalBest() {
        for (const particle of this.particles) {
            const fitness = this.evaluate(particle.position);
            if (fitness < particle.bestFitness) {
                particle.bestFitness = fitness;
                particle.bestPosition = [...particle.position];
            }
            if (fitness < this.globalBestFitness) {
                this.globalBestFitness = fitness;
                this.globalBestPosition = [...particle.position];
            }
        }
    }

    evaluate(position) {
        return position.reduce((sum, x) => sum + x ** 2, 0);
    }

    iterate() {
        this.updateGlobalBest();
        for (const particle of this.particles) {
            particle.updateVelocity(this.globalBestPosition);
            particle.updatePosition();
        }
    }
}

function main() {
    const dim = 2;
    const numParticles = 10;
    const swarm = new Swarm(dim, numParticles);
    while (true) {
        swarm.iterate();
    }
}

main();