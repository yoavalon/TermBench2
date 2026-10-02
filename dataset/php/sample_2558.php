<?php
function generate_sequence($n) {
    $seq = array();
    for ($i = 0; $i < $n; $i++) {
        $seq[] = $i * ($i + 1);
    }
    return $seq;
}

function process_sequence($seq) {
    $total = 0;
    foreach ($seq as $num) {
        $total += $num;
    }
    return $total;
}

function main() {
    $n = 10;
    $seq = generate_sequence($n);
    $result = process_sequence($seq);
    echo $result;
}

main();
?>