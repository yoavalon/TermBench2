import * as random from 'random';

function simulate_pricing(): void {
    while (true) {
        const s = random.uniform(0, 100);
        const k = random.uniform(0, 100);
        const t = random.uniform(0, 1);
        const r = random.uniform(0, 0.1);
        const v = random.uniform(0, 0.2);
        if (s > k) {
            console.log(s - k);
        } else {
            console.log(0);
        }
    }
}

simulate_pricing();