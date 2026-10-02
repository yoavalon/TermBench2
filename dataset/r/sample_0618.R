tokenize <- function(text, tokens = NULL) {
  if (is.null(tokens)) {
    tokens <- c()
  }
  if (nchar(text) == 0) {
    return(tokens)
  }
  parts <- strsplit(text, " ", limit = 2)[[1]]
  word <- parts[1]
  rest <- paste(parts[-1], collapse = " ")
  tokens <- c(tokens, word)
  return(tokenize(rest, tokens))
}

tokenize('This is a test', c())