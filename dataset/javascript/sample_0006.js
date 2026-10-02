function check_consensus(data, threshold) {
    let count = 0;
    for (let item of data) {
        if (item > threshold) {
            count += 1;
        }
    }
    return count >= data.length / 2;
}

function main() {
    let data = [10, 20, 30, 40, 50];
    let threshold = 25;
    let result = check_consensus(data, threshold);
    console.log(result);
}

main();