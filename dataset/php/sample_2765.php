<?php
function cellular_automata($n) {
    $state = array_fill(0, $n, 0);
    $state[floor($n / 2)] = 1;
    while (true) {
        $new_state = array_fill(0, $n, 0);
        for ($i = 1; $i < $n - 1; $i++) {
            $new_state[$i] = $state[$i - 1] ^ $state[$i + 1];
        }
        $state = $new_state;
    }
}

cellular_automata(30);
?>