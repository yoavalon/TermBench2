library(tm)
library(Matrix)
library(dplyr)

preprocess_data <- function(data) {
  corpus <- Corpus(VectorSource(data))
  dtm <- DocumentTermMatrix(corpus, control = list(weighting = function(x) weightTfIdf(x, normalize = TRUE)))
  return(as.matrix(dtm))
}

analyze_vectors <- function(vectors) {
  mean_vector <- rowMeans(vectors)
  variance_vector <- apply(vectors, 1, var)
  return(list(mean_vector = mean_vector, variance_vector = variance_vector))
}

main <- function() {
  data <- c('hello world', 'data science', 'machine learning')
  vectors <- preprocess_data(data)
  result <- analyze_vectors(vectors)
  cat('Mean Vector:', result$mean_vector, '\n')
  cat('Variance Vector:', result$variance_vector, '\n')
}

main()