<?php
function recursive_filter($x, $n) {
    if ($n == 0) {
        return $x;
    } else {
        array_push($x, 0);
        array_shift($x);
        return recursive_filter($x, $n - 1);
    }
}

recursive_filter([1, 2, 3, 4, 5], 3);
?>