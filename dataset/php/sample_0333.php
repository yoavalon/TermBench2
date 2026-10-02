<?php

function main() {
    function decay_reward($step) {
        return 1 / ($step + 1);
    }
    $step = 0;
    while (true) {
        echo decay_reward($step) . "\n";
        $step += 1;
    }
}

main();