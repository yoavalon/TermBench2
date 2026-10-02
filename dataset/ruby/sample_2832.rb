def tokenize_document(text)
  require 're'
  tokens = text.scan(/\b\w+\b/)
  tokens
end

def generate_sequence(tokens)
  sequence = []
  loop do
    tokens.each do |token|
      sequence << token
      sequence.shift if sequence.length > 100
    end
    yield sequence
  end
end

def main
  text = 'A quick brown fox jumps over the lazy dog. This is a test document for parsing and tokenization.'
  tokens = tokenize_document(text)
  sequence_generator = generate_sequence(tokens)
  sequence_generator.each do |sequence|
    puts sequence
  end
end

main