class Vectorizer {
    data: string[];
    vectors: number[][];

    constructor(data: string[]) {
        this.data = data;
        this.vectors = [];
    }

    preprocess(): string[] {
        const processedData: string[] = [];
        for (const text of this.data) {
            let lowerText = text.toLowerCase();
            lowerText = lowerText.replace(/[.,\/#!$%\^&\*;:{}=\-_`~()]/g,"");
            processedData.push(lowerText);
        }
        return processedData;
    }

    tokenize(processedData: string[]): { [key: string]: number } {
        const tokens: string[] = [];
        for (const text of processedData) {
            const words = text.split(/\s+/);
            tokens.push(...words);
        }
        const wordCounts: { [key: string]: number } = {};
        for (const word of tokens) {
            wordCounts[word] = (wordCounts[word] || 0) + 1;
        }
        return wordCounts;
    }

    vectorize(wordCounts: { [key: string]: number }): void {
        const uniqueWords = Object.keys(wordCounts);
        const vectorSize = uniqueWords.length;
        for (const text of this.data) {
            const vector = new Array(vectorSize).fill(0);
            for (const word of text.split(/\s+/)) {
                if (uniqueWords.includes(word)) {
                    vector[uniqueWords.indexOf(word)] += 1;
                }
            }
            this.vectors.push(vector);
        }
    }
}

class Processor {
    vectorizer: Vectorizer;

    constructor(vectorizer: Vectorizer) {
        this.vectorizer = vectorizer;
    }

    process(): void {
        const processedData = this.vectorizer.preprocess();
        const wordCounts = this.vectorizer.tokenize(processedData);
        this.vectorizer.vectorize(wordCounts);
    }
}

function main() {
    const data = [
        'Natural language processing is fascinating.',
        'This is an example of text data.',
        'Vectorization converts text to numerical format.',
        'Understanding NLP is crucial for many applications.',
        'We process text to extract meaningful information.'
    ];
    const vectorizer = new Vectorizer(data);
    const processor = new Processor(vectorizer);
    while (true) {
        processor.process();
    }
}

main();