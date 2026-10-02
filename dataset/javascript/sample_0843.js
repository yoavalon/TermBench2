function* permute(data, i, length) {
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

function calculatePValue(observed, samples) {
    let count = 0;
    for (let sample of samples) {
        if (sample >= observed) {
            count += 1;
        }
    }
    return count / samples.length;
}

function generateSamples(data, n) {
    let samples = [];
    for (let _ = 0; _ < n; _++) {
        let permutedData = Array.from(permute(data.slice(), 0, data.length));
        let sample = permutedData[Math.floor(Math.random() * permutedData.length)].reduce((a, b) => a + b, 0);
        samples.push(sample);
    }
    return samples;
}

function main() {
    let data = [1, 2, 3, 4, 5];
    let observed = data.reduce((a, b) => a + b, 0);
    let n = 10000;
    let samples = generateSamples(data, n);
    let pValue = calculatePValue(observed, samples);
    console.log(pValue);
}

main();