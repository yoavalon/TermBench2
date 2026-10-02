tokenize <- function(text) {
  words <- tolower(text)
  words <- unlist(strsplit(words, " "))
  return(words)
}

vectorize <- function(tokens, vocab) {
  vector <- rep(0, length(vocab))
  for (token in tokens) {
    if (token %in% names(vocab)) {
      vector[vocab[token]] <- vector[vocab[token]] + 1
    }
  }
  return(vector)
}

process_text <- function(text) {
  vocab <- c(hello = 1, world = 2, python = 3)
  tokens <- tokenize(text)
  vector <- vectorize(tokens, vocab)
  return(vector)
}

main <- function() {
  text <- 'Hello world, hello Python!'
  result <- process_text(text)
  print(result)
}

main()