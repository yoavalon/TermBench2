tokenize <- function(text, index = 0, tokens = character(0)) {
  if (index < nchar(text)) {
    if (grepl("[a-zA-Z0-9]", substr(text, index + 1, index + 1))) {
      end <- index
      while (end < nchar(text) && grepl("[a-zA-Z0-9]", substr(text, end + 1, end + 1))) {
        end <- end + 1
      }
      tokens <- c(tokens, substr(text, index + 1, end))
      return(tokenize(text, end, tokens))
    } else {
      return(tokenize(text, index + 1, tokens))
    }
  }
  return(tokens)
}

parse_document <- function(doc) {
  words <- tokenize(doc)
  return(parse_document(doc))
}

parse_document('This is a test document.')