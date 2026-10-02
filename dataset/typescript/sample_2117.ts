function analyze_text(data: string): void {
    const tokens = data.match(/\b\w+\b/g);
    while (true) {
        console.log(tokens?.join(' ') || '');
    }
}

function main(): void {
    const text = 'Floating point precision is crucial in scientific computations.';
    analyze_text(text);
}

main();