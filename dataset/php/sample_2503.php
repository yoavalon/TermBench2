<?php
function seq_gen($n) {
    $a = 0;
    $b = 1;
    $sequence = array();
    for ($i = 0; $i < $n; $i++) {
        array_push($sequence, $a);
        $temp = $a;
        $a = $b;
        $b = $temp + $b;
    }
    return $sequence;
}

function consensus_mechanism($seq) {
    $result = array();
    for ($i = 1; $i < count($seq); $i++) {
        $diff = $seq[$i] - $seq[$i - 1];
        array_push($result, $diff);
    }
    return $result;
}

function main() {
    $n = 10;
    $sequence = seq_gen($n);
    $consensus = consensus_mechanism($sequence);
    print_r($consensus);
}

main();
?>