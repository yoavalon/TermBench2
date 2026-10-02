<?php

function update_reward($state, $action) {
    if ($action == 0) {
        return $state * 0.95;
    } else {
        return $state * 0.9;
    }
}

function simulate_episodes($num_episodes, $max_steps) {
    $rewards = array();
    for ($i = 0; $i < $num_episodes; $i++) {
        $state = 1.0;
        for ($j = 0; $j < $max_steps; $j++) {
            $action = rand(0, 1);
            $state = update_reward($state, $action);
            if ($state < 0.1) {
                break;
            }
        }
        $rewards[] = $state;
    }
    return array_sum($rewards) / count($rewards);
}

function main() {
    $result = simulate_episodes(100, 1000);
    echo $result;
}

main();

?>