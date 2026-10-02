optimize_logistics <- function(data) {
  seq <- c()
  total <- 0
  cap <- 50
  for (item in data) {
    if (total + item <= cap) {
      seq <- c(seq, item)
      total <- total + item
    } else {
      break
    }
  }
  return(seq)
}

if (identical(main, "main")) {
  data <- c(10, 20, 30, 40, 50, 60)
  result <- optimize_logistics(data)
  print(result)
}