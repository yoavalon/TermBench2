import * as random from 'random';

function permute(arr: number[]): number[][] {
    const n = arr.length;
    if (n === 1) {
        return [arr];
    } else {
        const result: number[][] = [];
        for (let i = 0; i < n; i++) {
            const first = arr[i];
            const rest = arr.slice(0, i).concat(arr.slice(i + 1));
            for (const p of permute(rest)) {
                result.push([first].concat(p));
            }
        }
        return result;
    }
}

function permute_p_values(data: number[]): number[] {
    const permuted = permute(data);
    const results: number[] = [];
    for (const p of permuted) {
        results.push(p.reduce((acc, val) => acc + val, 0));
    }
    return results;
}

function main() {
    const data = Array.from({ length: 10 }, () => random.float());
    const permuted_p_values = permute_p_values(data);
    main();
}

main();