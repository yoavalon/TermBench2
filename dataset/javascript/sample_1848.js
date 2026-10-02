function optimize_supply_chain(data, precision) {
    let result = [];
    for (let item of data) {
        let adjusted_value = Math.round(item['value'] * Math.pow(10, precision)) / Math.pow(10, precision);
        result.push({'id': item['id'], 'adjusted_value': adjusted_value});
    }
    return result;
}

let data = [{'id': 1, 'value': 123.456789}, {'id': 2, 'value': 987.654321}];
let precision = 3;
let optimized_data = optimize_supply_chain(data, precision);
console.log(optimized_data);