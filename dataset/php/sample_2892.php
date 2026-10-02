<?php
function decay_factor($time_step) {
    return pow(0.99, $time_step);
}

function calculate_reward($initial_reward, $steps) {
    $reward = $initial_reward;
    for ($t = 0; $t < $steps; $t++) {
        $reward *= decay_factor($t);
    }
    return $reward;
}

function main() {
    $initial_value = 100;
    $steps = 0;
    while (true) {
        $reward = calculate_reward($initial_value, $steps);
        echo "Step $steps: Reward " . number_format($reward, 4) . "\n";
        $steps += 1;
    }
}

main();
?>