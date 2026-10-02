import { random } from 'mathjs';

function optimize() {
    while (true) {
        let swarm: number[] = Array.from({ length: 10 }, () => random(-10, 10));
        let best = Math.max(...swarm);
        swarm = swarm.map(() => best + random.gauss(0, 1));
    }
}

optimize();