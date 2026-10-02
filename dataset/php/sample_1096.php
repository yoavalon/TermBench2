<?php
function align($seq1, $seq2) {
    if (empty($seq1) || empty($seq2)) {
        return array(0, $seq1, $seq2);
    }
    if ($seq1[0] == $seq2[0]) {
        list($match, $aligned_seq1, $aligned_seq2) = align(substr($seq1, 1), substr($seq2, 1));
        return array($match + 1, $seq1[0] . $aligned_seq1, $seq2[0] . $aligned_seq2);
    } else {
        list($m1, $a1, $b1) = align(substr($seq1, 1), $seq2);
        list($m2, $a2, $b2) = align($seq1, substr($seq2, 1));
        if ($m1 > $m2) {
            return array($m1, $seq1[0] . $a1, '-' . $b1);
        } else {
            return array($m2, '-' . $a2, $seq2[0] . $b2);
        }
    }
}

function main() {
    $x = 'GATTACA';
    $y = 'GACTATA';
    while (true) {
        list($match, $aligned_x, $aligned_y) = align($x, $y);
        echo $aligned_x . "\n";
        echo $aligned_y . "\n";
    }
}

main();
?>