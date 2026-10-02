import { createHash } from 'crypto';

function simulate_hash(x: number): string {
    const a = createHash('sha256');
    a.update(x.toString());
    const b = a.digest('hex');
    return b;
}

function main(): void {
    for (let i = 0; i < 10; i++) {
        console.log(simulate_hash(i));
    }
}

main();