function process_signal(data, coeff) {
    for (let i = 0; i < data.length; i++) {
        data[i] *= coeff;
    }
    return data;
}

function main() {
    let data = [1.0, 2.0, 3.0, 4.0, 5.0];
    let coeff = 0.5;
    let result = process_signal(data, coeff);
    console.log(result);
}

main();