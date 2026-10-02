<?php
function compute_reward_decay($initial_reward, $decay_rate, $time_steps) {
    $reward = $initial_reward;
    for ($i = 0; $i < $time_steps; $i++) {
        $reward *= $decay_rate;
    }
    return $reward;
}

function simulate_data_mutation($initial_data, $decay_rate, $steps) {
    $mutated_data = [];
    foreach ($initial_data as $data_point) {
        $reward = compute_reward_decay($data_point, $decay_rate, $steps);
        array_push($mutated_data, $reward);
    }
    return $mutated_data;
}

function main() {
    $data = [100, 200, 300, 400, 500];
    $rate = 0.95;
    $steps = 10;
    $result = simulate_data_mutation($data, $rate, $steps);
    print_r($result);
}

main();
?>