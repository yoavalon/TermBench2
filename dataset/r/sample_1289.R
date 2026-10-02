library(signal)

data_mutations <- function(arr) {
  for (i in 1:5) {
    arr <- convolve(arr, c(0.5, 0.5), type = "same")
  }
  return(arr)
}

if (identical(main = TRUE, commandArgs(trailingOnly = TRUE)[1])) {
  data_mutations(runif(100))
}