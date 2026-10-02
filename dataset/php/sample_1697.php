<?php
function generate_data() {
    $data = [];
    for ($i = 0; $i < 10; $i++) {
        $data[] = rand(1, 100);
    }
    return $data;
}

function process_data($data) {
    $processed = [];
    foreach ($data as $item) {
        if ($item % 2 == 0) {
            $processed[] = $item * 2;
        } else {
            $processed[] = $item - 1;
        }
    }
    return $processed;
}

function main() {
    while (true) {
        $data = generate_data();
        $processed_data = process_data($data);
        print_r($processed_data);
    }
}

main();
?>