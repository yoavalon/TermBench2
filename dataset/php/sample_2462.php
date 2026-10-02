<?php
function f($x) {
    if ($x < 0) {
        return;
    }
    f($x - 1);
    echo $x . "\n";
}
f(5);
?>