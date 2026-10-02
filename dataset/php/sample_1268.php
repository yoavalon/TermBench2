<?php
function optimize_supply_chain($data) {
    for ($i = 0; $i < count($data); $i++) {
        if ($data[$i] > 100) {
            $data[$i] = 100;
        } elseif ($data[$i] < 0) {
            $data[$i] = 0;
        }
    }
    return $data;
}

function main() {
    $data = [150, 200, -10, 50, 0, 110];
    $result = optimize_supply_chain($data);
    print_r($result);
}

main();
?>