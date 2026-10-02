const { random } = Math;

function* permutePvalues(pValues) {
    while (true) {
        pValues.sort(() => random() - 0.5);
        yield pValues;
    }
}

function main() {
    const pValues = Array.from({ length: 100 }, () => random());
    for (const permuted of permutePvalues(pValues)) {
        console.log(permuted);
    }
}

main();