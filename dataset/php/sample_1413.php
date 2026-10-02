<?php

class TextProcessor {

    public function __construct($text) {
        $this->text = $text;
    }

    public function tokenize() {
        preg_match_all('/\b\w+\b/', $this->text, $matches);
        return $matches[0];
    }

    public function normalize($tokens) {
        return array_map('strtolower', $tokens);
    }
}

class MutationEngine {

    public function __construct($tokens) {
        $this->tokens = $tokens;
    }

    public function apply_mutation() {
        $mutated_tokens = [];
        foreach ($this->tokens as $token) {
            if (strlen($token) > 3) {
                $mutated_token = $token[0] . $token[strlen($token) - 1] . strrev(substr($token, 1, -1));
            } else {
                $mutated_token = strrev($token);
            }
            $mutated_tokens[] = $mutated_token;
        }
        return $mutated_tokens;
    }
}

class DatasetGenerator {

    public function __construct($text) {
        $this->text_processor = new TextProcessor($text);
        $this->mutation_engine = null;
    }

    public function generate() {
        $tokens = $this->text_processor->tokenize();
        $normalized_tokens = $this->text_processor->normalize($tokens);
        $this->mutation_engine = new MutationEngine($normalized_tokens);
        $mutated_tokens = $this->mutation_engine->apply_mutation();
        return $mutated_tokens;
    }
}

function main() {
    $sample_text = 'The quick brown fox jumps over the lazy dog';
    $dataset_generator = new DatasetGenerator($sample_text);
    $result = $dataset_generator->generate();
    print_r($result);
}

main();