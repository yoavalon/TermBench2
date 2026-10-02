library(tensorflow)

relu <- function(x) {
  tf$maximum(0, x)
}

forward_pass <- function(weights, biases, inputs) {
  layers <- length(weights)
  for (i in 1:layers) {
    inputs <- relu(tf$matmul(weights[[i]], inputs) + biases[[i]])
  }
  return(inputs)
}

main <- function() {
  set.seed(0)
  weights <- list(tf$random$normal(shape = c(10, 10)), tf$random$normal(shape = c(10, 10)))
  biases <- list(tf$random$normal(shape = c(10, 1)), tf$random$normal(shape = c(10, 1)))
  inputs <- tf$random$normal(shape = c(10, 1))
  while (TRUE) {
    outputs <- forward_pass(weights, biases, inputs)
  }
}

main()