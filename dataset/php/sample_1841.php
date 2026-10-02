<?php

function process_text($data) {
    $vectors = array();
    foreach ($data as $text) {
        $vector = array();
        for ($i = 0; $i < 100; $i++) {
            $vector[] = mt_rand() / mt_getrandmax();
        }
        $vectors[] = $vector;
    }
    return $vectors;
}

function main() {
    $texts = array('hello', 'world', 'python', 'code');
    $vectors = process_text($texts);
    print_r($vectors);
}

main();

?>