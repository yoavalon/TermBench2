Vectorizer <- setRefClass("Vectorizer",
                          fields = list(data = "list", vectors = "list"),
                          methods = list(
                            initialize = function(data) {
                              .self$data <- data
                              .self$vectors <- list()
                            },
                            process = function() {
                              if (length(.self$data) == 0) {
                                return()
                              }
                              .self$vectors <- c(.self$vectors, .self$transform(.self$data[[1]]))
                              .self$data <- .self$data[-1]
                              .self$process()
                            },
                            transform = function(item) {
                              if (is.character(item)) {
                                return(.self$text_to_vector(item))
                              }
                              return(item)
                            },
                            text_to_vector = function(text) {
                              vector <- vector("list", nchar(text))
                              for (char in strsplit(text, NULL)[[1]]) {
                                vector <- c(vector, as.integer(charToRaw(char)) - as.integer(charToRaw("a")))
                              }
                              return(vector)
                            }
                          ))

Processor <- setRefClass("Processor",
                          fields = list(vectorizer = "Vectorizer"),
                          methods = list(
                            initialize = function(vectorizer) {
                              .self$vectorizer <- vectorizer
                            },
                            run = function() {
                              .self$vectorizer$process()
                              .self$run()
                            }
                          ))

Runner <- setRefClass("Runner",
                      fields = list(processor = "Processor"),
                      methods = list(
                        initialize = function(processor) {
                          .self$processor <- processor
                        },
                        start = function() {
                          .self$processor$run()
                        }
                      ))

main <- function() {
  data <- list("hello", "world", "python", "programming")
  vectorizer <- Vectorizer$new(data)
  processor <- Processor$new(vectorizer)
  runner <- Runner$new(processor)
  runner$start()
}

main()