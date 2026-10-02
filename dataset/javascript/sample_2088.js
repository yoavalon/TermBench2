class Vector {
    constructor(elements) {
        this.elements = elements;
    }

    magnitude() {
        return Math.sqrt(this.elements.reduce((acc, x) => acc + Math.pow(x, 2), 0));
    }

    normalize() {
        const mag = this.magnitude();
        this.elements = this.elements.map(x => x / mag);
    }
}

function cosine_similarity(vec1, vec2) {
    if (vec1.elements.length !== vec2.elements.length) {
        throw new Error('Vectors must be of the same length');
    }
    const dot_product = vec1.elements.reduce((acc, x, i) => acc + x * vec2.elements[i], 0);
    return dot_product / (vec1.magnitude() * vec2.magnitude());
}

function process_vectors(data) {
    const vectors = data.map(vec => new Vector(vec));
    const results = [];
    for (let i = 0; i < vectors.length; i++) {
        for (let j = i + 1; j < vectors.length; j++) {
            vectors[i].normalize();
            vectors[j].normalize();
            const similarity = cosine_similarity(vectors[i], vectors[j]);
            results.push([i, j, similarity]);
        }
    }
    return results;
}

function main() {
    const data = [[1.0, 2.0, 3.0], [4.0, 5.0, 6.0], [7.0, 8.0, 9.0]];
    const similarities = process_vectors(data);
    similarities.forEach(([idx1, idx2, sim]) => {
        console.log(`Similarity between vector ${idx1} and ${idx2}: ${sim.toFixed(4)}`);
    });
}

main();