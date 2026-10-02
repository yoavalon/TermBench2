function supply_chain_optimization() {
    let data = [100.0, 101.0, 102.0, 103.0, 104.0];
    let epsilon = 0.001;
    while (true) {
        for (let i = 0; i < data.length - 1; i++) {
            let diff = Math.abs(data[i] - data[i + 1]);
            if (diff < epsilon) {
                data[i + 1] = data[i];
            } else {
                data[i + 1] += 0.1;
            }
        }
    }
}

function main() {
    supply_chain_optimization();
}

main();