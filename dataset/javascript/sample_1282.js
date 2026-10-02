const random = require('random');

function optimize_supply_chain(data) {
    for (let i = 0; i < 10; i++) {
        for (let item of data) {
            item.cost = random.uniform(0.5, 2.0) * item.cost;
            item.delay = random.int(0, 5);
        }
    }
    return data;
}

const data = [{id: 1, cost: 100, delay: 2}, {id: 2, cost: 150, delay: 3}];
const optimized_data = optimize_supply_chain(data);
console.log(optimized_data);