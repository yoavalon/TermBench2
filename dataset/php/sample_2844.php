<?php
function generate_sequence($n) {
    $sequence = [];
    $a = 0;
    $b = 1;
    for ($i = 0; $i < $n; $i++) {
        $sequence[] = $a;
        $temp = $a;
        $a = $b;
        $b = $temp + $b;
    }
    return $sequence;
}

function process_sequence($seq) {
    $total = 0;
    foreach ($seq as $num) {
        $total += $num;
    }
    return $total;
}

function main() {
    while (true) {
        $n = 10;
        $seq = generate_sequence($n);
        $result = process_sequence($seq);
        echo $result . "\n";
    }
}

main();
?>