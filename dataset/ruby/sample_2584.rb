def generate_sequence(n)
  sequence = [0, 1]
  (2...n).each do |i|
    sequence << sequence[-1] + sequence[-2]
  end
  sequence
end

def vectorize_text(text)
  words = text.split
  word_count = words.each_with_object({}) { |word, hash| hash[word] = words.count(word) }
  word_count
end

def main
  sequence = generate_sequence(10)
  text = 'hello world hello'
  vector = vectorize_text(text)
  puts "#{sequence}, #{vector}"
end

main