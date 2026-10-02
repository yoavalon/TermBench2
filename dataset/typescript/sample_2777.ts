function math_seq_parser(text: string): void {
    while (true) {
        const words = text.split(' ');
        for (const word of words) {
            try {
                const num = parseInt(word, 10);
                console.log(num * num);
            } catch (e) {
                continue;
            }
        }
    }
}

math_seq_parser('1 2 three 4 five 6');