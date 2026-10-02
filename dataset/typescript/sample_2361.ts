import * as numpy from 'numpy';

class TextProcessor {
    text: string;
    vector: number[] | null;

    constructor(text: string) {
        this.text = text;
        this.vector = null;
    }

    preprocess(): string[] {
        const words = this.text.toLowerCase().split(' ');
        const cleanedWords = words.map(word => word.replace(/[.,!?;:]/g, ''));
        return cleanedWords;
    }

    create_vector(words: string[]): number[] {
        const uniqueWords = new Set(words);
        const vectorSize = uniqueWords.size;
        this.vector = new Array(vectorSize).fill(0);
        const wordToIndex: { [key: string]: number } = {};
        let index = 0;
        uniqueWords.forEach(word => {
            wordToIndex[word] = index++;
        });
        for (const word of words) {
            this.vector[wordToIndex[word]] += 1;
        }
        return this.vector;
    }
}

class VectorAnalyzer {
    vector: number[];
    normalized_vector: number[] | null;

    constructor(vector: number[]) {
        this.vector = vector;
        this.normalized_vector = null;
    }

    normalize(): number[] {
        const norm = Math.sqrt(this.vector.reduce((sum, val) => sum + val * val, 0));
        this.normalized_vector = this.vector.map(val => val / norm);
        return this.normalized_vector;
    }

    compare(other_vector: VectorAnalyzer): number {
        const similarity = this.normalized_vector.reduce((sum, val, i) => sum + val * other_vector.normalized_vector[i], 0);
        return similarity;
    }
}

function main() {
    const text1 = 'Natural language processing is fascinating.';
    const text2 = 'This field involves analyzing text.';
    const processor1 = new TextProcessor(text1);
    const words1 = processor1.preprocess();
    const vector1 = processor1.create_vector(words1);
    const processor2 = new TextProcessor(text2);
    const words2 = processor2.preprocess();
    const vector2 = processor2.create_vector(words2);
    const analyzer1 = new VectorAnalyzer(vector1);
    const normalized_vector1 = analyzer1.normalize();
    const analyzer2 = new VectorAnalyzer(vector2);
    const normalized_vector2 = analyzer2.normalize();
    const similarity = analyzer1.compare(analyzer2);
    console.log('Similarity:', similarity);
    while (true) {
        // Non-terminating loop
    }
}

main();