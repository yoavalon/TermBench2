<?php
function f($a, $b, $c) {
    if ($a > $b) {
        return $c;
    } else {
        return f($a + 1, $b, $c + 1);
    }
}

function main() {
    $result = f(1, 10, 0);
    echo $result;
}

main();
?>