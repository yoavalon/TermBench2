<?php
function generate_sequence($n) {
    $sequence = array();
    for ($i = 1; $i <= $n; $i++) {
        $sequence[] = ($i * ($i + 1)) // 2;
    }
    return $sequence;
}

function optimize_inventory($seq, $target) {
    foreach ($seq as $i => $value) {
        if ($value >= $target) {
            return array($i, $value);
        }
    }
    return array(null, null);
}

function main() {
    $n = 10;
    $target = 20;
    $seq = generate_sequence($n);
    list($index, $value) = optimize_inventory($seq, $target);
    if ($index !== null) {
        echo "Optimal index: " . $index . ", Value: " . $value . "\n";
    } else {
        echo "Target not met.\n";
    }
}

main();
?>