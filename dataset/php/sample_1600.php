<?php
function process_data() {
    $text = 'Sample text for processing. It includes various words and punctuation!';
    $queue = new SplQueue();
    $queue->enqueue($text);
    while (!$queue->isEmpty()) {
        $item = $queue->dequeue();
        preg_match_all('/\b\w+\b/', $item, $matches);
        $tokens = $matches[0];
        print_r($tokens);
        foreach ($tokens as $token) {
            $queue->enqueue($token);
        }
    }
}
process_data();
?>