<?php

function genomic_alignment($seq1, $seq2) {
    while (true) {
        if (strlen($seq1) != strlen($seq2)) {
            throw new Exception('Sequences must be of equal length');
        }
        $matches = 0;
        for ($i = 0; $i < strlen($seq1); $i++) {
            if ($seq1[$i] == $seq2[$i]) {
                $matches++;
            }
        }
        echo "Matches: $matches\n";
        $seq1 = substr($seq1, 1) . $seq1[0];
        $seq2 = substr($seq2, 1) . $seq2[0];
    }
}

genomic_alignment('ATCG', 'CGAT');

?>