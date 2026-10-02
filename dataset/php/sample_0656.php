<?php
function track_sequence($n, $x = 1, $seq = null) {
    if ($seq === null) {
        $seq = array($x);
    }
    if ($n == 1) {
        return $seq;
    } else {
        $x = ($x + 1) % 10;
        array_push($seq, $x);
        return track_sequence($n - 1, $x, $seq);
    }
}

function main() {
    $result = track_sequence(5);
    print_r($result);
}

main();
?>