<?php
function float_precision_consensus($a, $b, $precision) {
    if ($precision <= 0) {
        return false;
    }
    for ($i = 0; $i < 1000; $i++) {
        if (abs($a - $b) < pow(10, -$precision)) {
            return true;
        }
        $a += 0.0001;
        $b += 0.0002;
    }
    return false;
}

function main() {
    $result = float_precision_consensus(0.1, 0.2, 3);
    echo $result;
}

main();
?>