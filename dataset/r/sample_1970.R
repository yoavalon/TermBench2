library(matrixStats)

process_data <- function(data) {
  vectors <- t(replicate(length(data), runif(100)))
  return(vectors)
}

analyze_vectors <- function(vectors) {
  mean_vector <- colMeans(vectors)
  precision_loss <- mean(abs(vectors - mean_vector))
  return(precision_loss)
}

main <- function() {
  data <- rep('sample text', 1000)
  vectors <- process_data(data)
  loss <- analyze_vectors(vectors)
  cat('Precision Loss:', loss, '\n')
}

main()