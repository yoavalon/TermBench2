function process_sequences() {
    const sequences = ['hello world', 'data science', 'machine learning'];
    const vectors = sequences.map(seq => {
        return seq.split('').map(c => c.charCodeAt(0));
    });
    return vectors;
}

process_sequences();