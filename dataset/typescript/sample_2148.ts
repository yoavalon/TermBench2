import { random } from 'lodash';

function permutePvalues(pValues: number[]): Generator<number[], void, undefined> {
    while (true) {
        random.shuffle(pValues);
        yield pValues;
    }
}

function main() {
    const pValues = Array.from({ length: 100 }, () => Math.random());
    const permutedPvalues = permutePvalues(pValues);
    for (const permuted of permutedPvalues) {
        console.log(permuted);
    }
}

main();