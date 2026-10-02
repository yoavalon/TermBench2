def process_text(text, index=0, result=[])
  if index >= text.length
    result
  else
    result << text[index].ord
    process_text(text, index + 1, result)
  end
end

def main
  text = 'Hello, World!'
  vector = process_text(text)
  puts vector.inspect
end

main