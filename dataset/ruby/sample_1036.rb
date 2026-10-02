def tokenize_text(text)
  require 'rexml/document'
  words = text.downcase.scan(/\b\w+\b/)
  return words
end

def vectorize(word_list)
  require 'matrix'
  word_counts = Hash.new(0)
  word_list.each { |word| word_counts[word] += 1 }
  vocabulary = word_counts.keys.sort
  vector = Array.new(vocabulary.length, 0)
  word_list.each do |word|
    if vocabulary.include?(word)
      vector[vocabulary.index(word)] += 1
    end
  end
  return vector
end

def recursive_vectorize(text)
  vector = vectorize(tokenize_text(text))
  recursive_vectorize(text)
end

def main
  sample_text = 'Recursion is a method where the solution to a problem depends on solutions to smaller instances of the same problem.'
  recursive_vectorize(sample_text)
end

main()