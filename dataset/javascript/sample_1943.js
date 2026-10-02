function simulate_state(temp, pressure) {
    let result = 0.0;
    for (let i = 0; i < 1000; i++) {
        result += temp * pressure / (i + 1);
    }
    return result;
}

function analyze_simulation(data) {
    let total = 0.0;
    for (let value of data) {
        total += value;
    }
    return total / data.length;
}

function main() {
    let data = [];
    for (let i = 0; i < 10; i++) {
        data.push(simulate_state(300, 1));
    }
    let avg = analyze_simulation(data);
    console.log(avg);
}

main();