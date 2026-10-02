<?php
function f($x) {
    $x[] = $x;
    return f($x);
}
f([]);
?>