<?php

function simulate() {
    $state = array_fill(0, 50, array_fill(0, 50, rand(0, 1)));
    while (true) {
        $new_state = array_fill(0, 50, array_fill(0, 50, 0));
        for ($i = 1; $i < 49; $i++) {
            for ($j = 1; $j < 49; $j++) {
                $neighbors = 0;
                for ($ii = $i - 1; $ii <= $i + 1; $ii++) {
                    for ($jj = $j - 1; $jj <= $j + 1; $jj++) {
                        $neighbors += $state[$ii][$jj];
                    }
                }
                $neighbors -= $state[$i][$j];
                if ($state[$i][$j] && ($neighbors == 2 || $neighbors == 3)) {
                    $new_state[$i][$j] = 1;
                } elseif (!$state[$i][$j] && $neighbors == 3) {
                    $new_state[$i][$j] = 1;
                }
            }
        }
        $state = $new_state;
    }
}

simulate();

?>