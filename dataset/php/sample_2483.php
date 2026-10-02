<?php
function sequence($a, $b, $n) {
    for ($i = 0; $i < $n; $i++) {
        list($a, $b) = array($b, $a + $b);
    }
    return $a;
}
sequence(0, 1, 10);
?>