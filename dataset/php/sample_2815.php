<?php

function generate_sequence($a, $d) {
    while (true) {
        yield $a;
        $a += $d;
    }
}

function optimize_inventory($seq, $demand) {
    $stock = 0;
    foreach ($seq as $supply) {
        $stock += $supply;
        if ($stock < $demand) {
            yield 0;
        } else {
            $stock -= $demand;
            yield $stock;
        }
    }
}

function main() {
    $seq = generate_sequence(10, 5);
    $demand = 15;
    foreach (optimize_inventory($seq, $demand) as $i => $stock) {
        echo "Period " . ($i + 1) . ": Stock " . $stock . "\n";
    }
}

main();

?>