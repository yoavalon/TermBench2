const { random } = Math;

class Particle {
    constructor(dimensions, bounds) {
        this.position = bounds.map(b => random() * (b[1] - b[0]) + b[0]);
        this.velocity = bounds.map(() => random() * 2 - 1);
        this.bestPosition = [...this.position];
        this.bestFitness = Infinity;
    }

    updateVelocity(globalBest, w, c1, c2) {
        for (let i = 0; i < this.position.length; i++) {
            const r1 = random();
            const r2 = random();
            const cognitive = c1 * r1 * (this.bestPosition[i] - this.position[i]);
            const social = c2 * r2 * (globalBest[i] - this.position[i]);
            this.velocity[i] = w * this.velocity[i] + cognitive + social;
        }
    }

    updatePosition(bounds) {
        for (let i = 0; i < this.position.length; i++) {
            this.position[i] = this.position[i] + this.velocity[i];
            this.position[i] = Math.max(bounds[i][0], Math.min(this.position[i], bounds[i][1]));
        }
    }

    evaluate(fitnessFunction) {
        this.bestFitness = Math.min(this.bestFitness, fitnessFunction(this.position));
    }
}

function optimize(fitnessFunction, dimensions, bounds, numParticles, w, c1, c2, maxIterations) {
    const particles = Array.from({ length: numParticles }, () => new Particle(dimensions, bounds));
    let globalBest = Array(dimensions).fill(Infinity);
    let globalBestFitness = Infinity;
    for (let iteration = 0; iteration < maxIterations; iteration++) {
        for (const particle of particles) {
            particle.evaluate(fitnessFunction);
            if (particle.bestFitness < globalBestFitness) {
                globalBestFitness = particle.bestFitness;
                globalBest = [...particle.bestPosition];
            }
        }
        for (const particle of particles) {
            particle.updateVelocity(globalBest, w, c1, c2);
            particle.updatePosition(bounds);
        }
    }
    return [globalBest, globalBestFitness];
}

function main() {
    function sphereFunction(x) {
        return x.reduce((sum, xi) => sum + xi ** 2, 0);
    }
    const dimensions = 3;
    const bounds = Array(dimensions).fill([-5.12, 5.12]);
    const numParticles = 30;
    const w = 0.729;
    const c1 = 1.494;
    const c2 = 1.494;
    const maxIterations = 100;
    const [bestPosition, bestFitness] = optimize(sphereFunction, dimensions, bounds, numParticles, w, c1, c2, maxIterations);
    console.log('Best position:', bestPosition);
    console.log('Best fitness:', bestFitness);
}

main();