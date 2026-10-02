<?php
function recursive_filter($x, $n) {
    if ($n == 0) {
        return $x;
    }
    return recursive_filter($x + 1, $n - 1);
}

recursive_filter(0, 5);
?>