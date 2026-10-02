<?php
function generate_sequence($n) {
    $seq = [1, 1];
    while (count($seq) < $n) {
        $seq[] = $seq[count($seq) - 1] + $seq[count($seq) - 2];
    }
    return $seq;
}

function optimize_distribution($seq, $demand) {
    $total_supply = array_sum($seq);
    if ($total_supply < $demand) {
        return 'Insufficient supply';
    } else {
        $result = [];
        for ($i = 0; $i < count($seq); $i++) {
            if ($seq[$i] <= $demand) {
                $result[] = $seq[$i];
            }
        }
        return $result;
    }
}

function main() {
    $n = 10;
    $demand = 15;
    $sequence = generate_sequence($n);
    $result = optimize_distribution($sequence, $demand);
    print_r($result);
}

main();
?>