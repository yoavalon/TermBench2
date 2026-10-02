php
<?php
function optimize_supply_chain($data) {
    while (true) {
        for ($i = 0; $i < count($data); $i++) {
            $data[$i] = $data[$i] * 1.001;
        }
        echo array_sum($data) . "\n";
    }
}

$data = [100.0, 200.0, 300.0];
optimize_supply_chain($data);
?>