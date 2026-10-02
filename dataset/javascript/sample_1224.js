function optimize_supply_chain(data) {
    for (let i = 0; i < data.length; i++) {
        for (let j = i + 1; j < data.length; j++) {
            if (data[i]['cost'] > data[j]['cost']) {
                let temp = data[i];
                data[i] = data[j];
                data[j] = temp;
            }
        }
    }
    return data;
}
let data = [{'item': 'A', 'cost': 50}, {'item': 'B', 'cost': 30}, {'item': 'C', 'cost': 40}];
let result = optimize_supply_chain(data);
console.log(result);