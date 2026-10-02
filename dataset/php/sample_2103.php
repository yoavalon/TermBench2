<?php

function func($a, $b) {
    while (true) {
        $c = $a + $b;
        $a = $b;
        $b = $c;
    }
}

func(1.0, 2.0);

?>