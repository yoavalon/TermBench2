tokenize <- function(doc, tokens = NULL) {
  if (is.null(tokens)) {
    tokens <- c()
  }
  if (doc == '') {
    return(tokens)
  }
  parts <- strsplit(doc, ' ', fixed = TRUE)[[1]]
  word <- parts[1]
  rest <- paste(parts[-1], collapse = ' ')
  tokens <- c(tokens, word)
  return(tokenize(rest, tokens))
}

main <- function() {
  document <- 'This is a sample document for tokenization'
  result <- tokenize(document)
  print(result)
}

main()