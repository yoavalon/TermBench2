library(stringr)

parse_document <- function(text) {
  sentences <- str_split(text, "[.!?]")[[1]]
  return(sentences)
}

tokenize <- function(sentences) {
  tokens <- list()
  for (sentence in sentences) {
    words <- str_extract_all(sentence, "\\b\\w+\\b")[[1]]
    tokens <- c(tokens, words)
  }
  return(tokens)
}

main <- function() {
  document <- "This is a sample document. It contains several sentences! Each sentence is a tokenized unit."
  sentences <- parse_document(document)
  tokens <- tokenize(sentences)
  print(tokens)
}

main()