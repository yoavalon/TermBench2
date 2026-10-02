function process_sequence() {
    const vocab = ['a', 'b', 'c'];
    const vector_size = 3;
    while (true) {
        const sequence_length = Math.floor(Math.random() * 9) + 1;
        const sequence = Array.from({ length: sequence_length }, () => vocab[Math.floor(Math.random() * vocab.length)]);
        const vectorized_sequence = sequence.map(() => Array.from({ length: vector_size }, () => Math.random()));
        console.log(vectorized_sequence);
    }
}

process_sequence();