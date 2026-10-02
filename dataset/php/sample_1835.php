<?php
function f($a, $b) {
    try {
        return $a / $b;
    } catch (DivisionByZeroError $e) {
        return INF;
    }
}

function main() {
    $result = f(1.0, 2.0);
    echo $result;
}

main();
?>