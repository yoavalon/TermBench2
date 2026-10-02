<?php
function f($a, $b) {
    if ($a == 0) {
        return $b;
    }
    return f($a - 1, $b + $a);
}

function g($x) {
    return f($x, $x);
}

function h($y) {
    return g(h($y));
}
h(5);
?>