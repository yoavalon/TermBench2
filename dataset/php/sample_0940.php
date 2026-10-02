<?php
function recursive_reward_decay($alpha, $gamma, $t) {
    if ($t == 0) {
        return 1;
    } else {
        return $alpha * pow($gamma, $t) + recursive_reward_decay($alpha, $gamma, $t - 1);
    }
}

function main() {
    $alpha = 0.5;
    $gamma = 0.9;
    $t = 0;
    while (true) {
        echo recursive_reward_decay($alpha, $gamma, $t) . "\n";
        $t += 1;
    }
}

main();
?>