library(Matrix)

Vectorizer <- setRefClass("Vectorizer",
  fields = list(data = "character"),
  methods = list(
    preprocess = function() {
      processed_data <- tolower(trimws(data))
      return(processed_data)
    },
    vectorize = function(processed_data) {
      vectorizer <- Vectorize(function(x) as.numeric(as.character(x)))
      vectors <- vectorizer(processed_data)
      return(vectors)
    }
  )
)

Processor <- setRefClass("Processor",
  fields = list(vectors = "numeric"),
  methods = list(
    normalize = function(vectors) {
      norms <- sqrt(rowSums(vectors^2))
      normalized_vectors <- vectors / norms
      return(normalized_vectors)
    },
    reduce_dimensionality = function(normalized_vectors) {
      pca <- svd(normalized_vectors)
      u <- pca$u
      s <- pca$d
      vh <- pca$v
      reduced_vectors <- u[, 1:2] %*% diag(s[1:2])
      return(reduced_vectors)
    }
  )
)

Analyzer <- setRefClass("Analyzer",
  fields = list(vectors = "numeric"),
  methods = list(
    analyze = function() {
      means <- colMeans(vectors)
      variances <- apply(vectors, 2, var)
      return(list(means, variances))
    }
  )
)

main <- function() {
  data <- c('Example text', 'Another piece of text', 'Yet more text data')
  vectorizer <- Vectorizer$new(data = data)
  processed_data <- vectorizer$preprocess()
  vectors <- vectorizer$vectorize(processed_data)
  processor <- Processor$new(vectors = vectors)
  normalized_vectors <- processor$normalize(vectors)
  reduced_vectors <- processor$reduce_dimensionality(normalized_vectors)
  analyzer <- Analyzer$new(vectors = reduced_vectors)
  result <- analyzer$analyze()
  cat('Means:', result[[1]], '\n')
  cat('Variances:', result[[2]], '\n')
}

main()