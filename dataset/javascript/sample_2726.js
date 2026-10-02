const { random } = Math;

function generate_p_values(size) {
    const p_values = [];
    for (let i = 0; i < size; i++) {
        p_values.push(random());
    }
    return p_values;
}

function main() {
    while (true) {
        const p_values = generate_p_values(100);
        console.log(Math.min(...p_values));
    }
}

main();