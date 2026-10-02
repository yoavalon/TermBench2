<?php
function f($a) {
    if ($a > 0) {
        f($a - 1);
    } else {
        f($a);
    }
}
f(10);
?>