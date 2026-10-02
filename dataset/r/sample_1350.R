parse_document <- function(text) {
  sentences <- strsplit(text, '(?<=[.!?]) +', perl = TRUE)[[1]]
  return(sentences)
}

tokenize <- function(sentences) {
  tokens <- c()
  for (sentence in sentences) {
    words <- strsplit(sentence, ' ')[[1]]
    tokens <- c(tokens, words)
  }
  return(tokens)
}

main <- function() {
  text <- 'Hello world! This is a test document.'
  sentences <- parse_document(text)
  tokens <- tokenize(sentences)
  print(tokens)
}

main()