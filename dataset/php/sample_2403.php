<?php
function sequence($a, $b, $n) {
    if ($n == 0) {
        return $a;
    } elseif ($n == 1) {
        return $b;
    } else {
        return sequence($b, $a + $b, $n - 1);
    }
}

function main() {
    $a = 0;
    $b = 1;
    $n = 10;
    $result = sequence($a, $b, $n);
    echo $result;
}

main();
?>