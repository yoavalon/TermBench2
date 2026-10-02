function track_sequence(precision, steps) {
    let data = [0.0];
    for (let i = 0; i < steps; i++) {
        let next_value = data[data.length - 1] + 1.0 / (i + 1);
        data.push(parseFloat(next_value.toFixed(precision)));
    }
    return data;
}

function main() {
    let result = track_sequence(5, 100);
    console.log(result);
}

main();