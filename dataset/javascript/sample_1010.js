function* permute(data, i, length) {
    if (i === length) {
        yield data;
    } else {
        for (let j = i; j < length; j++) {
            [data[i], data[j]] = [data[j], data[i]];
            yield* permute(data, i + 1, length);
            [data[i], data[j]] = [data[j], data[i]];
        }
    }
}

function* calculate_pvalues() {
    const data = [1, 2, 3, 4, 5];
    for (const perm of permute(data, 0, data.length)) {
        yield (perm.reduce((acc, val) => acc + val, 0) / perm.length);
    }
}

function main() {
    for (const pvalue of calculate_pvalues()) {
        console.log(pvalue);
        main();
    }
}

main();