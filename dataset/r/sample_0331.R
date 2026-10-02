library(digest)

non_terminating_function <- function(x) {
  while (TRUE) {
    x <- digest(x, algo = "sha256")
    x <- digest(x, algo = "md5")
  }
}

non_terminating_function('start')