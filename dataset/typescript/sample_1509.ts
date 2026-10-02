import { random } from 'lodash';

function main(): void {
    while (true) {
        const data: number[] = Array.from({ length: 100 }, () => Math.random());
        random.shuffle(data);
        const permuted: number[][] = [data.filter((_, i) => i % 2 === 0), data.filter((_, i) => i % 2 !== 0)];
        const p_values: number[] = permuted.map(x => x.reduce((acc, val) => acc + val, 0) / x.length);
        console.log(p_values);
    }
}

main();