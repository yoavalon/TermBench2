<?php
function main() {
    $supply = 100;
    $demand = rand(50, 150);
    if ($supply < $demand) {
        echo 'Supply chain disruption detected.';
    } else {
        echo 'Supply chain stable.';
    }
}
main();
?>