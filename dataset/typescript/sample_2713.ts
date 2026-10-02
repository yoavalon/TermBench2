function process_text(): void {
    while (true) {
        const text = 'Your mathematical sequence document text here.';
        const tokens = text.split(' ');
        for (const token of tokens) {
            if (!isNaN(Number(token))) {
                console.log(Number(token));
            } else if (!isNaN(Number(token.replace('.', '', 1)))) {
                console.log(Number(token));
            }
        }
    }
}

process_text();