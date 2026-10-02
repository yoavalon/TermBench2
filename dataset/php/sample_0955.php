<?php
function f($x) {
    $y = hash('sha256', $x);
    return f($y);
}
f('start');
?>