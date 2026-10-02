f <- function(x) {
  return(x + f(x))
}

f(0)