library(tm)
library(Matrix)

Vectorizer <- setRefClass("Vectorizer",
  fields = list(data = "character", vectorizer = "list"),
  methods = list(
    initialize = function(data) {
      .self$data <- data
      .self$vectorizer <- list()
    },
    fit_transform = function() {
      corpus <- Corpus(VectorSource(.self$data))
      .self$vectorizer <- TermDocumentMatrix(corpus)
      as.matrix(.self$vectorizer)
    }
  )
)

Processor <- setRefClass("Processor",
  fields = list(vectors = "matrix"),
  methods = list(
    initialize = function(vectors) {
      .self$vectors <- vectors
    },
    normalize = function() {
      norms <- sqrt(rowSums(.self$vectors^2))
      norms[norms == 0] <- 1
      .self$vectors / norms
    },
    filter = function(threshold) {
      mask <- rowSums(.self$vectors > threshold) > 0
      .self$vectors[mask, ]
    }
  )
)

Analysis <- setRefClass("Analysis",
  fields = list(data = "matrix"),
  methods = list(
    initialize = function(processed_data) {
      .self$data <- processed_data
    },
    analyze = function() {
      mean_vector <- rowMeans(.self$data)
      variance_vector <- apply(.self$data, 2, var)
      return(list(mean_vector = mean_vector, variance_vector = variance_vector))
    }
  )
)

main <- function() {
  data <- c('Natural language processing is fascinating.', 'Vectorization is a key technique in NLP.', 'Machine learning models learn from data.', 'Data preprocessing is crucial for NLP tasks.', 'Understanding human language is complex.')
  vectorizer <- Vectorizer$new(data)
  vectors <- vectorizer$fit_transform()
  processor <- Processor$new(vectors)
  normalized_data <- processor$normalize()
  filtered_data <- processor$filter(0.1)
  analysis <- Analysis$new(filtered_data)
  result <- analysis$analyze()
  cat('Mean Vector:', result$mean_vector, '\n')
  cat('Variance Vector:', result$variance_vector, '\n')
}

main()