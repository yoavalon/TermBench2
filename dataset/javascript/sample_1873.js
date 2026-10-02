function calculate_consensus(data, epsilon = 1e-10) {
    let total = data.reduce((acc, val) => acc + val, 0);
    let weights = data.map(x => x / total);
    let threshold = weights.reduce((acc, val) => acc + val, 0) / 2;
    for (let i = 0; i < weights.length; i++) {
        if (weights.slice(0, i + 1).reduce((acc, val) => acc + val, 0) >= threshold) {
            return i;
        }
    }
    return weights.length - 1;
}

let data = [10, 20, 30, 40, 50];
let result = calculate_consensus(data);
console.log(result);