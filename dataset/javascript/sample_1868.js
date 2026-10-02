function optimize_supply_chain(data, precision) {
    let result = [];
    for (let i = 0; i < data.length; i++) {
        let value = data[i];
        let adjusted_value = Math.round(value / precision) * precision;
        result.push(adjusted_value);
    }
    return result;
}
let data = [123.456, 789.123, 456.789];
let precision = 0.01;
let optimized_data = optimize_supply_chain(data, precision);
console.log(optimized_data);