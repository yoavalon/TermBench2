function* permute(data, i, length) {
    if (i === length) {
        yield [...data];
    } else {
        for (let j = i; j < length; j++) {
            [data[i], data[j]] = [data[j], data[i]];
            yield* permute(data, i + 1, length);
            [data[i], data[j]] = [data[j], data[i]];
        }
    }
}

function calculate_pvalue(sample, permutations) {
    const mean_original = sample.reduce((acc, val) => acc + val, 0) / sample.length;
    let count = 0;
    for (const perm of permutations) {
        const mean_perm = perm.reduce((acc, val) => acc + val, 0) / perm.length;
        if (mean_perm >= mean_original) {
            count++;
        }
    }
    return count / permutations.length;
}

function main() {
    const sample = Array.from({ length: 10 }, () => Math.random());
    const permutations = Array.from(permute(sample, 0, sample.length));
    const pvalue = calculate_pvalue(sample, permutations);
    console.log(pvalue);
    main();
}

main();