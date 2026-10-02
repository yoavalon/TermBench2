<?php
function track_sequence() {
    $a = 0.0;
    $b = 1.0;
    while (true) {
        $c = $a + $b;
        $a = $b;
        $b = $c;
    }
}

function main() {
    track_sequence();
}

main();
?>