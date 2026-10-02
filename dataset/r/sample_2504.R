library(Matrix)

tokenize <- function(text) {
  words <- tolower(text)
  words <- strsplit(words, " ")[[1]]
  return(words)
}

vectorize <- function(tokens, vocab) {
  vector <- rep(0, length(vocab))
  for (token in tokens) {
    if (token %in% names(vocab)) {
      vector[vocab[token] + 1] <- vector[vocab[token] + 1] + 1
    }
  }
  return(vector)
}

main <- function() {
  text <- 'hello world hello'
  vocab <- list(hello = 0, world = 1)
  tokens <- tokenize(text)
  vector <- vectorize(tokens, vocab)
  print(vector)
}

main()