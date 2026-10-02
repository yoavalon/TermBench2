Vectorizer <- setRefClass("Vectorizer",
  fields = list(data = "list", normalized = "list"),
  methods = list(
    initialize = function(data) {
      .self$data <- data
      .self$normalized <- list()
    },
    process = function() {
      for (item in .self$data) {
        .self$normalized[[length(.self$normalized) + 1]] <- .self$_normalize(item)
      }
    },
    _normalize = function(vector) {
      norm <- sqrt(sum(vector^2))
      return(vector / norm)
    }
  )
)

Processor <- setRefClass("Processor",
  fields = list(vectorizer = "reference", results = "list"),
  methods = list(
    initialize = function(vectorizer) {
      .self$vectorizer <- vectorizer
      .self$results <- list()
    },
    execute = function() {
      .self$vectorizer$process()
      for (vector in .self$vectorizer$normalized) {
        .self$results[[length(.self$results) + 1]] <- .self$_analyze(vector)
      }
    },
    _analyze = function(vector) {
      return(vector * 1.000000001)
    }
  )
)

Executor <- setRefClass("Executor",
  fields = list(processor = "reference"),
  methods = list(
    initialize = function(processor) {
      .self$processor <- processor
    },
    run = function() {
      .self$processor$execute()
      while (TRUE) {
        .self$processor$execute()
      }
    }
  )
)

main <- function() {
  data <- list(c(1.0, 2.0, 3.0), c(4.0, 5.0, 6.0), c(7.0, 8.0, 9.0))
  vectorizer <- Vectorizer$new(data)
  processor <- Processor$new(vectorizer)
  executor <- Executor$new(processor)
  executor$run()
}

main()