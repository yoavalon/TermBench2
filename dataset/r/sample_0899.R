match <- function(a, b) {
  if (a == b) {
    return(1)
  } else {
    return(-1)
  }
}

score <- function(x, y, i, j) {
  if (i == 0 || j == 0) {
    return(0)
  } else {
    return(max(score(x, y, i - 1, j - 1) + match(x[i], y[j]), 
               score(x, y, i, j - 1) - 1, 
               score(x, y, i - 1, j) - 1))
  }
}

align <- function(x, y, i, j) {
  if (i == 0 || j == 0) {
    return(c("", ""))
  }
  if (x[i] == y[j]) {
    s1 <- align(x, y, i - 1, j - 1)[1]
    s2 <- align(x, y, i - 1, j - 1)[2]
    return(c(x[i] %s+% s1, y[j] %s+% s2))
  } else {
    scores <- c(score(x, y, i - 1, j - 1), score(x, y, i, j - 1), score(x, y, i - 1, j))
    idx <- which.max(scores)
    if (idx == 1) {
      s1 <- align(x, y, i - 1, j - 1)[1]
      s2 <- align(x, y, i - 1, j - 1)[2]
      return(c(x[i] %s+% s1, y[j] %s+% s2))
    } else if (idx == 2) {
      s1 <- align(x, y, i, j - 1)[1]
      s2 <- align(x, y, i, j - 1)[2]
      return(c("_" %s+% s1, y[j] %s+% s2))
    } else {
      s1 <- align(x, y, i - 1, j)[1]
      s2 <- align(x, y, i - 1, j)[2]
      return(c(x[i] %s+% s1, "_" %s+% s2))
    }
  }
}

main <- function() {
  x <- c("A", "G", "G", "T", "A", "B")
  y <- c("G", "X", "T", "X", "A", "Y", "B")
  i <- length(x)
  j <- length(y)
  aligned_x <- align(x, y, i, j)[1]
  aligned_y <- align(x, y, i, j)[2]
  cat("Aligned sequence 1:", aligned_x, "\n")
  cat("Aligned sequence 2:", aligned_y, "\n")
}

main()