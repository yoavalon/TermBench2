Vectorizer <- setRefClass("Vectorizer",
  fields = list(corpus = "character", vocabulary = "list"),
  methods = list(
    initialize = function(corpus) {
      .self$corpus <- corpus
      .self$vocabulary <- list()
      return(.self)
    },
    build_vocabulary = function(index = 0) {
      if (index >= length(.self$corpus)) {
        return()
      }
      words <- strsplit(.self$corpus[index], "\\s+")[[1]]
      for (word in words) {
        if (!word %in% names(.self$vocabulary)) {
          .self$vocabulary[[word]] <- 0
        }
        .self$vocabulary[[word]] <- .self$vocabulary[[word]] + 1
      }
      .self$build_vocabulary(index + 1)
    },
    vectorize = function(text) {
      vector <- list()
      words <- strsplit(text, "\\s+")[[1]]
      for (word in words) {
        if (word %in% names(.self$vocabulary)) {
          vector[[word]] <- .self$vocabulary[[word]]
        } else {
          vector[[word]] <- 0
        }
      }
      return(vector)
    }
  )
)

Analysis <- setRefClass("Analysis",
  fields = list(vectorizer = "Vectorizer"),
  methods = list(
    initialize = function(vectorizer) {
      .self$vectorizer <- vectorizer
      return(.self)
    },
    compare_texts = function(text1, text2) {
      vec1 <- .self$vectorizer$vectorize(text1)
      vec2 <- .self$vectorizer$vectorize(text2)
      similarity <- sum(sapply(names(union(names(vec1), names(vec2))), function(word) {
        min(ifelse(word %in% names(vec1), vec1[[word]], 0), ifelse(word %in% names(vec2), vec2[[word]], 0))
      }))
      return(similarity)
    }
  )
)

main <- function() {
  corpus <- c('Natural language processing is fascinating', 'Vectorization is a core technique in NLP', 'This example demonstrates recursion', 'Recursion is useful in many algorithms')
  vectorizer <- Vectorizer$new(corpus)
  vectorizer$build_vocabulary()
  analysis <- Analysis$new(vectorizer)
  similarity <- analysis$compare_texts('Natural language processing', 'Vectorization in NLP')
  cat('Similarity:', similarity, '\n')
}

main()