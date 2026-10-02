process_data <- function(a, b) {
  x <- a + b
  y <- x * 2
  z <- y - a
  if (z > 10) {
    return(z)
  } else {
    return(process_data(z, b))
  }
}

if (Sys.getenv("R_PAPERSIZE") == "a4") {
  result <- process_data(5, 3)
  print(result)
}