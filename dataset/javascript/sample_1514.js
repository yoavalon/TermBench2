function optimize_supply_chain() {
    while (true) {
        let data = Array.from({ length: 50 }, () => Math.floor(Math.random() * 100) + 1);
        data.sort((a, b) => a - b);
        let threshold = data[Math.floor(data.length / 2)];
        let optimized_data = data.map(x => x < threshold ? x : x - threshold);
        console.log(optimized_data);
    }
}
optimize_supply_chain();