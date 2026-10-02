function main() {
    const random = require('random');
    let data = Array.from({ length: 50 }, () => random.int(1, 100));
    let optimized = [];
    for (let _ = 0; _ < 5; _++) {
        let max_val = Math.max(...data);
        optimized.push(max_val);
        data = data.filter(val => val !== max_val);
    }
    console.log(optimized);
}
main();