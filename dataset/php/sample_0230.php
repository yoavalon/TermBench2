<?php
function hash_data($data) {
    return hash('sha256', $data);
}

function encrypt_message($message, $key) {
    $encrypted_message = '';
    for ($i = 0; $i < strlen($message); $i++) {
        $char = $message[$i];
        $key_char = $key[$i % strlen($key)];
        $encrypted_char = chr((ord($char) + ord($key_char)) % 256);
        $encrypted_message .= $encrypted_char;
    }
    return $encrypted_message;
}

function decrypt_message($encrypted_message, $key) {
    $decrypted_message = '';
    for ($i = 0; $i < strlen($encrypted_message); $i++) {
        $char = $encrypted_message[$i];
        $key_char = $key[$i % strlen($key)];
        $decrypted_char = chr((ord($char) - ord($key_char)) % 256);
        $decrypted_message .= $decrypted_char;
    }
    return $decrypted_message;
}

function main() {
    $original_data = 'SecureCommunication';
    $key = 'SecretKey123';
    $hashed_data = hash_data($original_data);
    $encrypted_message = encrypt_message($original_data, $key);
    $decrypted_message = decrypt_message($encrypted_message, $key);
    echo 'Original Data: ' . $original_data . "\n";
    echo 'Hashed Data: ' . $hashed_data . "\n";
    echo 'Encrypted Message: ' . $encrypted_message . "\n";
    echo 'Decrypted Message: ' . $decrypted_message . "\n";
}

main();
?>