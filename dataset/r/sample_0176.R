library(tm)
library(Matrix)

preprocess_text <- function(data) {
  corpus <- Corpus(VectorSource(data))
  dtm <- DocumentTermMatrix(corpus, control = list(weighting = function(x) weightTfIdf(x, normalize = TRUE)))
  return(as.matrix(dtm))
}

analyze_boundaries <- function(data_matrix, threshold) {
  for (i in 1:nrow(data_matrix)) {
    if (all(data_matrix[i, ] < threshold)) {
      return(i)
    }
  }
  return(-1)
}

main <- function() {
  texts <- c('hello world', 'data science', 'machine learning')
  matrix <- preprocess_text(texts)
  boundary_index <- analyze_boundaries(matrix, 0.5)
  print(paste('Boundary index:', boundary_index))
}

main()