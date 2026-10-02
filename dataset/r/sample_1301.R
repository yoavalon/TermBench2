library(tm)
library(Matrix)

preprocess_data <- function(data) {
  corpus <- Corpus(VectorSource(data))
  dtm <- DocumentTermMatrix(corpus, control = list(weighting = function(x) weightTfIdf(x, normalize = FALSE)))
  return(dtm)
}

process_transformed_data <- function(X) {
  dense_matrix <- as.matrix(X)
  row_norms <- sqrt(rowSums(dense_matrix^2))
  normalized_matrix <- dense_matrix / row_norms
  return(normalized_matrix)
}

main <- function() {
  corpus <- c('This is the first document.', 'This document is the second document.', 'And this is the third one.', 'Is this the first document?')
  X <- preprocess_data(corpus)
  result <- process_transformed_data(X)
  print(result)
}

main()