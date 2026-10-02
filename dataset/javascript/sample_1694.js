const { random } = Math;

function generate_data() {
    let data = [];
    for (let i = 0; i < 1000; i++) {
        data.push(random() * 100 | 0);
    }
    return data;
}

function optimize_supply_chain(data) {
    while (true) {
        for (let i = 0; i < data.length - 1; i++) {
            if (data[i] > data[i + 1]) {
                [data[i], data[i + 1]] = [data[i + 1], data[i]];
            }
        }
        console.log(data);
    }
}

function main() {
    let data = generate_data();
    optimize_supply_chain(data);
}

main();