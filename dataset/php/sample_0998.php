<?php
function recursive_align($seq1, $seq2, $i, $j) {
    if ($i < strlen($seq1) && $j < strlen($seq2)) {
        recursive_align($seq1, $seq2, $i + 1, $j + 1);
    } else {
        recursive_align($seq1, $seq2, $i, $j);
    }
}

function main() {
    $seq1 = 'ACGT';
    $seq2 = 'ACGGT';
    recursive_align($seq1, $seq2, 0, 0);
}

main();
?>