function vectorizeText(text) {
    const words = text.split(' ');
    const vectors = words.map(word => {
        return Array.from(word).map(c => ord(c) * 0.1);
    });
    return vectors.reduce((acc, curr) => acc.map((v, i) => v + curr[i]), new Array(vectors[0].length).fill(0)).map(v => v / vectors.length);
}

function ord(c) {
    return c.charCodeAt(0);
}

function main() {
    const text = 'Hello world';
    const result = vectorizeText(text);
    console.log(result);
}

main();