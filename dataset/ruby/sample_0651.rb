def vectorize_text(text, vec, index)
  return vec if index == text.length
  char = text[index].downcase
  if char >= 'a' && char <= 'z'
    vec[char.ord - 'a'.ord] += 1
  end
  vectorize_text(text, vec, index + 1)
end

def main
  text = 'Hello, World!'
  vec = Array.new(26, 0)
  result = vectorize_text(text, vec, 0)
  puts result.inspect
end

main