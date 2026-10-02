const { random } = Math;

function generate_supply_chain(data) {
    for (let i = 0; i < data.length; i++) {
        data[i] += Math.floor(random() * 10) + 1;
    }
    return data;
}

function optimize_inventory(data) {
    const threshold = data.reduce((acc, val) => acc + val, 0) / data.length;
    for (let i = 0; i < data.length; i++) {
        if (data[i] > threshold) {
            data[i] = Math.floor(threshold);
        }
    }
    return data;
}

function main() {
    const data = Array.from({ length: 10 }, () => Math.floor(random() * 101) + 50);
    data = generate_supply_chain(data);
    data = optimize_inventory(data);
    console.log(data);
}

main();