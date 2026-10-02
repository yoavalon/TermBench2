function process_data() {
    const { random, dot, sum } = require('mathjs');
    let data = Array.from({ length: 1000 }, () => Array.from({ length: 1000 }, () => random()));
    while (true) {
        data = dot(data, data);
        console.log(sum(data));
    }
}
process_data();