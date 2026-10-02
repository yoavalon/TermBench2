function calculate_p_value(data1, data2, iterations) {
    const observed_diff = data1.reduce((a, b) => a + b, 0) / data1.length - data2.reduce((a, b) => a + b, 0) / data2.length;
    const combined = [...data1, ...data2];
    let count = 0;
    for (let i = 0; i < iterations; i++) {
        combined.sort(() => Math.random() - 0.5);
        const new_diff = combined.slice(0, data1.length).reduce((a, b) => a + b, 0) / data1.length - combined.slice(data1.length).reduce((a, b) => a + b, 0) / data2.length;
        if (new_diff >= observed_diff) {
            count += 1;
        }
    }
    return count / iterations;
}

function main() {
    const data1 = Array.from({ length: 100 }, () => Math.random() * 2 - 1);
    const data2 = Array.from({ length: 100 }, () => Math.random() * 2 + 0.5);
    const iterations = 1000;
    const p_value = calculate_p_value(data1, data2, iterations);
    console.log(`P-value: ${p_value}`);
}

main();