library(Matrix)

Network <- setRefClass("Network",
                      fields = list(layers = "numeric", weights = "list", biases = "list"),
                      methods = list(
                        initialize = function(layers) {
                          .self$layers <- layers
                          .self$weights <- lapply(1:(length(layers) - 1), function(i) {
                            matrix(rnorm(layers[i] * layers[i + 1]), nrow = layers[i], ncol = layers[i + 1])
                          })
                          .self$biases <- lapply(1:(length(layers) - 1), function(i) {
                            matrix(rnorm(layers[i + 1]), nrow = 1, ncol = layers[i + 1])
                          })
                        },
                        forward = function(input_data) {
                          activations <- list(input_data)
                          for (i in seq_along(.self$weights)) {
                            activation <- activations[[length(activations)]] %*% .self$weights[[i]] + .self$biases[[i]]
                            activations[[length(activations) + 1]] <- tanh(activation)
                          }
                          return(activations[[length(activations)]])
                        }
                      ))

DataGenerator <- setRefClass("DataGenerator",
                             fields = list(size = "numeric", features = "numeric", data = "matrix"),
                             methods = list(
                               initialize = function(size, features) {
                                 .self$size <- size
                                 .self$features <- features
                                 .self$data <- matrix(rnorm(size * features), nrow = size, ncol = features)
                               },
                               generate = function() {
                                 return(.self$data)
                               }
                             ))

Trainer <- setRefClass("Trainer",
                      fields = list(network = "Network", data_generator = "DataGenerator"),
                      methods = list(
                        initialize = function(network, data_generator) {
                          .self$network <<- network
                          .self$data_generator <<- data_generator
                        },
                        train = function() {
                          while (TRUE) {
                            data <- .self$data_generator$generate()
                            .self$network$forward(data)
                          }
                        }
                      ))

main <- function() {
  layers <- c(784, 128, 64, 10)
  network <- Network$new(layers)
  data_generator <- DataGenerator$new(1000, 784)
  trainer <- Trainer$new(network, data_generator)
  trainer$train()
}

main()