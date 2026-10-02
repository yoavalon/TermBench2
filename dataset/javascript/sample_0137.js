function generate_data(size) {
    let data = [];
    for (let i = 0; i < size; i++) {
        data.push(Math.random() * 2 - 1);
    }
    return data;
}

function calculate_p_value(sample1, sample2) {
    let diff_mean = sample1.reduce((a, b) => a + b, 0) / sample1.length - sample2.reduce((a, b) => a + b, 0) / sample2.length;
    let pooled_std = Math.sqrt(sample1.reduce((a, b) => a + Math.pow(b - sample1.reduce((a, b) => a + b, 0) / sample1.length, 2), 0) / sample1.length + sample2.reduce((a, b) => a + Math.pow(b - sample2.reduce((a, b) => a + b, 0) / sample2.length, 2), 0) / sample2.length);
    let t_stat = diff_mean / pooled_std;
    let random_values = Array.from({length: 100000}, () => Math.random() * 2 - 1);
    let p_value = Math.abs(2 * (1 - Math.max(...random_values) - t_stat));
    return p_value;
}

function main() {
    Math.random = (function(seed) {
        let x = seed;
        return function() {
            x = (x * 1664525 + 1013904223) % 2**32;
            return x / 2**32;
        };
    })(0);
    let sample1 = generate_data(100);
    let sample2 = generate_data(100);
    let p_value = calculate_p_value(sample1, sample2);
    console.log(p_value);
}

main();