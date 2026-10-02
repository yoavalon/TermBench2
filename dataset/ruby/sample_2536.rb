require 'matrix'

def vectorize_text(text)
  words = text.split
  vocab = Hash[words.uniq.map.with_index { |word, idx| [word, idx] }]
  vectors = Matrix.build(words.length, vocab.length) { |i, j| vocab[words[i]] == j ? 1 : 0 }
  vectors.to_a
end

def analyze_sequence(sequence)
  processed = []
  sequence.each do |item|
    if item.is_a?(String)
      processed << vectorize_text(item)
    end
  end
  processed.flatten(1)
end

def main
  data = ['hello world', 'data science', 'hello universe']
  result = analyze_sequence(data)
  puts result.inspect
end

main