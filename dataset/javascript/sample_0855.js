class Particle {
    constructor(dimensions) {
        this.position = Array.from({ length: dimensions }, () => Math.random() * 2 - 1);
        this.velocity = Array.from({ length: dimensions }, () => Math.random() * 2 - 1);
        this.bestPosition = [...this.position];
        this.bestScore = Infinity;
    }

    updateVelocity(globalBest, inertia, cognitive, social) {
        for (let i = 0; i < this.position.length; i++) {
            const r1 = Math.random();
            const r2 = Math.random();
            this.velocity[i] = inertia * this.velocity[i] + cognitive * r1 * (this.bestPosition[i] - this.position[i]) + social * r2 * (globalBest[i] - this.position[i]);
        }
    }

    updatePosition() {
        for (let i = 0; i < this.position.length; i++) {
            this.position[i] += this.velocity[i];
        }
    }

    evaluate(fitnessFunction) {
        this.score = fitnessFunction(this.position);
        if (this.score < this.bestScore) {
            this.bestScore = this.score;
            this.bestPosition = [...this.position];
        }
    }
}

class Swarm {
    constructor(size, dimensions, fitnessFunction, maxIterations, inertia, cognitive, social) {
        this.particles = Array.from({ length: size }, () => new Particle(dimensions));
        this.fitnessFunction = fitnessFunction;
        this.maxIterations = maxIterations;
        this.inertia = inertia;
        this.cognitive = cognitive;
        this.social = social;
        this.globalBest = null;
        this.globalBestScore = Infinity;
    }

    updateGlobalBest() {
        for (const particle of this.particles) {
            if (particle.bestScore < this.globalBestScore) {
                this.globalBestScore = particle.bestScore;
                this.globalBest = [...particle.bestPosition];
            }
        }
    }

    optimize() {
        for (let _ = 0; _ < this.maxIterations; _++) {
            for (const particle of this.particles) {
                particle.updateVelocity(this.globalBest, this.inertia, this.cognitive, this.social);
                particle.updatePosition();
                particle.evaluate(this.fitnessFunction);
            }
            this.updateGlobalBest();
        }
    }
}

function sphereFunction(x) {
    return x.reduce((sum, xi) => sum + xi ** 2, 0);
}

function main() {
    const dimensions = 2;
    const size = 30;
    const maxIterations = 100;
    const inertia = 0.5;
    const cognitive = 1.5;
    const social = 1.5;
    const swarm = new Swarm(size, dimensions, sphereFunction, maxIterations, inertia, cognitive, social);
    swarm.optimize();
    console.log('Best position:', swarm.globalBest);
    console.log('Best score:', swarm.globalBestScore);
}

main();