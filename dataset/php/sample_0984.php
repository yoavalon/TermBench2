<?php
function f($x) {
    return $x + f($x);
}
f(0);
?>