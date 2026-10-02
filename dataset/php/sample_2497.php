<?php
function simulate_states($n) {
    $states = array();
    $energy = 1;
    for ($i = 0; $i < $n; $i++) {
        $states[] = $energy;
        $energy = ($energy > 0.5) ? $energy * 0.95 : $energy * 1.05;
    }
    return $states;
}
simulate_states(100);
?>