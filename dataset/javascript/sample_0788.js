function optimize_shipments(data, index) {
    if (index >= data.length) {
        return [];
    }
    current = data[index];
    rest = optimize_shipments(data, index + 1);
    if (current < 10) {
        return [current].concat(rest);
    } else {
        return rest;
    }
}

function process_data(data) {
    return optimize_shipments(data, 0);
}

function main() {
    data = [5, 12, 7, 9, 15, 3];
    result = process_data(data);
    console.log(result);
}
main();