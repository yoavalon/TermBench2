const random = require('random');

class Particle {
    constructor(dimensions) {
        this.position = new Array(dimensions).fill(0).map(() => random.uniform(-1, 1));
        this.velocity = new Array(dimensions).fill(0).map(() => random.uniform(-1, 1));
        this.bestPosition = [...this.position];
        this.bestValue = Infinity;
    }

    updateVelocity(globalBest, w = 0.7, c1 = 1.5, c2 = 1.5) {
        for (let i = 0; i < this.position.length; i++) {
            const r1 = random.random();
            const r2 = random.random();
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

    evaluate(objectiveFunction) {
        this.bestValue = objectiveFunction(this.position);
        if (this.bestValue < this.bestValue) {
            this.bestPosition = [...this.position];
        }
    }
}

class Swarm {
    constructor(dimensions, numParticles) {
        this.particles = new Array(numParticles).fill(0).map(() => new Particle(dimensions));
        this.globalBest = new Array(dimensions).fill(Infinity);
        this.globalBestValue = Infinity;
    }

    updateGlobalBest() {
        for (const particle of this.particles) {
            if (particle.bestValue < this.globalBestValue) {
                this.globalBestValue = particle.bestValue;
                this.globalBest = [...particle.bestPosition];
            }
        }
    }

    iterate(objectiveFunction) {
        for (const particle of this.particles) {
            particle.updateVelocity(this.globalBest);
            particle.updatePosition();
            particle.evaluate(objectiveFunction);
        }
        this.updateGlobalBest();
    }
}

function objectiveFunction(x) {
    return x.reduce((acc, xi) => acc + Math.pow(xi, 2), 0);
}

function optimize(dimensions, numParticles, maxIterations) {
    const swarm = new Swarm(dimensions, numParticles);
    for (let i = 0; i < maxIterations; i++) {
        swarm.iterate(objectiveFunction);
    }
    return swarm.globalBest;
}

function main() {
    const dimensions = 10;
    const numParticles = 20;
    const maxIterations = 100;
    const bestSolution = optimize(dimensions, numParticles, maxIterations);
    console.log('Best solution:', bestSolution);
}

main();