class Vectorizer {
    constructor(data) {
        this.data = data;
    }

    preprocess() {
        return this.data.map(x => x.toLowerCase().trim());
    }

    vectorize(processed_data) {
        return processed_data.map(x => parseFloat(x));
    }
}

class Processor {
    constructor(vectors) {
        this.vectors = vectors;
    }

    normalize(vectors) {
        const norms = vectors.map(v => Math.sqrt(v.reduce((a, b) => a + b * b, 0)));
        return vectors.map((v, i) => v.map(x => x / norms[i]));
    }

    reduce_dimensionality(normalized_vectors) {
        const { u, s, vh } = this.svd(normalized_vectors);
        const reduced_vectors = u.map(row => row.slice(0, 2)).map((row, i) => row.map(x => x * s[i]));
        return reduced_vectors;
    }

    svd(matrix) {
        const { rows, cols } = this.getMatrixDimensions(matrix);
        const u = Array(rows).fill().map(() => Array(cols).fill(0));
        const s = Array(cols).fill(0);
        const vh = Array(cols).fill().map(() => Array(rows).fill(0));

        for (let k = 0; k < cols; k++) {
            let vk = matrix[k].slice();
            for (let j = 0; j < k; j++) {
                const uj = u[j];
                const sj = s[j];
                const alpha = vk.reduce((sum, x, i) => sum + uj[i] * x, 0);
                vk = vk.map((x, i) => x - alpha * uj[i]);
            }
            s[k] = Math.sqrt(vk.reduce((sum, x) => sum + x * x, 0));
            vk = vk.map(x => x / s[k]);
            u[k] = vk;
            for (let i = 0; i < rows; i++) {
                const sum = vk.reduce((sum, x, j) => sum + x * matrix[i][j], 0);
                vh[i][k] = sum;
            }
        }

        return { u, s, vh };
    }

    getMatrixDimensions(matrix) {
        return { rows: matrix.length, cols: matrix[0].length };
    }
}

class Analyzer {
    constructor(reduced_vectors) {
        this.vectors = reduced_vectors;
    }

    analyze() {
        const means = this.vectors[0].map((_, i) => this.vectors.reduce((sum, vec) => sum + vec[i], 0) / this.vectors.length);
        const variances = this.vectors[0].map((_, i) => this.vectors.reduce((sum, vec) => sum + Math.pow(vec[i] - means[i], 2), 0) / this.vectors.length);
        return [means, variances];
    }
}

function main() {
    const data = ['Example text', 'Another piece of text', 'Yet more text data'];
    const vectorizer = new Vectorizer(data);
    const processed_data = vectorizer.preprocess();
    const vectors = vectorizer.vectorize(processed_data);
    const processor = new Processor(vectors);
    const normalized_vectors = processor.normalize(vectors);
    const reduced_vectors = processor.reduce_dimensionality(normalized_vectors);
    const analyzer = new Analyzer(reduced_vectors);
    const [means, variances] = analyzer.analyze();
    console.log('Means:', means);
    console.log('Variances:', variances);
}

main();