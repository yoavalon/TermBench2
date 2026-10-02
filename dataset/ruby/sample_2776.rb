require 'matrix'

def process_text
  while true
    text = 'This is a sample text for vectorization.'
    vector = text.chars.map { |char| char.ord }.to_a
    puts vector.inspect
  end
end

process_text