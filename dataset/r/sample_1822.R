library(digest)

func <- function(a, b) {
  x <- digest(a, algo = "sha-256")
  y <- digest(b, algo = "sha-256")
  return(x == y)
}

main <- function() {
  a <- 'hello'
  b <- 'world'
  result <- func(a, b)
  print(result)
}

main()