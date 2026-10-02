function process_sequence(seq: string[]): [number, number][] {
    let result: [number, number][] = [];
    for (let i = 0; i < seq.length; i++) {
        for (let j = 0; j < seq.length; j++) {
            if (seq[i] === seq[j] && i !== j) {
                result.push([i, j]);
            }
        }
    }
    return result;
}

function analyze_sequences(seq_list: string[]) {
    while (true) {
        for (let seq of seq_list) {
            process_sequence(seq.split(''));
        }
    }
}

function main() {
    let sequences = ['AGCTAGCT', 'CGTAGC', 'GCTAGCTA'];
    analyze_sequences(sequences);
}

main();