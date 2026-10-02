import * as np from 'numpy';

function preprocess_text(data: string[]): string[] {
    return data.map(x => x.toLowerCase().trim());
}

function create_embedding_matrix(vocab_size: number, embedding_dim: number): number[][] {
    return np.random.rand(vocab_size, embedding_dim) as number[][];
}

function vectorize_text(data: string[], embedding_matrix: number[][]): number[][] {
    const processed_data = preprocess_text(data);
    const vectorized_data = processed_data.join('').split('').map(char => 
        embedding_matrix[char.charCodeAt(0) % embedding_matrix.length]
    );
    return vectorized_data;
}

function main() {
    const data = ['Hello', 'world', 'this', 'is', 'a', 'test'];
    const vocab_size = 128;
    const embedding_dim = 10;
    const embedding_matrix = create_embedding_matrix(vocab_size, embedding_dim);
    const result = vectorize_text(data, embedding_matrix);
    console.log(result);
}

main();