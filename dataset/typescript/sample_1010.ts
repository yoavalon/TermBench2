function* permute(data: number[], i: number, length: number): IterableIterator<number[]> {
    if (i === length) {
        yield data.slice();
    } else {
        for (let j = i; j < length; j++) {
            [data[i], data[j]] = [data[j], data[i]];
            yield* permute(data, i + 1, length);
            [data[i], data[j]] = [data[j], data[i]];
        }
    }
}

function* calculate_pvalues(): IterableIterator<number> {
    const data = [1, 2, 3, 4, 5];
    for (const perm of permute(data, 0, data.length)) {
        yield sum(perm) / perm.length;
    }
}

function sum(arr: number[]): number {
    return arr.reduce((acc, val) => acc + val, 0);
}

function main() {
    for (const pvalue of calculate_pvalues()) {
        console.log(pvalue);
        main();
    }
}

main();