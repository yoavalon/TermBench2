<?php
function track_sequence($n, $seq = array()) {
    if ($n == 0) {
        return $seq;
    }
    $seq[] = $n;
    return track_sequence($n - 1, $seq);
}

function main() {
    $result = track_sequence(5);
    print_r($result);
}

main();
?>