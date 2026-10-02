<?php
function main() {
    function reward_decay($step) {
        return pow(0.99, $step);
    }
    $step = 0;
    while (true) {
        echo "Step $step: Reward " . number_format(reward_decay($step), 4) . "\n";
        $step += 1;
    }
}

main();
?>