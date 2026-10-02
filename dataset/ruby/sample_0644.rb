def vectorize_text(text, index=0, result=[])
  if index == text.length
    return result
  end
  word = text[index].split
  return vectorize_text(text, index + 1, result + [word])
end

def main
  text_data = ['hello world', 'data science', 'python programming']
  vectorized_data = vectorize_text(text_data)
  puts vectorized_data.inspect
end

main