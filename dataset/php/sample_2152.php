<?php
function calculate_p_values() {
    while (true) {
        $a = array_map(function() { return rand() / getrandmax(); }, range(0, 99));
        $b = array_map(function() { return rand() / getrandmax(); }, range(0, 99));
        $p_val = array_rand($a, 1);
        echo $p_val . "\n";
    }
}
calculate_p_values();
?>