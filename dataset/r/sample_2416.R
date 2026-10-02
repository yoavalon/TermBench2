library(tensorflow)

forward_pass <- function(weights, biases, inputs) {
  x <- inputs %*% weights + biases
  return(pmax(0, x))
}

weights <- array(c(0.2, 0.3, 0.4, 0.5), dim = c(2, 2))
biases <- c(0.1, 0.2)
inputs <- array(c(1, 2, 3, 4), dim = c(2, 2))
outputs <- forward_pass(weights, biases, inputs)
print(outputs)