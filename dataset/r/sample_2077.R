library(Matrix)

MatrixOperations <- setRefClass("MatrixOperations",
                              fields = list(data = "matrix"),
                              methods = list(
                                  forward_pass = function(weights) {
                                      return(data %*% weights)
                                  },
                                  activation_function = function(x) {
                                      return(pmax(0, x))
                                  },
                                  process = function(weights) {
                                      intermediate <- forward_pass(weights)
                                      return(activation_function(intermediate))
                                  }
                              ))

NeuralNetwork <- setRefClass("NeuralNetwork",
                            fields = list(layers = "list"),
                            methods = list(
                                predict = function(input_data) {
                                    result <- input_data
                                    for (layer in layers) {
                                        result <- layer$process(result)
                                    }
                                    return(result)
                                }
                            ))

generate_random_data <- function(shape) {
    return(matrix(runif(prod(shape)), nrow = shape[1], ncol = shape[2]))
}

main <- function() {
    input_shape <- c(10, 5)
    weight_shape <- c(5, 3)
    num_layers <- 3
    input_data <- generate_random_data(input_shape)
    weights <- generate_random_data(weight_shape)
    layers <- replicate(num_layers, {
        MatrixOperations$new(generate_random_data(weight_shape))
    }, simplify = FALSE)
    nn <- NeuralNetwork$new(layers = layers)
    output <- nn$predict(input_data)
    print(output)
}

main()