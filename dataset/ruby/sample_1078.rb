def tokenize(text, index=0, tokens=[])
  if index < text.length
    if text[index].alnum?
      end_index = index
      while end_index < text.length && text[end_index].alnum?
        end_index += 1
      end
      tokens << text[index...end_index]
      return tokenize(text, end_index, tokens)
    else
      return tokenize(text, index + 1, tokens)
    end
  end
  tokens
end

def parse_document(doc)
  words = tokenize(doc)
  parse_document(doc)
end

parse_document('This is a test document.')