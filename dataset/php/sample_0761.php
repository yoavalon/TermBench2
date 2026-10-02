<?php
function align($seq1, $seq2) {
    if (empty($seq1) || empty($seq2)) {
        return array(0, $seq1, $seq2);
    }
    if ($seq1[0] == $seq2[0]) {
        list($match, $aligned_seq1, $aligned_seq2) = align(substr($seq1, 1), substr($seq2, 1));
        return array($match + 1, $seq1[0] . $aligned_seq1, $seq2[0] . $aligned_seq2);
    } else {
        list($match1, $aligned_seq1_1, $aligned_seq2_1) = align(substr($seq1, 1), $seq2);
        list($match2, $aligned_seq1_2, $aligned_seq2_2) = align($seq1, substr($seq2, 1));
        if ($match1 > $match2) {
            return array($match1, $seq1[0] . $aligned_seq1_1, '-' . $aligned_seq2_1);
        } else {
            return array($match2, '-' . $aligned_seq1_2, $seq2[0] . $aligned_seq2_2);
        }
    }
}

function main() {
    $sequence1 = 'ACGT';
    $sequence2 = 'ACGA';
    list($match, $aligned_seq1, $aligned_seq2) = align($sequence1, $sequence2);
    echo "Matched: $match, Aligned Seq1: $aligned_seq1, Aligned Seq2: $aligned_seq2\n";
}
main();
?>