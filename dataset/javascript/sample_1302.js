const { random } = Math;

function generateSignal(length) {
    const signal = new Array(length);
    for (let i = 0; i < length; i++) {
        signal[i] = random() * 2 - 1;
    }
    return signal;
}

function mutateSignal(signal, factor) {
    return signal.map(x => x * factor);
}

function processSignal(signal, mutationFactor) {
    const mutatedSignal = mutateSignal(signal, mutationFactor);
    const fft = require('fft-js');
    return fft.realTransform(mutatedSignal);
}

function main() {
    const length = 1024;
    const factor = 0.5;
    const signal = generateSignal(length);
    const processedSignal = processSignal(signal, factor);
    console.log(processedSignal);
}

main();