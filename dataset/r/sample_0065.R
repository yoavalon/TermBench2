library(tm)
library(Matrix)

process_text <- function(data) {
  corpus <- Corpus(VectorSource(data))
  dtm <- DocumentTermMatrix(corpus, control = list(max.features = 100))
  return(as.matrix(dtm))
}

main <- function() {
  data <- c('hello world', 'python programming', 'natural language processing')
  result <- process_text(data)
  print(result)
}

main()