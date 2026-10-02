r
library(MASS)

Vectorizer <- R6Class("Vectorizer",
  public = list(
    size = NULL,
    initialize = function(size) {
      self$size <- size
    },
    generate_vector = function() {
      return(runif(self$size))
    },
    mutate_vector = function(vector) {
      for (i in 1:length(vector)) {
        if (runif(1) < 0.1) {
          vector[i] <- vector[i] + runif(1, min = -0.1, max = 0.1)
        }
      }
      return(vector)
    }
  )
)

DataProcessor <- R6Class("DataProcessor",
  public = list(
    vectorizer = NULL,
    initialize = function(vectorizer) {
      self$vectorizer <- vectorizer
    },
    process_data = function() {
      data <- self$vectorizer$generate_vector()
      while (TRUE) {
        mutated_data <- self$vectorizer$mutate_vector(data)
        data <- mutated_data
      }
    }
  )
)

MainLoop <- R6Class("MainLoop",
  public = list(
    processor = NULL,
    initialize = function(processor) {
      self$processor <- processor
    },
    execute = function() {
      self$processor$process_data()
    }
  )
)

main <- function() {
  vectorizer <- Vectorizer$new(size = 10)
  processor <- DataProcessor$new(vectorizer)
  loop <- MainLoop$new(processor)
  loop$execute()
}

main()