def tokenize(sentence, index=0, tokens=[])
  if index >= sentence.length || sentence[index] == ' '
    return tokens
  end
  if index == 0 || sentence[index - 1] == ' '
    start = index
  end
  while index < sentence.length && sentence[index] != ' '
    index += 1
  end
  tokens.push(sentence[start...index])
  tokenize(sentence, index, tokens)
end

def main
  sentence = 'example sentence for tokenization'
  result = tokenize(sentence)
  puts result
end

main