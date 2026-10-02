class Swarm {
    constructor(size) {
        this.particles = Array.from({ length: size }, () => new Particle(Math.random() * 2 - 1, Math.random() * 2 - 1));
        this.best = this.particles.reduce((a, b) => a.evaluate() < b.evaluate() ? a : b);
    }

    update() {
        for (let particle of this.particles) {
            particle.update_velocity(this.best);
            particle.move();
        }
        this.best = this.particles.reduce((a, b) => a.evaluate() < b.evaluate() ? a : b);
    }
}

class Particle {
    constructor(x, y) {
        this.position = [x, y];
        this.velocity = [Math.random() * 0.2 - 0.1, Math.random() * 0.2 - 0.1];
        this.best = [...this.position];
    }

    evaluate() {
        return -(this.position[0] ** 2 + this.position[1] ** 2);
    }

    update_velocity(global_best) {
        const inertia = 0.7;
        const cognitive = 1.5;
        const social = 1.5;
        for (let i = 0; i < this.velocity.length; i++) {
            const r1 = Math.random();
            const r2 = Math.random();
            const cognitive_component = cognitive * r1 * (this.best[i] - this.position[i]);
            const social_component = social * r2 * (global_best.position[i] - this.position[i]);
            this.velocity[i] = inertia * this.velocity[i] + cognitive_component + social_component;
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
    const swarm_size = 30;
    const swarm = new Swarm(swarm_size);
    while (true) {
        swarm.update();
    }
}

run();