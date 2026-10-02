<?php
function simulate($x, $y, $t) {
    if ($t == 0) {
        return;
    }
    for ($i = 0; $i < $x; $i++) {
        for ($j = 0; $j < $y; $j++) {
            if (($i + $j) % 2 == 0) {
                echo '*';
            } else {
                echo '.';
            }
        }
        echo "\n";
    }
    simulate($x, $y, $t - 1);
}
simulate(5, 5, 3);
?>