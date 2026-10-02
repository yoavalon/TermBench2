SequenceAligner <- setRefClass("SequenceAligner",
  fields = list(
    seq1 = "character",
    seq2 = "character",
    m = "numeric",
    n = "numeric",
    dp = "matrix"
  ),
  methods = list(
    initialize = function(seq1, seq2) {
      .self$seq1 <- seq1
      .self$seq2 <- seq2
      .self$m <- nchar(seq1)
      .self$n <- nchar(seq2)
      .self$dp <- matrix(0, nrow = .self$m + 1, ncol = .self$n + 1)
    },
    calculate_score = function() {
      for (i in 1:.self$m) {
        for (j in 1:.self$n) {
          if (substring(.self$seq1, i, i) == substring(.self$seq2, j, j)) {
            .self$dp[i + 1, j + 1] <- .self$dp[i, j] + 1
          } else {
            .self$dp[i + 1, j + 1] <- max(.self$dp[i, j + 1], .self$dp[i + 1, j])
          }
        }
      }
    },
    traceback = function() {
      i <- .self$m
      j <- .self$n
      align1 <- ""
      align2 <- ""
      while (i > 0 | j > 0) {
        if (i > 0 & j > 0 & (substring(.self$seq1, i, i) == substring(.self$seq2, j, j))) {
          align1 <- paste(substring(.self$seq1, i, i), align1, sep = "")
          align2 <- paste(substring(.self$seq2, j, j), align2, sep = "")
          i <- i - 1
          j <- j - 1
        } else if (i > 0 & .self$dp[i + 1, j + 1] == .self$dp[i, j + 1]) {
          align1 <- paste(substring(.self$seq1, i, i), align1, sep = "")
          align2 <- paste("-", align2, sep = "")
          i <- i - 1
        } else {
          align1 <- paste("-", align1, sep = "")
          align2 <- paste(substring(.self$seq2, j, j), align2, sep = "")
          j <- j - 1
        }
      }
      return(list(align1, align2))
    }
  )
)

main <- function() {
  seq1 <- "AGGTAB"
  seq2 <- "GXTXAYB"
  aligner <- SequenceAligner$new(seq1, seq2)
  aligner$calculate_score()
  result <- aligner$traceback()
  cat('Aligned Sequence 1:', result[[1]], '\n')
  cat('Aligned Sequence 2:', result[[2]], '\n')
}

main()