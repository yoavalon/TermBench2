library(Matrix)

Vectorizer <- R6::R6Class("Vectorizer",
  public = list(
    data = NULL,
    initialize = function(data) {
      self$data <- data
    },
    normalize = function(vector) {
      magnitude <- sqrt(sum(vector^2))
      if (magnitude == 0) {
        return(rep(0.0, length(vector)))
      }
      return(vector / magnitude)
    },
    vectorize = function() {
      vectors <- list()
      for (item in self$data) {
        vector <- sapply(strsplit(item, NULL)[[1]], function(x) as.numeric(charToRaw(x)) / 1000.0)
        normalized_vector <- self$normalize(vector)
        vectors[[length(vectors) + 1]] <- normalized_vector
      }
      return(vectors)
    }
  )
)

Processor <- R6::R6Class("Processor",
  public = list(
    vectors = NULL,
    initialize = function(vectors) {
      self$vectors <- vectors
    },
    cosine_similarity = function(vec1, vec2) {
      dot_product <- sum(vec1 * vec2)
      norm1 <- sqrt(sum(vec1^2))
      norm2 <- sqrt(sum(vec2^2))
      if (norm1 == 0 || norm2 == 0) {
        return(0.0)
      }
      return(dot_product / (norm1 * norm2))
    },
    compare = function() {
      results <- list()
      for (i in 1:length(self$vectors)) {
        for (j in (i + 1):length(self$vectors)) {
          similarity <- self$cosine_similarity(self$vectors[[i]], self$vectors[[j]])
          results[[length(results) + 1]] <- c(i, j, similarity)
        }
      }
      return(results)
    }
  )
)

main <- function() {
  data <- c('hello', 'world', 'python', 'programming')
  vectorizer <- Vectorizer$new(data)
  vectors <- vectorizer$vectorize()
  processor <- Processor$new(vectors)
  results <- processor$compare()
  for (result in results) {
    cat(sprintf('Similarity between item %d and %d: %.4f\n', result[1], result[2], result[3]))
  }
}

main()