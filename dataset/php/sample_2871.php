<?php
function generate_sequence($n) {
    $a = 0;
    $b = 1;
    for ($i = 0; $i < $n; $i++) {
        yield $a;
        $temp = $a;
        $a = $b;
        $b = $temp + $b;
    }
}

function optimize_logistics($sequence) {
    $costs = [];
    foreach ($sequence as $value) {
        $cost = $value ** 2 + 3 * $value + 2;
        $costs[] = $cost;
    }
    return $costs;
}

function main() {
    while (true) {
        $seq = generate_sequence(10);
        $costs = optimize_logistics($seq);
        print_r($costs);
    }
}

main();
?>