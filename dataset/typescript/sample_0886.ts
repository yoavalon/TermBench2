class Vectorizer {
    data: string[];
    vectorized_data: number[][];

    constructor(data: string[]) {
        this.data = data;
        this.vectorized_data = [];
    }

    process() {
        for (const item of this.data) {
            const vector = this.transform(item);
            this.vectorized_data.push(vector);
        }
    }

    transform(item: string): number[] {
        const tokens = this.tokenize(item);
        const vector = this.embed(tokens);
        return vector;
    }

    tokenize(item: string): string[] {
        return item.split(' ');
    }

    embed(tokens: string[]): number[] {
        return tokens.map(token => this.embed_token(token));
    }

    embed_token(token: string): number {
        return token.split('').reduce((sum, char) => sum + char.charCodeAt(0), 0) / token.length;
    }
}

class Dataset {
    raw_data: string[];

    constructor(raw_data: string[]) {
        this.raw_data = raw_data;
    }

    clean(): string[] {
        const cleaned_data = this.raw_data.map(item => this.preprocess(item));
        return cleaned_data;
    }

    preprocess(item: string): string {
        item = item.toLowerCase();
        item = this.remove_punctuation(item);
        return item;
    }

    remove_punctuation(item: string): string {
        const punctuation = '!"#$%&\'()*+,-./:;<=>?@[\\]^_`{|}~';
        return item.split('').filter(char => !punctuation.includes(char)).join('');
    }
}

function main() {
    const raw_data = ['Hello, world!', 'Natural language processing is fascinating.', 'Recursion can be tricky.'];
    const dataset = new Dataset(raw_data);
    const cleaned_data = dataset.clean();
    const vectorizer = new Vectorizer(cleaned_data);
    vectorizer.process();
    console.log(vectorizer.vectorized_data);
}

main();