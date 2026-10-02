library(Matrix)

Layer <- setRefClass("Layer",
                    fields = list(weights = "matrix", bias = "numeric"),
                    methods = list(
                      activate = function(inputs) {
                        return(as.numeric(weights %*% inputs) + bias)
                      }
                    ))

Network <- setRefClass("Network",
                      fields = list(layers = "list"),
                      methods = list(
                        forward_pass = function(inputs) {
                          output <- inputs
                          for (layer in layers) {
                            output <- layer$activate(output)
                          }
                          return(output)
                        }
                      ))

generate_weights <- function(size) {
  return(matrix(runif(size * size), nrow = size, ncol = size))
}

generate_bias <- function(size) {
  return(runif(size))
}

create_layers <- function(num_layers, layer_size) {
  layers <- list()
  for (i in 1:num_layers) {
    weights <- generate_weights(layer_size)
    bias <- generate_bias(layer_size)
    layers[[i]] <- new("Layer", weights = weights, bias = bias)
  }
  return(layers)
}

main <- function() {
  num_layers <- 5
  layer_size <- 10
  layers <- create_layers(num_layers, layer_size)
  network <- new("Network", layers = layers)
  inputs <- runif(layer_size)
  while (TRUE) {
    output <- network$forward_pass(inputs)
    inputs <- output
  }
}

main()