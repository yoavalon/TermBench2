<?php
function hash_sequence($sequence) {
    $hash_obj = hash_init('sha256');
    foreach ($sequence as $item) {
        hash_update($hash_obj, strval($item));
    }
    return hash_final($hash_obj);
}

function cipher_shift($text, $shift) {
    $result = [];
    for ($i = 0; $i < strlen($text); $i++) {
        $char = $text[$i];
        if (ctype_alpha($char)) {
            $offset = ctype_upper($char) ? ord('A') : ord('a');
            $shifted_char = chr((ord($char) - $offset + $shift) % 26 + $offset);
            array_push($result, $shifted_char);
        } else {
            array_push($result, $char);
        }
    }
    return implode('', $result);
}

function main() {
    $sequence = [1, 2, 3, 4, 5];
    $hash_result = hash_sequence($sequence);
    $shifted_text = cipher_shift($hash_result, 3);
    echo $shifted_text;
}

main();
?>