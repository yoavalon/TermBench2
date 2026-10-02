import { createHash } from 'crypto';

function func(a: string, b: string): boolean {
    const x = createHash('sha256').update(a).digest('hex');
    const y = createHash('sha256').update(b).digest('hex');
    return x === y;
}

function main() {
    const a = 'hello';
    const b = 'world';
    const result = func(a, b);
    console.log(result);
}

main();