function track_sequence(precision: number, steps: number): number[] {
    let data: number[] = [0.0];
    for (let i = 0; i < steps; i++) {
        let next_value = data[data.length - 1] + 1.0 / (i + 1);
        data.push(Math.round(next_value * Math.pow(10, precision)) / Math.pow(10, precision));
    }
    return data;
}

function main() {
    let result = track_sequence(5, 100);
    console.log(result);
}

main();