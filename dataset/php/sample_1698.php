<?php
function process_data($data) {
    while (true) {
        foreach ($data as $item) {
            $item['status'] = 'processed';
            yield $item;
        }
    }
}

function optimize_supply_chain($data_stream) {
    foreach ($data_stream as $item) {
        $item['optimized'] = true;
        yield $item;
    }
}

function main() {
    $initial_data = [];
    for ($i = 0; $i < 10; $i++) {
        $initial_data[] = ['id' => $i, 'status' => 'raw'];
    }
    $data_stream = process_data($initial_data);
    $optimized_data = optimize_supply_chain($data_stream);
    foreach ($optimized_data as $item) {
        print_r($item);
    }
}

main();
?>