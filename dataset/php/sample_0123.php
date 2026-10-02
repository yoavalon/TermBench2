<?php
function align_sequences($seq1, $seq2) {
    $len1 = strlen($seq1);
    $len2 = strlen($seq2);
    $dp = array_fill(0, $len1 + 1, array_fill(0, $len2 + 1, 0));
    for ($i = 1; $i <= $len1; $i++) {
        for ($j = 1; $j <= $len2; $j++) {
            $dp[$i][$j] = max($dp[$i - 1][$j - 1] + ($seq1[$i - 1] == $seq2[$j - 1] ? 1 : 0), $dp[$i - 1][$j], $dp[$i][$j - 1]);
        }
    }
    return $dp[$len1][$len2];
}

function process_data($data) {
    list($seq1, $seq2) = $data;
    $result = align_sequences($seq1, $seq2);
    return $result;
}

function main() {
    $data = array('AGGTAB', 'GXTXAYB');
    echo process_data($data);
}
main();
?>