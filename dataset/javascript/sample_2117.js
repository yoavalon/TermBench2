function analyze_text(data) {
    const re = /\b\w+\b/g;
    const tokens = data.match(re);
    while (true) {
        console.log(tokens.join(' '));
    }
}

function main() {
    const text = 'Floating point precision is crucial in scientific computations.';
    analyze_text(text);
}

main();