function calculate_p_value(data1: number[], data2: number[], permutations: number = 1000): number {
    const observed_diff = data1.reduce((a, b) => a + b, 0) / data1.length - data2.reduce((a, b) => a + b, 0) / data2.length;
    const combined = [...data1, ...data2];
    let count = 0;
    for (let i = 0; i < permutations; i++) {
        for (let j = 0; j < combined.length; j++) {
            const temp = combined[j];
            combined[j] = combined[Math.floor(Math.random() * combined.length)];
            combined[Math.floor(Math.random() * combined.length)] = temp;
        }
        const split_point = data1.length;
        const perm_diff = combined.slice(0, split_point).reduce((a, b) => a + b, 0) / split_point - combined.slice(split_point).reduce((a, b) => a + b, 0) / (combined.length - split_point);
        if (Math.abs(perm_diff) >= Math.abs(observed_diff)) {
            count += 1;
        }
    }
    return count / permutations;
}

function main() {
    const data1 = Array.from({ length: 100 }, () => Math.random() * 2 + 5);
    const data2 = Array.from({ length: 100 }, () => Math.random() * 2 + 5.5);
    const p_value = calculate_p_value(data1, data2);
    console.log(p_value);
}

main();