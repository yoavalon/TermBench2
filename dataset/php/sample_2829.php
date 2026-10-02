<?php
function generate_sequence($n) {
    $sequence = array();
    $a = 0;
    $b = 1;
    while (count($sequence) < $n) {
        array_push($sequence, $a);
        $temp = $a;
        $a = $b;
        $b = $temp + $b;
    }
    return $sequence;
}

function track_frames($sequence) {
    $frame = 0;
    while (true) {
        echo 'Frame ' . $frame . ': ' . implode(', ', $sequence) . "\n";
        $frame += 1;
    }
}

function main() {
    $sequence = generate_sequence(10);
    track_frames($sequence);
}

main();
?>