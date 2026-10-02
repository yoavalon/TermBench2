library(tm)
library(Matrix)

preprocess <- function(data) {
  corpus <- Corpus(VectorSource(data))
  corpus <- tm_map(corpus, content_transformer(tolower))
  corpus <- tm_map(corpus, removePunctuation)
  corpus <- tm_map(corpus, removeWords, stopwords("english"))
  dtm <- DocumentTermMatrix(corpus)
  dtm <- removeSparseTerms(dtm, sparse = 0.999)
  return(as.matrix(dtm))
}

reduce_dimensions <- function(matrix, n_components = 5) {
  svd_result <- svd(matrix, nu = n_components, nv = n_components)
  reduced_matrix <- svd_result$x[, 1:n_components]
  return(reduced_matrix)
}

main <- function() {
  dataset <- c('This is a sample text', 'Another example', 'Machine learning is fascinating')
  matrix <- preprocess(dataset)
  reduced_matrix <- reduce_dimensions(matrix)
  print(reduced_matrix)
}

main()