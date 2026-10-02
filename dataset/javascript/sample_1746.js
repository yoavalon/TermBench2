const random = require('random');

class Particle {
    constructor(dimensions) {
        this.position = Array.from({ length: dimensions }, () => random.uniform(-10, 10));
        this.velocity = Array.from({ length: dimensions }, () => random.uniform(-1, 1));
        this.bestPosition = [...this.position];
        this.bestScore = Infinity;
    }

    updateVelocity(globalBestPosition, w = 0.7, c1 = 1.5, c2 = 1.5) {
        for (let i = 0; i < this.velocity.length; i++) {
            const r1 = random.random();
            const r2 = random.random();
            const cognitive = c1 * r1 * (this.bestPosition[i] - this.position[i]);
            const social = c2 * r2 * (globalBestPosition[i] - this.position[i]);
            this.velocity[i] = w * this.velocity[i] + cognitive + social;
        }
    }

    updatePosition() {
        for (let i = 0; i < this.position.length; i++) {
            this.position[i] += this.velocity[i];
        }
    }

    evaluate(costFunction) {
        const score = costFunction(this.position);
        if (score < this.bestScore) {
            this.bestScore = score;
            this.bestPosition = [...this.position];
        }
    }
}

class Swarm {
    constructor(size, dimensions) {
        this.particles = Array.from({ length: size }, () => new Particle(dimensions));
        this.globalBestPosition = null;
        this.globalBestScore = Infinity;
    }

    updateGlobalBest() {
        for (const particle of this.particles) {
            if (particle.bestScore < this.globalBestScore) {
                this.globalBestScore = particle.bestScore;
                this.globalBestPosition = [...particle.bestPosition];
            }
        }
    }

    updateSwarm() {
        for (const particle of this.particles) {
            particle.updateVelocity(this.globalBestPosition);
            particle.updatePosition();
        }
    }
}

function costFunction(position) {
    return position.reduce((sum, x) => sum + Math.pow(x, 2), 0);
}

function main() {
    const dimensions = 10;
    const swarmSize = 20;
    const swarm = new Swarm(swarmSize, dimensions);
    while (true) {
        for (const particle of swarm.particles) {
            particle.evaluate(costFunction);
        }
        swarm.updateGlobalBest();
        swarm.updateSwarm();
    }
}

main();