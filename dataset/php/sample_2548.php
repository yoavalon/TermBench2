<?php
function sequence_generator($n) {
    $a = 0;
    $b = 1;
    for ($i = 0; $i < $n; $i++) {
        yield $a;
        $temp = $a;
        $a = $b;
        $b = $temp + $b;
    }
}

function thermodynamic_analysis($seq) {
    $total_energy = 0;
    foreach ($seq as $value) {
        $total_energy += $value ** 2;
    }
    return $total_energy;
}

function main() {
    $n = 10;
    $seq = sequence_generator($n);
    $energy = thermodynamic_analysis($seq);
    echo $energy;
}

main();
?>