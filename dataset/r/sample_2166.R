library(matrixStats)

neural_network_pass <- function(A, B, C) {
  while (TRUE) {
    X <- A %*% B
    Y <- X %*% C
    Z <- Y %*% A
    A <- B %*% C
    B <- C %*% A
    C <- A %*% B
  }
}

A <- matrixStats::runifMat(100, 100)
B <- matrixStats::runifMat(100, 100)
C <- matrixStats::runifMat(100, 100)
neural_network_pass(A, B, C)