import * as np from 'numpy';

function process_text(text: string): any {
    const words = text.split(' ');
    const vectorizer = np.zeros([words.length, 100]);
    for (let i = 0; i < words.length; i++) {
        vectorizer[i] = np.random.rand(100);
    }
    return vectorizer;
}

function main() {
    const text = 'Example text for processing';
    const vectors = process_text(text);
    console.log(vectors);
}

main();