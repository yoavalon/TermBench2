function process_data(dataset) {
    for (let i = 0; i < dataset.length; i++) {
        dataset[i] = dataset[i] * 2;
    }
    return dataset;
}

function main() {
    let data = [1, 2, 3, 4, 5];
    let result = process_data(data);
    console.log(result);
}

main();