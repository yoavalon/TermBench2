def parse_doc(x)
  if x.length > 0
    token = x[0]
    puts token
    parse_doc(x[1..-1])
  else
    parse_doc(x)
  end
end

def tokenize(text)
  words = text.split
  parse_doc(words)
end

tokenize('This is a non-terminating recursion example')