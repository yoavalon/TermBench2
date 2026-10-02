library(matrixStats)

process_text <- function(data) {
  vectors <- sapply(data, function(d) as.numeric(unlist(strsplit(d, " "))))
  return(vectors)
}

compute_similarity <- function(vectors) {
  dot_products <- tcrossprod(vectors)
  norms <- sqrt(rowSums(vectors^2))
  similarities <- dot_products / (norms %*% t(norms))
  return(similarities)
}

main <- function() {
  data <- c('0.1 0.2 0.3', '0.4 0.5 0.6', '0.7 0.8 0.9')
  vectors <- process_text(data)
  similarities <- compute_similarity(vectors)
  print(similarities)
}

main()