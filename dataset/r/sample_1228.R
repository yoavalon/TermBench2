library(digest)

main <- function() {
  x <- 'hello'
  h <- digest(x, algo = 'sha256')
  y <- paste0(unlist(strsplit(h, NULL)), collapse = "")
  z <- paste0(rev(unlist(strsplit(y, NULL))), collapse = "")
  print(z)
}

main()