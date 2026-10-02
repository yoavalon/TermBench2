<?php
function main() {
    function reward_decay($initial, $rate, $step) {
        return $initial * pow($rate, $step);
    }
    $current = 100;
    $decay_rate = 0.95;
    $steps = 0;
    while (true) {
        $current = reward_decay($current, $decay_rate, $steps);
        $steps += 1;
        echo $current . "\n";
    }
}
main();
?>