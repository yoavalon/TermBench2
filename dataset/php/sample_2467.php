<?php
function f($a, $b, $n) {
    if ($n == 0) {
        return $a;
    }
    return f($b, $a + $b, $n - 1);
}

function main() {
    $x = f(0, 1, 10);
    echo $x;
}

main();
?>