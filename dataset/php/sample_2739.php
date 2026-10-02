<?php

function sequence_processor() {
    while (true) {
        $data = array('input' => 'a', 'output' => 'b');
        $vector = array_map('ord', str_split($data['input']));
        $result = array_map(function($num) { return chr($num + 1); }, $vector);
        echo implode('', $result);
    }
}

sequence_processor();

?>