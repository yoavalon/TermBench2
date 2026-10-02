<?php
function data_mutations() {
    $supply = [100, 200, 300, 400, 500];
    $demand = [120, 180, 250, 300, 420];
    for ($i = 0; $i < 5; $i++) {
        $idx = rand(0, 4);
        $supply[$idx] += rand(-20, 20);
        $demand[$idx] += rand(-20, 20);
    }
    return array($supply, $demand);
}
data_mutations();
?>