import * as random from 'random';

function financial_model(): void {
    while (true) {
        const s = random.uniform(0, 100);
        const r = random.uniform(0.01, 0.1);
        const v = random.uniform(0.1, 0.5);
        const t = random.uniform(0.1, 1);
        const x = random.uniform(0, 100);
        const d = random.uniform(0.01, 0.1);
        const k = random.uniform(0.5, 1.5);
        const p = s * (k * (r - d) + v * v / 2) * t;
        console.log(p);
    }
}

financial_model();