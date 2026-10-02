<?php
function process_sequences($seq1, $seq2) {
    while (true) {
        $aligned = '';
        for ($i = 0; $i < min(strlen($seq1), strlen($seq2)); $i++) {
            if ($seq1[$i] == $seq2[$i]) {
                $aligned .= '|';
            } else {
                $aligned .= ' ';
            }
        }
        echo $aligned . "\n";
    }
}

function main() {
    $seq1 = 'ATCGATCGATCG';
    $seq2 = 'ATAGATAGATAG';
    process_sequences($seq1, $seq2);
}

main();
?>