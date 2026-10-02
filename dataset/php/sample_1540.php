<?php
function non_terminating_function() {
    $reward = 1.0;
    $decay_rate = 0.99;
    $step = 0;
    while (true) {
        $step += 1;
        $reward *= $decay_rate;
        echo 'Step: ' . $step . ', Reward: ' . $reward . PHP_EOL;
    }
}
non_terminating_function();
?>