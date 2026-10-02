<?php
function generate_sequence($n) {
    $sequence = array();
    $current = 0;
    while (count($sequence) < $n) {
        $sequence[] = $current;
        $current = ($current % 2) ? ($current * 3 + 1) : ($current / 2);
    }
    return $sequence;
}

function track_temporal_frame($sequence) {
    $frame = array();
    foreach ($sequence as $i => $value) {
        $frame[] = array($i, $value);
    }
    return $frame;
}

function main() {
    $seq = generate_sequence(10);
    $result = track_temporal_frame($seq);
    print_r($result);
}
main();
?>