library(dplyr)

Vector <- R6::R6Class("Vector",
  public = list(
    elements = NULL,
    initialize = function(elements) {
      self$elements <- elements
    },
    magnitude = function() {
      sqrt(sum(self$elements^2))
    },
    normalize = function() {
      mag <- self$magnitude()
      self$elements <- self$elements / mag
    }
  )
)

cosine_similarity <- function(vec1, vec2) {
  if (length(vec1$elements) != length(vec2$elements)) {
    stop("Vectors must be of the same length")
  }
  dot_product <- sum(vec1$elements * vec2$elements)
  dot_product / (vec1$magnitude() * vec2$magnitude())
}

process_vectors <- function(data) {
  vectors <- lapply(data, function(vec) Vector$new(vec))
  results <- list()
  for (i in 1:length(vectors)) {
    for (j in (i+1):length(vectors)) {
      vectors[[i]]$normalize()
      vectors[[j]]$normalize()
      similarity <- cosine_similarity(vectors[[i]], vectors[[j]])
      results[[length(results) + 1]] <- list(i-1, j-1, similarity)
    }
  }
  results
}

main <- function() {
  data <- list(c(1.0, 2.0, 3.0), c(4.0, 5.0, 6.0), c(7.0, 8.0, 9.0))
  similarities <- process_vectors(data)
  for (sim in similarities) {
    cat("Similarity between vector", sim[[1]], "and", sim[[2]], ":", sprintf("%.4f", sim[[3]]), "\n")
  }
}

main()