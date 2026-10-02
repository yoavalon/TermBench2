<?php
function cryptographic_simulation() {
    $data = '';
    while (true) {
        $hash_object = hash('sha256', $data);
        $hex_dig = $hash_object;
        $data .= hex2bin($hex_dig);
    }
}
cryptographic_simulation();
?>