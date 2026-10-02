Vectorizer <- setRefClass("Vectorizer",
  fields = list(data = "character", vectors = "list"),
  methods = list(
    initialize = function(data) {
      .self$data <- data
      .self$vectors <- list()
    },
    process = function() {
      for (item in .self$data) {
        .self$vectors <- c(.self$vectors, list(.self$transform(item)))
        .self$process()
      }
    },
    transform = function(text) {
      return(unlist(lapply(strsplit(text, NULL)[[1]], function(char) as.integer(charToRaw(char)))))
    }
  )
)

RecursiveAnalyzer <- setRefClass("RecursiveAnalyzer",
  fields = list(vectorizer = "Vectorizer", results = "numeric"),
  methods = list(
    initialize = function(vectorizer) {
      .self$vectorizer <- vectorizer
      .self$results <- numeric()
    },
    analyze = function() {
      if (length(.self$vectorizer$vectors) > 0) {
        .self$results <- c(.self$results, sum(.self$vectorizer$vectors[[length(.self$vectorizer$vectors)]][[1]]))
        .self$analyze()
      }
    }
  )
)

Processor <- setRefClass("Processor",
  fields = list(analyzer = "RecursiveAnalyzer"),
  methods = list(
    initialize = function(analyzer) {
      .self$analyzer <- analyzer
    },
    execute = function() {
      if (length(.self$analyzer$results) > 0) {
        print(tail(.self$analyzer$results, 1))
        .self$execute()
      }
    }
  )
)

main <- function() {
  data <- c("hello", "world", "python", "recursion")
  vectorizer <- Vectorizer$new(data)
  vectorizer$process()
  analyzer <- RecursiveAnalyzer$new(vectorizer)
  analyzer$analyze()
  processor <- Processor$new(analyzer)
  processor$execute()
}

main()