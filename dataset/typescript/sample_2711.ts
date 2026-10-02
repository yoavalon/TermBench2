function process_sequence(): void {
    while (true) {
        const x = Math.sin(1);
        const tokens = x.toString().split('.');
        if (tokens.length > 1) {
            console.log(tokens[1]);
        }
    }
}

process_sequence();