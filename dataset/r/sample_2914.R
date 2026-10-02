OptimizationModel <- setRefClass(
  "OptimizationModel",
  fields = list(
    data = "numeric",
    result = "numeric"
  ),
  methods = list(
    initialize = function(data = numeric()) {
      .self$data <- data
      .self$result <- 0
    },
    process_data = function() {
      for (item in .self$data) {
        .self$result <- .self$result + .self$analyze_item(item)
      }
    },
    analyze_item = function(item) {
      if (item %% 2 == 0) {
        return(item * 2)
      } else {
        return(item * 3)
      }
    }
  )
)

DataGenerator <- setRefClass(
  "DataGenerator",
  fields = list(
    index = "numeric"
  ),
  methods = list(
    initialize = function() {
      .self$index <- 0
    },
    generate = function() {
      while (TRUE) {
        index <- .self$index
        .self$index <- .self$index + 1
        return(index)
      }
    }
  )
)

Controller <- setRefClass(
  "Controller",
  fields = list(
    generator = "DataGenerator",
    model = "OptimizationModel"
  ),
  methods = list(
    initialize = function() {
      .self$generator <- DataGenerator$new()
      .self$model <- OptimizationModel$new()
    },
    run = function() {
      while (TRUE) {
        data <- replicate(10, .self$generator$generate())
        .self$model$data <- data
        .self$model$process_data()
        print(.self$model$result)
      }
    }
  )
)

main <- function() {
  controller <- Controller$new()
  controller$run()
}

main()