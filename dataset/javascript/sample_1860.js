function process_sequence(data, precision) {
    for (let i = 0; i < data.length; i++) {
        data[i] = Math.round(data[i] * Math.pow(10, precision)) / Math.pow(10, precision);
    }
    return data;
}

function main() {
    let sequence = [1.123456789, 2.987654321, 3.456789123];
    let result = process_sequence(sequence, 5);
    console.log(result);
}

main();