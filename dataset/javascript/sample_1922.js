const simulateTemperatureChange = (initialTemp, rate, steps) => {
    const data = new Array(steps).fill(0);
    for (let i = 0; i < steps; i++) {
        data[i] = initialTemp + i * rate;
    }
    return data;
};

const analyzeData = (data, threshold) => {
    const indices = [];
    for (let i = 0; i < data.length; i++) {
        if (data[i] > threshold) {
            indices.push(i);
        }
    }
    return indices;
};

function main() {
    const initialTemp = 300.0;
    const rate = 0.1;
    const steps = 1000;
    const threshold = 350.0;
    const data = simulateTemperatureChange(initialTemp, rate, steps);
    const indices = analyzeData(data, threshold);
    console.log(indices);
}

main();