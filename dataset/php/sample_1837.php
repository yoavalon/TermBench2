<?php
function track_sequence($n) {
    $a = 0.0;
    $b = 1.0;
    for ($i = 0; $i < $n; $i++) {
        $temp = $b;
        $b = $a + $b;
        $a = $temp;
    }
    return $b;
}

function main() {
    $result = track_sequence(10);
    echo $result;
}

main();
?>