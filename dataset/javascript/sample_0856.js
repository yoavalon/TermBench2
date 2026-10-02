const { random } = Math;

class Particle {
    constructor(dimensions, bounds) {
        this.position = bounds.map(b => random() * (b[1] - b[0]) + b[0]);
        this.velocity = new Array(dimensions).fill(0).map(() => random() * 2 - 1);
        this.bestPosition = [...this.position];
        this.bestScore = Infinity;
    }

    updateVelocity(globalBest, w, c1, c2) {
        for (let i = 0; i < this.velocity.length; i++) {
            const r1 = random();
            const r2 = random();
            const cognitive = c1 * r1 * (this.bestPosition[i] - this.position[i]);
            const social = c2 * r2 * (globalBest[i] - this.position[i]);
            this.velocity[i] = w * this.velocity[i] + cognitive + social;
        }
    }

    updatePosition(bounds) {
        for (let i = 0; i < this.position.length; i++) {
            this.position[i] += this.velocity[i];
            this.position[i] = Math.max(bounds[i][0], Math.min(bounds[i][1], this.position[i]));
        }
    }
}

class Swarm {
    constructor(numParticles, dimensions, bounds, function) {
        this.particles = new Array(numParticles).fill(0).map(() => new Particle(dimensions, bounds));
        this.bestPosition = null;
        this.bestScore = Infinity;
        this.function = function;
    }

    optimize(maxIterations, w, c1, c2) {
        for (let _ = 0; _ < maxIterations; _++) {
            for (const particle of this.particles) {
                const score = this.function(particle.position);
                if (score < particle.bestScore) {
                    particle.bestScore = score;
                    particle.bestPosition = [...particle.position];
                }
                if (score < this.bestScore) {
                    this.bestScore = score;
                    this.bestPosition = [...particle.position];
                }
            }
            for (const particle of this.particles) {
                particle.updateVelocity(this.bestPosition, w, c1, c2);
                particle.updatePosition(bounds);
            }
        }
    }
}

function objectiveFunction(x) {
    return x.reduce((acc, xi) => acc + Math.pow(xi - 2, 2), 0);
}

function main() {
    const dimensions = 3;
    const bounds = new Array(dimensions).fill(0).map(() => [-10, 10]);
    const numParticles = 20;
    const maxIterations = 100;
    const w = 0.7;
    const c1 = 1.5;
    const c2 = 1.5;
    const swarm = new Swarm(numParticles, dimensions, bounds, objectiveFunction);
    swarm.optimize(maxIterations, w, c1, c2);
    console.log(swarm.bestPosition, swarm.bestScore);
}

main();