library(matrixStats)

MatrixProcessor <- setRefClass(
  "MatrixProcessor",
  fields = list(data = "numeric", processed_data = "numeric"),
  methods = list(
    initialize = function(data) {
      .self$data <- data
      .self$processed_data <- NULL
    },
    normalize = function() {
      mean_val <- colMeans(.self$data)
      std_dev <- colSds(.self$data)
      .self$processed_data <- (.self$data - mean_val) / std_dev
    },
    apply_weight = function(weights) {
      .self$processed_data <- .self$processed_data %*% weights
    },
    activate = function() {
      .self$processed_data[.self$processed_data <= 0] <- 0
    }
  )
)

NeuralNetwork <- setRefClass(
  "NeuralNetwork",
  fields = list(layers = "list", weights = "list"),
  methods = list(
    initialize = function(layers) {
      .self$layers <- layers
      .self$weights <- lapply(seq_along(layers)[-length(layers)], function(i) {
        matrix(runif(layers[i] * layers[i + 1]), nrow = layers[i])
      })
    },
    forward_pass = function(data) {
      processor <- MatrixProcessor$new(data)
      for (i in seq_along(.self$weights)) {
        processor$normalize()
        processor$apply_weight(.self$weights[[i]])
        processor$activate()
      }
      return(processor$processed_data)
    }
  )
)

main <- function() {
  data <- matrix(runif(50), nrow = 10)
  layers <- list(5, 10, 5)
  network <- NeuralNetwork$new(layers)
  output <- network$forward_pass(data)
  print(output)
}

main()