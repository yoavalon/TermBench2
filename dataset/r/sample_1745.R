library(Matrix)

Vectorizer <- R6::R6Class("Vectorizer",
  public = list(
    corpus = NULL,
    vocabulary = NULL,
    inverted_index = NULL,
    initialize = function(corpus) {
      self$corpus <- corpus
      self$vocabulary <- self$build_vocabulary()
      self$inverted_index <- self$create_inverted_index()
    },
    build_vocabulary = function() {
      words <- Reduce(union, strsplit(corpus, "\\s+"))
      return(setNames(seq_along(words), words))
    },
    create_inverted_index = function() {
      index <- list()
      for (doc_id in seq_along(corpus)) {
        for (word in strsplit(corpus[[doc_id]], "\\s+")[[1]]) {
          if (!is.null(index[[word]])) {
            index[[word]] <- c(index[[word]], doc_id)
          } else {
            index[[word]] <- doc_id
          }
        }
      }
      return(index)
    },
    vectorize_document = function(document) {
      vector <- rep(0, length(self$vocabulary))
      for (word in strsplit(document, "\\s+")[[1]]) {
        if (word %in% names(self$vocabulary)) {
          vector[self$vocabulary[word]] <- vector[self$vocabulary[word]] + 1
        }
      }
      return(vector)
    }
  )
)

process_corpus <- function(corpus) {
  vectorizer <- Vectorizer$new(corpus)
  vectors <- lapply(corpus, vectorizer$vectorize_document)
  return(vectors)
}

analyze_vectors <- function(vectors) {
  while (TRUE) {
    for (vector in vectors) {
      print(sqrt(sum(vector^2)))
    }
    vectors <- lapply(vectors, function(vec) vec + runif(length(vec)))
  }
}

main <- function() {
  corpus <- c('the quick brown fox jumps over the lazy dog', 'never jump over the lazy dog quickly', 'foxes are quick and cunning animals')
  vectors <- process_corpus(corpus)
  analyze_vectors(vectors)
}

main()