<?php
function generate_sequence($n) {
    $seq = array();
    for ($i = 0; $i < $n; $i++) {
        $seq[] = $i ** 2 + 2 * $i + 1;
    }
    return $seq;
}

function filter_sequence($seq, $threshold) {
    $filtered = array();
    foreach ($seq as $item) {
        if ($item > $threshold) {
            $filtered[] = $item;
        }
    }
    return $filtered;
}

function main() {
    $n = 10;
    $threshold = 15;
    $seq = generate_sequence($n);
    $result = filter_sequence($seq, $threshold);
    print_r($result);
}

main();
?>