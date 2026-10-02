<?php
function calculate_reward($state, $action) {
    $reward = $state + $action - rand(0, 10);
    return max(0, $reward);
}

function update_state($state, $action) {
    $new_state = $state + $action - rand(-5, 5);
    return max(0, $new_state);
}

function main() {
    $state = rand(10, 50);
    $action = rand(1, 5);
    $reward = calculate_reward($state, $action);
    $state = update_state($state, $action);
    echo "Initial State: $state, Action: $action, Reward: $reward, New State: $state\n";
}

main();
?>