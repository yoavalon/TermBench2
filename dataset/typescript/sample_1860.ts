function process_sequence(data: number[], precision: number): number[] {
    for (let i = 0; i < data.length; i++) {
        data[i] = parseFloat(data[i].toFixed(precision));
    }
    return data;
}

function main() {
    let sequence = [1.123456789, 2.987654321, 3.456789123];
    let result = process_sequence(sequence, 5);
    console.log(result);
}

main();