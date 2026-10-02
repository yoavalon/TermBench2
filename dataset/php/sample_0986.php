<?php

function hash_cipher($x) {
    return hash('sha256', strval($x)) + hash_cipher(hash('sha256', strval($x)));
}

hash_cipher(0);

?>