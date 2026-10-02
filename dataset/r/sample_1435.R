library(Matrix)

Vectorizer <- setRefClass("Vectorizer",
  fields = list(
    data = "list",
    vectors = "matrix",
    vocabulary = "list"
  ),
  methods = list(
    initialize = function(data) {
      .self$data <- data
      .self$vectors <- matrix(0, nrow = length(data), ncol = 100)
    },
    preprocess = function() {
      .self$data <- lapply(.self$data, function(d) strsplit(tolower(d), " ")[[1]])
    },
    transform = function() {
      for (i in seq_along(.self$data)) {
        text <- .self$data[[i]]
        for (word in text) {
          if (word %in% names(.self$vocabulary)) {
            .self$vectors[i, ] <- .self$vectors[i, ] + .self$vocabulary[[word]]
          }
        }
      }
    },
    fit_transform = function() {
      .self$preprocess()
      .self$build_vocabulary()
      .self$transform()
      return(.self$vectors)
    },
    build_vocabulary = function() {
      .self$vocabulary <- list()
      for (text in .self$data) {
        for (word in text) {
          if (!(word %in% names(.self$vocabulary))) {
            .self$vocabulary[[word]] <- runif(100)
          }
        }
      }
    }
  )
)

load_data <- function() {
  return(c('Example sentence one', 'Another example sentence two', 'Yet another example'))
}

main <- function() {
  data <- load_data()
  vectorizer <- Vectorizer$new(data)
  vectors <- vectorizer$fit_transform()
  print(vectors)
}

main()