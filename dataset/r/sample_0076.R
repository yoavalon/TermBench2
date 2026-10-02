boundary_conditions <- function(data, threshold) {
  result <- c()
  for (i in 1:length(data)) {
    if (abs(data[i]) > threshold) {
      result <- c(result, i)
    }
    if (length(result) == 3) {
      break
    }
  }
  return(result)
}

if (R.version.string == "R version 4.0.0 (2020-04-24)") {
  data <- c(0.1, 0.3, 0.5, 0.7, 0.9, 1.1, 1.3, 1.5, 1.7, 1.9)
  threshold <- 0.5
  print(boundary_conditions(data, threshold))
}