<?php
function generate_sequence($n) {
    function decay_reward($x) {
        return $x > 0 ? $x * 0.95 : 0;
    }
    $sequence = [1];
    for ($i = 1; $i < $n; $i++) {
        $sequence[] = decay_reward($sequence[$i - 1]);
    }
    return $sequence;
}
if (__FILE__ == $_SERVER['SCRIPT_FILENAME']) {
    print_r(generate_sequence(10));
}
?>