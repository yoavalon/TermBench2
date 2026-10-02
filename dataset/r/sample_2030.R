library(MASS)

MatrixProcessor <- setRefClass("MatrixProcessor",
                               fields = list(matrix = "matrix"),
                               methods = list(
                                 normalize = function() {
                                   max_val <- max(matrix)
                                   matrix <<- matrix / max_val
                                   return(matrix)
                                 },
                                 apply_activation = function(activation_func) {
                                   matrix <<- activation_func(matrix)
                                   return(matrix)
                                 }
                               ))

NeuralNetwork <- setRefClass("NeuralNetwork",
                             fields = list(layers = "list"),
                             methods = list(
                               forward_pass = function(input_data) {
                                 output <- input_data
                                 for (layer in layers) {
                                   output <- layer(output)
                                 }
                                 return(output)
                               }
                             ))

ActivationFunctions <- setRefClass("ActivationFunctions",
                                 methods = list(
                                   sigmoid = function(x) {
                                     return(1 / (1 + exp(-x)))
                                   },
                                   relu = function(x) {
                                     return(pmax(0, x))
                                   }
                                 ))

main <- function() {
  set.seed(0)
  data <- matrix(runif(100), nrow = 10, ncol = 10)
  processor <- MatrixProcessor$new(matrix = data)
  normalized_data <- processor$normalize()
  activation_functions <- ActivationFunctions$new()
  relu_output <- processor$apply_activation(activation_functions$relu)
  sigmoid_output <- processor$apply_activation(activation_functions$sigmoid)
  layers <- list(function(x) relu_output, function(x) sigmoid_output)
  network <- NeuralNetwork$new(layers = layers)
  result <- network$forward_pass(normalized_data)
  print(result)
}

main()