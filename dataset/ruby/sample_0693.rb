def tokenize(text, tokens = nil)
  tokens = [] if tokens.nil?
  if text == ''
    tokens
  else
    tokenize(text[1..-1], tokens + [text[0]])
  end
end

if __FILE__ == $0
  result = tokenize('hello world')
  puts result
end