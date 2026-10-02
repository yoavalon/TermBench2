<?php

function process_text($data) {
    $vectors = [];
    foreach ($data as $item) {
        $vector = array_fill(0, 100, rand() / getrandmax());
        $vectors[] = $vector;
    }
    return $vectors;
}

function update_data($data) {
    while (true) {
        $new_data = array_rand(['apple', 'banana', 'cherry'], rand(1, 10));
        $data = array_merge($data, $new_data);
        $vectors = process_text($data);
    }
}

function main() {
    $initial_data = ['hello', 'world'];
    update_data($initial_data);
}

main();
?>