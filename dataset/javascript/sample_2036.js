const { random } = Math;

class Particle {
    constructor(dimensions, lowerBound, upperBound) {
        this.position = new Array(dimensions).fill(0).map(() => random() * (upperBound - lowerBound) + lowerBound);
        this.velocity = new Array(dimensions).fill(0).map(() => random() * 2 - 1);
        this.bestPosition = [...this.position];
        this.bestScore = Infinity;
    }

    updateVelocity(globalBestPosition, w, c1, c2) {
        for (let i = 0; i < this.position.length; i++) {
            const r1 = random();
            const r2 = random();
            this.velocity[i] = w * this.velocity[i] + c1 * r1 * (this.bestPosition[i] - this.position[i]) + c2 * r2 * (globalBestPosition[i] - this.position[i]);
        }
    }

    updatePosition() {
        for (let i = 0; i < this.position.length; i++) {
            this.position[i] += this.velocity[i];
        }
    }

    evaluate(fitnessFunction) {
        const score = fitnessFunction(this.position);
        if (score < this.bestScore) {
            this.bestScore = score;
            this.bestPosition = [...this.position];
        }
    }
}

class Swarm {
    constructor(size, dimensions, lowerBound, upperBound) {
        this.particles = new Array(size).fill(0).map(() => new Particle(dimensions, lowerBound, upperBound));
        this.globalBestPosition = new Array(dimensions).fill(0).map(() => random() * (upperBound - lowerBound) + lowerBound);
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

    iterate(fitnessFunction, w, c1, c2) {
        for (const particle of this.particles) {
            particle.updateVelocity(this.globalBestPosition, w, c1, c2);
            particle.updatePosition();
            particle.evaluate(fitnessFunction);
        }
        this.updateGlobalBest();
    }
}

function fitnessFunction(position) {
    return position.reduce((sum, x) => sum + x ** 2, 0);
}

function main() {
    const dimensions = 2;
    const lowerBound = -10;
    const upperBound = 10;
    const swarmSize = 30;
    const w = 0.7;
    const c1 = 1.5;
    const c2 = 1.5;
    const iterations = 100;
    const swarm = new Swarm(swarmSize, dimensions, lowerBound, upperBound);
    for (let i = 0; i < iterations; i++) {
        swarm.iterate(fitnessFunction, w, c1, c2);
    }
    console.log('Global best score:', swarm.globalBestScore);
    console.log('Global best position:', swarm.globalBestPosition);
}

main();