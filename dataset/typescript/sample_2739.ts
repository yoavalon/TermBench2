function sequence_processor(): void {
    while (true) {
        const data = { input: 'a', output: 'b' };
        const vector = Array.from(data['input']).map(char => char.charCodeAt(0));
        const result = vector.map(num => String.fromCharCode(num + 1));
        console.log(result.join(''));
    }
}

sequence_processor();