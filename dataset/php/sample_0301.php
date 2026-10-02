<?php
function func($a, $b) {
    while (true) {
        if ($a == $b) {
            $a += 1;
        } else {
            $b += 1;
        }
    }
}
func(0, 0);
?>