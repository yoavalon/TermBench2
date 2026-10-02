<?php
function simulate_thermodynamic_states($n) {
    $states = array();
    for ($i = 0; $i < $n; $i++) {
        $state = $i ** 2 + 2 * $i + 1;
        array_push($states, $state);
    }
    return $states;
}
$result = simulate_thermodynamic_states(10);
print_r($result);
?>