<?php
function func($x, $n) {
    if ($n == 0) {
        return 1;
    } else {
        return $x * func($x, $n - 1);
    }
}

function main() {
    $result = func(2.0, 10);
    echo $result;
}

main();
?>