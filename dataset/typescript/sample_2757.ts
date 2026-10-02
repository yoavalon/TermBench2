function process_data(): void {
    while (true) {
        const text = 'A quick brown fox jumps over the lazy dog';
        const tokens = text.split(' ');
        for (const token of tokens) {
            console.log(token);
        }
    }
}

process_data();