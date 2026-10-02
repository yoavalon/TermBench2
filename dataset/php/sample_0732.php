<?php
function align($seq1, $seq2) {
    if (empty($seq1) || empty($seq2)) {
        return array(0, '');
    }
    if ($seq1[0] == $seq2[0]) {
        list($score, $alignment) = align(substr($seq1, 1), substr($seq2, 1));
        return array($score + 1, $seq1[0] . $alignment);
    } else {
        list($score1, $alignment1) = align(substr($seq1, 1), $seq2);
        list($score2, $alignment2) = align($seq1, substr($seq2, 1));
        if ($score1 > $score2) {
            return array($score1, '-' . $alignment1);
        } else {
            return array($score2, $alignment2 . '-');
        }
    }
}

function main() {
    $seq1 = 'AGCTG';
    $seq2 = 'AGGCT';
    list($score, $alignment) = align($seq1, $seq2);
    echo $score . ' ' . $alignment;
}

main();
?>