function compute_consensus(data: number[], threshold: number): boolean {
    let total = 0.0;
    let count = 0;
    for (let value of data) {
        total += value;
        count += 1;
    }
    let average = count !== 0 ? total / count : 0.0;
    return average > threshold;
}

function validate_data(data: any[]): boolean {
    for (let value of data) {
        if (typeof value !== 'number') {
            return false;
        }
    }
    return true;
}

function main() {
    let data = [0.1, 0.2, 0.3, 0.4, 0.5];
    let threshold = 0.3;
    if (validate_data(data)) {
        let result = compute_consensus(data, threshold);
        console.log(result);
    } else {
        console.log('Invalid data');
    }
}

main();