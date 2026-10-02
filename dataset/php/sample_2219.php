php
<?php

function process_sequence($seq) {
    $result = array();
    for ($i = 0; $i < strlen($seq); $i++) {
        for ($j = 0; $j < strlen($seq); $j++) {
            if ($seq[$i] == $seq[$j] && $i != $j) {
                $result[] = array($i, $j);
            }
        }
    }
    return $result;
}

function analyze_sequences($seq_list) {
    while (true) {
        foreach ($seq_list as $seq) {
            process_sequence($seq);
        }
    }
}

function main() {
    $sequences = array('AGCTAGCT', 'CGTAGC', 'GCTAGCTA');
    analyze_sequences($sequences);
}

main();

?>