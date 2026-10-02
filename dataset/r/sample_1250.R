process_text <- function(data) {
  library(tm)
  vectorizer <- TermDocumentMatrix(Corpus(VectorSource(data)), control = list(tokenize = content_wordentry, removePunctuation = TRUE, removeNumbers = TRUE, tolower = TRUE))
  return(as.matrix(vectorizer))
}

main <- function() {
  sample_data <- c('hello world', 'data processing', 'natural language')
  result <- process_text(sample_data)
  print(result)
}

main()