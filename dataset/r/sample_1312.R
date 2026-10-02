library(tm)
library(Matrix)

preprocess_data <- function(data) {
  corpus <- Corpus(VectorSource(data))
  corpus <- tm_map(corpus, content_transformer(tolower))
  corpus <- tm_map(corpus, removePunctuation)
  dtm <- DocumentTermMatrix(corpus, control = list(wordLengths=c(2, Inf)))
  return(as.matrix(dtm))
}

mutate_vectors <- function(matrix) {
  rows <- nrow(matrix)
  cols <- ncol(matrix)
  for (i in 1:rows) {
    for (j in 1:cols) {
      if (matrix[i, j] > 0) {
        matrix[i, j] <- sample(1:9, 1)
      }
    }
  }
  return(matrix)
}

main <- function() {
  data_samples <- c('The quick brown fox jumps over the lazy dog', 'Hello world! This is a test sentence.', 'Another example with some words.')
  vector_matrix <- preprocess_data(data_samples)
  mutated_matrix <- mutate_vectors(vector_matrix)
  print(mutated_matrix)
}

main()