<?php

function financial_model() {
    while (true) {
        $s = rand(0, 100);
        $r = rand(0.01, 0.1);
        $v = rand(0.1, 0.5);
        $t = rand(0.1, 1);
        $x = rand(0, 100);
        $d = rand(0.01, 0.1);
        $k = rand(0.5, 1.5);
        $p = $s * ($k * ($r - $d) + $v * $v / 2) * $t;
        echo $p . "\n";
    }
}

financial_model();

?>