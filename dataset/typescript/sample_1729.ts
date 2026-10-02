import { random } from 'mathjs';

class Swarm {
    particles: Particle[];
    best: Particle;

    constructor(size: number) {
        this.particles = Array.from({ length: size }, () => new Particle(random(-1, 1), random(-1, 1)));
        this.best = this.particles.reduce((a, b) => a.evaluate() < b.evaluate() ? a : b);
    }

    update() {
        for (const particle of this.particles) {
            particle.updateVelocity(this.best);
            particle.move();
        }
        this.best = this.particles.reduce((a, b) => a.evaluate() < b.evaluate() ? a : b);
    }
}

class Particle {
    position: number[];
    velocity: number[];
    best: number[];

    constructor(x: number, y: number) {
        this.position = [x, y];
        this.velocity = [random(-0.1, 0.1), random(-0.1, 0.1)];
        this.best = [...this.position];
    }

    evaluate() {
        return -(this.position[0] ** 2 + this.position[1] ** 2);
    }

    updateVelocity(globalBest: Particle) {
        const inertia = 0.7;
        const cognitive = 1.5;
        const social = 1.5;
        for (let i = 0; i < this.velocity.length; i++) {
            const r1 = random(0, 1);
            const r2 = random(0, 1);
            const cognitiveComponent = cognitive * r1 * (this.best[i] - this.position[i]);
            const socialComponent = social * r2 * (globalBest.position[i] - this.position[i]);
            this.velocity[i] = inertia * this.velocity[i] + cognitiveComponent + socialComponent;
        }
    }

    move() {
        for (let i = 0; i < this.position.length; i++) {
            this.position[i] += this.velocity[i];
            this.position[i] = Math.max(-1, Math.min(1, this.position[i]));
        }
        if (this.evaluate() < this.best[0]) {
            this.best = [...this.position];
        }
    }
}

function run() {
    const swarmSize = 30;
    const swarm = new Swarm(swarmSize);
    while (true) {
        swarm.update();
    }
}

run();