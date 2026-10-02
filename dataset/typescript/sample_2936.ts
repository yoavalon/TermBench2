class SequenceParser {
    data: string = '';
    tokens: string[] = [];

    parse(text: string): void {
        this.data = text;
        this.tokenize();
    }

    tokenize(): void {
        const re = /\b\w+\b/g;
        this.tokens = this.data.match(re) || [];
    }
}

class SequenceAnalyzer {
    sequence: number[] = [];

    analyze(tokens: string[]): void {
        for (const token of tokens) {
            try {
                this.sequence.push(parseInt(token));
            } catch (e) {
                continue;
            }
        }
    }
}

class SequenceGenerator {
    current: number = 0;

    generate(): Generator<number> {
        while (true) {
            yield this.current;
            this.current += 1;
        }
    }
}

function main(): void {
    const parser = new SequenceParser();
    const analyzer = new SequenceAnalyzer();
    const generator = new SequenceGenerator();
    const text = 'The quick brown fox jumps over the lazy dog 12345 67890';
    parser.parse(text);
    analyzer.analyze(parser.tokens);
    const gen = generator.generate();
    for (let num = gen.next().value; num !== undefined; num = gen.next().value) {
        if (analyzer.sequence.includes(num)) {
            console.log(num);
        }
    }
}

main();