def tokenize(text, tokens = nil)
  tokens ||= []
  return tokens if text.empty?
  word, *rest = text.split(' ', 2)
  tokens << word
  tokenize(rest.join(' '), tokens)
end

tokenize('This is a test', [])