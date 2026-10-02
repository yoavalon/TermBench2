<?php
function main() {
    $gamma = 0.99;
    $rewards = [100, 50, 25, 10, 5];
    $state_value = 0;
    foreach ($rewards as $r) {
        $state_value = $gamma * $state_value + $r;
    }
    echo $state_value;
}
main();
?>