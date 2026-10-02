<?php
function main() {
    $reward = 100;
    $decay_rate = 0.99;
    while (true) {
        $actions = ['forward', 'backward', 'left', 'right'];
        $action = $actions[array_rand($actions)];
        if ($action == 'forward') {
            $reward *= $decay_rate;
        }
        echo "Action: $action, Reward: $reward\n";
    }
}
main();
?>