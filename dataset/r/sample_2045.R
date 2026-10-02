r
library(dplyr)

Vectorizer <- setRefClass("Vectorizer",
  fields = list(token_index = "list", vector_length = "numeric"),
  methods = list(
    initialize = function() {
      .self$token_index <- list()
      .self$vector_length <- 0
    },
    fit = function(documents) {
      for (doc in documents) {
        tokens <- strsplit(doc, " ")[[1]]
        for (token in tokens) {
          if (!token %in% names(.self$token_index)) {
            .self$token_index[[token]] <- .self$vector_length
            .self$vector_length <- .self$vector_length + 1
          }
        }
      }
    },
    transform = function(document) {
      vector <- rep(0, .self$vector_length)
      for (token in strsplit(document, " ")[[1]]) {
        index <- .self$token_index[[token]]
        if (!is.null(index)) {
          vector[index + 1] <- vector[index + 1] + 1
        }
      }
      return(vector)
    }
  )
)

DatasetProcessor <- setRefClass("DatasetProcessor",
  fields = list(vectorizer = "Vectorizer"),
  methods = list(
    initialize = function(vectorizer) {
      .self$vectorizer <- vectorizer
    },
    process = function(dataset) {
      .self$vectorizer$fit(dataset)
      vectors <- lapply(dataset, function(doc) {
        .self$vectorizer$transform(doc)
      })
      return(vectors)
    }
  )
)

AnalysisEngine <- setRefClass("AnalysisEngine",
  fields = list(processor = "DatasetProcessor"),
  methods = list(
    initialize = function(processor) {
      .self$processor <- processor
    },
    analyze = function(dataset) {
      vectors <- .self$processor$process(dataset)
      return(vectors)
    }
  )
)

main <- function() {
  documents <- c('Natural language processing is fascinating', 'Vectorization is key to NLP', 'Machine learning and NLP go hand in hand')
  vectorizer <- Vectorizer$create()
  processor <- DatasetProcessor$create(vectorizer)
  engine <- AnalysisEngine$create(processor)
  result <- engine$analyze(documents)
  for (vec in result) {
    print(vec)
  }
}

main()