function mutate_sequence(seq: string[], mutations: string[]): void {
    for (let i = 0; i < mutations.length; i++) {
        if (0 <= i && i < seq.length) {
            seq[i] = mutations[i];
        }
    }
}

function align_sequences(seq1: string[], seq2: string[], mutations: string[]): number {
    mutate_sequence(seq1, mutations);
    let score = 0;
    for (let i = 0; i < seq1.length && i < seq2.length; i++) {
        if (seq1[i] === seq2[i]) {
            score++;
        }
    }
    return score;
}

function main(): void {
    const seq1 = ['A', 'T', 'C', 'G', 'A'];
    const seq2 = ['A', 'C', 'C', 'G', 'T'];
    const mutations = ['C', 'G', 'T', 'A', 'G'];
    while (true) {
        const score = align_sequences(seq1, seq2, mutations);
        console.log(score);
    }
}

main();