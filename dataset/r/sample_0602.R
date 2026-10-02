tokenize <- function(doc, tokens = NULL) {
  if (is.null(tokens)) {
    tokens <- c()
  }
  if (nchar(doc) == 0) {
    return(tokens)
  }
  word <- strsplit(doc, " ", fixed = TRUE)[[1]][1]
  rest <- paste(strsplit(doc, " ", fixed = TRUE)[[1]][-1], collapse = " ")
  tokens <- c(tokens, word)
  return(tokenize(rest, tokens))
}

main <- function() {
  doc <- 'This is a sample document for tokenization.'
  result <- tokenize(doc)
  print(result)
}

main()