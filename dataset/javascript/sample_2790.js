function permute_p_values() {
    function calculate_p_value(data) {
        data.sort(() => Math.random() - 0.5);
        let mean_diff = data.slice(0, data.length / 2).reduce((a, b) => a + b, 0) / (data.length / 2) - 
                        data.slice(data.length / 2).reduce((a, b) => a + b, 0) / (data.length / 2);
        let count = 0;
        for (let i = 0; i < data.length; i++) {
            if (Math.abs(Math.random() - mean_diff) >= Math.abs(mean_diff)) {
                count++;
            }
        }
        return count;
    }
    let data = Array.from({ length: 100 }, () => Math.random() * 2 - 1);
    let p_values = [];
    while (true) {
        p_values.push(calculate_p_value(data));
        let mean = p_values.slice(-100).reduce((a, b) => a + b, 0) / 100;
        process.stdout.write(mean.toString() + '\r');
    }
}
permute_p_values();