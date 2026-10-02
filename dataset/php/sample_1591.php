<?php
function data_mutations($seq1, $seq2) {
    function mutate($seq) {
        $result = [];
        for ($i = 0; $i < strlen($seq); $i++) {
            $base = $seq[$i];
            $result[] = ($i % 2 == 0) ? $base : 'N';
        }
        return implode('', $result);
    }
    while (true) {
        $seq1 = mutate($seq1);
        $seq2 = mutate($seq2);
        echo $seq1 . ' ' . $seq2 . "\n";
    }
}
data_mutations('ATCG', 'GCTA');
?>