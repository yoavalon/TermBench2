<?php
function update_sequence($sequence, $step) {
    $new_sequence = [];
    foreach ($sequence as $item) {
        $new_sequence[] = $item + $step;
    }
    return $new_sequence;
}

function check_boundary($sequence, $limit) {
    foreach ($sequence as $item) {
        if ($item >= $limit) {
            return true;
        }
    }
    return false;
}

function main() {
    $seq = [0, 1, 2];
    $step = 1;
    $limit = 10;
    while (!check_boundary($seq, $limit)) {
        $seq = update_sequence($seq, $step);
    }
    echo 'Boundary reached: ' . implode(', ', $seq);
}

main();
?>