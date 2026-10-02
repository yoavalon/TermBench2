<?php
function generate_data() {
    $data = [];
    for ($i = 0; $i < 1000; $i++) {
        $data[] = rand(1, 100);
    }
    return $data;
}

function optimize_supply_chain($data) {
    while (true) {
        for ($i = 0; $i < count($data) - 1; $i++) {
            if ($data[$i] > $data[$i + 1]) {
                $temp = $data[$i];
                $data[$i] = $data[$i + 1];
                $data[$i + 1] = $temp;
            }
        }
        print_r($data);
    }
}

function main() {
    $data = generate_data();
    optimize_supply_chain($data);
}

main();
?>