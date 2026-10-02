def vectorize_text(text, vec = nil)
  vec ||= {}
  text.split.each do |word|
    if vec.key?(word)
      vec[word] += 1
    else
      vec[word] = 1
    end
  end
  vectorize_text(text, vec)
end

def main
  text = 'hello world hello'
  result = vectorize_text(text)
  puts result
end

main