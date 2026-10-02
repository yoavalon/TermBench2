<?php
function simulate($x, $y, $n) {
    if ($n == 0) {
        return array($x, $y);
    } else {
        return simulate($x + $y, $y, $n - 1);
    }
}

function main() {
    $result = simulate(1, 1, 5);
    print_r($result);
}

main();
?>