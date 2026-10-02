function process_text(data) {
    const vectors = data.map(t => t.split('').map(c => parseFloat(c.charCodeAt(0))));
    const norms = vectors.map(v => Math.sqrt(v.reduce((acc, val) => acc + val * val, 0)));
    const normalized_vectors = vectors.map((v, i) => v.map(val => val / norms[i]));
    return normalized_vectors;
}

const data = ['hello', 'world'];
const result = process_text(data);
console.log(result);