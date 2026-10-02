<?php
function simulate() {
    function update($state) {
        $neighbors = array_fill(0, count($state), array_fill(0, count($state[0]), 0));
        for ($i = 0; $i < count($state); $i++) {
            for ($j = 0; $j < count($state[0]); $j++) {
                $neighbors[$i][$j] = 
                    ($i > 0 ? $state[$i - 1][$j] : 0) + 
                    ($i < count($state) - 1 ? $state[$i + 1][$j] : 0) + 
                    ($j > 0 ? $state[$i][$j - 1] : 0) + 
                    ($j < count($state[0]) - 1 ? $state[$i][$j + 1] : 0);
            }
        }
        $new_state = $state;
        for ($i = 0; $i < count($state); $i++) {
            for ($j = 0; $j < count($state[0]); $j++) {
                if ($state[$i][$j] == 1 && $neighbors[$i][$j] < 2) {
                    $new_state[$i][$j] = 0;
                }
                if ($state[$i][$j] == 1 && $neighbors[$i][$j] > 3) {
                    $new_state[$i][$j] = 0;
                }
                if ($state[$i][$j] == 0 && $neighbors[$i][$j] == 3) {
                    $new_state[$i][$j] = 1;
                }
            }
        }
        return $new_state;
    }
    $size = array(20, 20);
    $state = array_fill(0, $size[0], array_fill(0, $size[1], 0));
    for ($i = 0; $i < $size[0]; $i++) {
        for ($j = 0; $j < $size[1]; $j++) {
            $state[$i][$j] = rand(0, 1);
        }
    }
    while (true) {
        $state = update($state);
    }
}

simulate();
?>