library(tm)
library(Matrix)
library(SparseM)

process_text <- function(data, dim=100) {
  vectorizer <- function(texts) {
    corpus <- Corpus(VectorSource(texts))
    dtm <- DocumentTermMatrix(corpus, control = list(weighting = function(x) weightTfIdf(x, normalize = TRUE), max.features = dim))
    as.matrix(dtm)
  }
  vectorizer(data)
}

main <- function() {
  data <- c('hello world', 'goodbye universe', 'python programming')
  result <- process_text(data)
  print(result)
}

main()