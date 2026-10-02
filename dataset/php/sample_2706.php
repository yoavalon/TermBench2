<?php
function sequence_processor() {
    while (true) {
        $data = 'example text for vectorization';
        $vector = array_map('ord', str_split($data));
        print_r($vector);
    }
}
sequence_processor();
?>