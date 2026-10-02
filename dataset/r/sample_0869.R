SequenceAligner <- setRefClass("SequenceAligner",
  fields = list(seq1 = "character", seq2 = "character"),
  methods = list(
    initialize = function(seq1, seq2) {
      .self$seq1 <- seq1
      .self$seq2 <- seq2
    },
    score = function(a, b) {
      if (a == b) {
        return(1)
      } else {
        return(-1)
      }
    },
    align = function() {
      m <- nchar(.self$seq1)
      n <- nchar(.self$seq2)
      matrix <- matrix(0, nrow = m + 1, ncol = n + 1)
      for (i in 1:m) {
        matrix[i + 1, 1] <- i
      }
      for (j in 1:n) {
        matrix[1, j + 1] <- j
      }
      for (i in 1:m) {
        for (j in 1:n) {
          match <- matrix[i, j] + .self$score(substr(.self$seq1, i, i), substr(.self$seq2, j, j))
          delete <- matrix[i, j + 1] + 1
          insert <- matrix[i + 1, j] + 1
          matrix[i + 1, j + 1] <- min(match, delete, insert)
        }
      }
      return(.self$traceback(matrix, m, n))
    },
    traceback = function(matrix, i, j) {
      align1 <- ""
      align2 <- ""
      while (i > 0 || j > 0) {
        if (i > 0 && j > 0 && (matrix[i + 1, j + 1] == matrix[i, j] + .self$score(substr(.self$seq1, i, i), substr(.self$seq2, j, j)))) {
          align1 <- paste0(substr(.self$seq1, i, i), align1)
          align2 <- paste0(substr(.self$seq2, j, j), align2)
          i <- i - 1
          j <- j - 1
        } else if (i > 0 && matrix[i + 1, j + 1] == matrix[i, j + 1] + 1) {
          align1 <- paste0(substr(.self$seq1, i, i), align1)
          align2 <- paste0("-", align2)
          i <- i - 1
        } else {
          align1 <- paste0("-", align1)
          align2 <- paste0(substr(.self$seq2, j, j), align2)
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
  result <- aligner$align()
  cat('Alignment 1:', result[[1]], '\n')
  cat('Alignment 2:', result[[2]], '\n')
}

main()