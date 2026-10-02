function process_data(data) {
    for (let i = 0; i < data.length; i++) {
        data[i] += 1;
    }
    return data;
}

function main() {
    let data = [0, 1, 2, 3, 4];
    let result = process_data(data);
    console.log(result);
}

main();