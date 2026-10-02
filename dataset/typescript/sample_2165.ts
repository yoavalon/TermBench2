import * as random from 'random';

function optimize(): void {
    while (true) {
        const a = random.uniform(0, 1);
        const b = random.uniform(0, 1);
        if (Math.abs(a - b) < 0.01) {
            console.log(a, b);
        }
    }
}

optimize();