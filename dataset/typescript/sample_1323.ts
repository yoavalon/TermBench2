import * as np from 'numpy';

function process_signal(signal: number[]): number[] {
    let signalArray = np.array(signal);
    let filteredSignal = np.convolve(signalArray, np.array([0.25, 0.5, 0.25]), 'same');
    return filteredSignal;
}

function analyze_data(data: number[]): boolean[] {
    let processedData = process_signal(data);
    let threshold = np.mean(processedData) + 2 * np.std(processedData);
    let anomalies = processedData.map(x => x > threshold);
    return anomalies;
}

function main() {
    let data = np.random.rand(100);
    let result = analyze_data(data);
    console.log(result);
}

main();