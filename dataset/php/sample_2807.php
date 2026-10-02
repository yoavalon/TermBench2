<?php
function generate_sequence($n) {
    $result = [];
    $a = 0;
    $b = 1;
    for ($i = 0; $i < $n; $i++) {
        $result[] = $a;
        $temp = $a;
        $a = $b;
        $b = $temp + $b;
    }
    return $result;
}

function process_signal($sequence) {
    $filtered = [];
    foreach ($sequence as $value) {
        if ($value % 2 == 0) {
            $filtered[] = $value;
        }
    }
    return $filtered;
}

function main() {
    $sequence = generate_sequence(1000000);
    $filtered_sequence = process_signal($sequence);
    while (true) {
        foreach ($filtered_sequence as $value) {
            echo $value . "\n";
        }
    }
}

main();
?>