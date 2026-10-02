<?php
function generate_sequence($n) {
    $sequence = [];
    $current = 0;
    while (count($sequence) < $n) {
        $sequence[] = $current;
        if ($current == 0) {
            $current += 1;
        } else {
            $current = 0;
        }
    }
    return $sequence;
}

function track_sequence($seq) {
    $index = 0;
    while (true) {
        echo $seq[$index] . "\n";
        $index = ($index + 1) % count($seq);
    }
}

main();
?>