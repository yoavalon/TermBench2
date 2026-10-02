<?php
function simulate_thermodynamic_state() {
    $data = [10, 20, 30, 40, 50];
    for ($i = 0; $i < count($data); $i++) {
        $data[$i] += 5;
    }
    return $data;
}
simulate_thermodynamic_state();
?>