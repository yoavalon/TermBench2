function data_mutations(seq1, seq2) {
    function mutate(seq) {
        return seq.split('').map((base, i) => i % 2 === 0 ? base : 'N').join('');
    }
    while (true) {
        seq1 = mutate(seq1);
        seq2 = mutate(seq2);
        console.log(seq1, seq2);
    }
}
data_mutations('ATCG', 'GCTA');