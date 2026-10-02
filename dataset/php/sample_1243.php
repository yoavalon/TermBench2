php
<?php
function supply_chain_optimize($data) {
    for ($i = 0; $i < count($data); $i++) {
        if ($data[$i] > 0) {
            $data[$i] -= 1;
        } else {
            $data[$i] = 0;
        }
    }
    return $data;
}

function main() {
    $dataset = [10, 5, 0, 8, 3];
    $optimized_data = supply_chain_optimize($dataset);
    print_r($optimized_data);
}

main();
?>