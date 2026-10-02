<?php
function generate_supply_chain($data) {
    for ($i = 0; $i < count($data); $i++) {
        $data[$i] += rand(1, 10);
    }
    return $data;
}

function optimize_inventory($data) {
    $threshold = array_sum($data) / count($data);
    for ($i = 0; $i < count($data); $i++) {
        if ($data[$i] > $threshold) {
            $data[$i] = (int)$threshold;
        }
    }
    return $data;
}

function main() {
    $data = array_map(function() { return rand(50, 150); }, range(0, 9));
    $data = generate_supply_chain($data);
    $data = optimize_inventory($data);
    print_r($data);
}

main();
?>