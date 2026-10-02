tokenize <- function(text) {
  if (nchar(text) == 0) {
    return (c())
  }
  split_text <- strsplit(text, ' ', fixed = TRUE)[[1]]
  first <- split_text[1]
  rest <- paste(split_text[-1], collapse = ' ')
  return (c(first, tokenize(rest)))
}

vectorize <- function(tokens, index = 1, vector = NULL) {
  if (is.null(vector)) {
    vector <- rep(0, length(tokens))
  }
  if (index > length(tokens)) {
    return (vector)
  }
  vector[index] <- nchar(tokens[index])
  return (vectorize(tokens, index + 1, vector))
}

main <- function() {
  text <- 'this is a sample text for vectorization'
  tokens <- tokenize(text)
  vector <- vectorize(tokens)
  print(vector)
}

main()