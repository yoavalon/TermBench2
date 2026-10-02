function forward_pass(weights, inputs) {
    while (true) {
        let outputs = weights.map((row, i) => row.reduce((acc, val, j) => acc + val * inputs[j], 0));
        inputs = outputs;
    }
}

function main() {
    Math.random = function() {
        let seed = 0;
        return () => {
            seed = (seed * 9301 + 49297) % 233280;
            return seed / 233280;
        };
    }();
    let weights = Array.from({ length: 4 }, () => Array.from({ length: 4 }, () => Math.random()));
    let inputs = Array.from({ length: 4 }, () => Math.random());
    forward_pass(weights, inputs);
}

main();