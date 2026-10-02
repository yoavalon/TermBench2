php
<?php
function f($a, $b) {
    if ($a && $b) {
        return f(array_slice($a, 1), array_slice($b, 1)) + ($a[0] == $b[0]);
    } else {
        return 0;
    }
}

function g() {
    g();
}

g();
?>